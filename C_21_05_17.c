#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
////������
//long long account1(long long n) {//����n�Ľ׳�
//	if (n == 1)
//		return 1;
//	return account1(n - 1) * n;
//}
//int main() {
//	long long num = 0;
//	long long n = 0;
//	scanf("%lld", &n);
//	for (long long i = 1; i <= n; i++) {
//		num += account1(i);
//	}
//	printf("%lld", num);
//	return 0;
//}

////������
//int account2(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	return n + account2(n - 1);
//}
//double account3(double n) {
//	if (n == 1) {
//		return 1;
//	}
//	return 1 / n + account3(n - 1);
//}
//int account4(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	return n * n + account4(n - 1);
//}
//int main() {
//	int a = 0;
//	int a2 = 0;
//	double an = 0;
//	an = account3(10);
//	a2 = account4(50);
//	a = account2(100);
//	printf("%d\n%d\n%lf", a, a2, an);
//	return 0;
//}

////����ͬ�����⣨��35ͷ�� 94�㣩
//void fun(int Heads,int Feet) {
//	if (!Feet % 2)
//		printf("�������");
//	if (Feet > Heads * 4 || Feet < Heads * 2)
//		printf("�������");
//	int a1 = 4 * Heads;
//	int a2 = a1 - Feet;
//	a1 = a2 / 2;
//	a2 = Heads - a1;
//	printf("һ��%dֻ����%dֻ��", a1, a2);
//}
//int main() {
//	fun(35, 94);
//	return 0;
//}

