/*************	功能说明	**************

本文件为STC15xxx系列的延时程序,用户几乎可以不修改这个程序.

******************************************/

#include	"delay.h"

//========================================================================
// 函数: void  delay_ms(unsigned char ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
void  delay_ms(unsigned char ms)
{
     unsigned int i;
	 do{
	      i = MAIN_Fosc / 13000;
		  while(--i)	;   //14T per loop
     }while(--ms);
}

void Delay240us()		//@24.000MHz
{
	unsigned char i, j;

	i = 6;
	j = 151;
	do
	{
		while (--j);
	} while (--i);
}

void Delay180us()		//@24.000MHz
{
	unsigned char i, j;

	i = 5;
	j = 48;
	do
	{
		while (--j);
	} while (--i);
}

void Delay60us()		//@24.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 99;
	do
	{
		while (--j);
	} while (--i);
}

void Delay1us()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 3;
	while (--i);
}
