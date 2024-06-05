#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	char string[100] = "LED10KEY12FND1234BUZ1";
	char* p;
	char temp[20];

	//p = strstr(string, "LED");
	//printf(p);
	//p1 = strchr(p, 'D'); //p1[1], *(p + 2)

	if ((p = strstr(string, "LED")) != 0) {
		if (p[3] == '0') printf("LED 0번입니다. ");
		else if (p[3] == '1') printf("LED 1번입니다. ");

		if (*(p + 4) == '0') printf("LED OFF입니다. ");
		else if (*(p + 4) == '1') printf("LED ON입니다. ");
	}

	printf("\n");
	if ((p = strstr(string, "KEY")) != 0) {
		strcpy_s(temp, 20, p + 3); //가운데 buffer의 최대값
		temp[2] = '\0';
		printf("KEY의 값은 %s입니다. ", temp);
	}

	printf("\n");
	if ((p = strstr(string, "FND")) != 0) {
		strcpy_s(temp, 20, p + 3);
		temp[4] = '\0';
		printf("FND의 출력값은 %s입니다. ", temp);
	}

	printf("\n");
	if ((p = strstr(string, "BUZ")) != 0) {
		if (p[3] == '0') printf("BUZ OFF입니다. ");
		else if (p[3] == '1') printf("BUZ ON입니다. ");
	}

	return 0;
}