#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//����ʵ�ֶ�����ĳ�ʼ��
void init(int arr[], int n) {
	for (int i = 0; i < n; i++) 
		arr[i] = 0;
}
//ʵ�ִ�ӡ�����е�ÿһ��Ԫ��
void print(int arr[10],int n) {
	for (int j = 0; j < 10; j++) {
		printf("%d ", arr[j]);
	}
}
//ʵ������Ԫ�ص�����
void reverse(int arr[], int n) {
	for (int i = 0; i < n / 2; i++) {
		arr[i] = arr[i] + arr[n - 1 - i];
		arr[n - 1 - i] = arr[i] - arr[n - 1 - i];
		arr[i] = arr[i] - arr[n - 1 - i];
	}
}//��ʾ����
int main() {
	int arr[10];
	init(arr, 10);
	print(arr, 10);
	printf("\n");
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	print(arr, 10);
	printf("\n");
	reverse(arr, 10);
	print(arr, 10);
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
