#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
////ʵ��strlen�������ַ�����
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
////��ʾ
//int main(){
//	char a[]="abcdef";
//	strlen(a);
//	return 0;
//	}

////ʵ�����������
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

////ʵ�ַǸ������ĸ���λ��֮��
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

////�ݹ�ʵ��n��k�η�
//int nk(int n,int k) {
//	if(k == 1)
//	return n;
//	return n * nk(n, k - 1);
//}
//int main() {
//	int t = nk(3, 3);
//	printf("%d", t);
//}

//�ݹ�ʵ����쳲�������
int F1(int n) {
	if (n == 1 || n == 2)
		return 1;
	return F1(n - 1) + F1(n - 2);
}
//�ǵݹ�ʵ����쳲�������
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
	printf("�����룺");
	scanf("%d", &n);
	int t1 = F1(n);
	int t2 = F2(n);
	printf("�ݹ麯���ã�%d\n�ǵݹ麯���ã�%d\n���롰1�������������˳���", t1, t2);
	int t = 0;
	scanf("%d", &t);
	if (t == 1)
		goto BEGIN;
	return 0;
}