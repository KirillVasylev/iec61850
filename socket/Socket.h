/*
 * Socket.h
 *
 *  Created on: 25.09.2012
 *      Author: kv
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include "Transport.h"

using namespace std;
#define BUFF_SIZE 10240
#define SOCKET_READY 0
#define SOCKET_CREATE_FAIL -1
#define SOCKET_BIND_FAIL -2
#define SOCKET_MYLTI_CREATE_FAIL -3
#define NEW_PARCEL 1
#define TIMEOUT -10
#define MAX_CONNECTION_QUEUE 3
#define PORT 10202
#define TIMEOUT_SEC 10
#define TIMEOUT_USEC 0
class Socket
{
private:
  int sock;
  int listener;
  struct sockaddr_in addr;
  set<int>clients;
  fd_set readset;
  char buf[BUFF_SIZE];
  int bytes_read;
  timeval timeout;
  vector<Transport>parcel;
public:
  Socket();
  int init();
  void close_socket();
  int read();
  void send_message(int socket, int size,const char* message);
  int get_socket();
  Transport get_buff();
};


#endif /* SOCKET_H_ */
