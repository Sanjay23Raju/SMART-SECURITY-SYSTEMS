#include <lpc214x.h>
#include "lcd.h"

#include "gsm.h"
main()
{
char *ch;
IODIR0|=0x0f<<17;
IODIR0|=0x03<<15;
//IODIR0|=1<<25;
IODIR1|=0x03<<16;
lcd_init();
init1();
init0();
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Smart Security");
lcd_cmd(0xc0);
lcd_str("for 2 wheelers");
//delaylcd(1000);


 while(1)
 {
if(IOPIN1 & 1<<18)
{
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("REQUESTING.....");
delaylcd(1000);
IOSET1=1<<16;
delaylcd(20000);
IOCLR1=1<<16;
gsmtx1("Request for starting the vehicle. Reply Y for allowing access,N for denying access");
gsmrx();
}

if(!(IOPIN0 & 1<<25))
{
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Security");
lcd_cmd(0xc0);
lcd_str("breached");
delaylcd(1000);
gsmtx1("Security Breached, Reply L to know thw location");
gsmrx();

}
}
}
//}