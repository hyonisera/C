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

int main(void) {
    struct rect stRect[20];
    int i, j, temp, least;
    int index[20];

    srand((unsigned)time(NULL));

    for (i = 0; i < 20; i++) {
        stRect[i].p1.x = rand() % 91 + 10;
        stRect[i].p1.y = rand() % 91 + 10;

        do {
            stRect[i].p2.x = rand() % 91 + 10;
        } while (stRect[i].p2.x <= stRect[i].p1.x);

        do {
            stRect[i].p2.y = rand() % 91 + 10;
        } while (stRect[i].p2.y <= stRect[i].p1.y);
    }

    for (i = 0; i < 20; i++) {
        stRect[i].width = stRect[i].p2.x - stRect[i].p1.x;
        stRect[i].height = stRect[i].p2.y - stRect[i].p1.y;
        stRect[i].area = stRect[i].width * stRect[i].height;
        stRect[i].peri = (stRect[i].width + stRect[i].height) * 2;

        index[i] = i;
    }

    for (i = 0; i < 20; i++) {
        printf("�ε��� %d: ", index[i]);
        printf("(%d, %d), (%d, %d)\n", stRect[i].p1.x, stRect[i].p1.y, stRect[i].p2.x, stRect[i].p2.y);
        printf("��: %d, ����: %d, ����: %d, �ѷ�: %d\n\n", stRect[i].width, stRect[i].height, stRect[i].area, stRect[i].peri);
    }

    int maxWidth = 0, maxHeight = 0, maxArea = 0, maxPeri = 0;
    for (i = 1; i < 20; i++) {
        if (stRect[i].width > stRect[maxWidth].width) maxWidth = i;
        if (stRect[i].height > stRect[maxHeight].height) maxHeight = i;
        if (stRect[i].area > stRect[maxArea].area) maxArea = i;
        if (stRect[i].peri > stRect[maxPeri].peri) maxPeri = i;
    }
    printf("\n���� ���� ū �簢���� �ε���: %d", maxWidth);
    printf("\n���̰� ���� ū �簢���� �ε���: %d", maxHeight);
    printf("\n���̰� ���� ū �簢���� �ε���: %d", maxArea);
    printf("\n�ѷ��� ���� ū �簢���� �ε���: %d", maxPeri);

    for (i = 0; i < 19; i++) {
        least = i;
        for (j = i + 1; j < 20; j++) {
            if (stRect[index[j]].area < stRect[index[least]].area) least = j;
        }
        temp = index[i];
        index[i] = index[least];
        index[least] = temp;
    }

    printf("\n\n���̰� ū ������� ����(�ε���): ");
    for (i = 0; i < 20; i++) {
        printf("%d ", index[i]);
    }

    return 0;
}