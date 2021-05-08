#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void printMAT(int *arr,int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }
}
void contra(int* arr, int n) {
    int cup = 0;
    for (int i = 0; i < n / 2; i++) {
        cup = arr[i];
        arr[i] = arr [n - 1 - i];
        arr[n - 1 - i] = cup;
    }
}
void year(int n) {
    int a = 0;
    if (n % 400 == 0)
        a = 1;
    else if (n % 100 != 0 && n % 4 == 0)
        a = 1;
    else
        a = 0;
    if (a)
        printf("是闰年\n");
    else
        printf("不是闰年\n");
}

int panduan(int n) {
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void printsushu(int n) {
    int i = panduan(n);
    if (i)
        printf("%d ", n);
}

int main() {
    int a = 0;
    //for (int i = 100; i <= 200; i++) {
    //    printsushu(i);
    //}
    int i = 1;
    for (; i;) {
        scanf("%d", &a);
        year(a);
    }
   
    //int arr[6] = { 0,1,2,3,4,5 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    //printMAT(arr, n);
    //contra(arr, n);
    //printf("\n");
    //printMAT(arr, n);
    //int arr[] = { 1,2,3,4,5 };
    //short* p = (short*)arr;
    //int i = 0;
    //for (i = 0; i < 4; i++)
    //{
    //    *(p + i) = 0;
    //}

    //for (i = 0; i < 5; i++)
    //{
    //    printf("%d ", arr[i]);
    //}
    //return 0;
    //int a = 0x11223344;
    //char* pc = (char*)&a;
    //*pc = 0;
    //printf("%x\n", a);
    //return 0;
    return 0;
}