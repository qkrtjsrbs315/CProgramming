#include<stdio.h>

int main(void) {
	int myAge = 12;
	int num1 = 7, num2 = 13;
	printf("제 나이는 10진수로 %d살, 16진수로 %X살입니다. \n", myAge, myAge);
	printf("%o %#o \n", num1, num1);
	printf("%x %#x \n", num2, num2);
	
	return 0;
}