#include "../State_Machine.h"

State_Machine::State_Machine()
{
	next_node.clear();
	message.clear();
	stack.clear();
	size_node.clear();
	init();
}
State_Machine::~State_Machine()
{

  next_node.clear();
  message.clear();
  stack.clear();
  size_node.clear();

}
State_Machine::State_Machine(int sock, string buff)
{
	next_node.clear();
	message.clear();
	socket = sock;
	stack.clear();
	size_node.clear();
	init();
	
}
unsigned char State_Machine::get_char_by_name(string name)
{
	if(name == "Start")
		return 0x0;
	if(name == "initiate_RequestPDU")
		return initiate_RequestPDU;
	if(name == "initiate-RequestPDU")
		return initiate_RequestPDU;
	if(name == "confirmed_RequestPDU")
		return confirmed_RequestPDU;
	if(name == "confirmed-RequestPDU")
		return confirmed_RequestPDU;
	if(name == "LocalDetailCalled")
		return LocalDetailCalled;
	if (name == "negociatedMaxServOutstandingCalling")
		return negociatedMaxServOutstandingCalling;
	if(name == "negociatedMaxServOutstandingCalled")
		return negociatedMaxServOutstandingCalled;
	if(name == "negociatedDataStructureNestingLevel")
		return  negociatedDataStructureNestingLevel;
	if(name == "mmsInitResponseDetail")
		return mmsInitResponseDetail;
	if(name =="ProposedVersionNumber")
		return ProposedVersionNumber;
	if(name == "ProposedParameters")
		return ProposedParam;
	if(name == "ProposedServices")
		return ProposedServices;
	if(name  =="InokeID")
		return InnvokeID;
	if(name == "ServiceRead")
		return serviceReadRequest;
	if(name == "ServiceWrite")
		return serviceWriteRequest;
	if(name =="ListOfVariable")
		return List;
	if(name == "Item")
		return List_ofVariableItem;
	return 0x0;
}
void State_Machine::init()
{
	
	ifstream rules_file("rule.txt",fstream::in);
	if(!rules_file.good())
	  cerr<<"broken rule file";
	int size; 
	string next;
	Rule tmp;
	while (!rules_file.eof())
	{

		rules_file>>next;
		tmp.name = get_char_by_name(next);
		rules_file>>size;
		for(int i=0; i< size; i++)
		{
			rules_file>>next;
			tmp.next.push_back(get_char_by_name(next));
		}
		rules_file>>next;
		if(next == "NODE")
			tmp.type=NODE;
		else if(next=="BASIC")
			tmp.type=BASIC;
		rules.push_back(tmp);
		tmp.next.clear();
	}
}

int State_Machine::start(int sock,string buff)
{
	next_node.clear();
	message.clear();
	stack.clear();
	size_node.clear();
	for(unsigned int i =0; i < buff.size();i++)
	{
		message.push_back(buff.c_str()[i]);
	}
	socket = sock;
	stack.push_back("Start");
	size_node.push_back(message.size());
	return next_step();
	
}
int State_Machine::check_next(unsigned char current_symbol)
{
	unsigned char current_rule_node =get_char_by_name(stack.back());
	for(unsigned int i = 0; i<rules.size(); i++)
	{
		if(current_rule_node == rules[i].name)
		{
			for(unsigned int j =0; j<rules[i].next.size(); j++)
			{
				if(rules[i].next[j] == current_symbol)
					return 0;
			}
			
		}
	}
	return 1;

}
int State_Machine::get_type(unsigned char current_symbol)
{
	for(unsigned int i=0; i<rules.size(); i++)
	{
		if(current_symbol ==  rules[i].name)
			return rules[i].type;
	}
	return -1;

}
string State_Machine::get_name_by_char(unsigned char symbol)
{
	if(stack.back() == "Start")
	{
		if(symbol == initiate_RequestPDU)
			return "initiate_RequestPDU";
		if(symbol == confirmed_RequestPDU)
			return "confirmed_RequestPDU";
	}
	if(stack.back()=="initiate_RequestPDU")
	{
		if(symbol == LocalDetailCalled)
			return "LocalDetailCalled";
		if(symbol == negociatedMaxServOutstandingCalling)
			return "negociatedMaxServOutstandingCalling";
		if(symbol == negociatedMaxServOutstandingCalled) 
			return "negociatedMaxServOutstandingCalled";
		if(symbol == negociatedDataStructureNestingLevel)
			return "negociatedDataStructureNestingLevel";
		if(symbol == mmsInitResponseDetail)
			return "mmsInitResponseDetail"; 
	}
	
	if((stack.back() == "mmsInitResponseDetail")&&(*(stack.end()-2)=="initiate_RequestPDU"))
	{
		if(symbol == ProposedVersionNumber)
			return "ProposedVersionNumber";
		if(symbol == ProposedServices)
			return "ProposedServices";
		if(symbol == ProposedServices)
			return "ProposedServices";
	}

	if(stack.back() == "confirmed_RequestPDU")
	{
		if(symbol == InnvokeID)
			return "InnvokeID";
		if(symbol == serviceReadRequest)
			return "serviceReadRequest";
		if(symbol == serviceWriteRequest)
			return "serviceWriteRequest";
	}
	if((stack.back() == "serviceReadRequest")&&(*(stack.end()-2) =="confirmed_RequestPDU"))
	{
		if(symbol == List)
			return "List";
	}
	if((stack.back() == "serviceWriteRequest")&&(*(stack.end()-2) =="confirmed_RequestPDU"))
	{
		if(symbol == List)
			return "List";
	}
	if(stack.back() == "List")
	{
		return "Elem";
	}
	return "None";
}
int State_Machine::next_step()
{
	unsigned char current_symbol;
	unsigned char current_size;
	int octet_poped;
	while(message.size()>0)
	{
		octet_poped = 0;
		current_symbol = message.front();
		message.pop_front();
		octet_poped++;
		if(check_next(current_symbol))
			return 1;
		int current_type= get_type(current_symbol);
		current_size = message.front();
		message.pop_front();
		octet_poped++;
		cout<<get_name_by_char(current_symbol)<<"  "<<int(current_size)<<endl;
		if(current_type == NODE)
		{
			stack.push_back(get_name_by_char(current_symbol));
			size_node.push_back(int(current_size));
		}
		else if (current_type == BASIC)
		{
			vector<unsigned char> for_basic_decoder;
			for_basic_decoder.push_back(current_symbol);
			for_basic_decoder.push_back(current_size);
			for(int i=0; i<current_size; i++)
			{
				for_basic_decoder.push_back(message.front());
				message.pop_front();
				octet_poped++;
			}
			
		}
		else return 1;
		for(unsigned int i=0; i< size_node.size(); i++)
		{
			size_node[i] -=octet_poped;
			if(size_node[i]<=0)
			{
				size_node.erase(size_node.begin()+i, size_node.begin()+(i+1));
			}
		}


	}
	return 0;
}
