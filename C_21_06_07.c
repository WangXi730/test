#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�����������һ�����򵥵İ취������֮ǰ���뷨���ϰ�~
void func() {
	//����ÿ���ַ���ascll��
	//�ո���32��a��97��A��65��z��122��Z��90
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
				printf("����Ƿ������������룺");
				continue;
			}
		}
		if (b == 32) {//�ո�
			printf("C");
			break;
		}
		else if ((b <= 122 && b >= 97) || (b <= 90 && b >= 65)) {//��ĸ
			printf("B");
			break;
		}
		else if ((b <= 57 && b >= 48)) {//����
			printf("A");
			break;
		}
		else {
			printf("����Ƿ������������룺");
			continue;
		}
	}
}

//��һ�⣬����3��������С���������Ҫ����ָ�봦��
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


//��21�⣬��ָ��ָ���ָ���n��������������Ҫ�������ú�����ɣ�n�����������������룬�������������

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
	//��������end
	int end = 1;
	////��1�����
	//while (end) {
	//	int a, b, c;
	//	printf("��1�����\n���������֣�");
	//	scanf("%d%d%d", &a, &b, &c);
	//	func1(&a, &b, &c);
	//	printf("%d %d %d\n", a, b, c);
	//	printf("�Ƿ������\n1>��\n0>��\n");
	//	scanf("%d", &end);
	//}
	//end = 1;
	//��21�����
	while (end) {
		t21 arr[100];
		for (int i = 0; i < 100; i++) {
			arr[i].np = NULL;
		}
		printf("������1�����֣�");
		int lingshi = 0;
		for (int i = 0; i < 100; i++) {
			scanf("%d", &arr[i].num);
			printf("�Ƿ�������룿\n1>��\n0>��\n");
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
		printf("\n�Ƿ������\n1>��\n0>��\n");
		scanf("%d", &end);
	}

	return 0;
}