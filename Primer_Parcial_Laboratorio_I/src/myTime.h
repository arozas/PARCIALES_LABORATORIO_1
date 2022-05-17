/*
 * myTime.h
 *
 *  Created on: 16 may. 2022
 *      Author: alejandro
 */

#ifndef MYTIME_H_
#define MYTIME_H_

#include <time.h>
#include <stdio.h>

long int myTime_current(void);
long int myTime_add(double secondsAdd);
void mytime_showTime(long int time);
#endif /* MYTIME_H_ */
