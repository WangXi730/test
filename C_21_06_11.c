#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//第一题
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
//第二题
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
//第三题
const char* myStrstr(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	const char* rad = str1;
	const char* blue = str2;
	//变量i是为了让rad指针往下走的
	int i = 0;
	while (rad[i] != '\0') {//如果rad结束都没有找到子字符串，就返回NULL
		//让指针rad一直走到与bule[0]相同的字符开始，
		//才可能出现子字符串，如果不相等，则i++，看下一个
		if (rad[i] == blue[0]) {
			//接下来创建一个black指针来与blue对接
			char* black = rad + i;
			//变量j是为了让blue与black可以往下走的
			int j = 0;
			//如果二者相等，就继续比较下一位，不相等，就跳出循环，接着让rad走
			while (black[j] == blue[j]) {
				j++;
				//如果blue出现'\0'，就代表着在rad中可以完整地找到blue，就可以返回black了
				if (blue[j] == '\0') {
					return black;
				}
			}
		}
		i++;
	}
	//至此，已检查字符串str1，未发现子字符串
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
		printf("未找到\0");
	}
	const char* test2 = myStrstr(arr, brr);
	if (test2 != NULL) {
		printf("%s\n%s\n", test, brr);
	}
	else {
		printf("未找到\0");
	}*/
	return 0;
}
