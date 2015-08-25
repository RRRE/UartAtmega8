unsigned char xitoa(unsigned int uiVal, char* pBuff)
{
	unsigned char ucIndex = 0;
	unsigned char ucHelper = 0;
	unsigned char ucLenght = 0;
	char cDigit;
	do
	{
		cDigit = '0' + uiVal%10;
		pBuff[ucIndex++] = cDigit;
		uiVal /= 10;
	}while(uiVal);

	ucLenght = ucIndex;
	pBuff[ucIndex--] = 0;

	while(ucHelper < ucIndex)
	{
		cDigit = pBuff[ucIndex];
		pBuff[ucIndex--] = pBuff[ucHelper];
		pBuff[ucHelper++] = cDigit;
	}
	return ucLenght;
}

unsigned int xstrlength(char* pString)
{
	unsigned int uiIndex = 0;
	while(pString[uiIndex++]!=0);
	return uiIndex;
}
