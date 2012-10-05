/*
 * Data_node.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      Описвавем одну строку базы данных, содержащюю всю информацию
 *      ровно об одном значении
 */

#ifndef DATA_NODE_H_
#define DATA_NODE_H_

#include <vector>
#include <string>
#include "datatypes/access.h"
#include "datatypes/name.h"
#include "datatypes/data.h"
using namespace std;

class Data_Node {
public:
  bool set_name(string newNameIn, string newNameOut);
  bool set_value(data newData, long Time);
  bool check_name(string Name, string Dest);
  data get_value();
  bool init(string Name);
  bool synchro();

protected:
  string Name;
  data_access Access;
  data Data;
  int Min_Value;
  int Max_Value;
  name Name_In;
  name Name_Out;
  unsigned long Last_Changing_Time;
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};


#endif /* DATA_NODE_H_ */
