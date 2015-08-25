

#ifndef DATA_H_
#define DATA_H_
#include "../Uart/object.h"

class UART;

/// Data class.
class Data
{
public:
	/// Sending strings.
	Data& operator << (char*);
	/// Sending unsigned integers.
	Data& operator << (unsigned int);

	/// Receiving strings.
	Data& operator >> (char*);
	/// Receiving unsigned integers.
	Data& operator >> (unsigned int);

	/// Initiating UART.
	Data(void)
	{

	}
};
#endif /*DATA_H_*/
