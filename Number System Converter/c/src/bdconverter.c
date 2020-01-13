#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bdconverter.h"

char *B2D(char *binary, char *decimal) {
	int size = 0;
	int number = 0;

	for (int i = 0; i < strlen(binary); i++) {
		number += (binary[strlen(binary) - i - 1] - '0') * pow(2, i);
	}

	int temp = number;
	while (temp > 0) {
		temp /= 10;
		size++;
	}

	decimal = (char*)malloc(sizeof(char) * (size + 1));
	memset(decimal, 0, size+1);

	sprintf(decimal, "%d", number);
	return decimal;
}

void ShowB2D(char *binary) {
	int length = 4;
	char *decimal;

	printf("BIN %s = %s\n", binary, B2D(binary, decimal));
	free(decimal);
	ShowD2B(binary);
}


char *D2B(char *number, char *binary, int length) {
	int capacity = length;
	int size = 0;
	int start = 0;
	int decimal = 0;
	sscanf(number, "%d", &decimal);
	binary = (char*)malloc(sizeof(char) * (capacity+1));
	memset(binary, '0', capacity+1);
	binary[length--] = '\0';

	while (decimal > 0) {
		binary[length--] = decimal % 2 + '0';
		decimal /= 2;
		size++;

		if (size >= capacity) {
			capacity *= 2;
			char *temp = (char*)malloc(sizeof(char) * (capacity+1));
			memset(temp, ' ', capacity+1);
			start = size;

			for (int i = capacity; i >= 0; i--) {
				if (i >= start) {
					temp[i] = binary[i-start];
				} else {
					for (int j = start-1; j > start - start%4; j--) {
						temp[j] = '0';
					}
					break;
				}
			}

			free(binary);
			binary = temp;
			length = size-1;
		}
	}

	if (binary[0] == ' ') {
		char *temp = (char *)malloc(sizeof(char) * (size + 1));
		memset(temp, 0, size+1);

		for (int i = 0; i < size; i++) {
			temp[i] = binary[i+capacity - size];
		}

		free(binary);
		binary = temp;
	}

	return binary;
}

void ShowD2B(char *number) {
	int length = 4;
	char *binary;

	printf("DEC %s = %s\n", number, D2B(number, binary, length));
	free(binary);
}

