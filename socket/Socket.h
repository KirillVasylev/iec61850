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
#include <unistd.h>
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

class Socket {
private:
	int sock;
	int listener;
	int port;
	int TimeOut_Sec;
	int TimeOut_USec;
	struct sockaddr_in addr;
	set<int> clients;
	fd_set readset;
	char buf[BUFF_SIZE];
	int bytes_read;
	timeval timeout;
	vector<Transport> parcel;

public:
	Socket(int _port, int TimeOut_Sec, int _TimeOut_Usec);
	~Socket();
	int init();
	void close_socket();
	int read();
	void send_message(Transport parcel);
	void send_message(int socket, int size, const char* message);
	int get_socket();
	Transport get_buff();
};

#endif /* SOCKET_H_ */
