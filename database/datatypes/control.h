/*
 * control.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      описывает режимы работы
 *      Возможные значения:
 *              местное управление;
 *              удаленное управление;
 */

#ifndef CONTROL_H_
#define CONTROL_H_

typedef enum _control
{
  local=0,
  remoute=1
}control;

#endif /* CONTROL_H_ */
