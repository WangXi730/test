#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define COL_MAX 10
#define ROW_MAX 10
#define MINE_COUNT 10
//int main() {
//	long long i = time(0);
//	printf("%d", i);
//	return 0;
//}

//int main() {
//	int a, b, c, d, e, f;
//	b = 1;
//	c = 2;
//	d = 1;
//	e = 2;
//	f = 1;
//	a = (b = c > d) && (e < f);
//	printf("%d%d%d%d%d%d",a, b, c, d, e, f);
//	return 0;
//}

//int main() {
//	/*int arr[] = { 1,2,(3,4),5 };
//	printf("%d\n", sizeof(arr));*/
//	char str[] = "hello bit";
//	printf("%d %d\n", sizeof(str), strlen(str));
//	return 0;
//}

//mine cleaner
int Menu();
void Game();

int main() {
	int a=Menu();
	if (a == 1)
		Game();
	printf("\nbyby!");
	return 0;
}
int Menu() {
//以下是修饰用的菜单面板
	printf("##########################\n");
	printf("######               #####\n");
	printf("###### 1：开始游戏   #####\n");
	printf("###### 2：退出游戏   #####\n");
	printf("######               #####\n");
	printf("##########################\n");
	printf("请选择：");
//下面这个循环的目的是为了确认玩家是否输入的是“1”或者“2”，为了使系统可以稳定运行，这个很重要
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i == 1 || i == 2) {
			break;
		}
		printf("\n输入无效，请重新输入：");
	}
	if (i == 1)
	return 1;
	return 2;
}

void Game() {
	//先来埋雷吧，在埋雷的面板（下面简称雷图）上，我们需要有雷的区域，无雷的区域
	//有雷就是有一个雷，无雷就是有零个雷，我们需要的是一个0和1的方阵，用数组实现
	int mine[ROW_MAX][COL_MAX] = { 0 };
	//方括号内可以直接用数字，不用是为了更好明确含义
	//接下类埋雷
	srand(time(0));//设置随机种子，这里采用了时间戳
	int col = 0;
	int row = 0;
	for (int i = 1; i <MINE_COUNT ;) {//这里一样可以直接用数字表示MINE_COUNT（雷的数量）
	    col = rand() % 10;
		row = rand() * rand() % 10;
		if (mine[row][col] == 1)
			continue;
		mine[row][col] = 1;
		i++;
	}
	//我们总不能吧雷图展现给玩家吧？所以需要一个展示给玩家的图，需要展示的有：未翻开区域，我们用*表示，读者随意，
	//翻开的区域需要展示给读者，这块附近有几个雷，那么需要展示数字1到8，综上所述，采用字符类型
	char show[ROW_MAX][COL_MAX] = {' '};
	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			show[i][j] = '*';
		}
	}
	while (1) {
		system("cls");
		for (int i = 0; i < ROW_MAX; i++) {
			for (int j = 0; j < COL_MAX; j++) {
				printf("%c ", show[i][j]);
			}
			printf("\n");
		}
		//接下来需要玩家输入坐标
		printf("请输入坐标：");
		while (1) {
			scanf("%d %d", &row, &col);
			if (row < ROW_MAX && col < COL_MAX)
				break;
			printf("\n输入有误，请重新输入：");
		}
		int count = 0;
		//判断游戏是否结束
		if (mine[row][col] == 1) {
			printf("Game Over! You are a loser!");
			break;
		}
		else{
			for (int i = col - 1; i <= col + 1; i++) {
				for (int j = row - 1; j <= row + 1; j++) {
					if (j<0 || i<0 || j>ROW_MAX || i>COL_MAX)
						continue;
					if(mine[j][i]==1)
					count++;
				}
			}
		}
		int win = 0;
		show[row][col] = count+48;
		for (int i = 0; i < ROW_MAX; i++) {
			for (int j = 0; j < COL_MAX; j++) {
				if (show[i][j] == '*') {
					win++;
				}
			}
		}
		if (win == MINE_COUNT) {
			printf("You are winner");
			break;
		}
	}
	printf("##########################\n");
	printf("######               #####\n");
	printf("###### 1：再来一局   #####\n");
	printf("###### 2：退出游戏   #####\n");
	printf("######               #####\n");
	printf("##########################\n");
	printf("请选择：");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i == 1 || i == 2) {
			break;
		}
		printf("\n输入无效，请重新输入：");
	}
	if (i == 1)
		Game();
}

