#include "main.h"

//u8 t=' ';
double temp_value = 3.14159;
char Temperture_string[50];

//void GPIO_config(void)
//{
//	GPIO_InitTypeDef	GPIO_InitStructure;									//�ṹ����
//	
//	//��ʼ��LED����
//	GPIO_InitStructure.Pin  = GPIO_Pin_2|GPIO_Pin_3;						//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P5 &= ~0x0d;															//����P5.2/P5.3��ƽ
//	GPIO_Inilize(GPIO_P5,&GPIO_InitStructure);								//��ʼ��
//	
//	//��ʼ����������
//	GPIO_InitStructure.Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;	//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P4,&GPIO_InitStructure);								//��ʼ��
//	GPIO_InitStructure.Pin  = GPIO_Pin_5|GPIO_Pin_6;						//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);								//��ʼ��
//	
//	//��ʼ��PWM����
//	GPIO_InitStructure.Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;				//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P2 &= ~0x0e;															//����P2.1/P2.2/P2.3��ƽ
//	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);								//��ʼ��
//	GPIO_InitStructure.Pin  = GPIO_Pin_7;									//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	P3 &= ~0x80;															//����P3.7��ƽ
//	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);								//��ʼ��
//	
//	//��ʼ������������
//	GPIO_InitStructure.Pin  = GPIO_Pin_All;									//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//	GPIO_InitStructure.Mode = GPIO_HighZ;									//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	GPIO_Inilize(GPIO_P6,&GPIO_InitStructure);								//��ʼ��
//	GPIO_Inilize(GPIO_P7,&GPIO_InitStructure);								//��ʼ��
//}

//void PWM_config(void)
//{
//	P_SW2 |= 0x80;
//	
//	PWMCKS = 0x00;
//	PWMC   = CYCLE;		//����PWM����
//	PWM2T1 = 1;
//	PWM2T2 = 0;
//	PWM2CR = 0x00;		//PWM2�����P3.7
//	PWM3T1 = 1;
//	PWM3T2 = 0;
//	PWM3CR = 0x00;		//PWM3�����P2.1
//	PWM4T1 = 1;
//	PWM4T2 = 0;
//	PWM4CR = 0x00;		//PWM4�����P2.2
//	PWM5T1 = 1;
//	PWM5T2 = 0;
//	PWM5CR = 0x00;		//PWM5�����P2.3
//	PWMCFG = 0x00;		//����PWM�������ʼ��ƽ
//	PWMCR  = 0x0f;		//ʹ��PWM�ź����
//	PWMCR |= 0x80;		//ʹ��PWMģ��
//	
//	P_SW2 &= ~0x80;
//}

//void timer_config(void)
//{
//	TIM_InitTypeDef	TIM_InitStructure;								//�ṹ����
//	
//	TIM_InitStructure.TIM_Mode		= TIM_16BitAutoReload;
//	TIM_InitStructure.TIM_Polity	= PolityLow;
//	TIM_InitStructure.TIM_Interrupt	= ENABLE;
//	TIM_InitStructure.TIM_ClkSource	= TIM_CLOCK_1T;
//	TIM_InitStructure.TIM_ClkOut	= DISABLE;
//	TIM_InitStructure.TIM_Value		= 65536-(MAIN_Fosc/1000);		//12T:value=65536-(MAIN_Fosc/12/f)	fΪƵ��		���31Hz
//	TIM_InitStructure.TIM_Run		= ENABLE;						//1T :value=65536-(MAIN_Fosc/f)		fΪƵ��
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
//		PWM2_SetPwmWide(CYCLE);				//P3.7 ���
//		PWM3_SetPwmWide((1-Speed_L)*CYCLE);	//P2.1 ���
//	}
//	if(Direction_L == NEGATIVE)
//	{
//		PWM2_SetPwmWide((1-Speed_L)*CYCLE);	//P3.7 ���
//		PWM3_SetPwmWide(CYCLE);				//P2.1 ���
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
//		PWM4_SetPwmWide(CYCLE);				//P2.2 ���
//		PWM5_SetPwmWide((1-Speed_R)*CYCLE);	//P2.3 ���
//	}
//	if(Direction_R == NEGATIVE)
//	{
//		PWM4_SetPwmWide((1-Speed_R)*CYCLE);	//P3.7 ���
//		PWM5_SetPwmWide(CYCLE);				//P2.1 ���
//	}
//}

void uart_config(void)
{
	
	COMx_InitDefine		COMx_InitStructure;					//�ṹ����
	
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//ģʽ,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//ʹ�ò�����,   BRT_Timer1, BRT_Timer2 (ע��: ����2�̶�ʹ��BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//������, һ�� 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//��������,   ENABLE��DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//�����ʼӱ�, ENABLE��DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//�ж�����,   ENABLE��DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//�ж����ȼ�, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(����ʹ���ڲ�ʱ��)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//�ڲ���·RXD��TXD, ���м�, ENABLE,DISABLE
	
	USART_Configuration(USART1, &COMx_InitStructure);		//��ʼ������1 USART1,USART2
	
}



void main( )
{
//	GPIO_config( );
//	
//	PWM_config( );
	
	uart_config( );
	
//	PWM2_SetPwmWide(CYCLE);			//P3.7 ���
//	PWM3_SetPwmWide(0.6*CYCLE);		//P2.1 ���
//	
//	PWM4_SetPwmWide(CYCLE);			//P2.2 ���
//	PWM5_SetPwmWide(0.125*CYCLE);	//P2.3 ���

//	OLED_Init( );
//	OLED_Clear( );
//	OLED_DrawBMP(64, 0, 128, 8, BMP3);
	
//	timer_config( );
	
//	EA = 1;
	
	while(1)
	{

		temp_value = DS18B20_GetTemperature( );
		sprintf(Temperture_string, "Temperture is : %4.4f��\r\n", (temp_value));
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
		
//		OLED_ShowChar(0,  0,t,16);	//��ʾASCII�ַ�	   
//		OLED_ShowChar(8,  0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(16, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(24, 0,t,16);	//��ʾASCII�ַ�	   
//		OLED_ShowChar(32, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(40, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(48, 0,t,16);	//��ʾASCII�ַ�	   
//		OLED_ShowChar(56, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(64, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(72, 0,t,16);	//��ʾASCII�ַ�	   
//		OLED_ShowChar(80, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(88, 0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(96, 0,t,16);	//��ʾASCII�ַ�	   
//		OLED_ShowChar(104,0,t,16);	//��ʾASCII�ַ�
//		OLED_ShowChar(112,0,t,16);	//��ʾASCII�ַ�
//		t++;
//		if(t>'~')t=' ';
	}
}

/********************* Timer0�жϺ���************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{

}

/********************* Timer1�жϺ���************************/
void timer1_int (void) interrupt TIMER1_VECTOR
{

}

/********************* Timer2�жϺ���************************/
void timer2_int (void) interrupt TIMER2_VECTOR
{
	
}
