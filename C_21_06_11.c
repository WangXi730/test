#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//��һ��
void* myMemmove(void* dest, const void* soc, size_t num) {
	assert(dest!=NULL);
	assert(soc != NULL);
	char* destcp = (char*)dest;
	char* soccp = (char*)soc;
	size_t i = 0;
	if ((size_t)destcp >= (size_t)soccp) {
		for (i = num; i > 0; i--) {
			destcp[i - 1] = soccp[i - 1];
		}
	}
	else {
		for (i = 0; i < num; i++) {
			destcp[i] = soccp[i];
		}
	}
	return dest;
}
//�ڶ���
void* myMemcpy(void* dest, const void* soc, size_t num) {
	assert(dest != NULL);
	assert(soc != NULL);
	char* destcp = (char*)dest;
	char* soccp = (char*)soc;
	size_t i = 0;
	for (i = 0; i < num; i++) {
		destcp[i] = soccp[i];
	}
	return dest;
}
//������
const char* myStrstr(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	const char* rad = str1;
	const char* blue = str2;
	//����i��Ϊ����radָ�������ߵ�
	int i = 0;
	while (rad[i] != '\0') {//���rad������û���ҵ����ַ������ͷ���NULL
		//��ָ��radһֱ�ߵ���bule[0]��ͬ���ַ���ʼ��
		//�ſ��ܳ������ַ������������ȣ���i++������һ��
		if (rad[i] == blue[0]) {
			//����������һ��blackָ������blue�Խ�
			char* black = rad + i;
			//����j��Ϊ����blue��black���������ߵ�
			int j = 0;
			//���������ȣ��ͼ����Ƚ���һλ������ȣ�������ѭ����������rad��
			while (black[j] == blue[j]) {
				j++;
				//���blue����'\0'���ʹ�������rad�п����������ҵ�blue���Ϳ��Է���black��
				if (blue[j] == '\0') {
					return black;
				}
			}
		}
		i++;
	}
	//���ˣ��Ѽ���ַ���str1��δ�������ַ���
	return NULL;
}
int main() {
	char arr[20] = "abcdefghijklmnopq";
	char brr[20] = "myname";
	char crr[20] = "lmnop";
	myMemcpy(arr, brr, 6);
	printf("%s\n", arr);
	//myMemmove(arr, arr+2, 5);
	//memcpy(arr, brr, 5);
	//memmove(arr+2, arr, 5);
	//printf("%s\n", arr);
	//myMemmove(arr + 2, arr, 5);
	//printf("%s\n", arr);
	/*const char* test = myStrstr(arr, crr);
	if (test != NULL) {
		printf("%s\n%s\n", test, crr);
	}
	else {
		printf("δ�ҵ�\0");
	}
	const char* test2 = myStrstr(arr, brr);
	if (test2 != NULL) {
		printf("%s\n%s\n", test, brr);
	}
	else {
		printf("δ�ҵ�\0");
	}*/
	return 0;
}
