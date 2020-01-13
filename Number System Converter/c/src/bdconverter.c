#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bdconverter.h"

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
//			printf("size=%d temp[%d]=%c\n", size, i, temp[i]); 
//			printf("binary[%d]=%c\n", i+start, binary[i+capacity - size]); 
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

/*
void ShowD2B(char *number) {
	int capacity = 4, size = 0;
	int length = capacity;
	char *binary = (char*)malloc(sizeof(char) * (capacity+1));
	memset(binary, '0', capacity+1);

	int decimal = 0;
	sscanf(number, "%d", &decimal);
	binary[length--] = '\0';

	while (decimal > 0) {
		int space = capacity/4-1;
		if ((size+1)%5 == 0) {
			binary[length--] = ',';
		}
		binary[length--] = decimal % 2 + '0';
		decimal /= 2;
		size++;
//printf("binary[%d]=%c\n", length+1, binary[length+1]);
		if (size >= capacity) {
			capacity *= 2;
			char *temp = (char*)malloc(sizeof(char) * (capacity+1 + space));
			int start = size + space;

			for (int i = 0; i < capacity + space; i++) {
				if (i >= start) {
					temp[i] = binary[i-start];
				} else {
					temp[i] = '0';
				}
			}

			free(binary);
			binary = temp;
			length = size-1;
			printf("temp: %s\n", temp);
		}
//		printf("size=%d decimal=%d %s\n", size, decimal, binary);
	}

	printf("DEC %s = %s\n", number, binary);
	free(binary);
}
*/
void ShowB2D(char *binary) {
}

