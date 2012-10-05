/*
 * Data_Node_Heir.h
 *
 *  Created on: 24.09.2012
 *      Author: kv
 */

#ifndef DATA_NODEHEIR_H_
#define DATA_NODEHEIR_H_
#include "Data_Node.h"

class Setpoint_VoltageClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};
class StatismClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};
class Setpoint_AmperageClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};
class Work_modeClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};
class ControlClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};
class StatusClass : public Data_Node
{
protected:
  virtual void sau_to_protocol();
  virtual void protocol_to_sau();
  virtual void load_value_tosau();
  virtual void get_value_fromsau();
};

#endif /* DATA_NODE_HEIR_H_ */
