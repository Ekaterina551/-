#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

int input(double ptr_array[200][2], int);          // ���� ������ 
double output(double ptr_array[200][2], int);      // ����� ������
int write(double ptr_array[200][2], int, char*);   // ������ � ����
int read(char*);                                   // ������ �� �����
double corr();                                     // �������� ������������ �����

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int store = 0;                // �����������
	int c;                        // ����� ������
	int flag;
	int test;                     //��������
	char fname[200] = "clay.txt";  //�������� �������� ����� ��� ������ � ������
	double clay[200][2];
	int aaa = 0;

	printf("********************************\n");
	printf("*                              *\n");
	printf("*      ����� ���������� �      *\n");
	printf("*       ����������� ����       *\n");
	printf("*                              *\n");
	printf("********************************\n");

	while (1)
	{
		printf("* * * � � � � * * * \n1) ������ ������ ���� \n2) ����� ������ \n3) ������ � ���� \n4) ������ �� ����� \n5) ����� \n������� �����, ������� ���������� ���������: ");
		flag = scanf("%d", &c);
		system("cls");
		if (flag == 1) {
			switch (c) {
			case 1:
				store = 1;
				while (1) {
					aaa = input(clay, aaa);
					printf("������ ������ �����? \n�� - 1\n��� - 2\n");
					scanf("%d", &c);
					system("cls");
					if (c == 2)  break;
				}
				break;
			case 2:
				if (aaa) {
					double colclay;
					colclay = output(clay, aaa);
					printf("\n����� ��� ������� ������� ���� = %2.f \n", colclay);
					printf("\n");
					printf("\n��� ���� ���� � ������� �� �� ����� ����������, �������� �������� ������:");
					printf("\n���� Bergauf: %.2f ��", ceil(colclay * 3.6));
					printf("\n���� Unis: %.2f ��", ceil(colclay * 1.3));
					printf("\n���� Ceresit: %.2f ��", ceil(colclay * 4.2));
					printf("\n������� Enter ��� ����������� � �����\n");
					getchar();
					getchar();
					system("cls");
				}
				else printf("������ �����������\n\n");
				break;

			case 3:
				if (aaa) {
					test = write(clay, aaa, fname);
					if (test) {
						printf("���������� ������� ��������\n\n");
						store = 0;
					}
					else {
						printf("������\n\n");
					}
				}
				else printf("��� ����������\n\n");
				break;
			case 4:
				read(fname);
				break;
			case 5:
				return 0; // ����� �� ���������

			default:
				printf("���\n\n");
				getchar();
				break;
			}
		}
		else {
			system("cls");
			printf("������� ������������ ������\n\n");
			getchar();
		}
	}
}

int input(double ptr_array[200][2], int aaa) {  //���� ������
	int ch;
	printf("\n�������� ����� ����:\n1)������������� �����������\n2)�������������� �����������\n3)�������\n4)�������������\n");
	scanf("%d", &ch);
	switch (ch) {
	case 1:
		printf("\n������� ����� ������� � �:\n");
		printf("\n����� 1 = ");
		ptr_array[aaa][0] = corr();
		printf("\n����� 2 = ");
		ptr_array[aaa][1] = corr();
		break;
	case 2:
		printf("\n������� ������ � ��������� ������������ ���� � �");
		printf("\n������ = ");
		ptr_array[aaa][0] = corr();
		printf("\n��������� = ");
		ptr_array[aaa][1] = corr();
		break;
	case 3:
		printf("\n������� ������� �������� � �");
		printf("\n������� 1 = ");
		ptr_array[aaa][0] = corr();
		printf("\n������� 2 = ");
		ptr_array[aaa][1] = corr();
		break;
	case 4:
		printf("\n������� ����� � ������ ���� � �");
		printf("\n����� = ");
		ptr_array[aaa][0] = corr();
		printf("\n������ = ");
		ptr_array[aaa][1] = corr();
		break;

	}
	printf("������� ������� ���� � �� �� 2� ������ ����� ������� ");
	ptr_array[aaa][2] = corr();
	return ++aaa;
}

double output(double ptr_array[200][2], int aaa) {   //����� ������
	double colclay = 0;
	int n;
	printf("* * * * * ����� ������ * * * * *\n\n������� 1 | ������� 2| ������� ����\n");
	for (int i = 0; i < aaa; i++)
	{
		printf("%5.2lf        %.2lf        %.2lf\n", ptr_array[i][0], ptr_array[i][1], ptr_array[i][2]);
		printf("������� ����� ������ �� ����������� ������ = ");
		scanf("%d", &n);
		switch (n) {
		case 1:
		case 2:
			colclay += ptr_array[i][0] * ptr_array[i][1] / 2; break;
		case 3:
		case 4:
			colclay += ptr_array[i][0] * ptr_array[i][1]; break;
		}
		colclay = colclay * ptr_array[i][2];
	}
	return colclay;
}
int write(double ptr_array[200][2], int index, char* fname) {  //������ � ����
	FILE* in = fopen(fname, "wt");
	if (!in) {
		printf("������");
		return 0;
	}
	for (int i = 0; i < index; i++) {
		fprintf(in, "\n%.2f %.2f %.2f", ptr_array[i][0], ptr_array[i][1], ptr_array[i][2]);
		fprintf(in, "\n���� Bergauf: %.2f ��", ptr_array[i][0]* ptr_array[i][1]*ptr_array[i][2] * 3.6);
		fprintf(in, "\n���� Unis: %.2f ��", ptr_array[i][0] * ptr_array[i][1] * ptr_array[i][2] * 1.3);
		fprintf(in, "\n���� Ceresit: %.2f ��", ptr_array[i][0] * ptr_array[i][1] * ptr_array[i][2] * 4.2);
	}
	fclose(in);
	return 1;
}

int read(char* fname) {                                      //������ �� �����
	double colclay = 0;
	double st1, st2, ex;
	int n;
	FILE* out = fopen(fname, "rt");
	if (out == NULL) {
		printf("������\n\n");
		return 0;
	}
	printf("* * * * * ����� ������ * * * * *\n\n������� 1 | ������� 2| ������� ����\n");
	while (1) {
		fscanf(out, "%lf", &st1);
		fscanf(out, "%lf", &st2);
		fscanf(out, "%lf", &ex);
		printf("%.2lf %10.2lf %14.2lf\n", st1, st2, ex);
		printf("������� ����� ������ �� ����������� ������ = ");
		scanf("%d", &n);
		switch (n) {
		case 1:
		case 2:
			colclay += st1 * st2 * ex / 2; break;
		case 3:
		case 4:
			colclay += st1 * st2 * ex; break;
			if (feof(out)) break;
		}
		fclose(out);
		printf("\n����� ��� ������� ������� ���� = %2.f \n", colclay);
		printf("\n");
		printf("\n��� ���� ���� � ������� �� �� ����� ����������, �������� �������� ������:");
		printf("\n���� Bergauf: %.2f ��", colclay * 3.6);
		printf("\n���� Unis: %.2f ��", colclay * 1.3);
		printf("\n���� Ceresit: %.2f ��", colclay * 4.2);
		printf("\n������� Enter ��� ������ � ����\n");
		getchar();
		getchar();
		system("cls");
		return 1;
	}
}

double corr() {                                                       //������������
	double saving;
	while (1) {
		int test = scanf("%lf", &saving);
		getchar();
		if ((test != 1) || (saving <= 0)) printf("������ ��� ����� ������ \n���������� �����, ����� ������ �������� ");
		else break;
	}
	return saving;
}
