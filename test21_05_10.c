#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//求解一元二次方程
void account(double a, double b, double c) {
	//printf("\n");
		double d1 = 0.0;
		double d2 = 0.0;
	if (a == 0) {
		double d = 0.0;
		if (b != 0) {
			d = (c / b * 1.0);
			printf("解为%lf", d);
		}
		else
			printf("无解");
	}
	else if ((b * b * 1.0 - 4 * a * c) < 0) {
		d1 = (-b )/ (2 * a) * 1.0;
		d2 = sqrt(4 * a * c - b * b) / (2 * a) * 1.0;
		printf("解为%lf+%lfi,以及%lf-%lfi",d1, d2, d1, d2);
	}
	else {
		d1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a) * 1.0;
		d2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a) * 1.0;
		if (d1 == d2)
			printf("%lf是方程的解",d1);
		else
			printf("%lf和%lf是方程的解", d1, d2);
     }
	printf("\n");
}

//求出一个函数的位数
int account1(int a) {
	if (a > 10) {
		a = a / 10;
	}
	else
		return 1;
	return account1(a)+1;
}

//输出每一位数字
void account2(int a) {
	if (a > 10) {
		int b = a;
		a = a / 10;
		account2(a);
		printf("%d ", b%10);
	}
	else
	printf("%d ",a);
}

//逆序输出数字
void account3(int a) {
	if (a > 10) {
		printf("%d", a % 10);
		a = a / 10;
		account3(a);
	}
	else
		printf("%d", a);
}

int main() {
	//double a, b, c;
	//while(1){
	//scanf("%lf %lf %lf", &a, &b, &c);
	//account(a, b, c);
	//}
	int e;
	while (1) {
	scanf("%d", &e);
	int d = account1(e);
	printf("输入的数字是%d位", d);
	printf("\n分别打印：");
	account2(e);//打印每一位
	printf("\n逆序为：");
	account3(e);//逆序
	printf("\n");
	}

	return 0;
}