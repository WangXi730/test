#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void print(int n) {
	if (n / 10)
		print(n / 10);
	printf("%d ", n%10);
}
//����Ĭ��n��k��Ϊ����
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
			printf("%2d��%2d=%3d  ", j, i, j * i);
		}
		printf("\n");
	}
}
int main() {
	int a = 0;
	int k = 0;
	while (1) {
		printf("����Ϊ��");
		scanf("%d", &a);
		print99(a);
		//printf("����n,k:");
		//scanf("%d %d", &a, &k);
		//print(a);
		//printf("n��k�η��ǣ�");
		//a = account1(a, k);
		//account1��������a��k�η���
		//printf("%d", a);
		//printf("\n");
	}
	return 0;
}