#ifndef _ds18b20_H
#define _ds18b20_H

#include "delay.h"

sbit DQ = P2^0;

void DS18B20_Reset();
void DS18B20_WriteByte(BYTE dat);
BYTE DS18B20_ReadByte();

double DS18B20_GetTemperature( );
u32 a();

#endif
