/*
 * access.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      содержит уровни доступа в системе.
 *      Возможные значения:
 *              без внешнего доступа;
 *              внешнее чтение;
 *              внешнее чтение и запись;
 */

#ifndef ACCESS_H_
#define ACCESS_H_

typedef enum _access
{
  no_internal_access = 0,
  external_read = 1,
  external_write = 2
}data_access;

#endif /* ACCESS_H_ */
