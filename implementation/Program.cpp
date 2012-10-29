/*
 * Program.cpp
 *
 *  Created on: 29.10.2012
 *      Author: KV
 */

#include "../Program.h"

void
Program::start()
{

  get_info_from_sau_base();
  get_info_from_socket();
  new_state_machine();
  if(!(socket->init()==0))// что-топошло не так не возможно запустить новый сокет
    {
      cerr<<"socket error";
    }

  reset();



}
void Program::reset()
{
  kill();
  start();
}
void Program::kill()
{
  delete socket;
  delete state_machine;

}
void
Program::get_info_from_sau_base()
{

  Socket_port = 8886;
  Socket_TimeOut_Sec = 10;
  Socket_TimeOut_Usec = 0;

}
void
Program::new_state_machine()
{
  state_machine = new State_Machine();

}
void
Program::get_info_from_socket()
{
  int read;
  socket = new Socket(Socket_port, Socket_TimeOut_Sec, Socket_TimeOut_Usec);

  while (1)
    {
      read = socket->read();
      if (read > 0)
        {
          Transport tmp = socket->get_buff();
          while (tmp.bytes_read > 0)
            {
              new_transmission(tmp);//обрабатываем посылку
              tmp = socket->get_buff();
            }
          continue;
        }
      if ((read < 0) && (read != TIMEOUT))
        break;

    }

}
void
Program::close_socket()
{
  socket->close_socket();
}
void
Program::new_transmission(Transport parcel)
{
  cout<<parcel.buff;

}



