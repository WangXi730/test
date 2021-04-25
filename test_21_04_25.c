#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int print(int arr[],int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d地址是%p\n", arr[i], &arr[i]);
//	}
//	printf("\n");
//}
//int main() {
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 6,7,8,9,0 };
//	printf("修改前：\n");
//	print(a, 5);
//	print(b, 5);
//	for (int i = 0; i < 5; i++) {
//		int cup = a[i];
//		a[i] = b[i];
//		b[i] = cup;
//	}
//	printf("修改后：\n");
//	print(a, 5);
//	print(b, 5);
//	return 0;
//}

//实现一个对整形数组的冒泡排序
void test(int arr[],int n) {
	for (; n > 0 ; n-- ) {
		for (int i = 0; i < n; i++) {
				if (arr[i] < arr[i + 1]) {
					int cup = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = cup;
		         }
	     }
	}
}
int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	test(arr, 10);
	for(int i=0;i<10;i++)
	printf("%d", arr[i]);
	return 0;
}