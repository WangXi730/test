#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//����ʵ�ֶ�����ĳ�ʼ��
void init(int arr[], int n) {
	for (int i = 0; i < n; i++) 
		arr[i] = 0;
}
int main() {
	int arr[10];
	init(arr, 10);
	for (int j = 0; j < 10; j++) {
		printf("%d ", arr[j]);
	}
	return 0;
}
////��������ʱ������������������λ��
//int main() {
//	int a, b;
//	scanf("%d%d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d", a, b);
//	return 0;
//}
