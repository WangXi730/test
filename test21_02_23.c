#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
////ʵ����������
//int decide(int n) {
//	int i = 3;
//	if (n % 2 == 1) {
//		for (; i <= sqrt(n); i += 2) {
//			if (n % i == 0)
//				break;
//		}
//		if(i > sqrt(n))
//			return 1;//��ʾ������
//		if(i<= sqrt(n))
//			return 0;//��ʾ������
//	}
//}
////��ӡ����
//int main() {
//	int a,b;
//	printf("100��200֮����������£�\n");
//	for (a = 101; a < 200; a += 2) {
//     b = decide(a);
//     if (b == 1)
//     printf("%d ", a);
//	}
//	
//	return 0;
//}

////ʵ���ж�����
//void decide(int year) {
//	int t = 0;
//	if (year % 400 == 0)
//		t = 1;
//	else if (year % 4 == 0 && year % 100 != 0)
//		t = 1;
//	if (t == 1)
//		printf("������");
//	if (t == 0)
//		printf("��������");
//}
////����
//int main() {
//	int year=0;
//	scanf("%d", &year);
//	decide(year);
//	return 0;
//}

////ʵ�ֽ�����������������
//void exchange(int* a,int* b) {
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
//}
////չʾ
//int main() {
//	int a, b;
//	scanf("%d%d", &a, &b);
//	exchange(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

////�˷��ھ���Ĵ�ӡ
//void nine() {
//	int i = 1;
//	for (; i <= 9; i++) {
//		for (int j = 1; j <= i; j++)
//			printf("%d��%d=%2d ", j, i, i * j);
//		printf("\n");
//	}
//}
////չʾ
//int main() {
//	nine();
//	return 0;
//}

////�ݹ��ӡһ������ÿһλ
//int print(int n) {
//	int i = 0;
//	if (n / 10 > 0) {
//		i = n / 10;
//		print(i);
//	}
//		printf("%d ", n%10);
//}
////��ʾ
//int main() {
//	int a;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}

//�ǵݹ���n�Ľ׳�
int test1(int n) {
	int t = 1;
	int i = 1;
	while (i <= n) {
     t *= i;
	 i++;
	}
	return t;
}
//�ݹ�ʵ����n�Ľ׳�
int test2(int n) {
	if (n > 1) {
		n *= test2(n - 1);
	}
	else if (n == 0)
		n = 1;
	return n;
}
//��ʾ
int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", test1(n));
	printf("%d", test2(n));
	return 0;
}