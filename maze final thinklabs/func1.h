void turn(char dir);
void linefollower(void);
void update(void);
char decide(void);
void inch (void) ;
void inchb(void) ;
void linefollower1(void);


unsigned int currx=0,curry=0,ori=1,f1=0,f2=0,blkiden=0;



void turn (char dir)        //  used for taking turns at intersections

{
    switch (dir)
	{
	
	 case 'L':
	   PORTD &=~(1<<4);
       PORTD |=(1<<5);    // left turn 
       PORTD |=(1<<6);
       PORTD &=~(1<<7); 
       _delay_ms(350);
	   
       while(!(PINA&(1<<3))) ;
          PORTD |=(1<<4);
          PORTD |=(1<<5);    // stop as the 3th sensor senses the line 
          PORTD |=(1<<6);
          PORTD |=(1<<7);
	   
	   if(ori==2)
	   ori=1;
	   else if(ori==3)
	   ori=2;
	   else if(ori==1)
	   ori=4;
	   else if(ori==4)
	   ori=3;
	   break;
		 
		 
     case 'R' : 
	   
	   PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD &=~(1<<6);   // right turn
       PORTD |=(1<<7);   
       _delay_ms(350);
	   
	   while(!(PINA&(1<<3))) ;
          PORTD |=(1<<4);
          PORTD |=(1<<5);    // stop as the 3nd sensor senses the line 
          PORTD |=(1<<6);
          PORTD |=(1<<7);
       
	   if(ori==1)
	   ori=2;
	   else if(ori==2)
	   ori=3;  
	   else if(ori==3)
	   ori=4;
	   else if(ori==4)
	   ori=1;
       break;

 	 
	 case 'U' :
	   
	   
	   PORTD |= (1<<4);
       PORTD &=~ (1<<5);
       PORTD &=~ (1<<6);    // U -turn
       PORTD |= (1<<7);
	   
	   _delay_ms(300);
	   
	   while(!(PINA&(1<<3)));
	   while((PINA&(1<<3)));
	   while(!(PINA&(1<<3)));
          PORTD |=(1<<4);
          PORTD |=(1<<5);    // stop as the 5th sensor senses the line 
          PORTD |=(1<<6);
          PORTD |=(1<<7);
       
        if(ori==1)
		ori=3;
		else if(ori==2)
	    ori=4;  
	    else if(ori==3)
	    ori=1;
	    else if(ori==4)
	    ori=2;
		
		
		break;

	 
     case 'S':
	  
	    break ;                 // go straight i.e follow the line ,no turn
		
		
	 case 'N':
	    
		  PORTD |=(1<<4);
          PORTD |=(1<<5);    
          PORTD |=(1<<6);
          PORTD |=(1<<7);
	 
		
		
	}
}	



void linefollower ()
{
   while(1)
   {
      if((PINA & (1<<2))&&(PINA & (1<<3))&&(PINA & (1<<4))) //111== forward
   { 
      
       
       PORTD |=(1<<5);
	   PORTD |=(1<<7);
	   _delay_us(25);      
       PORTD |= (1<<4);
       PORTD &=~(1<<5);
       PORTD |= (1<<6);
       PORTD &=~(1<<7);
	   _delay_us(75);
	   
       
   }
   
   else if ((PINA & (1<<2))&&(PINA & (1<<3)) && !(PINA & (1<<4))) // 110 - slight left
   {
	   PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(15);
	   PORTD &=~(1<<5);
	   _delay_us(85);
	   _delay_us(75);
	   
	 
	 
   }
   
   else if (!(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))) // 011 - slight right
   {
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   _delay_us(15);
	   PORTD &=~(1<<7);
	   _delay_us(85);
	   _delay_us(75);
	   
	 
   }
   
   else if(!(PINA & (1<<2))&&!(PINA & (1<<3)) && (PINA & (1<<4)))// 001  = right  
   { 
     
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25); 
       PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD &=~(1<<7);
	   _delay_us(75);
	   _delay_us(75);
	      
   }
    
  
      
   else if((PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4)))// 100 - left
   { 
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25); 
       PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(25);
	   PORTD &=~(1<<5);
	   _delay_us(75);
	   _delay_us(75);
	   
   }
   
    else if((PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5)))// 10000 - left
   { 
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25); 
       PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(25);
	   PORTD &=~(1<<5);
	   _delay_us(75);
	   _delay_us(75);
	   
   }
   
    else if(!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&& (PINA & (1<<5)))// 00001  = right  
   { 
     
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25); 
       PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD &=~(1<<7);
	   _delay_us(75);
	   _delay_us(75);
	      
   }
   
   
    if(!(PINA & (1<<1))||!(PINA & (1<<5)))
	f2=0;
	
	if ((PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&(PINA & (1<<5))) // 11111 - + junction
	return;
   
   else if ((blkiden=2 )&& (f1==0) )// black and white block found  
    {
		f1=1;
	  return;
    }
	
	
	else if ((blkiden=1) && (f1==0)) // white block found
	{ f1=1;
	  return;
    }
	
/*	else if (!(PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&!(PINA & (1<<5))) // 01110 - node
	{
		nodeflag=1;
		return;	
	}
	
	else if ((PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5))) // 10000 - right bridge
	{	
		bridgetime=time;          //taking current timer value
		if(bridgetime < 31.25)
		{
			bridgeflag=1; // backward bridge
		}
		else
		{
			bridgeflag=2; // forward bridge
		}
		return;
	}
	
	else if (!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&&(PINA & (1<<5))) // 00001 - left bridge
	{	
		bridgetime=time;          //taking current timer value
		if(bridgetime < 31.25)
		{
			bridgeflag=3; // backward bridge
		}
		else
		{
			bridgeflag=4; // forward bridge
		}
		return;
	}
	*/
	else if (!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3))&&!(PINA & (1<<4))&&!(PINA & (1<<5)))// 00000- dead end 
    //turn('U'); 
	//inchb();
	
   }
}


void update()
{
 if(f2==0)
 { 
   if(ori==1)
   currx++;
   else if(ori==2)
   curry++;
   else if(ori==3)
   currx--;
   else if(ori==4)
   curry--;
   
   f2=1;
   PORTD^=(1<<1);
 }
}

char decide()
{  
   if(currx==0 && curry == 7)
   return 'N'; 
   else if(currx==0)
   return 'L';
   else if(currx==7)
   return 'R';  
   else if(currx<7&&currx>0)
   return 'S';
   else
   return 'S';
}

void inch() 
   {    
	   PORTD |= (1<<4);
       PORTD &=~(1<<5);
       PORTD |= (1<<6);   // going  inch forward
       PORTD &=~(1<<7);
	   _delay_ms(300);
	   PORTD |= (1<<4);
       PORTD |=(1<<5);
       PORTD |= (1<<6);  
       PORTD |=(1<<7);
    }


void inchb() 
   {    
	   PORTD &=~ (1<<4);
       PORTD |=(1<<5);
       PORTD &=~ (1<<6);   // going  inch backward 
       PORTD |=(1<<7);
	   _delay_ms(300);
	   PORTD |= (1<<4);
       PORTD |=(1<<5);
       PORTD |= (1<<6);  
       PORTD |=(1<<7);
    }



void linefollower1()
{
   
   while(1)
   {
     
	 
    if ((PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&(PINA & (1<<5))) // 11111 - + junction
	{  turn('N');
	  _delay_ms(1000); 
	  PORTC|=(1<<3);
	  return;
	}
	
	
   
      if(!(PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3))&&(PINA & (1<<4))&&!(PINA & (1<<5))) //01110== forward
   { 
      
       
             
       PORTD |= (1<<4);
       PORTD &=~(1<<5);
       PORTD |= (1<<6);
       PORTD &=~(1<<7);
       
   }
   
   else if (!(PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5))) // 011000 - slight left
   {
         PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(15);
	   PORTD &=~(1<<5);
	   _delay_us(85);
	   _delay_us(75);
	 
	 
   }
   
    else if ((PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5))) // 11100 - slight left
   {
        PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(15);
	   PORTD &=~(1<<5);
	   _delay_us(85);
	   _delay_us(75);
	 
	 
   }
   
   else if (!(PINA & (1<<1))&&!(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&!(PINA & (1<<5))) //00110 - slight right
   {
	   PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   _delay_us(15);
	   PORTD &=~(1<<7);
	   _delay_us(85);
	   _delay_us(75);
	 
   }
   
   else if (!(PINA & (1<<1))&&!(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&(PINA & (1<<5))) //00111 - slight right
   {
        PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25);
	   PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   _delay_us(15);
	   PORTD &=~(1<<7);
	   _delay_us(85);
	   _delay_us(75);    
	 
   }
   
   else if(!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && (PINA & (1<<4))&&(PINA & (1<<5)))// 00011  = right  
   { 
     
       PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	  
   }
    
  
      
   else if((PINA & (1<<1))&&(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5)))// 11000 - left
   { 
   
       PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	 
   }
   
    else if((PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&&!(PINA & (1<<5)))// 10000 - left
   { 
       PORTD |=(1<<4);
	   PORTD |=(1<<5);
	   PORTD |=(1<<6);
	   PORTD |=(1<<7);
	   _delay_us(25); 
       PORTD |=(1<<6);
       PORTD &=~(1<<7);
       PORTD |=(1<<4);
       PORTD |=(1<<5);
	   _delay_us(25);
	   PORTD &=~(1<<5);
	   _delay_us(75);
	   _delay_us(75);

	  
	   
   }
   
    else if(!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3)) && !(PINA & (1<<4))&& (PINA & (1<<5)))// 00001  = right  
   { 
     
      
       PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD |=(1<<6);
       PORTD |=(1<<7);
	   
	      
   }
   
   
  
	
	else if (!(PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&(PINA & (1<<5))) // 01111  - right    
	{  inch();
	
	   PORTD |=(1<<4);
       PORTD &=~(1<<5);
       PORTD &=~(1<<6);
       PORTD |=(1<<7);
	     lcd_char('R');
          while(PINA&(1<<2)) ;
          PORTD |=(1<<4);
          PORTD |=(1<<5);    // stop as the 2th sensor senses the line 
          PORTD |=(1<<6);
          PORTD |=(1<<7);
	   
	}
	else if ((PINA & (1<<1))&&(PINA & (1<<2))&&(PINA & (1<<3)) && (PINA & (1<<4))&&!(PINA & (1<<5))) // 11110 - left  
	{
	   PORTD &=~(1<<4);
       PORTD |=(1<<5);
       PORTD |=(1<<6);
       PORTD &=~(1<<7);
	   
	   lcd_char('L');
       while(PINA&(1<<4)) ;
          PORTD |=(1<<4);
          PORTD |=(1<<5);    // stop as the 4th sensor senses the line 
          PORTD |=(1<<6);
          PORTD |=(1<<7);
	}
	
    else if (!(PINA & (1<<1))&&!(PINA & (1<<2))&&!(PINA & (1<<3))&&!(PINA & (1<<4))&&!(PINA & (1<<5)))// 00000- dead end 
    { inchb();
	 
	}
}
}

