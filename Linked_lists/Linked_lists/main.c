#include "longnumber.h"

void main() {
	LongNumber numa = ReadLongnum("a.txt");
	printf("First number: ");
	PrintLongnum(numa);
	LongNumber numb = ReadLongnum("b.txt");
	printf("Second number: ");
	PrintLongnum(numb);
	
	LongNumber numc = AddLongnum(numa, numb);
	printf("Sum: "); 
	PrintLongnum(numc);
	
	LongNumber numd = MulByDigit(numc, 9);
	printf("Multiplication by digit(9): "); 
	PrintLongnum(numd);
	
	LongNumber nume = MulByPow10(numd, 3);
	printf("Multiplication by pow of 10(3): ");
	PrintLongnum(nume);
	
	LongNumber numf = MulByLongnum(numa, numb);
	printf("Multiplying first and second number: "); 
	PrintLongnum(numf);
	
	WriteLongnum(numf, "c.txt");
	
	DeleteLongnum(numa);
	DeleteLongnum(numb);
	DeleteLongnum(numc);
	DeleteLongnum(numd);
	DeleteLongnum(nume);
	DeleteLongnum(numf);
	
	system("pause");
}