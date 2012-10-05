/*
 * Database.cpp
 *
 *  Created on: 21.09.2012
 *      Author: kv
 */
#include "../Database.h"
bool Database::init()//первоначальная инициализация бд.
//Вызываем соттветсвующий init из узла
{

  if(!Setpoint_Voltage.init("Setpoint_Voltage"))
    return (false);

  if(!Statism.init("Statism"))
    return (false);

  if(!Setpoint_Amperage.init("Setpoint_Amperage"))
    return (false);

  if(!Work_Mode.init("Work_Mode"))
    return (false);

  if(!Control.init("Control"))
    return (false);

  if(!Status.init("Status"))
    return (!false);

  return (true);
}

bool Database::synchro()//синхронизируем протокол и сау. аналогично init.
{
  if(!(Control.get_value().Control==remoute))//запрещаем обновление, если запрещено удаленное управление.
    return (false);
  if(!Setpoint_Voltage.synchro())
    return (false);

  if(!Statism.synchro())
    return (false);

  if(!Setpoint_Amperage.synchro())
    return (false);

  if(!Work_Mode.synchro())
    return (false);

  if(!Control.synchro())
    return (false);

  if(!Status.synchro())
    return (!false);

  return (true);

}

bool Database::set_value(string Name, data NewData, long Time)
{
  if(Setpoint_Voltage.check_name(Name, "IN"))
    return (Setpoint_Voltage.set_value(NewData, Time));

  if(Statism.check_name(Name, "IN"))
    return (Statism.set_value(NewData, Time));

  if(Setpoint_Amperage.check_name(Name, "IN"))
    return (Setpoint_Amperage.set_value(NewData, Time));

  if(Work_Mode.check_name(Name, "IN"))
    return (Work_Mode.set_value(NewData, Time));

  if(Control.check_name(Name, "IN"))
    return (Control.set_value(NewData, Time));

  if(Status.check_name(Name,"IN"))
    return (Status.set_value(NewData, Time));

  return (false);
}

data Database::get_value(string Name)
{

  if(Setpoint_Voltage.check_name(Name , "OUT"))
    return (Setpoint_Voltage.get_value());

  if(Statism.check_name(Name, "OUT"))
    return(Statism.get_value());

  if(Setpoint_Amperage.check_name(Name, "OUT"))
    return(Setpoint_Amperage.get_value());

  if(Work_Mode.check_name(Name, "OUT"))
    return (Work_Mode.get_value());

  if(Control.check_name(Name, "OUT"))
    return(Control.get_value());

  if(Status.check_name(Name, "OUT"))
    return (Status.get_value());

  data tmp;
  tmp.Int = -1;
  return (tmp);
}

bool Database::set_name(string Name, string newNameIn, string newNameOut)
{
  if(Setpoint_Voltage.check_name(Name , "GEN"))
    return (Setpoint_Voltage.set_name(newNameIn, newNameOut));

  if(Statism.check_name(Name, "GEN"))
    return(Statism.set_name(newNameIn, newNameOut));

  if(Setpoint_Amperage.check_name(Name, "GEN"))
    return(Setpoint_Amperage.set_name(newNameIn, newNameOut));

  if(Work_Mode.check_name(Name, "GEN"))
    return (Work_Mode.set_name(newNameIn, newNameOut));

  if(Control.check_name(Name, "GEN"))
    return(Control.set_name(newNameIn, newNameOut));

  if(Status.check_name(Name, "GEN"))
    return (Status.set_name(newNameIn,newNameOut));

  return (false);
}
