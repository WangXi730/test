#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct G {
	double a;//实根1或者实部
	double b;//实根2
	double i;//虚部
}G;
//最大公约数
int Max(int a,int b) {
	if (a > b) {
		int cup = a;
		a = b;
		b = cup;
	}
	int c = 0;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			c = i;
		}
	}
	return c;
}
//最小公倍数
int Min(int a,int b) {
	int c = Max(a, b);
	a = a / c;
	b = b / c;
	return a * b * c;
}
//求解ax²+bx+c=0
G qiugen(double a, double b, double c) {
	G j;
	if (b * b - 4 * a * c > 0) {
		j.a = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
		j.b = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
		j.i = 0;
		return j;
	}
	else if (b * b - 4 * a * c == 0) {
		j.a = (-b / 2*a);
		j.b = j.a;
		j.i = 0;
		return j;
	}
	else {
		j.a=(-b / 2 * a);
		j.i = sqrt(4 * a * c - b * b) / 2 * a;
		return j;
	}
}
int main() {
	int c = 1;//结束变量
	//第一题，求最大公约数以及最小公倍数
	int a, b;
	while (c) {
		printf("输入要求公约数与公倍数的俩数字：");
		scanf("%d %d", &a, &b);
		printf("%d是最大公约数，%d是最小公倍数\n", Max(a, b), Min(a, b));
		printf("是否继续？\n1、是\n0、否\n");
		scanf("%d", &c);
	}
	c = 1;
	//第二题，求ax²+bx+c=0的解，要求a,b,c从主函数输入
	while (c) {
		double a1, b1, c1;
		printf("请输入ax^2+bx+c=0中的a,b,c:\n");
		scanf("%lf %lf %lf", &a1, &b1, &c1);
		G j;
		j.a = qiugen(a1, b1, c1).a;
		j.b = qiugen(a1, b1, c1).b;
		j.i = qiugen(a1, b1, c1).i;
		if (j.i == 0) {//有实根
			if (j.b == j.a) {
				printf("%lf是方程的解\n",j.a);
			}
			else {
				printf("%lf与%lf是方程的解\n",j.a,j.b);
			}
		}
		else {//无实根
			printf("%lf+%lfi与%lf-%lfi是方程的解\n", j.a, j.i, j.a, j.i);
		}

		printf("是否继续？\n1、是\n0、否\n");
		scanf("%d", &c);
	}
	return 0;
}