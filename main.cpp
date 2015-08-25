

#include <avr/io.h>
#include <avr/interrupt.h>

#include "main.h"
#include "Device/device.h"
#include "Uart/object.h"

using namespace Object;
using namespace Device;

class UART UART1;

int main(void)
{
	sei();
	unsigned int uartTest = 7263;
	data<<"I am a test \n"<<"uartTest = "<<uartTest<<"\n";
	while(1);
}
