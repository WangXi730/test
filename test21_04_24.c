#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
////实现strlen函数求字符长度
//void strlen(char a[]) {
//	int i = 0;
//	while (1) {
//		if (a[i] == '/0') {
//			i++;
//			break;
//		}
//		i++;
//	}
//
//}
////演示
//int main(){
//	char a[]="abcdef";
//	strlen(a);
//	return 0;
//	}

////实现数组的逆置
//	int i = -1;
//void reverse_string(char arr[],int n) {
//	i++;
//	if (i < n / 2) {
//    char cup = arr[i];
//	arr[i] = arr[n - i - 1];
//	arr[n - i - 1] = cup;
//	reverse_string(arr, n);
//	}
//}
//int main() {
//	char arr[] = "abcdef";
//	int n = sizeof(arr) / sizeof(arr[0])-1;
//	reverse_string(arr,n);
//	printf("%s", arr);
//	return 0;
//}

////实现非负整数的各个位数之和
//int i = 0;
//DigitSum(int n) {
//	if (n / 10 > 0) 
//		i = n % 10 + DigitSum(n / 10);
//	else
//		i=n%10;
//	return i;
//}
//int main() {
//	int n = 5689;
//	int t=DigitSum(n);
//	printf("%d", t);
//	return 0;
//}

////递归实现n的k次方
//int nk(int n,int k) {
//	if(k == 1)
//	return n;
//	return n * nk(n, k - 1);
//}
//int main() {
//	int t = nk(3, 3);
//	printf("%d", t);
//}

//递归实现求斐波那契数
int F1(int n) {
	if (n == 1 || n == 2)
		return 1;
	return F1(n - 1) + F1(n - 2);
}
//非递归实现求斐波那契数
int F2(int n) {
	if (n == 1) {
		return 1;
	}
	int i = 1, j = 0, t = 0;
	for (int r=1; r< n;r++) {
		t = i + j;
		j = i;
		i = t;
	}
	return t;
}
int main() {
    int n=0 ;
BEGIN:
	printf("请输入：");
	scanf("%d", &n);
	int t1 = F1(n);
	int t2 = F2(n);
	printf("递归函数得：%d\n非递归函数得：%d\n输入“1”继续，其他退出：", t1, t2);
	int t = 0;
	scanf("%d", &t);
	if (t == 1)
		goto BEGIN;
	return 0;
}