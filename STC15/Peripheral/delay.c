/*************	����˵��	**************

���ļ�ΪSTC15xxxϵ�е���ʱ����,�û��������Բ��޸��������.

******************************************/

#include	"delay.h"

//========================================================================
// ����: void  delay_ms(unsigned char ms)
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~255ms. �Զ���Ӧ��ʱ��.
// ����: none.
// �汾: VER1.0
// ����: 2013-4-1
// ��ע: 
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
