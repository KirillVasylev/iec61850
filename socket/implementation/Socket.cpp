/*
 * Socket.cpp
 *
 *  Created on: 25.09.2012
 *      Author: kv
 */

#include "../Socket.h"

Socket::Socket()
{
  parcel.clear();
  clients.clear();
}

int
Socket::init()
{

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    {
      cerr << "socket fail" << endl;
      return (SOCKET_CREATE_FAIL);
    }
  fcntl(listener, F_SETFL, O_NONBLOCK);
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
      cerr << "bind fail" << endl;
      return (SOCKET_BIND_FAIL);
    }

  listen(sock, MAX_CONNECTION_QUEUE);
  // Задаём таймаут
  timeout.tv_sec = TIMEOUT_SEC;
  timeout.tv_usec = TIMEOUT_USEC;
  return (SOCKET_READY);
}

int
Socket::read()
{
  while (1)
    {
      // Заполняем множество сокетов

      FD_ZERO(&readset);
      FD_SET(sock, &readset);

      for (set<int>::iterator it = clients.begin(); it != clients.end(); it++)
        FD_SET(*it, &readset);

      // Ждём события в одном из сокетов
      int mx = max(sock, *max_element(clients.begin(), clients.end()));
      if (select(mx + 1, &readset, NULL, NULL, &timeout) <= 0)
        {
          //cerr<<"time out"<<endl;
          return (TIMEOUT);
        }

      // Определяем тип события и выполняем соответствующие действия
      if (FD_ISSET(sock, &readset))
        {
          // Поступил новый запрос на соединение, используем accept
          listener = accept(sock, NULL, NULL);
          if (sock < 0)
            {
              cerr << "accept";
              return (SOCKET_MYLTI_CREATE_FAIL);
            }
          fcntl(listener, F_SETFL, O_NONBLOCK);
          clients.insert(listener);
        }

      for (set<int>::iterator it = clients.begin(); it != clients.end(); it++)
        {
          if (FD_ISSET(*it, &readset))
            {
              // Поступили данные от клиента, читаем их
              bytes_read = recv(*it, buf, BUFF_SIZE, 0);
              if (bytes_read <= 0)
                {
                  // Соединение разорвано, удаляем сокет из множества
                  close(*it);
                  clients.erase(*it);
                  continue;
                }
              //отправляем на обработку
              Transport tmp;
              tmp.socket = *it;
              tmp.bytes_read = bytes_read;
              tmp.buff = buf;
              parcel.push_back(tmp);
              return (NEW_PARCEL);
            }
        }
    }
}
Transport
Socket::get_buff()
{
  Transport tmp;
  if (parcel.size() == 0)
    {
      tmp.bytes_read = 0;
      return (tmp);

    }
  else
    {
      tmp = parcel[0];
      parcel.erase(parcel.begin(), parcel.begin() + 1);

      return (tmp);
    }
}
void
Socket::send_message(int socket, int size, const char* message)
{
  send(socket, message, size, 0);
}
void
Socket::close_socket()
{
  close(sock);
}
