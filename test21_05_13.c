#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void print(int n) {
	if (n / 10)
		print(n / 10);
	printf("%d ", n%10);
}
//这里默认n、k均为整数
int account1(int n, int k) {
	if (k == 0)
		return 1;
	else if (k > 1)
	return n * account1(n, k - 1);
	return n;
}
void print99(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%2d×%2d=%3d  ", j, i, j * i);
		}
		printf("\n");
	}
}
int main() {
	int a = 0;
	int k = 0;
	while (1) {
		printf("传参为：");
		scanf("%d", &a);
		print99(a);
		//printf("输入n,k:");
		//scanf("%d %d", &a, &k);
		//print(a);
		//printf("n的k次方是：");
		//a = account1(a, k);
		//account1是用来求a的k次方的
		//printf("%d", a);
		//printf("\n");
	}
	return 0;
}