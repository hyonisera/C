#ifndef __MAIN_H__ //정의가 안되었다면 정의할 것임 (if not def)
#define __MAIN_H__

typedef unsigned char UCHAR;

struct BF { //8bit(1 byte)내에서 bit를 쪼갬(bit field)
	UCHAR a : 2;
	UCHAR b : 3;
	UCHAR c : 1;
	UCHAR d : 2;
};

typedef struct BF stBF;

union uBF { //1byte 내에서
	stBF b;
	UCHAR ch;
};

typedef union uBF unBF;

#endif#pragma once
