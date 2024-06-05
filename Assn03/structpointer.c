#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
    int width;
    int height;
    int area;
    int peri;
};

void calculate(struct rect*);
void maxIndex(struct rect*);
void sorting(struct rect*);

int main(void) {
    struct rect stRect[20];

    calculate(&stRect);
    maxIndex(&stRect);
    sorting(&stRect);

    return 0;
}

void calculate(struct rect* r) {
    srand((unsigned)time(NULL));

    for (int i = 0; i < 20; i++) {
        (r + i) -> p1.x = rand() % 91 + 10;
        (r + i) -> p1.y = rand() % 91 + 10;

        do {
            (r + i) -> p2.x = rand() % 91 + 10;
        } while ((r + i) -> p2.x <= (r + i) -> p1.x);

        do {
            (r + i) -> p2.y = rand() % 91 + 10;
        } while ((r + i) -> p2.y <= (r + i) -> p1.y);
    }

    for (int i = 0; i < 20; i++) {
        (r + i) -> width = (r + i) -> p2.x - (r + i) -> p1.x;
        (r + i) -> height = (r + i) -> p2.y - (r + i) -> p1.y;
        (r + i) -> area = (r + i) -> width * (r + i) -> height;
        (r + i) -> peri = ((r + i) -> width + (r + i) -> height) * 2;
    }

    for (int i = 0; i < 20; i++) {
        printf("인덱스 %d: ", i);
        printf("(%d, %d), (%d, %d)\n", (r + i) -> p1.x, (r + i) -> p1.y, (r + i) -> p2.x, (r + i) -> p2.y);
        printf("폭: %d, 높이: %d, 넓이: %d, 둘레: %d\n\n", (r + i) -> width, (r + i) -> height, (r + i) -> area, (r + i) -> peri);
    }
}

void maxIndex(struct rect* r2) {
    int maxWidth = 0, maxHeight = 0, maxArea = 0, maxPeri = 0;

    for (int i = 1; i < 20; i++) {
        if ((r2 + i) -> width > (r2 + maxWidth) -> width) maxWidth = i;
        if ((r2 + i) -> height > (r2 + maxHeight) -> height) maxHeight = i;
        if ((r2 + i) -> area > (r2 + maxArea) -> area) maxArea = i;
        if ((r2 + i) -> peri > (r2 + maxPeri) -> peri) maxPeri = i;
    }
    printf("\n폭이 가장 큰 사각형의 인덱스: %d", maxWidth);
    printf("\n높이가 가장 큰 사각형의 인덱스: %d", maxHeight);
    printf("\n넓이가 가장 큰 사각형의 인덱스: %d", maxArea);
    printf("\n둘레가 가장 큰 사각형의 인덱스: %d", maxPeri);
}

void sorting(struct rect* r3) {
    int temp = 0, least = 0;
    int index[20];

    for (int i = 0; i < 20; i++) {
        index[i] = i;
    }

    for (int i = 0; i < 19; i++) {
        least = i;
        for (int j = i + 1; j < 20; j++) {
            if ((r3 + index[j]) -> area < (r3 + index[least]) -> area) {
                least = j;
            }
        }
        temp = index[i];
        index[i] = index[least];
        index[least] = temp;
    }

    printf("\n\n넓이가 큰 순서대로 정렬(인덱스): ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", index[i]);
    }
}