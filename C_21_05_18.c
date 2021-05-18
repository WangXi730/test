#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int*arr,int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(arr + i));
	}
}
int main() {
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		*(arr + i) = i;
	}
	print(arr, 10);
	return 0;
}