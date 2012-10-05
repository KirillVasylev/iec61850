/*
 * Decoder.h
 *
 *  Created on: 02.10.2012
 *      Author: kv
 */

#ifndef DECODER_H_
#define DECODER_H_
#include <vector>
#include <iostream>
using namespace std;

class Decoder
{
public:
  int socket;
  Decoder(int sock, int last_type, vector<unsigned char>message);
  int next(int sock, int type, vector<unsigned char>message);
  void check();
protected:
  unsigned char type;
  int lenght;
  vector<unsigned char>body;

};



#endif /* DECODER_H_ */
