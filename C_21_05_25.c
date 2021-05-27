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
//	printf("你想打印几行？\n");
//	while (n < 1) {
//		scanf("%d", &n);
//		if (n < 1) {
//			printf("输入不符合标准\n请重新输入：");
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
	//1表示指控，-1代表辩解，0表示
	int a[4] = { -1,0,0,0 };
	int b[4] = { 0,0,1,0 };
	int c[4] = { 0,0,0,1 };
	int d[4] = { 0,0,0,-1 };
	int lie[4] = { 0 };
	int x[4] = { 0 };//凶手的嫌疑人
	int account = 0;//记录被指控者的人数
	//只有一个人说谎了，而且通过观察，每个人只对一个人是不是凶手做出发言
	for (int i = 0; i < 4; i++) {//找冲突
		if (a[i] == b[i] && b[i] == c[i] && c[i] == d[i]) {
			continue;
			}
		else if (a[i] + b[i] + c[i] + d[i] == 0) {//说明有分歧,代表有人说谎
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
				printf("a是凶手");
			else if (i == 1)
				printf("b是凶手");
			else if (i == 2)
				printf("c是凶手");
			else if (i == 3)
				printf("d是凶手");
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
					printf("a是凶手");
				else if (i == 1)
					printf("b是凶手");
				else if (i == 2)
					printf("c是凶手");
				else if (i == 3)
					printf("d是凶手");

		     }

	}
	else {
		for (int i = 0; i < 1; i++) {
			if (a[i] + b[i] + c[i] + d[i] == -1) {
			if (i == 0)
				printf("a是凶手");
			else if (i == 1)
				printf("b是凶手");
			else if (i == 2)
				printf("c是凶手");
			else if (i == 3)
				printf("d是凶手");
			}
		}
	}
	return 0;
	printf("无法判断谁是凶手");//由于无人指控，且每个人为一个人且仅为一人指控或辩护,无法判断谁说谎了
	return 1;
}
int main() {
	//Func();
	Choose();
	return 0;
}