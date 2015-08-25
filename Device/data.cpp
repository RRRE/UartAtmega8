

#include "../Device/data.h"

#include "../Extra/xstring.h"
#include "../Uart/object.h"
#include "../Uart/uart.h"

// Transmit Method overloading
Data& Data::operator <<(char* pBuffer)
{
	Object::UART0.Send(pBuffer,xstrlength(pBuffer)-1);
	while(!Object::UART0.IsTxReady());
	return *this;
}

Data& Data::operator <<(unsigned int uiVal)
{
	char aIntBuff[6];
	xitoa(uiVal, aIntBuff);
	*this << aIntBuff;
	return *this;
}

// Receive Methods overloading
Data& Data::operator >>(char* pBuffer)
{
	Object::UART0.Receive(pBuffer,xstrlength(pBuffer)-1);
	while(!Object::UART0.IsRxReady());
	return *this;
}

Data& Data::operator >>(unsigned int uiVal)
{
	char aIntBuff[6];
	xitoa(uiVal, aIntBuff);
	*this >> aIntBuff;
	return *this;
}
