#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
//��һ��
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

//�ڶ���
void test2(char* p[], int n) {
	assert(p != NULL);
	assert(n != 0);
	//strcmp()ʵ�ֱȽ�
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

//������
typedef struct t3 {
	int year;
	int month;
	int day;
}t3;

int test3_s(int y) {//�ж�����
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
	//��һ�⣬ѡ��1
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	test1(a, b, c);
	//�ڶ��⣬ѡ��20
	char* arr[] = { "abc","def","abe","tcg" };
	test2(arr, 4);
	for (int i = 0; i < 4; i++) {
		printf("%s ", arr[i]);
	}
	printf("\n");
	//�����⣬ѡ��1
	printf("�������꣬�£��գ�");
	t3 d;
	scanf("%d%d%d", &d.year, &d.month, &d.day);
	printf("����ĵ�%d��\n", test3(d));
	return 0;
}