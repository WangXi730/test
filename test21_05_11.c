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

//计算位数并输出
int account2(int a) {
    if (a / 10 == 0)
        return 1;
    return 1 + account2(a / 10);
}

//这个函数求一个数的个位的n次方并输出
int account5(int a, int n) {
    if (a / 10)
    a = a % 10;
    if (n > 1)
        return a * account5(a, n - 1);
    return a;
}

//这个用来输出各位数的n次方之和
int account4(int a, int n) {
    if (a > 0)
        return account4(a / 10, n) + account5(a, n);
        //account5的作用是求个位的n次方
    return 0;
}

//这个函数用来输出水仙花数
int account3(int a) {
    int n = account2(a);//n是a的位数
    n = account4(a, n);//输出的是各位数的n次方之和
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

    //输出所有的“水仙花数”
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