/*
 * Data_Node.cpp
 *
 *  Created on: 21.09.2012
 *      Author: kv
 */

#include "../Data_Node.h"
#include <ctime>
#include <cstring>

bool
Data_Node::check_name(string Name, string Dest)
{
  if (Dest == "GEN")
    return (Name == this->Name);

  if (Dest == "IN")
    return (strcmp(this->Name_In.Char,Name.c_str()));

  if (Dest == "OUT")
    return (strcmp(this->Name_Out.Char,Name.c_str()));

  return (false);
}
bool
Data_Node::synchro()
{
  sau_to_protocol();
  return(true);
}
bool
Data_Node::set_name(string newNameIn, string newNameOut)
{
  if((newNameIn.length()>MAX_NAME_LENGTH)||newNameOut.length()>MAX_NAME_LENGTH)
    return(false);
  else
   {
     strncpy(this->Name_In.Char,newNameIn.c_str(),newNameIn.length());
     strncpy(this->Name_Out.Char, newNameOut.c_str(), newNameOut.length());
     return (true);
  }

}
data
Data_Node::get_value()
{
  get_value_fromsau();
  return (this->Data);
}
bool
Data_Node::set_value(data newData, long Time)
{

  this->Data = newData;
  this->Last_Changing_Time = time(0);
  load_value_tosau();
  return (true);
}

bool
Data_Node::init(string Name)
{
  this->Name = Name;
  sau_to_protocol();
  return (true);
}
void Data_Node::sau_to_protocol(){}
void Data_Node::protocol_to_sau(){}
void Data_Node::load_value_tosau(){}
void Data_Node::get_value_fromsau(){}
