#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int mystrcmp(char* a, char* b) {
	assert(a != NULL && b != NULL);
	int i = 0;
	//依次按照字典序比较字符大小
	while (1) {
		if (a[i] - b[i] != 0)
			return (int)a[i] - (int)b[i];//不相等返回一个大于或小于0的值
		else if (a[i] == '\0')//相等且同时结束，则返回0
			return 0;
		else//相等但没有结束，则比较下一位
			i++;
	}
}
char* mystrcat(char* a,char* b) {
	assert(a != NULL && b != NULL);
	int i = 0;
	while (1) {
		if (a[i] != '\0')
			i++;
		else
			break;
	}
	int j = 0;
	while (1) {
		a[i] = b[j];
		if (b[j] == '\0')
			break;
		i++;
		j++;
	}
	return a;
}

char* mystrcpy(char* a, char* b) {
	assert(a != NULL && b != NULL);
	int i = 0;
	while (1) {
		if (b[i] == '\0')
			break;
		a[i] = b[i];
		i++;
	}
	i++;
	a[i] = b[i];
	return a;
}

size_t mystrlen(const char* a) {
	size_t i = 0;
	while (1) {
		if (a[i] == '\0')
			break;
		i++;
	}
	return i;
}

int main() {
	char arr[] = "hello world";
	printf("%d\n", mystrlen(arr));
	
	
	
	
	
	
	//char arr[] = "hello";
	//char brr[] = "world";
	//char crr[] = "xxxxx";
	//mystrcpy(arr, mystrcpy(brr, crr));
	//printf("%s\n%s\n%s\n", arr, brr, crr);




	//char arr[] = "abcde";
	//char brr[] = "abcfe";
	//printf("%d", mystrcmp(arr, brr));



	/*char arr[20] = "Hello";
	char brr[20] = "world";
	mystrcat(arr, brr);
	printf("%s\n", arr);*/
	return 0;
}