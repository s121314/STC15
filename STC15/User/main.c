#include "main.h"

//u8 t=' ';
double temp_value = 3.14159;
char Temperture_string[50];

//void GPIO_config(void)
//{
//	GPIO_InitTypeDef	GPIO_InitStructure;									//结构定义
//	
//	//初始化LED引脚
//	GPIO_InitStructure.Pin  = GPIO_Pin_2|GPIO_Pin_3;						//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P5 &= ~0x0d;															//设置P5.2/P5.3电平
//	GPIO_Inilize(GPIO_P5,&GPIO_InitStructure);								//初始化
//	
//	//初始化按键引脚
//	GPIO_InitStructure.Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;	//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P4,&GPIO_InitStructure);								//初始化
//	GPIO_InitStructure.Pin  = GPIO_Pin_5|GPIO_Pin_6;						//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);								//初始化
//	
//	//初始化PWM引脚
//	GPIO_InitStructure.Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;				//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P2 &= ~0x0e;															//设置P2.1/P2.2/P2.3电平
//	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);								//初始化
//	GPIO_InitStructure.Pin  = GPIO_Pin_7;									//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P3 &= ~0x80;															//设置P3.7电平
//	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);								//初始化
//	
//	//初始化传感器引脚
//	GPIO_InitStructure.Pin  = GPIO_Pin_All;									//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P6,&GPIO_InitStructure);								//初始化
//	GPIO_Inilize(GPIO_P7,&GPIO_InitStructure);								//初始化
//}

//void PWM_config(void)
//{
//	P_SW2 |= 0x80;
//	
//	PWMCKS = 0x00;
//	PWMC   = CYCLE;		//设置PWM周期
//	PWM2T1 = 1;
//	PWM2T2 = 0;
//	PWM2CR = 0x00;		//PWM2输出到P3.7
//	PWM3T1 = 1;
//	PWM3T2 = 0;
//	PWM3CR = 0x00;		//PWM3输出到P2.1
//	PWM4T1 = 1;
//	PWM4T2 = 0;
//	PWM4CR = 0x00;		//PWM4输出到P2.2
//	PWM5T1 = 1;
//	PWM5T2 = 0;
//	PWM5CR = 0x00;		//PWM5输出到P2.3
//	PWMCFG = 0x00;		//配置PWM的输出初始电平
//	PWMCR  = 0x0f;		//使能PWM信号输出
//	PWMCR |= 0x80;		//使能PWM模块
//	
//	P_SW2 &= ~0x80;
//}

//void timer_config(void)
//{
//	TIM_InitTypeDef	TIM_InitStructure;								//结构定义
//	
//	TIM_InitStructure.TIM_Mode		= TIM_16BitAutoReload;
//	TIM_InitStructure.TIM_Polity	= PolityLow;
//	TIM_InitStructure.TIM_Interrupt	= ENABLE;
//	TIM_InitStructure.TIM_ClkSource	= TIM_CLOCK_1T;
//	TIM_InitStructure.TIM_ClkOut	= DISABLE;
//	TIM_InitStructure.TIM_Value		= 65536-(MAIN_Fosc/1000);		//12T:value=65536-(MAIN_Fosc/12/f)	f为频率		最低31Hz
//	TIM_InitStructure.TIM_Run		= ENABLE;						//1T :value=65536-(MAIN_Fosc/f)		f为频率
//	
//	while(Timer_Inilize(Timer0, &TIM_InitStructure));
//}

//void Motor_L(u8 Direction_L, float Speed_L)
//{
//	if(Speed_L < 0)
//		Speed_L = 0;
//	if(Speed_L > 1)
//		Speed_L = 1;
//	
//	if(Direction_L == POSITIVE)
//	{
//		PWM2_SetPwmWide(CYCLE);				//P3.7 输出
//		PWM3_SetPwmWide((1-Speed_L)*CYCLE);	//P2.1 输出
//	}
//	if(Direction_L == NEGATIVE)
//	{
//		PWM2_SetPwmWide((1-Speed_L)*CYCLE);	//P3.7 输出
//		PWM3_SetPwmWide(CYCLE);				//P2.1 输出
//	}
//}

//void Motor_R(u8 Direction_R, float Speed_R)
//{
//	if(Speed_R < 0)
//		Speed_R = 0;
//	if(Speed_R > 1)
//		Speed_R = 1;
//	
//	if(Direction_R == POSITIVE)
//	{
//		PWM4_SetPwmWide(CYCLE);				//P2.2 输出
//		PWM5_SetPwmWide((1-Speed_R)*CYCLE);	//P2.3 输出
//	}
//	if(Direction_R == NEGATIVE)
//	{
//		PWM4_SetPwmWide((1-Speed_R)*CYCLE);	//P3.7 输出
//		PWM5_SetPwmWide(CYCLE);				//P2.1 输出
//	}
//}

void uart_config(void)
{
	
	COMx_InitDefine		COMx_InitStructure;					//结构定义
	
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//模式,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//使用波特率,   BRT_Timer1, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//波特率, 一般 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//波特率加倍, ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//中断优先级, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//切换端口,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(必须使用内部时钟)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//内部短路RXD与TXD, 做中继, ENABLE,DISABLE
	
	USART_Configuration(USART1, &COMx_InitStructure);		//初始化串口1 USART1,USART2
	
}



void main( )
{
//	GPIO_config( );
//	
//	PWM_config( );
	
	uart_config( );
	
//	PWM2_SetPwmWide(CYCLE);			//P3.7 输出
//	PWM3_SetPwmWide(0.6*CYCLE);		//P2.1 输出
//	
//	PWM4_SetPwmWide(CYCLE);			//P2.2 输出
//	PWM5_SetPwmWide(0.125*CYCLE);	//P2.3 输出

//	OLED_Init( );
//	OLED_Clear( );
//	OLED_DrawBMP(64, 0, 128, 8, BMP3);
	
//	timer_config( );
	
//	EA = 1;
	
	while(1)
	{

		temp_value = DS18B20_GetTemperature( );
		sprintf(Temperture_string, "Temperture is : %4.4f℃\r\n", (temp_value));
		serial_send_string(Temperture_string);
		P55 = ~P55;
		delay_ms(250);
		delay_ms(250);
		
//		OLED_DrawBMP(0,0,128,8,BMP1);
//		delay_ms(68);
//		OLED_DrawBMP(0,0,128,8,BMP2);
//		delay_ms(68);
//		OLED_DrawBMP(0,0,128,8,BMP3);
//		delay_ms(68);
//		OLED_DrawBMP(0,0,128,8,BMP2);	//57mS
//		delay_ms(68);
		
//		OLED_ShowNum(0, 2,P60,1,16);
//		OLED_ShowNum(8, 2,P61,1,16);
//		OLED_ShowNum(16,2,P62,1,16);
//		OLED_ShowNum(24,2,P63,1,16);
//		OLED_ShowNum(32,2,P64,1,16);
//		OLED_ShowNum(40,2,P65,1,16);
//		OLED_ShowNum(48,2,P66,1,16);
//		OLED_ShowNum(56,2,P67,1,16);
//	
//		OLED_ShowNum(0, 4,P70,1,16);
//		OLED_ShowNum(8, 4,P71,1,16);
//		OLED_ShowNum(16,4,P72,1,16);
//		OLED_ShowNum(24,4,P73,1,16);
//		OLED_ShowNum(32,4,P74,1,16);
//		OLED_ShowNum(40,4,P75,1,16);
//		OLED_ShowNum(48,4,P76,1,16);
//		OLED_ShowNum(56,4,P77,1,16);
		
//		Motor_L(NEGATIVE,0.5642);
//		Motor_R(POSITIVE,0.2);
		
//		OLED_ShowChar(0,  0,t,16);	//显示ASCII字符	   
//		OLED_ShowChar(8,  0,t,16);	//显示ASCII字符
//		OLED_ShowChar(16, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(24, 0,t,16);	//显示ASCII字符	   
//		OLED_ShowChar(32, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(40, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(48, 0,t,16);	//显示ASCII字符	   
//		OLED_ShowChar(56, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(64, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(72, 0,t,16);	//显示ASCII字符	   
//		OLED_ShowChar(80, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(88, 0,t,16);	//显示ASCII字符
//		OLED_ShowChar(96, 0,t,16);	//显示ASCII字符	   
//		OLED_ShowChar(104,0,t,16);	//显示ASCII字符
//		OLED_ShowChar(112,0,t,16);	//显示ASCII字符
//		t++;
//		if(t>'~')t=' ';
	}
}

/********************* Timer0中断函数************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{

}

/********************* Timer1中断函数************************/
void timer1_int (void) interrupt TIMER1_VECTOR
{

}

/********************* Timer2中断函数************************/
void timer2_int (void) interrupt TIMER2_VECTOR
{
	
}
