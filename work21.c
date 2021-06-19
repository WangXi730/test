#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
//第一题
void test1(int a, int b, int c) {
	if (a > b) {
		int cup = a;
		a = b;
		b = cup;
	}
	if (a > c) {
		int cup = a;
		a = c;
		c = cup;
	}
	if (b > c) {
		int cup = b;
		b = c;
		c = cup;
	}
	printf("%d %d %d\n", a, b, c);
}

//第二题
void test2(char* p[], int n) {
	assert(p != NULL);
	assert(n != 0);
	//strcmp()实现比较
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(p[j], p[j + 1])>0) {
				char* cup = p[j];
				p[j] = p[j + 1];
				p[j + 1] = cup;
			}
		}
	}
}

//第三题
typedef struct t3 {
	int year;
	int month;
	int day;
}t3;

int test3_s(int y) {//判断闰年
	if (y % 400 == 0) {
		return 1;
	}
	else if (y % 4 == 0 && y % 100 != 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int test3(t3 d) {
	d.month = d.month - 1;
	while (d.month) {
		if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
			d.day += 31;
		}
		else if (d.month == 2) {
			if (test3_s(d.year)) {
				d.day += 29;
			}
			else {
				d.day += 28;
			}
		}
		else {
			d.day += 30;
		}
		d.month--;
	}
	return d.day;
}

int main() {
	//第一题，选题1
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	test1(a, b, c);
	//第二题，选题20
	char* arr[] = { "abc","def","abe","tcg" };
	test2(arr, 4);
	for (int i = 0; i < 4; i++) {
		printf("%s ", arr[i]);
	}
	printf("\n");
	//第三题，选题1
	printf("请输入年，月，日：");
	t3 d;
	scanf("%d%d%d", &d.year, &d.month, &d.day);
	printf("本年的第%d天\n", test3(d));
	return 0;
}