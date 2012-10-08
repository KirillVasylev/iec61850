/*
 * Basic_Type_Coder&Decoder.h
 *
 *  Created on: 05.10.2012
 *      Author: KV
 */

#ifndef BASIC_TYPE_CODER_DECODER_H_
#define BASIC_TYPE_CODER_DECODER_H_

#include <vector>
#include <cmath>
#include <string>
#include "ASN_Type.h"
using namespace std;

class Basic_Type_Coder_Decoder
{
public:
	
 vector<unsigned char>Encode_Integer(int num);
 int Decode_Integer(vector<unsigned char>message);
 vector<unsigned char>Encode_Bool(bool val);
 bool Decode_Bool(vector<unsigned char>message);
 vector<unsigned char>Encode_VisibleString(string value);
 string Decode_VisibleString(vector<unsigned char> message);
 

};



#endif /* BASIC_TYPE_CODER_DECODER_H_ */