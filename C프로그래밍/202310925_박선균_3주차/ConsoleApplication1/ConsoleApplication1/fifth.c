#include<stdio.h>

int main() {

	int plus_val = 255;
	int minus_val = -255;

	int sum = plus_val + minus_val;

	printf("%08x + %08x = %08x \n", plus_val, minus_val, sum);
}