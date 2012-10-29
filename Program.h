/*
 * Program.h
 *
 *  Created on: 29.10.2012
 *      Author: KV
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "socket/Socket.h"
#include "mms/State_Machine.h"
#include <iostream>

using namespace std;

class Program {
private:
	int Socket_port;
	int Socket_TimeOut_Sec;
	int Socket_TimeOut_Usec;
	Socket *socket;
	State_Machine *state_machine;


public:
	void start();
	void kill();
	void reset();
	void get_info_from_sau_base(); //this function should initialize variable depending from sau_base, such as port time out;
	void new_state_machine();//load state machine
	void get_info_from_socket(); //Initialize and work with socket
	void close_socket();
	void new_transmission(Transport parcel);//handler for new message

};



#endif /* PROGRAM_H_ */
