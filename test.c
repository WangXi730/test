#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
////��ӡ0��100��9�ĸ���
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

////��1/1-1/2+1/3...-1/100=?
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

////��10�����������ֵ
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
//	printf("������������");
//	scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
//    m = max10(a, b, c, d, e, f, g, h, i, j);
//	printf("\n���ֵΪ��");
//	printf("%d", m);
//	return 0;
//}

////��ӡ�žų˷���
//int main() {
//	for (int i = 1; i <= 9; i++) {
//		for (int j =1; j <= i; j++) {
//			printf("%d��%d=%2d  ",j,i, j * i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////��������Ϸ
//int main() {
//	int i = (time(0)%100);
//	int j = 0;
//BEGIN:
//	printf("�����������е����֣���ʾ��������1��100֮�������Ŷ~����");
//	scanf("%d", &j);
//	if (i == j)
//		printf("��ϲŶ�����¶�����");
//	else if(i > j){
//		printf("��΢С��һЩŶ!");
//		goto BEGIN;
//	}
//	else if (i < j) {
//		printf("���Դ���һЩŶ��");
//		goto BEGIN;
//	}
//	return 0;	
//}

////���ֲ��ҵ���ϰ
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
//			printf("�±�Ϊ%d", i);
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
//		printf("�Ҳ���");
//	return 0;
//}
////ע���������������䣬�ɹ��ҵ��ĸ�������Ϊ��0.1�������ȡ�˵��Եķ�ʽֱ���ҡ�

