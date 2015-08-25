

#ifndef _UART_H_
#define _UART_H_
#include <avr/interrupt.h>

extern "C" void USART_TXC_vect(void) __attribute__ ((signal));
extern "C" void USART_RXC_vect(void) __attribute__ ((signal));


/* Define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/* 9600 baud */
#define UART_BAUD_RATE      9600


#define UART_BAUD_SELECT(baudRate,xtalFpu)  (((xtalFpu) + 8UL * (baudRate)) / (16UL * (baudRate)) -1UL)


/// UART class.
class UART
{
private:
	/// Data to send.
	char* pTxBuffer;
	/// Buffer for received data.
	char* pRxBuffer;
	/// Transmitter data counter and data size. When equals - transmiter is ready to send new data.
	volatile unsigned int TxCounter;
	volatile unsigned int TxSize;
	/// Receiver data counter and data size. When equals - transmiter is ready to send new data.
	volatile unsigned int RxCounter;
	volatile unsigned int RxSize;
	/// Static pointer used in interrupts routines.
	static UART* ptrUart;
public:
	/// Setting up UART registers.
	void Init(unsigned int baudrate);
	/// Sending data.
	bool Send(char* pBuffer, unsigned int uiSize);
	/// Receiving data.
	bool Receive(char* pBuffer, unsigned int uiSize);

//	char sendData(char* pBuffer);

	/// Checks if transmitter is ready to send new data.
	bool IsTxReady(void)
	{
		return !TxSize;
	}
	/// Checks if receiver is ready to send new data.
	bool IsRxReady(void)
	{
		return !RxSize;
	}
	/// Setting static ptrUart pointer.
	UART()
	{
		ptrUart = this;

		Init(UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU));
		//*pTxBuffer = 0;
		//*pRxBuffer = 0;

	}

	~UART(){};
	/// Interrupt routines.
	friend void USART_TXC_vect(void);
	friend void USART_RXC_vect(void);
};

#endif

