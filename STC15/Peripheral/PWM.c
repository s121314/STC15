#include "PWM.h"

void PWM2_SetPwmWide(unsigned short Wide)
{
    if (Wide == 0)
    {
        PWMCR &= ~0x01;
        PWM2 = 0;
    }
    else if (Wide == CYCLE)
    {
        PWMCR &= ~0x01;
        PWM2 = 1;
    }
    else
    {
        P_SW2 |= 0x80;
        PWM2T1 = Wide;
        P_SW2 &= ~0x80;
        PWMCR |= 0x01;
    }
}

void PWM3_SetPwmWide(unsigned short Wide)
{
    if (Wide == 0)
    {
        PWMCR &= ~0x02;
        PWM3 = 0;
    }
    else if (Wide == CYCLE)
    {
        PWMCR &= ~0x02;
        PWM3 = 1;
    }
    else
    {
        P_SW2 |= 0x80;
        PWM3T1 = Wide;
        P_SW2 &= ~0x80;
        PWMCR |= 0x02;
    }
}

void PWM4_SetPwmWide(unsigned short Wide)
{
    if (Wide == 0)
    {
        PWMCR &= ~0x04;
        PWM4 = 0;
    }
    else if (Wide == CYCLE)
    {
        PWMCR &= ~0x04;
        PWM4 = 1;
    }
    else
    {
        P_SW2 |= 0x80;
        PWM4T1 = Wide;
        P_SW2 &= ~0x80;
        PWMCR |= 0x04;
    }
}

void PWM5_SetPwmWide(unsigned short Wide)
{
    if (Wide == 0)
    {
        PWMCR &= ~0x08;
        PWM5 = 0;
    }
    else if (Wide == CYCLE)
    {
        PWMCR &= ~0x08;
        PWM5 = 1;
    }
    else
    {
        P_SW2 |= 0x80;
        PWM5T1 = Wide;
        P_SW2 &= ~0x80;
        PWMCR |= 0x08;
    }
}