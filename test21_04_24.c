#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COL 3;
#define ROW 3;

////�ǵݹ�ʵ��strlen�������ַ�����
//int  strlen1(char a[]) {
//	int i = 0;
//	while (a[i]!='\0') {
//		i++;
//		}
//	return i;
//}
////�ݹ�ʵ��strlen�������ַ�������
//int strlen2(char a[]) {
//	static int i = 0;
//	if (a[i] == '\0')
//		return 0;
//	i++;
//	return 1 + strlen2(a);
//}
////��ʾ
//int main(){
//	char a[]="abcdef";
//	int i = strlen1(a);
//	printf("%d\n",i);
//    i = strlen2(a);
//	printf("%d",i);
//	return 0;
//	}

////ʵ�����������
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

////ʵ�ַǸ������ĸ���λ��֮��
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

////�ݹ�ʵ��n��k�η�
//int nk(int n,int k) {
//	if(k == 1)
//	return n;
//	return n * nk(n, k - 1);
//}
//int main() {
//	int t = nk(3, 3);
//	printf("%d", t);
//}

////�ݹ�ʵ����쳲�������
//int F1(int n) {
//	if (n == 1 || n == 2)
//		return 1;
//	return F1(n - 1) + F1(n - 2);
//}
////�ǵݹ�ʵ����쳲�������
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
//	printf("�����룺");
//	scanf("%d", &n);
//	int t1 = F1(n);
//	int t2 = F2(n);
//	printf("�ݹ麯���ã�%d\n�ǵݹ麯���ã�%d\n���롰1�������������˳���", t1, t2);
//	int t = 0;
//	scanf("%d", &t);
//	if (t == 1)
//		goto BEGIN;
//	return 0;
//}

////��������Ϸ
//void Game();
//int Menu() {
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1����ʼ��Ϸ   #####\n");
//	printf("###### 2���˳���Ϸ   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("��ѡ��");
//	int i = 0;
//	while (1) {
//		scanf("%d", &i);
//		if (i == 1 || i == 2) {
//			break;
//		}
//		printf("\n������Ч�����������룺");
//	}
//	if (i == 1)
//	return 1;
//	return 2;
//}
//void PVE() {
//	int arr[3][3] = { { ' ',' ',' ' } ,{' ', ' ', ' '}, {' ', ' ', ' '} };
//	//ʤ���б�
//	char win = ' ';
//	//���ӵ����궨��
//	int i = 0;
//	int j = 0;
//	//��ӡ����
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//	printf("\n+---+---+---+\n");
//	while (1) {
//		//�������
//		printf("�����ӣ�");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'x';
//				break;
//			}
//			printf("\n���������룺");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//�ж�ʤ��
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
//		//�������� 
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
//		//�ж�ʤ��
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
//		printf("\n����ɣ�����ɣ����������������˹����ϰɣ�\n");
//	}
//	else if (win == 'x') {
//		printf("\n��ϲ��ʤ������\n");
//	}
//	else {
//		printf("\n��ϲ�����˹����ϴ��ƽ�֣�����\n");
//	}	
//	int re = 0;
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1�����ز˵�   #####\n");
//	printf("###### 2������һ��   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("��ѡ��");
//	while (1) {
//     scanf("%d", &re);
//	 if (re == 1 || re == 2)
//		 break;
//	 printf("\n����Υ�������������룺");
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
//	//ʤ���б�
//	char win = ' ';
//	//���ӵ����궨��
//	int i = 0;
//	int j = 0;
//	//��ӡ����
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//	printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//	printf("\n+---+---+---+\n");
//	while (1) {
//		//���p1����
//		printf("P1��������ӣ�");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'x';
//				break;
//			}
//			printf("\nP1������������룺");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//�ж�ʤ��
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
//		//���p2���� 
//		printf("P2��������ӣ�");
//		while (1) {
//			scanf("%d%d", &i, &j);
//			if (i < 3 && j < 3 && arr[i][j] == ' ') {
//				arr[i][j] = 'o';
//				break;
//			}
//			printf("\nP2������������룺");
//		}
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[0][0], arr[0][1], arr[0][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[1][0], arr[1][1], arr[1][2]);
//		printf("\n+---+---+---+\n| %c | %c | %c |", arr[2][0], arr[2][1], arr[2][2]);
//		printf("\n+---+---+---+\n");
//		//�ж�ʤ��
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
//		printf("\nP2���ʤ��������\n");
//	}
//	else if (win == 'x') {
//		printf("\nP1���ʤ��������\n");
//	}
//	else {
//		printf("\nƽ�֣�����\n");
//	}
//	int re = 0;
//	printf("##########################\n");
//	printf("######               #####\n");
//	printf("###### 1�����ز˵�   #####\n");
//	printf("###### 2������һ��   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("��ѡ��");
//	while (1) {
//		scanf("%d", &re);
//		if (re == 1 || re == 2)
//			break;
//		printf("\n����Υ�������������룺");
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
//	printf("###### 1���˻���ս   #####\n");
//	printf("###### 2��˫�˶�ս   #####\n");
//	printf("###### 3���˳���Ϸ   #####\n");
//	printf("######               #####\n");
//	printf("##########################\n");
//	printf("��ѡ��");
//	int choose = 0;
//	while (1) {
//    scanf("%d", &choose);
//	if (choose == 1 || choose == 2||choose==3)
//		break;
//	printf("\n������Ч�����������룺");
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
//		printf("�ټ�");
//	return 0;
//}
//
