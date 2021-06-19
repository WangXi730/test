#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//选自第九章第5题
typedef struct s {
	int num;
	char name[1024];
	double class1;
	double class2;
	double class3;
}s;
double test5_1(s t) {//求学生平均成绩
	return (t.class1 + t.class2 + t.class3) / 3;
}
s test5_2(s t[],int n) {//计算最优秀学生
	s best = t[0];
	for (int i = 1; i < n; i++) {
		if (test5_1(best) < test5_1(t[i])) {
			best.class1 = t[i].class1;
			best.class2 = t[i].class2;
			best.class3 = t[i].class3;
			strcpy(best.name, t[i].name);
			best.num = t[i].num;
		}
	}
	return best;
}
s test5_3(s t[], int n) {//计算三科平均成绩
	s r;
	double p = 0;
	for (int i = 0; i < n; i++) {
		p += t[i].class1;
	}
	r.class1 = p / n;
	p = 0;
	for (int i = 0; i < n; i++) {
		p += t[i].class2;
	}
	r.class2 = p / n;
	p = 0;
	for (int i = 0; i < n; i++) {
		p += t[i].class3;
	}
	r.class3 = p / n;
	return r;
}

//选自第九章第十一题
typedef struct st {
	char name[20];
	int num;
	struct st* next;
}st;
//从dest中删除掉与soc指向的学号相同的
st* test9(st* dest, st* soc) {
	st* destp = dest;
	st* socp = soc;
	//先判断第一个节点是否需要删除
	while (destp->num == socp->num) {
		dest = dest->next;
		free(destp);
		destp = dest;
	}
	//接下来判断剩余节点
	while (destp->next != NULL) {
		if ((destp->next)->num == socp->num) {
			st* cup = destp->next;
			destp->next = (dest->next)->next;
			free(cup);
			cup = NULL;
		}
		destp = destp->next;
	}
	return dest;
}

int main() {
	//第一个
	s a[10];
	printf("这是第一个题：\n");
	printf("请输入数据:(按照名字 学号 成绩1 成绩2 成绩3)\n");
	for (int i = 0; i < 10; i++) {
		scanf("%s %d %lf %lf %lf", &a[i].name, &a[i].num, &a[i].class1, &a[i].class2, &a[i].class3);
		printf("该学生平均分为：%lf\n", test5_1(a[i]));
	}
	s t = test5_2(a, 10);
	printf("最优秀的学生信息及成绩：\n名字%s \n学号%d \n科目1 %lf \n科目2 %lf \n科目3 %lf \n平均%lf\n", t.name, t.num, t.class1, t.class2, t.class3,test5_1(t));
	s t2 = test5_3(a, 10);
	printf("各科的平均成绩为：%lf %lf %lf", t2.class1, t2.class2, t2.class3);
	//第二个
	printf("这是第二个题：\n");
	st* p1= (st*)malloc(sizeof(st));
	st*	p2=p1;
	st* desthead=p1;//这是目标链表
	st* sochead;//这是删除信息
	//首先建立目标链表
	printf("请输入学生的信息：（名字 学号）\n");
	scanf("%s %d", &p1->name, &p1->num);
	for (int i = 1; i < 5; i++)
	{
		p1 = (st*)malloc(sizeof(st));
		p2->next = p1;
		p2 = p1;
		scanf("%s %d", &p1->name, &p1->num);
	}
	//最后一个节点的next为NULL
	p1->next = NULL;
	//打印出来
	printf("确认学生信息：\n");
	p1 = desthead;
	while(p1 != NULL) {
		printf("姓名：%s\n", p1->name);
		printf("学号：%d\n\n", p1->num);
		p1 = p1->next;
	}
	//然后我们以同样的方式创建一个soc链表
	p1 = (st*)malloc(sizeof(st));
	p2 = p1;
	sochead = p1;
	printf("请输入需要删除的学生的信息：（名字 学号）\n");
	scanf("%s %d", &p1->name, &p1->num);
	for (int i = 1; i < 3; i++) {
		//设置为3个吧，于实验足够
		p1 = (st*)malloc(sizeof(st));
		p2->next = p1;
		p2 = p1;
		scanf("%s %d", &p1->name, &p1->num);
	}
	p1->next = NULL;
	//接下来删除dest的节点，通过函数test9
	while (sochead != NULL) {
		desthead = test9(desthead, sochead);
		sochead = sochead->next;
	}
	//再把结果打印一遍
	printf("确认结果；\n");
	p1 = desthead;
	while (p1 != NULL) {
		printf("姓名：%s\n", p1->name);
		printf("学号：%d\n\n", p1->num);
		p1 = p1->next;
	}
	return 0;
}