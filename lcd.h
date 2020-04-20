//#include<lpc214x.h>

#define en 1<<16
#define rs 1<<15




void delaylcd(int y)
{
int i,j;
for(i=0;i<y;i++)
for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char x)
{
IOCLR0=rs;
IOSET0 = ((x&0xf0)>>4)<<17;
IOSET0=en;
delaylcd(300);
IOCLR0=en;
IOCLR0 =0x0f<<17;

IOSET0 = (x&0x0f)<<17;
IOSET0=en;
delaylcd(300);
IOCLR0=en;
IOCLR0 =0x0f<<17;

}

void lcd_data(unsigned char x)
{
IOSET0=rs;
IOSET0 = ((x&0xf0)>>4)<<17;
IOSET0=en;
delaylcd(300);
IOCLR0=en;
IOCLR0 =0x0f<<17;

IOSET0 = (x&0x0f)<<17;
IOSET0=en;
delaylcd(300);
IOCLR0=en;
IOCLR0 =0x0f<<17;

}



void lcd_init()
{
 
 lcd_cmd(0x28);	 //initializing the commands 
 lcd_cmd(0x06);
 lcd_cmd(0x0e);
 lcd_cmd(0x01);
}



void lcd_str(unsigned char *s)
{
while(*s)									 //for printing the string in lcd
{
lcd_data(*s++);
}
}
