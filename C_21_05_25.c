#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//int account(int n) {
//	int count = 1;
//	for (int i = 1; i <= n; i++) {
//		count *= i;
//	}
//	return count;
//}
//int iCj(int i, int j) {
//	return account(i) / account(i - j) / account(j);
//}
//void Func() {
//	int n = 0;
//	printf("�����ӡ���У�\n");
//	while (n < 1) {
//		scanf("%d", &n);
//		if (n < 1) {
//			printf("���벻���ϱ�׼\n���������룺");
//		}
//	}
//	n = n - 1;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= i; j++) {
//			if (j == 0) {
//				printf("1 ");
//			}
//			else {
//				printf("%4d ", iCj(i, j));
//			}
//		}
//		printf("\n");
//	}
//}
int Choose() {
	//1��ʾָ�أ�-1�����⣬0��ʾ
	int a[4] = { -1,0,0,0 };
	int b[4] = { 0,0,1,0 };
	int c[4] = { 0,0,0,1 };
	int d[4] = { 0,0,0,-1 };
	int lie[4] = { 0 };
	int x[4] = { 0 };//���ֵ�������
	int account = 0;//��¼��ָ���ߵ�����
	//ֻ��һ����˵���ˣ�����ͨ���۲죬ÿ����ֻ��һ�����ǲ���������������
	for (int i = 0; i < 4; i++) {//�ҳ�ͻ
		if (a[i] == b[i] && b[i] == c[i] && c[i] == d[i]) {
			continue;
			}
		else if (a[i] + b[i] + c[i] + d[i] == 0) {//˵���з���,��������˵��
			lie[i] = 1;
		}
		if (a[i] == 1 || b[i] == 1 || c[i] == 1 || d[i] == 1) {
			account++;
			x[i] = 1;
		}
	}
	if (account == 1) {
		for (int i = 0; i < 4; i++) {
			if (x[i] == 0)
				continue;
			else if (i == 0)
				printf("a������");
			else if (i == 1)
				printf("b������");
			else if (i == 2)
				printf("c������");
			else if (i == 3)
				printf("d������");
		}
	}
	else if (account > 1) {
		for (int i = 0; i < 4; i++) {
			if (lie[i] == 1) {
				x[i] = 0;
			}
		}
			for (int i = 0; i < 4; i++) {
				if (x[i] == 0)
					continue;
				else if (i == 0)
					printf("a������");
				else if (i == 1)
					printf("b������");
				else if (i == 2)
					printf("c������");
				else if (i == 3)
					printf("d������");

		     }

	}
	else {
		for (int i = 0; i < 1; i++) {
			if (a[i] + b[i] + c[i] + d[i] == -1) {
			if (i == 0)
				printf("a������");
			else if (i == 1)
				printf("b������");
			else if (i == 2)
				printf("c������");
			else if (i == 3)
				printf("d������");
			}
		}
	}
	return 0;
	printf("�޷��ж�˭������");//��������ָ�أ���ÿ����Ϊһ�����ҽ�Ϊһ��ָ�ػ�绤,�޷��ж�˭˵����
	return 1;
}
int main() {
	//Func();
	Choose();
	return 0;
}