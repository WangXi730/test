#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void Paiming(int arr[5][2][2]) {
//	int ture[] = { 0,0,0,0,0};//ture[i]=j�����i�����ǵ�j��
//	int w = 1;
//	while (w) {//ѡ��һ����ȷ������
//		for (int i = 0; i < 5; i++) {
//			ture[i] = 0;//��ture ��ʼ��
//		}
//		//�Ա���ÿ���˵�һ�仰������Ƿ���ȷ
//		for (int i = 0; i < 5; i++) {
//					ture[arr[i][0][0]-1] = arr[i][0][1];
//			}
//		int t = 0;
//		for (t = 0; t < 5; t++) {
//			if (ture[t] == 0)
//				break;
//		}
//		if (t == 5) {//��������Ƿ����
//			for (int i = 0; i < 5; i++) {
//				if (ture[i] == 5) {
//					for (int i = 0; i < 5; i++) {
//						if (ture[i] == 4) {
//							for (int i = 0; i < 5; i++) {
//								if (ture[i] == 3) {
//									for (int i = 0; i < 5; i++) {
//										if (ture[i] == 2) {
//											for (int i = 0; i < 5; i++) {
//												if (ture[i] == 1) {
//													w = 0;
//												}
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//				else if (ture[i] == 4) {
//					for (int i = 0; i < 5; i++) {
//						if (ture[i] == 3) {
//							for (int i = 0; i < 5; i++) {
//								if (ture[i] == 2) {
//									for (int i = 0; i < 5; i++) {
//										if (ture[i] == 1) {
//											w = 0;
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//				else if (ture[i] == 3) {
//					for (int i = 0; i < 5; i++) {
//						if (ture[i] == 2) {
//							for (int i = 0; i < 5; i++) {
//								if (ture[i] == 1) {
//									w = 0;
//								}
//							}
//						}
//					}
//				}
//				else if (ture[i] == 2) {
//					for (int i = 0; i < 5; i++) {
//						if (ture[i] == 1) {
//							w = 0;
//						}
//					}
//				}
//					
//			}
//			
//		
//		}
//	
//		
//		
//		//����ÿ����˵����˳���Դﵽ��ÿһ�������ȷ�Խ����Ų�
//		if (w > 0) {
//			int name = arr[0][0][0];
//			int scor = arr[0][0][1];
//			arr[0][0][0] = arr[0][1][0];
//			arr[0][0][1] = arr[0][1][1];
//			arr[0][1][0] = name;
//			arr[0][1][1] = scor;
//		}
//		if(w>2&&w%2==1){
//			int name = arr[1][0][0];
//			int scor = arr[1][0][1];
//			arr[1][0][0] = arr[1][1][0];
//			arr[1][0][1] = arr[1][1][1];
//			arr[1][1][0] = name;
//			arr[1][1][1] = scor;
//		}
//		if (w > 4 && w % 4 == 1) {
//			int name = arr[2][0][0];
//			int scor = arr[2][0][1];
//			arr[2][0][0] = arr[2][1][0];
//			arr[2][0][1] = arr[2][1][1];
//			arr[2][1][0] = name;
//			arr[2][1][1] = scor;
//		}
//		if (w > 8 && w % 8 == 1) {
//			int name = arr[3][0][0];
//			int scor = arr[3][0][1];
//			arr[3][0][0] = arr[3][1][0];
//			arr[3][0][1] = arr[3][1][1];
//			arr[3][1][0] = name;
//			arr[3][1][1] = scor;
//		}
//		if (w > 16 && w % 16 == 1) {
//			int name = arr[4][0][0];
//			int scor = arr[4][0][1];
//			arr[4][0][0] = arr[4][1][0];
//			arr[4][0][1] = arr[4][1][1];
//			arr[4][1][0] = name;
//			arr[4][1][1] = scor;
//		}
//		if (w != 0)
//			w++;
//		//��Щѡ�������Ϊ���л�˳���Դﵽ�������д������ȷ��
//	}
//	printf("a��%d��\n", ture[0]);
//	printf("b��%d��\n", ture[1]);
//	printf("c��%d��\n", ture[2]);
//	printf("d��%d��\n", ture[3]);
//	printf("e��%d��\n", ture[4]);
//
//}
//
//
//
//int main(){/*
//		Aѡ��˵��B�ڶ����ҵ�����
//		Bѡ��˵���ҵڶ���E���ģ�
//		Cѡ��˵���ҵ�һ��D�ڶ���
//		Dѡ��˵��C����ҵ�����
//		Eѡ��˵���ҵ��ģ�A��һ��*/
//
//
//	int arr[5][2][2] = { {{ 2,2},{1,3} },
//						 { {2,2},{5,4} },
//						 { {3,1},{4,2} },
//						 { {3,5},{4,3} },
//						 { {5,4},{1,1} } };//arr[i][j][k]��ʾ��i���˵Ļ��У���j�������˵�k��
//	Paiming(arr);
//	return 0;
//}

//void xuanzhuan(char arr[], int n, int times) {
//	while (times) {
//		char cup = arr[0];
//		for (int i = 0; i < n; i++) {
//			if (i == n - 1)
//				arr[i] = cup;
//			else
//				arr[i] = arr[i + 1];
//		}
//		times--;
//	}
//}
//
//int func(char arr[],char brr[], int n) {
//	int m = 0;
//	for (int i = 0; i < n-1; i++) {
//		xuanzhuan(arr, n-1, 1);
//		m++;
//		int j = 0;
//		for (j = 0; j < n; j++) {
//			if (arr[j] != brr[j])
//				break;
//		}
//		if (j == n) {
//			xuanzhuan(arr, n, n - 1 - m);
//			return 1;
//		}
//			
//	}
//	return 0;
//}
//int main() {
//	char arr[] = "abcdefg";
//	char brr[] = "abcdefg";
//	char crr[] = "abcdefp";
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printf("%s\n", arr);
//	xuanzhuan(arr, n - 1, 2);
//	printf("%s\n", arr);
//	printf("%d\n", func(arr, brr, n));
//	printf("%d\n", func(arr, crr, n));
//	return 0;
//}