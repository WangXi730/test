#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ѡ�Եھ��µ�5��
typedef struct s {
	int num;
	char name[1024];
	double class1;
	double class2;
	double class3;
}s;
double test5_1(s t) {//��ѧ��ƽ���ɼ�
	return (t.class1 + t.class2 + t.class3) / 3;
}
s test5_2(s t[],int n) {//����������ѧ��
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
s test5_3(s t[], int n) {//��������ƽ���ɼ�
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

//ѡ�Եھ��µ�ʮһ��
typedef struct st {
	char name[20];
	int num;
	struct st* next;
}st;
//��dest��ɾ������socָ���ѧ����ͬ��
st* test9(st* dest, st* soc) {
	st* destp = dest;
	st* socp = soc;
	//���жϵ�һ���ڵ��Ƿ���Ҫɾ��
	while (destp->num == socp->num) {
		dest = dest->next;
		free(destp);
		destp = dest;
	}
	//�������ж�ʣ��ڵ�
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
	//��һ��
	s a[10];
	printf("���ǵ�һ���⣺\n");
	printf("����������:(�������� ѧ�� �ɼ�1 �ɼ�2 �ɼ�3)\n");
	for (int i = 0; i < 10; i++) {
		scanf("%s %d %lf %lf %lf", &a[i].name, &a[i].num, &a[i].class1, &a[i].class2, &a[i].class3);
		printf("��ѧ��ƽ����Ϊ��%lf\n", test5_1(a[i]));
	}
	s t = test5_2(a, 10);
	printf("�������ѧ����Ϣ���ɼ���\n����%s \nѧ��%d \n��Ŀ1 %lf \n��Ŀ2 %lf \n��Ŀ3 %lf \nƽ��%lf\n", t.name, t.num, t.class1, t.class2, t.class3,test5_1(t));
	s t2 = test5_3(a, 10);
	printf("���Ƶ�ƽ���ɼ�Ϊ��%lf %lf %lf", t2.class1, t2.class2, t2.class3);
	//�ڶ���
	printf("���ǵڶ����⣺\n");
	st* p1= (st*)malloc(sizeof(st));
	st*	p2=p1;
	st* desthead=p1;//����Ŀ������
	st* sochead;//����ɾ����Ϣ
	//���Ƚ���Ŀ������
	printf("������ѧ������Ϣ�������� ѧ�ţ�\n");
	scanf("%s %d", &p1->name, &p1->num);
	for (int i = 1; i < 5; i++)
	{
		p1 = (st*)malloc(sizeof(st));
		p2->next = p1;
		p2 = p1;
		scanf("%s %d", &p1->name, &p1->num);
	}
	//���һ���ڵ��nextΪNULL
	p1->next = NULL;
	//��ӡ����
	printf("ȷ��ѧ����Ϣ��\n");
	p1 = desthead;
	while(p1 != NULL) {
		printf("������%s\n", p1->name);
		printf("ѧ�ţ�%d\n\n", p1->num);
		p1 = p1->next;
	}
	//Ȼ��������ͬ���ķ�ʽ����һ��soc����
	p1 = (st*)malloc(sizeof(st));
	p2 = p1;
	sochead = p1;
	printf("��������Ҫɾ����ѧ������Ϣ�������� ѧ�ţ�\n");
	scanf("%s %d", &p1->name, &p1->num);
	for (int i = 1; i < 3; i++) {
		//����Ϊ3���ɣ���ʵ���㹻
		p1 = (st*)malloc(sizeof(st));
		p2->next = p1;
		p2 = p1;
		scanf("%s %d", &p1->name, &p1->num);
	}
	p1->next = NULL;
	//������ɾ��dest�Ľڵ㣬ͨ������test9
	while (sochead != NULL) {
		desthead = test9(desthead, sochead);
		sochead = sochead->next;
	}
	//�ٰѽ����ӡһ��
	printf("ȷ�Ͻ����\n");
	p1 = desthead;
	while (p1 != NULL) {
		printf("������%s\n", p1->name);
		printf("ѧ�ţ�%d\n\n", p1->num);
		p1 = p1->next;
	}
	return 0;
}