#include <stdio.h>
#include "main.h"

int main(void) {
	unBF ubf;
	ubf.b.a = 3;
	ubf.b.b = 7;
	ubf.b.c = 0;
	ubf.b.d = 2;

	// 10 0 111 11
	// 1001 1111 = 9F

	printf("%02X", ubf.ch); //1byte·Î Àü´Þ

	return 0;
}