#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int account1(int a) {
    if (a < 10000)
        return a + account1(a * 10 + a % 10);
    return a;
}

//����λ�������
int account2(int a) {
    if (a / 10 == 0)
        return 1;
    return 1 + account2(a / 10);
}

//���������һ�����ĸ�λ��n�η������
int account5(int a, int n) {
    if (a / 10)
    a = a % 10;
    if (n > 1)
        return a * account5(a, n - 1);
    return a;
}

//������������λ����n�η�֮��
int account4(int a, int n) {
    if (a > 0)
        return account4(a / 10, n) + account5(a, n);
        //account5�����������λ��n�η�
    return 0;
}

//��������������ˮ�ɻ���
int account3(int a) {
    int n = account2(a);//n��a��λ��
    n = account4(a, n);//������Ǹ�λ����n�η�֮��
    if (n == a)
        return a;
    return 0;
}
int main() {
    char arr[13] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '  };
    for (int i = 0; i <6 ; i ++ ) {
        arr[6 + i] = '*';
        arr[6 - i] = '*';
        for (int j = 0; j < 13; j++) {
            printf("%c",arr[j]);
        }
        printf("\n");
    }
    for (int i = 1; i < 6; i++) {
        arr[i] = ' ';
        arr[12 - i] = ' ';
        for (int j = 0; j < 13; j++) {
            printf("%c",arr[j]);
        }
        printf("\n");
    }

    //������еġ�ˮ�ɻ�����
    //int a = 0;
    //for (int i = 0; i <= 100000; i++) {
    //    a = account3(i);
    //    if (i == 0)
    //        printf("%d ", a);
    //    if (a)
    //        printf("%d ",a);
    //}
    return 0;
}