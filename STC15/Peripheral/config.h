#ifndef		__CONFIG_H
#define		__CONFIG_H


/*********************************************************/

//#define MAIN_Fosc		22118400L	//������ʱ��
//#define MAIN_Fosc		12000000L	//������ʱ��
//#define MAIN_Fosc		11059200L	//������ʱ��
//#define MAIN_Fosc		 5529600L	//������ʱ��
#define MAIN_Fosc		24000000L	//������ʱ��


/*********************************************************/

#include	"STC15Fxxxx.H"


/**************************************************************************/

#define Main_Fosc_KHZ	(MAIN_Fosc / 1000)

/***********************************************************/

sbit up_key     = P4^2;
sbit down_key   = P4^1;
sbit right_key  = P4^3;
sbit left_key   = P4^4;
sbit done_key   = P3^5;
sbit cancel_key = P3^6;

sbit state_led	= P5^5;




/***************************************************************/

#endif
