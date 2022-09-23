#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//ѧ����
typedef struct student {
	//ѧ��7λ���ַ�����\0��β������size��8
	char id[8];
	//���֣�һ�����ֿ���2���ֽڣ�\0ռһ���ֽڣ�����size��9
	char name[9];
	//�ɼ�
	//���ĳɼ�
	double chinese_sco;
	//��ѧ�ɼ�
	double math_sco;
	//Ӣ��ɼ�
	double english_sco;
}student;

//ʹ��list�������
typedef struct stu_list {
	student stu;
	struct stu_list* next;
	int is_head;//ͷ�����
}stu_list;

//���������õ��ĺ���
void stu_init(student* stu);//��ʼ��name��idΪ0�������ӡ
void stu_save(stu_list* sl, char* save_file);//¼��ѧ����Ϣ
stu_list* stu_load(char* save_file);//��ȡѧ����Ϣ
void stu_push(stu_list* sl, student* stu);//����һ��ѧ��
void stu_delete(stu_list* sl, char* id);//ɾ��һ��ѧ��
void stu_show(stu_list* sl);//��ʾѧ����Ϣ
student* stu_find(stu_list* sl, char* id);//����һ��ѧ��
void stu_sort(stu_list* sl);//����ѧ����Ϣ
void stul_init(stu_list* sl);


//���
void menu(stu_list* sl, char* save_file) {
	while (1) {
		//��ӡһ�����
		printf("\n");
		printf("\tѧ������ϵͳ\n");
		printf("\n");
		printf("===============================\n");
		printf("\t1��¼��ѧ������\n");
		printf("\t2��׷��ѧ������\n");
		printf("\t3���޸�ѧ������\n");
		printf("\t4��ɾ��ѧ������\n");
		printf("\t5����ʾѧ������\n");
		printf("\t6������ѧ������\n");
		printf("\t7������ѧ������\n");
		printf("\t0���˳�����\n");
		printf("===============================\n");
		printf("\n");
		printf("����������ѡ��<0-7>��");
		int choose = 0;
		scanf("%d",&choose);
		if (choose == 0) {
			return;
		}
		else if (choose == 1) {
			//��������
			stu_save(sl,save_file);
			printf("����ɹ���\n");
		}
		else if (choose == 2) {
			//��������
			student* stu = (student*)malloc(sizeof(student));
			//��ʼ��ѧ����Ϣ
			stu_init(stu);
			printf("����ѧ��������(���4����)��");
			scanf("%s", stu->name);
			printf("����ѧ����ѧ��(7λ)��");
			scanf("%s", stu->id);
			printf("����ѧ�������ĳɼ���");
			scanf("%lf", &(stu->chinese_sco));
			printf("����ѧ������ѧ�ɼ���");
			scanf("%lf", &(stu->math_sco));
			printf("����ѧ����Ӣ��ɼ���");
			scanf("%lf", &(stu->english_sco));
			stu_push(sl, stu);
			printf("�����ɹ���\n");
		}
		else if (choose == 3) {
			//�޸�ѧ������
			printf("�������޸�ѧ����ѧ�ţ�");
			char id[8] = { 0 };
			scanf("%s", id);
			//ɾ��ԭ��ѧ��
			stu_delete(sl, id);
			printf("�������޸ĺ�����ݣ�");
			student stu;
			//��ʼ��ѧ����Ϣ
			stu_init(&stu);
			printf("����(���4����)��");
			scanf("%s", stu.name);
			printf("ѧ��(7λ)��");
			scanf("%s", stu.id);
			printf("���ĳɼ���");
			scanf("%lf", &(stu.chinese_sco));
			printf("��ѧ�ɼ���");
			scanf("%lf", &(stu.math_sco));
			printf("Ӣ��ɼ���");
			scanf("%lf", &(stu.english_sco));
			//�������ѧ��
			stu_push(sl, &stu);
		}
		else if (choose == 4) {
			//ɾ��ѧ������
			printf("��Ҫɾ����ѧ��ѧ�ţ�");
			char id[8] = { 0 };
			scanf("%s", id);
			//ɾ��ѧ��
			stu_delete(sl, id);
		}
		else if (choose == 5) {
			//��ʾѧ������
			stu_show(sl);
		}
		else if (choose == 6) {
			//����ѧ������
			printf("������ѧ��ѧ�ţ�");
			char id[8] = { 0 };
			scanf("%s",id);
			student* stu = stu_find(sl, id);
			if (stu == NULL) {
				printf("�Ҳ�����Ӧѧ����\n");
				continue;
			}
			//��ӡѧ����Ϣ
			printf("������%s\n", stu->name);
			printf("ѧ�ţ�%s\n", stu->id);
			printf("��ѧ�ɼ���%lf\n", stu->math_sco);
			printf("���ĳɼ���%lf\n", stu->chinese_sco);
			printf("Ӣ��ɼ���%lf\n", stu->english_sco);
		}
		else if (choose == 7) {
			//����ѧ������
			stu_sort(sl);
			printf("������ɣ�\n");
		}
		system("pause");
		system("cls");
	}
}

//��������ʵ��
void stu_init(student* stu) {
	assert(stu != NULL);
	for (int i = 0; i < 9; ++i) {
		stu->name[i] = '\0';
	}
	stu->id[7] = '\0';
}//��ʼ��name��idΪ0�������ӡ

void stu_save(stu_list* sl, char* save_file) {
	assert(sl != NULL);
	assert(save_file != NULL);
	//���л���ʽΪ��
	//id name math chinese english
	//����
	stu_list* s = sl->next;
	int count = 0;
	while (s != NULL) {
		s = s->next;
		++count;
	}
	//����count��ѧ��������
	//����ռ�
	char* buffer = (char*)malloc((8 + 9 + 8 + 8 + 8) * count);
	//¼��
	int i = 0;//i�ǵ�ǰѧ��ǰ�����˶��ٸ�ѧ��
	sl = sl->next;//ͷ�ڵ㲻�������л�

	while (sl != NULL) {
		//�����Ƶĸ�ʽ¼�뵱ǰѧ����Ϣ
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8)], sl->stu.id, 8);
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + 8], sl->stu.name, 9);
		double a = sl->stu.math_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9)], (char*)&a, 8);
		a = sl->stu.chinese_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8)], (char*)&a, 8);
		a = sl->stu.english_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8 + 8)], (char*)&a, 8);
		++i;//i����
		sl = sl->next;
	}
	//���ļ�
	FILE* f = fopen(save_file, "wb");
	fwrite(buffer, 8 + 9 + 8 + 8 + 8, i, f);
	fclose(f);
}//¼��ѧ����Ϣ

stu_list* stu_load(char* save_file) {
	//���ļ�
	FILE* f = fopen(save_file, "rb");
	//�鿴�ļ�����
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	if (len == 0) {
		return NULL;
	}
	rewind(f);
	//��ȡ�ļ�
	char* buffer = (char*)malloc(sizeof(char) * len);
	fread(buffer, 1, len, f);
	//�ر��ļ�
	fclose(f);
	//���췵��ֵ
	stu_list* res = (stu_list*)malloc(sizeof(stu_list));
	stul_init(res);
	stu_list* tmp = res;
	//�����л�
	for (int i = 0; i < len / (8 + 9 + 8 + 8 + 8);) {
		memcpy(tmp->stu.id, buffer+i*(8+9+8+8+8), 8);
		memcpy(tmp->stu.name, buffer + i * (8 + 9 + 8 + 8 + 8) + 8, 9);
		tmp->stu.math_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9));
		tmp->stu.chinese_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8));
		tmp->stu.english_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8 + 8));
		//������һ�����
		++i;
		if (i < len / (8 + 9 + 8 + 8 + 8)) {
			tmp->next = (stu_list*)malloc(sizeof(stu_list));
			stul_init(tmp->next);
			tmp = tmp->next;
		}
	}
	//����
	return res;
}//��ȡѧ����Ϣ

void stu_push(stu_list* sl, student* stu) {
	stu_list* dest = (stu_list*)malloc(sizeof(stu_list));
	stul_init(dest);
	dest->stu = *stu;
	while (sl->next != NULL) {
		sl = sl->next;
	}
	sl->next = dest;
}//����һ��ѧ��

void stu_delete(stu_list* sl, char* id) {
	while(sl->next != NULL){
		if (strncmp(sl->next->stu.id, id, 7) == 0) {
			stu_list* tmp = sl->next;
			sl->next = tmp->next;
			free(tmp);
			return;
		}
		sl = sl->next;
	}
}//ɾ��һ��ѧ��

void stu_show(stu_list* sl) {
	printf("ѧ��\t����\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\n");
	sl = sl->next;
	while (sl != NULL) {
		printf("%s\t%s\t%lf\t%lf\t%lf\n",sl->stu.id,sl->stu.name,sl->stu.math_sco,sl->stu.chinese_sco,sl->stu.english_sco);
		sl = sl->next;
	}
}//��ʾѧ����Ϣ

student* stu_find(stu_list* sl, char* id) {
	student* res = NULL;
	sl = sl->next;
	while (sl != NULL) {
		if (strncmp(sl->stu.id, id, 7)) {
			res = &(sl->stu);
			break;
		}
	}
	return res;
}//����һ��ѧ��

void stu_sort(stu_list* sl) {
	//ð������
	sl = sl->next;
	for (stu_list* i = sl; i != NULL; i = i->next) {
		for (stu_list* j = sl; j != NULL; j = j->next) {
			if (strcmp(j->stu.id, j->next->stu.id) > 0) {
				//����ֵ
				student tmp = j->stu;
				j->stu = j->next->stu;
				j->next->stu = tmp;
			}
		}
	}
}//����ѧ����Ϣ

void stul_init(stu_list* sl) {
	sl->is_head = 0;
	sl->next = NULL;
}


int main(void) {
	char filename[] = "school.txt";
	//���ļ�
	stu_list* sl = (stu_list*)malloc(sizeof(stu_list));
	stul_init(sl);
	sl->is_head = 1;
	sl->next = stu_load(filename);

	//ʹ�ò˵�
	menu(sl,filename);

	//�ͷ���Դ
	while (sl != NULL) {
		stu_list* tmp = sl;
		sl = sl->next;
		free(tmp);
	}
	/*student b;
	b.math_sco = 1.2;
	scanf("%lf", &b.math_sco);
	double a = b.math_sco;
	char arr[8] = { 0 };
	strncpy(&arr[0], (char*)&a, 8);*/
	return 0;
}