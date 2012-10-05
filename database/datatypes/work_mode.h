/*
 * work_mode.h
 *
 *  Created on: 21.09.2012
 *      Author: kv
 *      описывает режимы работы.
 *      Возможные значения:
 *              стабилизация напряжения;
 *              стабилизация силы тока
 */

#ifndef WORK_MODE_H_
#define WORK_MODE_H_

typedef enum _work_mode
{
  voltage_regulator=0,
  amperage_regulator =1

}work_mode;


#endif /* WORK_MODE_H_ */
