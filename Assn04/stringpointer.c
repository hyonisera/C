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
		if (p[3] == '0') printf("LED 0���Դϴ�. ");
		else if (p[3] == '1') printf("LED 1���Դϴ�. ");

		if (*(p + 4) == '0') printf("LED OFF�Դϴ�. ");
		else if (*(p + 4) == '1') printf("LED ON�Դϴ�. ");
	}

	printf("\n");
	if ((p = strstr(string, "KEY")) != 0) {
		strcpy_s(temp, 20, p + 3); //��� buffer�� �ִ밪
		temp[2] = '\0';
		printf("KEY�� ���� %s�Դϴ�. ", temp);
	}

	printf("\n");
	if ((p = strstr(string, "FND")) != 0) {
		strcpy_s(temp, 20, p + 3);
		temp[4] = '\0';
		printf("FND�� ��°��� %s�Դϴ�. ", temp);
	}

	printf("\n");
	if ((p = strstr(string, "BUZ")) != 0) {
		if (p[3] == '0') printf("BUZ OFF�Դϴ�. ");
		else if (p[3] == '1') printf("BUZ ON�Դϴ�. ");
	}

	return 0;
}