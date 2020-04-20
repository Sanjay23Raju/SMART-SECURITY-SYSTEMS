	
#include<string.h>
#include"uart1.h"

unsigned char * mylocation()
{
unsigned char buff[80];
char header[6];
char time[10], speed[8], date[7];
char latitude[11], longitude[11];
char dir1, dir2,status;


unsigned char i;
char ch;
	
	do
	{
		while(rx1()!='$');
		i=0;

	   while((ch=rx1())!=',')			 //Get the Header
			header[i++]=ch;
  			header[i]=0;
			
		i=0;

		while((ch=rx1())!=',')			 //Get the Time
		time[i++]=ch;
		time[i]=0;
		
		status=rx1();
	
	while(rx1()!=',');

	i=0;

	while((ch=rx1())!=',')			 //Get Latitude
		latitude[i++]=ch;
		latitude[i]=0;

  	    dir1=rx1();		        //Get Direction	N or S
		 rx1();				//Skip Comma

   	i=0;


	 while((ch=rx1())!=',')
		longitude[i++]=ch;			//Get Longitude
		longitude[i]=0;

	    dir2=rx1();		        //Get Direction	E or W
		rx1();				//Skip Comma


   }while( strcmp(header,"GPRMC"));
   
   strcpy(buff,"Person At this Place");
		  	 strcat(buff," ,lat:");
			 strcat(buff,latitude);
		
			 strcat(buff,",Lan:");
			 strcat(buff,longitude);
			 
			 str12(buff);
             return buff;	 
}


