#include <stdio.h>
#include <string.h>
#include "bdconverter.h"

int main()
{
	char number[80] = {0};
	scanf("%s", number);
	enum IsDecimal {False, True};
	enum IsDecimal decimal = False;

	for (int i = 0; i < strlen(number); i++) {
		if ((number[i] - 48) > 1) {
			decimal = True;
			break;
		}
	}

	decimal ? ShowD2B(number) : ShowB2D(number);
	return 0;
}