#include<string.h>
#include "uart0.h"
 #include "gps.h"
char str[120]={0};
char mes[50]={0};
char no[20]={0};

//char gsmcom[100]={0};
char c[1]="\\";
char *g;
unsigned int ph;
 void delaygsm(int x)
 {
 int i,j;
 for(i=0;i<x;i++)
 for(j=0;j<1275;j++);
 }



//////////////////GSMtx//////////////////
void gsmtx1(unsigned char *m)
{
delay(20000);
	string0("AT");
	 tx0('\r');
	tx0('\n');
	delay(50);
	string0("AT+CMGF=1");
	tx0('\r');
	tx0('\n');
		string0("AT+CMGS=\"8147066675\"");
			 
	
	 
	delay(100);
	tx0('\r');
	tx0('\n');
  string0(m);///////ur msg
	delay(5000);
	tx0('\r');
	tx0('\n');
	tx0(0x1a);
	string0("sent");
	delay(50000);
}




void gsmrx()
{

 
  	delay(20000);
 		string0("\n\r ATE0\n\r");  				//to make echo mode off
 	delay(5000);
 		string0("AT\n\r");
  	rec_str00(str);  					//to rec the responce of gsm(OK)
  	delay(5);	
    	string0("AT+CMGF=1\n\r");							   //to enter the message mode
 	rec_str00(str);
    delay(500);
	string0("AT+CMGDA=\"DEL ALL\"\n\r");				  //to delete the old messages
   rec_str00(str);									  //it rec the OK
   delay(500);


   	while(1)
	{
	    int i;
     	rec_str00(str);
     	if(!strncmp(str+2,"+CMTI",5))					//it compare the string with +CMTI
	  	{
		 
		 	string0("AT+CMGL=\"REC UNREAD\"\n\r");
   		 	rec_str00(str);

         	rec_str00(mes);  							//it contains message 
		 	rec_str00(str);  							//it contains OK 
 			   						 
//         	 string0(gsmcom);
			if((!strncmp(mes,"y",1)) |(!strncmp(mes,"Y",1)))
			{
			   	IOSET1=(1<<17);	 //led glows
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str("ACCESS GRANTED");
				delaylcd(1000);
				break;
				
	 		}
	  		if((!strncmp(mes,"n",1)) |(!strncmp(mes,"N",1)))
			{
			   	lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str("ACCESS DENIED");
				delaylcd(1000);
				break;
	 		}
		
			 if((!strncmp(mes,"l",1)) |(!strncmp(mes,"L",1)))
			{
			   	lcd_cmd(0x01);
				lcd_cmd(0x80);
				lcd_str("SENDING LOCATION");
				delaylcd(1000);
				g=mylocation();
				gsmtx1(g);
				break;
	 		}
			
	
//		 break;
			}

//	  break;

}


}