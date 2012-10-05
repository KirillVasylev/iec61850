/*
 * main.cpp
 *
 *  Created on: 21.09.2012
 *      Author: kv
 */
#include <iostream>
#include "database/Database.h"
#include "database/datatypes/data.h"
#include <ctime>
#include "socket/Socket.h"
using namespace std;
int
main()
{
  Socket *s = new Socket();
  s->init();
  while (1)
    {
      int read = s->read();
      if (read > 0)
        {
          Transport tmp = s->get_buff();
          while (tmp.bytes_read > 0)
            {
              cout << tmp.socket << " " << tmp.bytes_read << " " << tmp.buff
                  << endl;
              s->send_message(tmp.socket, tmp.bytes_read, tmp.buff.c_str());
              tmp = s->get_buff();
            }
          continue;
        }
      if ((read < 0) && (read != TIMEOUT))
        break;

    }
  s->close_socket();

}
