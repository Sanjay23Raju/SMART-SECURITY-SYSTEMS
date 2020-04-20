 unsigned char ch[8];
void delay(int a)
{
         int i,J;
		 for(i=0;i<a;i++)
		 {
			for(J=0;J<1275;J++);
		 }

}



void tx0(unsigned char x)
{
	while((U0LSR&0x20)!=0x20);
	
	U0THR=x;

}

unsigned char rx0()
{
	while((U0LSR&0x01)!=0x01);
	
	{

	return U0RBR;
  
	}

}
void string0(unsigned char *p )
  {
   while(*p)
   {
    tx0(*p++);
 
   }
  }

 void rec_str00(char str[])
{
  int i=0;
   
  while(1)
  {
   str[i] = rx0();
	
   if(i>1)	                         //pos 0 & 1 contains \n,\r so neglect it
	{  
	  if( (str[i]==13) )	         //13 is the integer value of enter 
	  {
	    str[i]='\0';
	    rx0();
	    break;
	  }
	}

	  i++;
  }

}

void init0()
{
VPBDIV=2;
PINSEL0|=1<<0;
PINSEL0|=1<<2;
U0LCR=0X83;
		
U0DLL=0xc3;
U0DLM=0X00;	
U0LCR=0X03;
}
//
void gsmtx2(unsigned char *m)
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

//
//   void gsmtx3(unsigned char *m)
//{
//delay(20000);
//	string0("AT");
//	 tx0('\r');
//	tx0('\n');
//	delay(50);
//	string0("AT+CMGF=1");
//	tx0('\r');
//	tx0('\n');
//	string0("AT+CMGS=\"8296471994\"");
//	delay(100);
//	tx0('\r');
//	tx0('\n');
//  string0(m);///////ur msg
//	delay(5000);
//	tx0('\r');
//	tx0('\n');
//	tx0(0x1a);
//	string0("sent");
//	delay(50000);
//}
//void gsmtx4(unsigned char *m)
//{
//delay(20000);
//	string0("AT");
//	 tx0('\r');
//	tx0('\n');
//	delay(50);
//	string0("AT+CMGF=1");
//	tx0('\r');
//	tx0('\n');
//	string0("AT+CMGS=\"7795429894\"");
//	delay(100);
//	tx0('\r');
//	tx0('\n');
//  string0(m);///////ur msg
//	delay(5000);
//	tx0('\r');
//	tx0('\n');
//	tx0(0x1a);
//	string0("sent");
//	delay(50000);
//}
void recieve()
{

int i=0;
string0("hi");
for(i=0;i<8;i++)
{
ch[i]=rx0();
}
}


