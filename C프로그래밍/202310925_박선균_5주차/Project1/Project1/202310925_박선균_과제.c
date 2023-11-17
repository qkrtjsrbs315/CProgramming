#include<stdio.h>

int returnMaxValue(int num1,int num2, int num3);
int returnMinValue(int num1, int num2, int num3);
int* returnOrderedValueByASC(int num1, int num2, int num3);

int main() {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	printf("가장 큰 값 : %d \n", returnMaxValue(a, b, c));
	printf("가장 작은 값 : %d \n", returnMinValue(a,b,c));

	return 0;
}

int* returnOrderedValueByASC(int num1, int num2, int num3) {
	int numbers[3] = { num1,num2,num3 };
	int temp = numbers[0];
	int count = sizeof(numbers) / sizeof(numbers[0]);
//	printf("count의 값 : %d \n", count);
//	printf("returnOrderedValue 의 numbers값 : %d \n", sizeof(numbers));

	for (int i = 0; i <  count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}//오름차순 버블 정렬
		}
	}
	return numbers;
}
int returnMaxValue(int num1, int num2, int num3) {
	int* numbers = returnOrderedValueByASC(num1, num2, num3);
	
	return numbers[2]; //정렬된 후 가장 오른쪽 끝 값. 즉, 가장 큰 값
}
int returnMinValue(int num1, int num2, int num3) {
	int* numbers = returnOrderedValueByASC(num1, num2, num3);
	
	return numbers[0]; //정렬된 후 가장 왼쪽 끝 값.즉, 가장 작은 값
}
