#define SET(x,b) x|=(1<<b)
#define CLR(x,b) x&=~(1<<b)
#define CHK(x,b) (x&(1<<b))
#define TOG(x,b) x^=(1<<b)
void initialize(void);
void serial_tx(unsigned char);
void serial_tx_no(unsigned int);
unsigned char serial_rx(void);
unsigned int serial_rx_no(void);
void serial_tx_str(char *ptr);
void serial_rx_str(char *p);

void initialize()
{
//int x;
//x=((16000000/(16*baud))-1);
UBRRL=103;
UBRRH=0;
//UCSRC=0b10000110;
UCSRB=0b00011000;
}

void serial_tx(unsigned char data)
{

while( !CHK(UCSRA,UDRE) );
UDR=data;
}

void serial_tx_no(unsigned int data)
{

while( !CHK(UCSRA,UDRE) );
UDR=data;
}

unsigned char serial_rx(void)
{
while ( !CHK(UCSRA,RXC) );

return UDR;

}

unsigned int serial_rx_no(void)
{
while ( !CHK(UCSRA,RXC) );

return UDR;


}

void serial_tx_str(char *ptr)
{
while(*ptr!='\0')
	{
	serial_tx(*ptr);
	ptr++;
	}
}

void serial_rx_str(char *p)
{
while(1)
	{
	*p=serial_rx();
	if((*p=='\n')||(*p=='\r'))
		{
		*p='\0';
		break;
		}
	else p++;
	}
}





/*{
char x;
int a=0;
x=serial_rx();
	serial_tx('\n');
	serial_tx('u');
	serial_tx('m');
	serial_tx('i');
	serial_tx('t');
	serial_tx('\n');
while((x!='\n')||(x!='\r')||(a!=8))
	{
	
	serial_tx('\n');
	serial_tx('m');
	serial_tx('i');
	serial_tx('t');
	serial_tx('\n');
	
	*ptr=x;
	x=serial_rx();
	
	serial_tx('\n');
	serial_tx('i');
	serial_tx('t');
	serial_tx('\n');
	
	serial_tx('\n');
	serial_tx('P');
	serial_tx(*ptr);
	serial_tx('\n');	
	
	ptr++;
	a++;
	}
*ptr='\0';
}*/
