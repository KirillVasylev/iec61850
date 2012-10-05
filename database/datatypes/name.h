/*
 * name.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      определяем имя так чтобы можно было обращатся как к строке, так и к числу
 */

#ifndef NAME_H_
#define NAME_H_

#define MAX_NAME_LENGTH 8

typedef union _name
{
  unsigned long long Long;
  char Char[MAX_NAME_LENGTH];
}name;

#endif /* NAME_H_ */
