

#include "../Uart/uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../Extra/xstring.h"

UART* UART::ptrUart = 0;


/*************************************************************************
Method:   uart::Init()
Purpose:  initialize UART and set baud rate
Input:    baud rate using macro UART_BAUD_SELECT()

**************************************************************************/
void UART::Init(unsigned int baudrate)
{
  /* Set baud rate */
  if ( baudrate & 0x8000 )
  {
  	 UCSRA = (1<<U2X);  //Enable 2x speed
   	 baudrate &= ~0x8000;
  }
  UBRRH = (unsigned char)(baudrate>>8);
  UBRRL = (unsigned char) baudrate;

  /* Enable USART receiver and transmitter and receive complete interrupt */
  UCSRB = _BV(RXCIE)|(1<<RXEN)|(1<<TXEN);

  /* Set frame format: asynchronous, 8data, no parity, 1stop bit */
  #ifdef URSEL
  	  UCSRC = (1<<URSEL)|(3<<UCSZ0);
  #else
	  UCSRC = (3<<UCSZ0);
  #endif


  TxCounter = 0;
  TxSize = 0;
  RxCounter = 0;
  RxSize = 0;
}

/*************************************************************************
Method :  UART Transmit flag set
Purpose:  when byte is transmit properly the flag is set true
**************************************************************************/

bool UART::Send(char *pBuffer, unsigned int uiSize)
{
	if(!uiSize || !pBuffer || TxSize) return false;
	TxSize = uiSize;
	pTxBuffer = pBuffer;
	TxCounter = 1;
	UCSRB = (1<<TXEN) | (1<<TXCIE);
	UDR = pBuffer[0];
	return true;
}

/*************************************************************************
Method :  UART Receive flag set
Purpose:  when byte is received properly the flag is set true
**************************************************************************/

bool UART::Receive(char *pBuffer, unsigned int uiSize)
{
	if(!uiSize || !pBuffer || RxSize) return false;
	RxSize = uiSize;
	pRxBuffer = pBuffer;
	RxCounter = 0;
	UCSRB = (1<<RXEN) | (1<<RXCIE);
	return true;
}

/*************************************************************************
Method :  UART Receive Complete interrupt
Purpose:  called when the UART has received a character
**************************************************************************/

void USART_RXC_vect(void)
{
	UART::ptrUart->pRxBuffer[UART::ptrUart->RxCounter++] = UDR;
	if(UART::ptrUart->RxCounter == UART::ptrUart->RxSize)
	{
		UART::ptrUart->RxSize = 0;
		UCSRB &= ~((1<<RXEN) | (1<<RXCIE));
	}
}

/*************************************************************************
Method :  UART Transmit Complete interrupt
Purpose:  called when the UART has transmit a character
**************************************************************************/
void USART_TXC_vect(void)
{
	if(UART::ptrUart->TxCounter == UART::ptrUart->TxSize)
	{
		UART::ptrUart->TxSize = 0;
		UCSRB &= ~((1<<TXEN) | (1<<TXCIE));
	}
	else
		UDR = UART::ptrUart->pTxBuffer[UART::ptrUart->TxCounter++];
}



//char UART::sendData(char* pBuffer)
//{
//	UART::Send(pBuffer,xstrlength(pBuffer)-1);
//	while(!UART::IsTxReady());
//	return *this;
//}
