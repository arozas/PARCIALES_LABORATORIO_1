/*
 * myTime.c
 *
 *  Created on: 16 may. 2022
 *      Author: alejandro
 */
#include "myTime.h"

long int myTime_current(void)
{
	return time(NULL);
}
long int myTime_add(double secondsAdd)
{
	return secondsAdd + time(NULL);
}
void mytime_showTime(long int time)
{
	char* date = ctime(&time);
	printf("%s",date);
}
