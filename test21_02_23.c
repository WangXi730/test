#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
////实现质数检验
//int decide(int n) {
//	int i = 3;
//	if (n % 2 == 1) {
//		for (; i <= sqrt(n); i += 2) {
//			if (n % i == 0)
//				break;
//		}
//		if(i > sqrt(n))
//			return 1;//表示是质数
//		if(i<= sqrt(n))
//			return 0;//表示非质数
//	}
//}
////打印质数
//int main() {
//	int a,b;
//	printf("100到200之间的质数如下：\n");
//	for (a = 101; a < 200; a += 2) {
//     b = decide(a);
//     if (b == 1)
//     printf("%d ", a);
//	}
//	
//	return 0;
//}

////实现判断闰年
//void decide(int year) {
//	int t = 0;
//	if (year % 400 == 0)
//		t = 1;
//	else if (year % 4 == 0 && year % 100 != 0)
//		t = 1;
//	if (t == 1)
//		printf("是闰年");
//	if (t == 0)
//		printf("不是闰年");
//}
////测试
//int main() {
//	int year=0;
//	scanf("%d", &year);
//	decide(year);
//	return 0;
//}

////实现交换两个整数的内容
//void exchange(int* a,int* b) {
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
//}
////展示
//int main() {
//	int a, b;
//	scanf("%d%d", &a, &b);
//	exchange(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

////乘法口诀表的打印
//void nine() {
//	int i = 1;
//	for (; i <= 9; i++) {
//		for (int j = 1; j <= i; j++)
//			printf("%d×%d=%2d ", j, i, i * j);
//		printf("\n");
//	}
//}
////展示
//int main() {
//	nine();
//	return 0;
//}

////递归打印一个数的每一位
//int print(int n) {
//	int i = 0;
//	if (n / 10 > 0) {
//		i = n / 10;
//		print(i);
//	}
//		printf("%d ", n%10);
//}
////演示
//int main() {
//	int a;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}

//非递归求n的阶乘
int test1(int n) {
	int t = 1;
	int i = 1;
	while (i <= n) {
     t *= i;
	 i++;
	}
	return t;
}
//递归实现求n的阶乘
int test2(int n) {
	if (n > 1) {
		n *= test2(n - 1);
	}
	else if (n == 0)
		n = 1;
	return n;
}
//演示
int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", test1(n));
	printf("%d", test2(n));
	return 0;
}