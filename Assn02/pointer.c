#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int* x) {
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 20; i++) {
		*(x + i) = rand() % 100 + 1;
	}

	for (i = 0; i < 20; i++) {
		printf("%d ", *(x + i));
	}
}

void sorting(int* y) {
	int i, j, least, temp;

	for (i = 0; i < 19; i++) {
		least = i;
		for (j = i + 1; j < 20; j++) {
			if (*(y + j) < *(y + least)) {
				least = j;
			}
		}
		temp = *(y + i);
		*(y + i) = *(y + least);
		*(y + least) = temp;
	}
	for (i = 0; i < 20; i++) {
		printf("%d ", *(y + i));
	}
}

int main(void) {
	int a[20];
	
	random(&a);
	printf("\n");
	sorting(&a);

	return 0;
}