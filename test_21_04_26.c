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
//�����������õĲ˵����
	printf("##########################\n");
	printf("######               #####\n");
	printf("###### 1����ʼ��Ϸ   #####\n");
	printf("###### 2���˳���Ϸ   #####\n");
	printf("######               #####\n");
	printf("##########################\n");
	printf("��ѡ��");
//�������ѭ����Ŀ����Ϊ��ȷ������Ƿ�������ǡ�1�����ߡ�2����Ϊ��ʹϵͳ�����ȶ����У��������Ҫ
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i == 1 || i == 2) {
			break;
		}
		printf("\n������Ч�����������룺");
	}
	if (i == 1)
	return 1;
	return 2;
}

void Game() {
	//�������װɣ������׵���壨��������ͼ���ϣ�������Ҫ���׵��������׵�����
	//���׾�����һ���ף����׾���������ף�������Ҫ����һ��0��1�ķ���������ʵ��
	int mine[ROW_MAX][COL_MAX] = { 0 };
	//�������ڿ���ֱ�������֣�������Ϊ�˸�����ȷ����
	//����������
	srand(time(0));//����������ӣ����������ʱ���
	int col = 0;
	int row = 0;
	for (int i = 1; i <MINE_COUNT ;) {//����һ������ֱ�������ֱ�ʾMINE_COUNT���׵�������
	    col = rand() % 10;
		row = rand() * rand() % 10;
		if (mine[row][col] == 1)
			continue;
		mine[row][col] = 1;
		i++;
	}
	//�����ܲ��ܰ���ͼչ�ָ���Ұɣ�������Ҫһ��չʾ����ҵ�ͼ����Ҫչʾ���У�δ��������������*��ʾ���������⣬
	//������������Ҫչʾ�����ߣ���鸽���м����ף���ô��Ҫչʾ����1��8�����������������ַ�����
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
		//��������Ҫ�����������
		printf("���������꣺");
		while (1) {
			scanf("%d %d", &row, &col);
			if (row < ROW_MAX && col < COL_MAX)
				break;
			printf("\n�����������������룺");
		}
		int count = 0;
		//�ж���Ϸ�Ƿ����
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
	printf("###### 1������һ��   #####\n");
	printf("###### 2���˳���Ϸ   #####\n");
	printf("######               #####\n");
	printf("##########################\n");
	printf("��ѡ��");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i == 1 || i == 2) {
			break;
		}
		printf("\n������Ч�����������룺");
	}
	if (i == 1)
		Game();
}

