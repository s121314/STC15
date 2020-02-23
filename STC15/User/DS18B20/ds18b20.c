#include "ds18b20.h"
#include "intrins.h"
#include "math.h"


/**************************************
复位DS18B20,并检测设备是否存在
**************************************/
void DS18B20_Reset()
{
    CY = 1;
    while (CY)
    {
        DQ = 0;                     //送出低电平复位信号
        Delay240us( );              //延时至少480us
        Delay240us( );
        DQ = 1;                     //释放数据线
        Delay60us();               //等待60us
        CY = DQ;                    //检测存在脉冲
        Delay240us( );              //等待设备释放数据线
        Delay180us( );
    }
}

/**************************************
从DS18B20读1字节数据
**************************************/
BYTE DS18B20_ReadByte()
{
    BYTE i;
    BYTE dat = 0;

    for (i=0; i<8; i++)             //8位计数器
    {
        dat >>= 1;
        DQ = 0;                     //开始时间片
        Delay1us( );                //延时等待
        DQ = 1;                     //准备接收
        Delay1us( );                //接收延时
        if (DQ) dat |= 0x80;        //读取数据
        Delay60us( );               //等待时间片结束
    }

    return dat;
}

/**************************************
向DS18B20写1字节数据
**************************************/
void DS18B20_WriteByte(BYTE dat)
{
    char i;

    for (i=0; i<8; i++)             //8位计数器
    {
        DQ = 0;                     //开始时间片
        Delay1us( );                //延时等待
        dat >>= 1;                  //送出数据
        DQ = CY;
        Delay60us( );               //等待时间片结束
        DQ = 1;                     //恢复数据线
        Delay1us( );                //恢复延时
    }
}

double DS18B20_GetTemperature( )
{
	u16 TPH = 0;                           //存放温度值的高字节
	u16 TPL = 0;                           //存放温度值的低字节
	u16 TEMP= 0;							//存放温度值
	float VALUE = 0.0;						//return值
	
	EA = 0;
	DS18B20_Reset();                //设备复位
    DS18B20_WriteByte(0xCC);        //跳过ROM命令
    DS18B20_WriteByte(0x44);        //开始转换命令
    while (!DQ);                    //等待转换完成

    DS18B20_Reset();                //设备复位
    DS18B20_WriteByte(0xCC);        //跳过ROM命令
    DS18B20_WriteByte(0xBE);        //读暂存存储器命令
    TPL = DS18B20_ReadByte();       //读温度低字节
    TPH = DS18B20_ReadByte();       //读温度高字节
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