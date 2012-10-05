/*
 * status.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      Описывает  возможные состояния устроййства
 *      Возможные значения:
 *              готова;
 *              неисправность;
 *              перегрев;
 *              пререгрузка;
 */

#ifndef STATUS_H_
#define STATUS_H_

typedef enum _status
{
  ready=0,
  malfunction =1,
  overheat=2,
  overload=3
}status;

#endif /* STATUS_H_ */
