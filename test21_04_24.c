#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COL 3;
#define ROW 3;

////非递归实现strlen函数求字符长度
//int  strlen1(char a[]) {
//	int i = 0;
//	while (a[i]!='\0') {
//		i++;
//		}
//	return i;
//}
////递归实现strlen函数求字符串长度
//int strlen2(char a[]) {
//	static int i = 0;
//	if (a[i] == '\0')
//		return 0;
//	i++;
//	return 1 + strlen2(a);
//}
////演示
//int main(){
//	char a[]="abcdef";
//	int i = strlen1(a);
//	printf("%d\n",i);
//    i = strlen2(a);
//	printf("%d",i);
//	return 0;
//	}

////实现数组的逆置
//	int i = -1;
//void reverse_string(char arr[],int n) {
//	i++;
//	if (i < n / 2) {
//    char cup = arr[i];
//	arr[i] = arr[n - i - 1];
//	arr[n - i - 1] = cup;
//	reverse_string(arr, n);
//	}
//}
//int main() {
//	char arr[] = "abcdef";
//	int n = sizeof(arr) / sizeof(arr[0])-1;
//	reverse_string(arr,n);
//	printf("%s", arr);
//	return 0;
//}

////实现非负整数的各个位数之和
//int i = 0;
//DigitSum(int n) {
//	if (n / 10 > 0) 
//		i = n % 10 + DigitSum(n / 10);
//	else
//		i=n%10;
//	return i;
//}
//int main() {
//	int n = 5689;
//	int t=DigitSum(n);
//	printf("%d", t);
//	return 0;
//}

////递归实现n的k次方
//int nk(int n,int k) {
//	if(k == 1)
//	return n;
//	return n * nk(n, k - 1);
//}
//int main() {
//	int t = nk(3, 3);
//	printf("%d", t);
//}

////递归实现求斐波那契数
//int F1(int n) {
//	if (n == 1 || n == 2)
//		return 1;
//	return F1(n - 1) + F1(n - 2);
//}
////非递归实现求斐波那契数
//int F2(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	int i = 1, j = 0, t = 0;
//	for (int r=1; r< n;r++) {
//		t = i + j;
//		j = i;
//		i = t;
//	}
//	return t;
//}
//int main() {
//    int n=0 ;
//BEGIN:
//	printf("请输入：");
//	scanf("%d", &n);
//	int t1 = F1(n);
//	int t2 = F2(n);
//	printf("递归函数得：%d\n非递归函数得：%d\n输入“1”继续，其他退出：", t1, t2);
//	int t = 0;
//	scanf("%d", &t);
//	if (t == 1)
//		goto BEGIN;
//	return 0;
//}

////三子棋游戏
//void Game();
//int Menu() {
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1：开始游戏   #####\n");
//	printf("###### 2：退出游戏   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("请选择：");
//	int i = 0;
//	while (1) {
//		scanf("%d", &i);
//		if (i == 1 || i == 2) {
//			break;
//		}
//		printf("\n输入无效，请重新输入：");
//	}
//	if (i == 1)
//	return 1;
//	return 2;
//}
//void PVE() {
//	int arr[3][3] = { { ' ',' ',' ' } ,{' ', ' ', ' '}, {' ', ' ', ' '} };
//	//胜负判别
//	char win = ' ';
//	//落子的坐标定义
//	int i = 0;
//	int j = 0;
//	//打印棋盘
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//	printf("\n+---+---+---+\n");
//	while (1) {
//		//玩家落子
//		printf("请落子：");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'x';
//				break;
//			}
//			printf("\n请重新输入：");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//判定胜负
//		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' && arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' && arr[2][1] != ' ' && arr[2][0] != ' ' && arr[2][2] != ' ') {
//            win = '0';
//			break;
//		}
//		//电脑落子 
//		while (1) {
//			i = (time(0) % 3);
//			j = ((time(0)*time(0)) % 3);
//			if (arr[i][j] == ' ') {
//				arr[i][j] = 'o';
//				break;
//			}
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//判定胜负
//		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' && arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' && arr[2][1] != ' ' && arr[2][0] != ' ' && arr[2][2] != ' ') {
//			win = '0';
//			break;
//		}
//	}
//	if (win == 'o') {
//		printf("\n不会吧？不会吧！不会真的有人输给人工智障吧？\n");
//	}
//	else if (win == 'x') {
//		printf("\n恭喜获胜！！！\n");
//	}
//	else {
//		printf("\n恭喜您与人工智障打成平手！！！\n");
//	}	
//	int re = 0;
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1；返回菜单   #####\n");
//	printf("###### 2：再来一次   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("请选择：");
//	while (1) {
//     scanf("%d", &re);
//	 if (re == 1 || re == 2)
//		 break;
//	 printf("\n输入违法，请重新输入：");
//	}
//	if (re == 1) {
//		re=Menu();
//		if (re == 1) {
//			Game();
//		}
//	}
//	else if (re == 2) {
//		PVE();
//	}
//}
//
//void PVP() {
//	int arr[3][3] = { { ' ',' ',' ' } ,{' ', ' ', ' '}, {' ', ' ', ' '} };
//	//胜负判别
//	char win = ' ';
//	//落子的坐标定义
//	int i = 0;
//	int j = 0;
//	//打印棋盘
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//	printf("\n+---+---+---+\n");
//	while (1) {
//		//玩家p1落子
//		printf("P1玩家请落子：");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'x';
//				break;
//			}
//			printf("\nP1玩家请重新输入：");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//判定胜负
//		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'x') {
//			win = 'x';
//			break;
//		}
//		else if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' && arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' && arr[2][1] != ' ' && arr[2][0] != ' ' && arr[2][2] != ' ') {
//			win = '0';
//			break;
//		}
//		//玩家p2落子 
//		printf("P2玩家请落子：");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'o';
//				break;
//			}
//			printf("\nP2玩家请重新输入：");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//判定胜负
//		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == '0') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'o') {
//			win = 'o';
//			break;
//		}
//		else if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' && arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' && arr[2][1] != ' ' && arr[2][0] != ' ' && arr[2][2] != ' ') {
//			win = '0';
//			break;
//		}
//	}
//	if (win == 'o') {
//		printf("\nP2获得胜利！！！\n");
//	}
//	else if (win == 'x') {
//		printf("\nP1获得胜利！！！\n");
//	}
//	else {
//		printf("\n平手！！！\n");
//	}
//	int re = 0;
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1；返回菜单   #####\n");
//	printf("###### 2：再来一次   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("请选择：");
//	while (1) {
//		scanf("%d", &re);
//		if (re == 1 || re == 2)
//			break;
//		printf("\n输入违法，请重新输入：");
//	}
//	if (re == 1) {
//		re = Menu();
//		if (re == 1) {
//			Game();
//		}
//	}
//	else if (re == 2) {
//		PVP();
//	}
//}
//
//void Game() {
//	char arr[3][3] = {{ ' ',' ',' ' } ,{' ', ' ', ' '}, {' ', ' ', ' '}};
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1：人机对战   #####\n");
//	printf("###### 2：双人对战   #####\n");
//	printf("###### 3：退出游戏   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("请选择：");
//	int choose = 0;
//	while (1) {
//    scanf("%d", &choose);
//	if (choose == 1 || choose == 2||choose==3)
//		break;
//	printf("\n输入无效，请重新输入：");
//	}
//	if (choose == 1)
//		PVE();
//	if (choose == 2)
//		PVP();
//}
//int main() {
//	int i=Menu();
//	if (i == 1) {
//		Game();
//	}
//		printf("再见");
//	return 0;
//}
//
