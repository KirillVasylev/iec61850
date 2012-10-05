/*
 * Decoder.cpp
 *
 *  Created on: 02.10.2012
 *      Author: kv
 */
#include "../Decoder.h"

Decoder::Decoder(int sock, int last_type, vector<unsigned char> message)
{
  next(sock,last_type,message);
}
int Decoder::next(int sock,int last_type, vector<unsigned char>message)
{

}

void Decoder::check()
{
  if(body.size()>0)
    {

    }
  else//разшифровка закончена;
    {
      cout<<"ok";
    }

}

