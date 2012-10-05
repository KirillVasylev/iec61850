/*
 * data.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      Сборище всевозможных информаций
 */

#ifndef DATA_H_
#define DATA_H_

#include "work_mode.h"
#include "control.h"
#include "status.h"

#define MAX_DATA_SIZE 8

typedef union _data
{
  int Int;
  work_mode Work_Mode;
  control Control;
  status Status;
  char Char[MAX_DATA_SIZE];

}data;


#endif /* DATA_H_ */
