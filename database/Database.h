/*
 * Database.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      хранит всю информацию
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <list>
#include "Data_NodeHeir.h"
using namespace std;

class Database {
public:
  bool init();
  bool synchro();
  bool set_value(string Name, data newData, long Time);
  data get_value(string Name);
  bool set_name(string Name, string newNameIn, string newNameOut);

private:
  Setpoint_VoltageClass Setpoint_Voltage;
  Setpoint_AmperageClass Setpoint_Amperage;
  StatismClass Statism;
  Work_modeClass Work_Mode;
  ControlClass Control;
  StatusClass Status;
  //exclude for future releases
  //list<Data_Node> Other_Value;//для подхватывания настроек "на лету"
};


#endif /* DATABASE_H_ */
