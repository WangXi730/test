#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
////打印0到100中9的个数
//int main(){
//	int a = 0;
//	int account = 0;
//	for (a = 9; a < 100; a ++) {
//		if (a % 10 == 9)
//			account++;
//		if (a / 10 == 9)
//			account++;
//	}
//	printf("%d", account);
//	return 0;
//}

////求1/1-1/2+1/3...-1/100=?
//int main() {
//    int i = 1;
//    double sum = 0;
//    int j = 0;
//    for (; i <= 100; i++) {
//        j = -i; 
//        sum += (1.0 / j) ;
//    }
//    printf("%lf", -sum);
//    return 0;
//} 

////求10个整数的最大值
//int max2(int x ,int y) {
//	int m = (x > y ? x : y);
//	return m;
//}
//
//int max4(int a, int b, int c, int d) {
//	int m = max2(a, b);
//	 m = max2(c, m);
//	 m = max2(d, m);
//	return m;
//}
//
//int max10(int a, int b, int c, int d, int e, int f, int g, int h,int i,int j) {
//	int m1 = max4(a, b, c, d);
//	int m2 = max4(e, f, g, h);
//	int m = max4(m1, m2, i, j);
//	return m;
//}
//
//int main() {
//	int a, b, c, d, e, f, g, h, i, j ,m;
//	printf("请输入整数：");
//	scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
//    m = max10(a, b, c, d, e, f, g, h, i, j);
//	printf("\n最大值为：");
//	printf("%d", m);
//	return 0;
//}

////打印九九乘法表
//int main() {
//	for (int i = 1; i <= 9; i++) {
//		for (int j =1; j <= i; j++) {
//			printf("%d×%d=%2d  ",j,i, j * i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////猜数字游戏
//int main() {
//	int i = (time(0)%100);
//	int j = 0;
//BEGIN:
//	printf("请输入您心中的数字（提示：数字是1到100之间的整数哦~）：");
//	scanf("%d", &j);
//	if (i == j)
//		printf("恭喜哦，您猜对啦！");
//	else if(i > j){
//		printf("略微小了一些哦!");
//		goto BEGIN;
//	}
//	else if (i < j) {
//		printf("稍稍大了一些哦！");
//		goto BEGIN;
//	}
//	return 0;	
//}

////二分查找的练习
//int main() {
//	int a = 0;
//	int b = 0;
//	int arr[10] = { 0 };
//	for (int i = 0; i <= 9; ) {
//		a = (time(0)%100);
//		if (a > b && a<=90+i) {
//			b = a;
//			arr[i] = b + 1;
//			i++;
//		}
//	}
//	int t = 0;
//	scanf("%d",&t);
//	int max = 9;
//	int min = 0;
//	int test = 0;
//	for (int i = 5; i <= 9 && i >= 0;) {
//		if (t == arr[i]) {
//			printf("下标为%d", i);
//			test = 1;
//			break;
//		} 
//		if (t > arr[i]) {
//			min = i;
//			i = ((max + i) / 2) + 1;
//		}
//		if (t < arr[i]) {
//			max = i;
//			i = ((min + i) / 2) - 1;
//		}
//	    if (min>=max)
//				break;
//	}	
//		if(test==0)
//		printf("找不到");
//	return 0;
//}
////注：由于是随机数填充，成功找到的概率设置为了0.1，这里采取了调试的方式直接找。

