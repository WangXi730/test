#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int func(const void* a,const void* b);
int func2(const void* a, const void* b);
void test(void *a,int number,int size,int(* in)(const void* a,const void* b)) {
	if (size == 4) {
		int* b = (int*)a;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number - i - 1; j++) {
				if (in((b + j), (b + j + 1)) > 0) {
					int cup = *(b+j);
					*(b + j) = *(b + 1 + j);
					*(b + 1 + j) = cup;
				}
			}
		}
	}
	else if (size == 1) {
		char* b = (char*)a;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number - i - 1; j++) {
				if (in(b + j, b + j + 1) > 0) {
					char cup = *(b + j);
					*(b + j) = *(b + 1 + j);
					*(b + 1 + j) = cup;
				}
			}
		}
	}
}
int main() {
	int a[10] = { 0,5,1,6,3,7,2,7,4,6 };
	char b[10] = { 'a','c','t','j','w','b','d','s','q','n' };
	//test(a, 10, sizeof(a[0]), &func);
	//test(b, 10, sizeof(b[0]), &func2);
	qsort(a, 10, sizeof(a[0]), &func);
	qsort(b, 10, sizeof(b[0]), &func2);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%c\n", b[i]);
	}
	return 0;
}

int func(const void* a, const void* b) {
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	return *a1 - *b1;
}
int func2(const void* a, const void* b) {
	char* a1 = (char*)a;
	char* b1 = (char*)b;
	return (int)(*a1 - *b1);
}
