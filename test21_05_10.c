#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//���һԪ���η���
void account(double a, double b, double c) {
	//printf("\n");
		double d1 = 0.0;
		double d2 = 0.0;
	if (a == 0) {
		double d = 0.0;
		if (b != 0) {
			d = (c / b * 1.0);
			printf("��Ϊ%lf", d);
		}
		else
			printf("�޽�");
	}
	else if ((b * b * 1.0 - 4 * a * c) < 0) {
		d1 = (-b )/ (2 * a) * 1.0;
		d2 = sqrt(4 * a * c - b * b) / (2 * a) * 1.0;
		printf("��Ϊ%lf+%lfi,�Լ�%lf-%lfi",d1, d2, d1, d2);
	}
	else {
		d1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a) * 1.0;
		d2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a) * 1.0;
		if (d1 == d2)
			printf("%lf�Ƿ��̵Ľ�",d1);
		else
			printf("%lf��%lf�Ƿ��̵Ľ�", d1, d2);
     }
	printf("\n");
}

//���һ��������λ��
int account1(int a) {
	if (a > 10) {
		a = a / 10;
	}
	else
		return 1;
	return account1(a)+1;
}

//���ÿһλ����
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

//�����������
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
	printf("�����������%dλ", d);
	printf("\n�ֱ��ӡ��");
	account2(e);//��ӡÿһλ
	printf("\n����Ϊ��");
	account3(e);//����
	printf("\n");
	}

	return 0;
}