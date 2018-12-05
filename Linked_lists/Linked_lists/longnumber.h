#ifndef LONGNUM_H
#define LONGNUM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _Digit {
	int z;
	struct _Digit *next;
} Digit;

typedef Digit* LongNumber;

LongNumber AddToHead(LongNumber lista, int z);

LongNumber Reverse(LongNumber num);

LongNumber ReadLongnum(char* fname);

void WriteLongnum(LongNumber num, char* fname);

void PrintLongnum(LongNumber num);

void DeleteLongnum(LongNumber num);

LongNumber AddLongnum(LongNumber a, LongNumber b);

LongNumber MulByDigit(LongNumber num, int z);

LongNumber MulByPow10(LongNumber num, int pow);

LongNumber MulByLongnum(LongNumber a, LongNumber b);

#endif

