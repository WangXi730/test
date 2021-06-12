#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//由于我想出了一个更简单的办法，所以之前的想法作废啊~
void func() {
	//按照每个字符的ascll码
	//空格是32，a是97，A是65，z是122，Z是90
	while (1) {
		char a = getchar();
		int b = (int)a;
		if (b == 45) {
			b=getchar();
			if ((b <= 57 && b >= 48)) {
				printf("A");
				break;
			}
			else {
				printf("输入非法，请重新输入：");
				continue;
			}
		}
		if (b == 32) {//空格
			printf("C");
			break;
		}
		else if ((b <= 122 && b >= 97) || (b <= 90 && b >= 65)) {//字母
			printf("B");
			break;
		}
		else if ((b <= 57 && b >= 48)) {//数字
			printf("A");
			break;
		}
		else {
			printf("输入非法，请重新输入：");
			continue;
		}
	}
}

//第一题，输入3个数，从小到大输出，要求用指针处理
void func1(int* a,int* b,int* c) {
	int cup = 0;
	if (*a > *b) {
		cup = *a;
		*a = *b;
		*b = *c;
	}
	if (*a > *c) {
		cup = *a;
		*a = *c;
		*c = cup;
	}
	if (*b > *c) {
		cup = *b;
		*b = *c;
		*c = cup;
	}
}


//第21题，用指向指针的指针对n个整数进行排序，要求排序用函数完成，n个数在主函数中输入，在主函数中输出

typedef struct t21 {
	int num;
	struct t21* np;
}t21;

void func21(t21**p,int n) {
	t21* t1 = *p;
	while (n) {
		while ((*p)->np != NULL) {
			if ((*p)->num > (*p)->np->num) {
				t21* cup = (*p);
				(*p) = (*p)->np;
				cup->np = (*p)->np;
				(*p)->np = cup;
		     }
		}
		n--;
		p = &t1;
	}	
}

int main() {
	//结束变量end
	int end = 1;
	////第1题测试
	//while (end) {
	//	int a, b, c;
	//	printf("第1题测试\n请输入数字：");
	//	scanf("%d%d%d", &a, &b, &c);
	//	func1(&a, &b, &c);
	//	printf("%d %d %d\n", a, b, c);
	//	printf("是否继续？\n1>是\n0>否\n");
	//	scanf("%d", &end);
	//}
	//end = 1;
	//第21题测试
	while (end) {
		t21 arr[100];
		for (int i = 0; i < 100; i++) {
			arr[i].np = NULL;
		}
		printf("请输入1个数字：");
		int lingshi = 0;
		for (int i = 0; i < 100; i++) {
			scanf("%d", &arr[i].num);
			printf("是否继续输入？\n1>是\n0>否\n");
			scanf("%d", &end);
			arr[i].np = &arr[i + 1];
			lingshi = i;
			if (end == 0)
				break;
		}
		arr[lingshi].np = NULL;
		t21* p = arr;
		func21(&p, lingshi);
		for (int i = 0; i < 100; i++) {
			printf("%d ", p->num);
			if (p == NULL)
				break;
		}
		printf("\n是否继续？\n1>是\n0>否\n");
		scanf("%d", &end);
	}

	return 0;
}