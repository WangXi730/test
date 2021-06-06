#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//typedef struct doubleint {
//	int a;
//	int b;
//}dint;
//dint func(int arr[4][4],int n) {//在数组arr中找n
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (arr[i][j] == n) {
//				dint ret = { i,j };
//				return ret;
//			}
//		}
//	}
//	dint ret = { -1,-1 };
//	return ret;
//}
//int main() {
//	int arr[4][4] = { { 1,2,3,4 }, { 5,6,7,8 }, { 9,10,11,12 }, { 13,14,15,16 } };
//	dint ret = func(arr, 6);
//	printf("%d,%d", ret.a, ret.b);
//	return 0;
//}


//对于考试题最后一题，引发的对于scanf的思考与探究
int main() {
	char arr[100][100] ;
	char brr[100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			arr[i][j] = '\0';
		}
	}
	/*scanf("%s", arr);
	scanf("%s", brr);*/
	int i = -1;
	while (arr[i][0]!='.') {
		i++;
		scanf("%s",arr[i]);
	}
	i--;
	for (; i >= 0; i--) {
		printf("%s ", arr[i]);
	}
	printf(".");

	//printf("%s %s", arr, brr);
	
	//char a[2][10] = { '\0' };
	//for (int j = 0; j < 2; j++) {
	//	a[j][0] = '*';
	//}
	//int t = 2;
	//int i = 0;
	//a[1][0] = '\0';
	//while (t) {
	//	if (a[i][0] == '\0') {
	//		t = 0;
	//	}
	//	printf("%s", a[i]);
	//	i++;
	//}
	/*scanf("%s", a[0]);
	t = (int)a[i][0];
	printf("%s", a[0]);
	printf("%s", a[1]);
	printf("%d", t);
	*/
	
	/*
	int a = 0;
	char b = 0;
	a=scanf("%d", &b);
	printf("%c",b);
	*/
	return 0;
}