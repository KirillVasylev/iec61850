#include "Basic_Type_Coder_Decoder.h"
#define MESSAGE_TYPE 0
#define MESSAGE_LENGHT 1
vector<unsigned char>Basic_Type_Coder_Decoder::Encode_Integer(int num)
{
	vector<unsigned char>message;
	message.clear();
	
	message.push_back(Integer);
	AST_Int tmp;
	memset(tmp.Char,0x0,sizeof(AST_Int));
	tmp.Int = num;
	
	int size=0;
	message.push_back(size);
	for(int i=sizeof(AST_Int)-1; i>=0; i--)
	{
		if(tmp.Char[i]!=0)
		{
			message.push_back(tmp.Char[i]);
			size=size+1;
		}
	}
	message[MESSAGE_LENGHT]=size;
	return message;

}
int Basic_Type_Coder_Decoder::Decode_Integer(vector<unsigned char> message)
{
	
	AST_Int tmp;
	memset(tmp.Char,0x0,2);
	tmp.Int=0;
	if(message[MESSAGE_TYPE]!=Integer)
		return NULL;
	if(message[MESSAGE_LENGHT]>sizeof(int))
		return NULL;
//	for(int i=0; i<message[MESSAGE_LENGHT]; i++)
//		tmp.Int= tmp.Int + message[MESSAGE_LENGHT+1+i]*pow(256,message[MESSAGE_LENGHT]-1 - i);
//exclude, wong work witn negative numbers

	for(int i=0; i<message[MESSAGE_LENGHT]; i++)
	{
		tmp.Char[sizeof(int)-1-i]=message[MESSAGE_LENGHT+1+i];

	}
	return tmp.Int;
}

vector<unsigned char>Basic_Type_Coder_Decoder::Encode_Bool(bool val)
{
	vector<unsigned char> message;
	message.clear();
	message.push_back(Bollean);
	message.push_back(1);
	if(val == false)
	{
		message.push_back(0);
	}
	else
	{
		message.push_back(1);
	}
	return message;
}

bool Basic_Type_Coder_Decoder::Decode_Bool(vector<unsigned char> message)
{
	if(message[MESSAGE_TYPE]!=Bollean)
		return NULL;
	if(message[MESSAGE_LENGHT]>1)
		return NULL;
	if(message[MESSAGE_LENGHT+1]==0)
		return false;
	else
		return true;
}

vector<unsigned char> Basic_Type_Coder_Decoder::Encode_VisibleString(string value)
{
	vector<unsigned char> message;
	message.clear();
	message.push_back(VisibleString);
	message.push_back(value.size());
	for(int i=0; i<value.size(); i++)
	{
		message.push_back(value.c_str()[i]);
	}
	return message;
}

string Basic_Type_Coder_Decoder::Decode_VisibleString(vector<unsigned char> message)
{
	string tmp;
	if(message[MESSAGE_TYPE]!=VisibleString)
		return NULL;
	for(int i = 0; i<message[MESSAGE_LENGHT]; i++)
	{
		tmp +=message[MESSAGE_LENGHT+i];
	}
	return tmp;
}