void init1()
{ 
  PINSEL0|=1<<16|1<<18;
  VPBDIV=2;
  U1LCR=0x83;
  U1DLL=0xc3;
  U1DLM=0x00;
  U1LCR=0x03;
}

void tx1(unsigned char x)
{
while((U1LSR&0x20)!=0x20);

U1THR =x;

}

void str12(unsigned char *s)
{
  while(*s)
  {
  tx1(*s++);
  }
}

unsigned char rx1()
{
 while((U1LSR&0x01)!=0x01);
 {
 return U1RBR ;
 }
} 

void rec_str01(char str[])
{
  int i=0;
   
  while(1)
  {
   str[i] = rx1();
	
   if(i>1)	                         //pos 0 & 1 contains \n,\r so neglect it
	{  
	  if( (str[i]==13) )	         //13 is the integer value of enter 
	  {
	    str[i]='\0';
	    rx1();
	    break;
	  }
	}

	  i++;
  }

}
