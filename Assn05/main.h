#ifndef __MAIN_H__ //���ǰ� �ȵǾ��ٸ� ������ ���� (if not def)
#define __MAIN_H__

typedef unsigned char UCHAR;

struct BF { //8bit(1 byte)������ bit�� �ɰ�(bit field)
	UCHAR a : 2;
	UCHAR b : 3;
	UCHAR c : 1;
	UCHAR d : 2;
};

typedef struct BF stBF;

union uBF { //1byte ������
	stBF b;
	UCHAR ch;
};

typedef union uBF unBF;

#endif#pragma once
