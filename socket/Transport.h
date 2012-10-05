/*
 * Transport.h
 *
 *  Created on: 25.09.2012
 *      Author: kv
 */

#ifndef TRANSPORT_H_
#define TRANSPORT_H_
#include <string>
using namespace std;

typedef struct _Transport
{
  int socket;
  int bytes_read;
  string buff;
}Transport;


#endif /* TRANSPORT_H_ */
