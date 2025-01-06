#include <AT89X52.h>
 
sbit M11=P2^0;
sbit M12=P2^1;

sbit M13=P2^2;
sbit M14=P2^3;

sbit M21=P2^4;
sbit M22=P2^5;

sbit M23=P2^6;
sbit M24=P2^7;

sbit D1=P1^0; 
sbit D2=P1^1;
sbit D3=P1^2;
sbit D4=P1^3;
sbit VT=P1^4;
sbit led=P0^0;


bit switch_mode=0;

void rf_process();
void rf_process2();

void frwd()
{
M11=1;
M12=0;
M13=1;
M14=0; 
}

void Bkwd()
{
M11=0;
M12=1;
M13=0;
M14=1;
}

void Right()
{
M11=0;
M12=0;
M13=1;
M14=0;
}

void Left()
{
M11=0;
M12=1;
M13=0;
M14=0;
}

void Delay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<120;j++)
        {
        }
    }
}


void main() 
{
P1=0XFF;
P2=0X00;
P3=0X00;
VT=1;
switch_mode=1;
while(1)
	{
		if(D1==1&&D2==1&&D3==0&&D4==0&&VT==1)
		{
			Delay(1000);
			if(D1==1&&D2==1&&D3==0&&D4==0&&VT==1)
			{switch_mode=~switch_mode;}	
		}
		
		
		if(switch_mode==1)
		{	
			led=0;
			rf_process();
			M21=0;
			M22=0;
			M23=0;
			M24=0;
		}
		if(switch_mode==0)
		{
			led=1;
			rf_process2();
			M11=0;
			M12=0;
			M13=0;
			M14=0;
		}	
	}
}

void rf_process()
{
if(D1==0&&D2==0&&D3==0&&D4==1&&VT==1)
		{
			frwd();
		}
	else if(D1==0&&D2==0&D3==1&&D4==0&&VT==1)
		{
			Bkwd();
		}
	else if(D1==1&&D2==0&&D3==0&&D4==0&&VT==1)
		{
			Left(); 
		}
	else if(D1==0&&D2==1&&D3==0&&D4==0&&VT==1)
		{
			Right();	
		}
	else
		{
			M11=0;
			M12=0;
			M13=0;
			M14=0;	
		}
}	

void rf_process2()
{
	{
if(D1==0&&D2==0&&D3==0&&D4==1&&VT==1)
		{
			M21=1;
			M22=0;
			M23=0;
			M24=0;
		}
	else if(D1==0&&D2==0&D3==1&&D4==0&&VT==1)
		{
			M21=0;
			M22=1;
			M23=0;
			M24=0;	
		}
	else if(D1==1&&D2==0&&D3==0&&D4==0&&VT==1)
		{
			M21=0;
			M22=0;
			M23=1;
			M24=0; 	
		}
	else if(D1==0&&D2==1&&D3==0&&D4==0&&VT==1)
		{
			M21=0;
			M22=0;
			M23=0;
			M24=1;	
		}
	else
		{
			M21=0;
			M22=0;
			M23=0;
			M24=0;	
		}
}	
}
