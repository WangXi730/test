#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//学生类
typedef struct student {
	//学号7位，字符串以\0结尾，所以size给8
	char id[8];
	//名字，一个汉字可能2个字节，\0占一个字节，所以size给9
	char name[9];
	//成绩
	//语文成绩
	double chinese_sco;
	//数学成绩
	double math_sco;
	//英语成绩
	double english_sco;
}student;

//使用list存放数据
typedef struct stu_list {
	student stu;
	struct stu_list* next;
	int is_head;//头结点标记
}stu_list;

//声明将会用到的函数
void stu_init(student* stu);//初始化name和id为0，方便打印
void stu_save(stu_list* sl, char* save_file);//录入学生信息
stu_list* stu_load(char* save_file);//读取学生信息
void stu_push(stu_list* sl, student* stu);//新增一个学生
void stu_delete(stu_list* sl, char* id);//删除一个学生
void stu_show(stu_list* sl);//显示学生信息
student* stu_find(stu_list* sl, char* id);//查找一个学生
void stu_sort(stu_list* sl);//排序学生信息
void stul_init(stu_list* sl);


//面板
void menu(stu_list* sl, char* save_file) {
	while (1) {
		//打印一个面板
		printf("\n");
		printf("\t学生管理系统\n");
		printf("\n");
		printf("===============================\n");
		printf("\t1、录入学生数据\n");
		printf("\t2、追加学生数据\n");
		printf("\t3、修改学生数据\n");
		printf("\t4、删除学生数据\n");
		printf("\t5、显示学生数据\n");
		printf("\t6、查找学生数据\n");
		printf("\t7、排序学生数据\n");
		printf("\t0、退出程序\n");
		printf("===============================\n");
		printf("\n");
		printf("请输入您的选择<0-7>：");
		int choose = 0;
		scanf("%d",&choose);
		if (choose == 0) {
			return;
		}
		else if (choose == 1) {
			//保存数据
			stu_save(sl,save_file);
			printf("保存成功！\n");
		}
		else if (choose == 2) {
			//新增数据
			student* stu = (student*)malloc(sizeof(student));
			//初始化学生信息
			stu_init(stu);
			printf("新增学生的姓名(最多4个字)：");
			scanf("%s", stu->name);
			printf("新增学生的学号(7位)：");
			scanf("%s", stu->id);
			printf("新增学生的语文成绩：");
			scanf("%lf", &(stu->chinese_sco));
			printf("新增学生的数学成绩：");
			scanf("%lf", &(stu->math_sco));
			printf("新增学生的英语成绩：");
			scanf("%lf", &(stu->english_sco));
			stu_push(sl, stu);
			printf("操作成功！\n");
		}
		else if (choose == 3) {
			//修改学生数据
			printf("请输入修改学生的学号：");
			char id[8] = { 0 };
			scanf("%s", id);
			//删除原有学生
			stu_delete(sl, id);
			printf("请输入修改后的数据：");
			student stu;
			//初始化学生信息
			stu_init(&stu);
			printf("姓名(最多4个字)：");
			scanf("%s", stu.name);
			printf("学号(7位)：");
			scanf("%s", stu.id);
			printf("语文成绩：");
			scanf("%lf", &(stu.chinese_sco));
			printf("数学成绩：");
			scanf("%lf", &(stu.math_sco));
			printf("英语成绩：");
			scanf("%lf", &(stu.english_sco));
			//新增这个学生
			stu_push(sl, &stu);
		}
		else if (choose == 4) {
			//删除学生数据
			printf("需要删除的学生学号：");
			char id[8] = { 0 };
			scanf("%s", id);
			//删除学生
			stu_delete(sl, id);
		}
		else if (choose == 5) {
			//显示学生数据
			stu_show(sl);
		}
		else if (choose == 6) {
			//查找学生数据
			printf("请输入学生学号：");
			char id[8] = { 0 };
			scanf("%s",id);
			student* stu = stu_find(sl, id);
			if (stu == NULL) {
				printf("找不到对应学生！\n");
				continue;
			}
			//打印学生信息
			printf("姓名：%s\n", stu->name);
			printf("学号：%s\n", stu->id);
			printf("数学成绩：%lf\n", stu->math_sco);
			printf("语文成绩：%lf\n", stu->chinese_sco);
			printf("英语成绩：%lf\n", stu->english_sco);
		}
		else if (choose == 7) {
			//排序学生数据
			stu_sort(sl);
			printf("排序完成！\n");
		}
		system("pause");
		system("cls");
	}
}

//函数具体实现
void stu_init(student* stu) {
	assert(stu != NULL);
	for (int i = 0; i < 9; ++i) {
		stu->name[i] = '\0';
	}
	stu->id[7] = '\0';
}//初始化name和id为0，方便打印

void stu_save(stu_list* sl, char* save_file) {
	assert(sl != NULL);
	assert(save_file != NULL);
	//序列化格式为：
	//id name math chinese english
	//遍历
	stu_list* s = sl->next;
	int count = 0;
	while (s != NULL) {
		s = s->next;
		++count;
	}
	//现在count是学生的数量
	//申请空间
	char* buffer = (char*)malloc((8 + 9 + 8 + 8 + 8) * count);
	//录入
	int i = 0;//i是当前学生前面存放了多少个学生
	sl = sl->next;//头节点不进行序列化

	while (sl != NULL) {
		//二进制的格式录入当前学生信息
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8)], sl->stu.id, 8);
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + 8], sl->stu.name, 9);
		double a = sl->stu.math_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9)], (char*)&a, 8);
		a = sl->stu.chinese_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8)], (char*)&a, 8);
		a = sl->stu.english_sco;
		memcpy(&buffer[i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8 + 8)], (char*)&a, 8);
		++i;//i迭代
		sl = sl->next;
	}
	//打开文件
	FILE* f = fopen(save_file, "wb");
	fwrite(buffer, 8 + 9 + 8 + 8 + 8, i, f);
	fclose(f);
}//录入学生信息

stu_list* stu_load(char* save_file) {
	//打开文件
	FILE* f = fopen(save_file, "rb");
	//查看文件长度
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	if (len == 0) {
		return NULL;
	}
	rewind(f);
	//读取文件
	char* buffer = (char*)malloc(sizeof(char) * len);
	fread(buffer, 1, len, f);
	//关闭文件
	fclose(f);
	//构造返回值
	stu_list* res = (stu_list*)malloc(sizeof(stu_list));
	stul_init(res);
	stu_list* tmp = res;
	//反序列化
	for (int i = 0; i < len / (8 + 9 + 8 + 8 + 8);) {
		memcpy(tmp->stu.id, buffer+i*(8+9+8+8+8), 8);
		memcpy(tmp->stu.name, buffer + i * (8 + 9 + 8 + 8 + 8) + 8, 9);
		tmp->stu.math_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9));
		tmp->stu.chinese_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8));
		tmp->stu.english_sco = *(double*)(buffer + i * (8 + 9 + 8 + 8 + 8) + (8 + 9 + 8 + 8));
		//创造下一个结点
		++i;
		if (i < len / (8 + 9 + 8 + 8 + 8)) {
			tmp->next = (stu_list*)malloc(sizeof(stu_list));
			stul_init(tmp->next);
			tmp = tmp->next;
		}
	}
	//返回
	return res;
}//读取学生信息

void stu_push(stu_list* sl, student* stu) {
	stu_list* dest = (stu_list*)malloc(sizeof(stu_list));
	stul_init(dest);
	dest->stu = *stu;
	while (sl->next != NULL) {
		sl = sl->next;
	}
	sl->next = dest;
}//新增一个学生

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
}//删除一个学生

void stu_show(stu_list* sl) {
	printf("学号\t姓名\t数学成绩\t语文成绩\t英语成绩\n");
	sl = sl->next;
	while (sl != NULL) {
		printf("%s\t%s\t%lf\t%lf\t%lf\n",sl->stu.id,sl->stu.name,sl->stu.math_sco,sl->stu.chinese_sco,sl->stu.english_sco);
		sl = sl->next;
	}
}//显示学生信息

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
}//查找一个学生

void stu_sort(stu_list* sl) {
	//冒泡排序
	sl = sl->next;
	for (stu_list* i = sl; i != NULL; i = i->next) {
		for (stu_list* j = sl; j != NULL; j = j->next) {
			if (strcmp(j->stu.id, j->next->stu.id) > 0) {
				//交换值
				student tmp = j->stu;
				j->stu = j->next->stu;
				j->next->stu = tmp;
			}
		}
	}
}//排序学生信息

void stul_init(stu_list* sl) {
	sl->is_head = 0;
	sl->next = NULL;
}


int main(void) {
	char filename[] = "school.txt";
	//读文件
	stu_list* sl = (stu_list*)malloc(sizeof(stu_list));
	stul_init(sl);
	sl->is_head = 1;
	sl->next = stu_load(filename);

	//使用菜单
	menu(sl,filename);

	//释放资源
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