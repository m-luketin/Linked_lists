#include "longnumber.h"

LongNumber AddToHead(LongNumber list, int z) {
	LongNumber newNum;
	newNum = (LongNumber)malloc(sizeof(Digit));

	newNum->z = z;
	newNum->next = list;
	list = newNum;

	return list;
}

LongNumber Reverse(LongNumber num) {
	LongNumber newNum, s = num;
	newNum = (LongNumber)malloc(sizeof(LongNumber));
	newNum = NULL;
	while (s != NULL) {
		newNum = AddToHead(newNum, s->z);
		s = s->next;
	}
	
	return newNum;
}

LongNumber ReadLongnum(char* fname) {
	int buffer;
	
	FILE* fp;
	fp = fopen(fname, "r");
	
	LongNumber list;
	list = NULL;

	while (!feof(fp)) {
		buffer = fgetc(fp);
		if (buffer != EOF)
			list = AddToHead(list, buffer - '0');
	}
	
	list = Reverse(list);
	return list;
}

void WriteLongnum(LongNumber num, char* fname) {
	FILE* fp;
	fp = fopen(fname, "w");

	while (num != NULL) {
		fputc(num->z + '0', fp);
		num = num->next;
	}
}

void PrintLongnum(LongNumber num) {
	LongNumber s = num;
	while (s != NULL) {
		printf("%d", s->z);
		s = s->next;
	}
	printf("\n");
}

void DeleteLongnum(LongNumber num) {
	if (num == NULL)
		return;
	LongNumber tmp1 = num, tmp2 = num->next;
	while (tmp2 != NULL) {
		free(tmp1); 
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	free(tmp1);
}

LongNumber AddLongnum(LongNumber a, LongNumber b) {
	LongNumber newNum;
	int overflow = 0;

	newNum = (LongNumber)malloc(sizeof(LongNumber));
	newNum = NULL;

	if (a == NULL) {
		newNum = b;
		return newNum;
	}
	else if (b == NULL) {
		newNum = a;
		return newNum;
	}
	
	LongNumber sa = Reverse(a), sb = Reverse(b);
	
	while (sa != NULL && sb != NULL) {
		
		newNum = AddToHead(newNum, (sa->z + sb->z + overflow)%10);

		if ((sa->z + sb->z + overflow) > 9)
			overflow = 1;
		else
			overflow = 0;
		
		sa = sa->next;
		sb = sb->next;
	}
	if (sa == NULL)
		while (sb != NULL) {
			if (overflow) {
				newNum = AddToHead(newNum, sb->z + overflow);
				overflow = 0;
			}
			else 
				newNum = AddToHead(newNum, sb->z + overflow);
			sb = sb->next;
		}
	else if (sb == NULL)
		while (sa != NULL) {
			if (overflow) {
				newNum = AddToHead(newNum, sa->z + overflow);
				overflow = 0;
			}
			else
				newNum = AddToHead(newNum, sa->z + overflow);
			sa = sa->next;
		}
	if (overflow)
		newNum = AddToHead(newNum, overflow);

	return newNum;
}

LongNumber MulByDigit(LongNumber num, int z) {
	LongNumber s = Reverse(num), newNum;
	int overflow = 0;

	newNum = (LongNumber)malloc(sizeof(LongNumber));
	newNum = NULL;

	if (num == NULL)
		return newNum;

	while (s != NULL) {
		newNum = AddToHead(newNum, ((s->z)*z + overflow) % 10);
		overflow = ((s->z)*z + overflow) / 10;
		
		s = s->next;
	}
	while (overflow) {
		newNum = AddToHead(newNum, overflow % 10);
		overflow /= 10;
	}

	return newNum;
}

LongNumber MulByPow10(LongNumber num, int pow) {
	LongNumber newNum = Reverse(num);
	for (int i = 0; i < pow; i++)
		newNum = AddToHead(newNum, 0);
	newNum = Reverse(newNum);
	return newNum;
}

LongNumber MulByLongnum(LongNumber a, LongNumber b) {
	LongNumber sb = Reverse(b), newNum, tmp = NULL;
	newNum = (LongNumber)malloc(sizeof(LongNumber));
	newNum = NULL;
	int i = 1;
	while (sb != NULL) {
		tmp = MulByDigit(a, (sb->z)*i);
		newNum = AddLongnum(newNum, tmp);
		i*=10;
		sb = sb->next;
	}
	
	return newNum;
}