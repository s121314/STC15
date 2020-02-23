#include "ds18b20.h"
#include "intrins.h"
#include "math.h"


/**************************************
��λDS18B20,������豸�Ƿ����
**************************************/
void DS18B20_Reset()
{
    CY = 1;
    while (CY)
    {
        DQ = 0;                     //�ͳ��͵�ƽ��λ�ź�
        Delay240us( );              //��ʱ����480us
        Delay240us( );
        DQ = 1;                     //�ͷ�������
        Delay60us();               //�ȴ�60us
        CY = DQ;                    //����������
        Delay240us( );              //�ȴ��豸�ͷ�������
        Delay180us( );
    }
}

/**************************************
��DS18B20��1�ֽ�����
**************************************/
BYTE DS18B20_ReadByte()
{
    BYTE i;
    BYTE dat = 0;

    for (i=0; i<8; i++)             //8λ������
    {
        dat >>= 1;
        DQ = 0;                     //��ʼʱ��Ƭ
        Delay1us( );                //��ʱ�ȴ�
        DQ = 1;                     //׼������
        Delay1us( );                //������ʱ
        if (DQ) dat |= 0x80;        //��ȡ����
        Delay60us( );               //�ȴ�ʱ��Ƭ����
    }

    return dat;
}

/**************************************
��DS18B20д1�ֽ�����
**************************************/
void DS18B20_WriteByte(BYTE dat)
{
    char i;

    for (i=0; i<8; i++)             //8λ������
    {
        DQ = 0;                     //��ʼʱ��Ƭ
        Delay1us( );                //��ʱ�ȴ�
        dat >>= 1;                  //�ͳ�����
        DQ = CY;
        Delay60us( );               //�ȴ�ʱ��Ƭ����
        DQ = 1;                     //�ָ�������
        Delay1us( );                //�ָ���ʱ
    }
}

double DS18B20_GetTemperature( )
{
	u16 TPH = 0;                           //����¶�ֵ�ĸ��ֽ�
	u16 TPL = 0;                           //����¶�ֵ�ĵ��ֽ�
	u16 TEMP= 0;							//����¶�ֵ
	float VALUE = 0.0;						//returnֵ
	
	EA = 0;
	DS18B20_Reset();                //�豸��λ
    DS18B20_WriteByte(0xCC);        //����ROM����
    DS18B20_WriteByte(0x44);        //��ʼת������
    while (!DQ);                    //�ȴ�ת�����

    DS18B20_Reset();                //�豸��λ
    DS18B20_WriteByte(0xCC);        //����ROM����
    DS18B20_WriteByte(0xBE);        //���ݴ�洢������
    TPL = DS18B20_ReadByte();       //���¶ȵ��ֽ�
    TPH = DS18B20_ReadByte();       //���¶ȸ��ֽ�
	EA = 1;
	
	TEMP = TPL + (TPH << 8);
	
	if((TEMP&0xf800)==0xf800)
	{
		TEMP=(~TEMP)+1;
		VALUE = (float)(TEMP*(-0.0625));
	}
	else
	{
		VALUE = (float)(TEMP*(0.0625));
	}
	
	return (VALUE);
}

u32 a()
{
	return 193374UL;
}