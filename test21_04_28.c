#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//int main() {
//	int a = 1,b=10,c=0;
//	for (; a < b; a++) {
//		c = a | b;
//		printf("%d\n", c);
//	}
//	return 0;
//}
//int account(int c) {
//	int i = 0;
//	static int a = 0;
//	if (c < 0) {
//		c = -c;
//		a++;
//		i++;
//	}
//	if (i == 0)
//		a = 0;
//	if (c / 2 > 0)
//		return c % 2 + account(c/2);
//	else if (c / 2 == 0) {
//		return c+a;
//	}
//}
//int main() {
//	int d = 0;
//	scanf("%d", &d);
//	d = account(d);
//	printf("%d个1",d);
//	return 0;
//}

//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d", a, b);
//	return 0;
//}

//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//int main() {
//	int a = 0;
//	int b = 1;
//	int account = 0;
//	scanf("%d", &a);
//	for (int i = 0; i <= 32; i++) {	
//		if (a & b)
//			account++;
//		b=(b<<1);
//	}
//	printf("共有%d个“1”", account);
//    return 0;
//}

//int main() {
//	int a = 16;
//	a = 1 << a;
//	printf("%d", a);
//	return 0;
//}

//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	a = a ^ b;
//	b = 0;
//	for (int i = 0; i < 32; i++) {
//		if (a & (1 << i))
//			++b;
//	}
//	printf("%d", b);
//	return 0;
//}

//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	printf("偶数位：");
//	for (int i = 31; i > 0; i -= 2) {
//		if (a & (1 << i))
//			b = 1;
//		else
//			b = 0;
//		printf("%d ", b);
//	}
//	printf("\n奇数位：");
//	for (int i = 30; i >= 0; i -= 2) {
//		if (a & (1 << i))
//			b = 1;
//		else
//			b = 0;
//		printf(" %d", b);
//	}
//	return 0;
//}
