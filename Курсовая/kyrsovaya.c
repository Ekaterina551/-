#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

int input(double ptr_array[200][2], int);          // ввод данных 
double output(double ptr_array[200][2], int);      // вывод данных
int write(double ptr_array[200][2], int, char*);   // запись в файл
int read(char*);                                   // чтение из файла
double corr();                                     // проверка корректности ввода

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int store = 0;                // сохранность
	int c;                        // выбор пункта
	int flag;
	int test;                     //проверка
	char fname[200] = "clay.txt";  //хранение названия файла для записи и чтения
	double clay[200][2];
	int aaa = 0;

	printf("********************************\n");
	printf("*                              *\n");
	printf("*      Добро пожаловать в      *\n");
	printf("*       Калькулятор клея       *\n");
	printf("*                              *\n");
	printf("********************************\n");

	while (1)
	{
		printf("* * * М е н ю * * * \n1) Ввести данные пола \n2) Вывод данных \n3) Запись в файл \n4) Чтение из файла \n5) Выход \nВведите пункт, который необходимо выполнить: ");
		flag = scanf("%d", &c);
		system("cls");
		if (flag == 1) {
			switch (c) {
			case 1:
				store = 1;
				while (1) {
					aaa = input(clay, aaa);
					printf("Ввести данные снова? \nДа - 1\nНет - 2\n");
					scanf("%d", &c);
					system("cls");
					if (c == 2)  break;
				}
				break;
			case 2:
				if (aaa) {
					double colclay;
					colclay = output(clay, aaa);
					printf("\nОбъём для залития данного пола = %2.f \n", colclay);
					printf("\n");
					printf("\nТри вида клея и сколько кг их будет необходимо, учитывая введённые данные:");
					printf("\nКлей Bergauf: %.2f кг", ceil(colclay * 3.6));
					printf("\nКлей Unis: %.2f кг", ceil(colclay * 1.3));
					printf("\nКлей Ceresit: %.2f кг", ceil(colclay * 4.2));
					printf("\nНажмите Enter для возвращения в лобби\n");
					getchar();
					getchar();
					system("cls");
				}
				else printf("Данные отсутствуют\n\n");
				break;

			case 3:
				if (aaa) {
					test = write(clay, aaa, fname);
					if (test) {
						printf("Информация успешно записана\n\n");
						store = 0;
					}
					else {
						printf("Ошибка\n\n");
					}
				}
				else printf("Нет информации\n\n");
				break;
			case 4:
				read(fname);
				break;
			case 5:
				return 0; // выход из программы

			default:
				printf("Упс\n\n");
				getchar();
				break;
			}
		}
		else {
			system("cls");
			printf("Введены некорректные данные\n\n");
			getchar();
		}
	}
}

int input(double ptr_array[200][2], int aaa) {  //ВВОД ДАННЫХ
	int ch;
	printf("\nВыберите форму пола:\n1)Прямоугольный треугольник\n2)Непрямогульный треугольник\n3)Квадрат\n4)Прямоугольник\n");
	scanf("%d", &ch);
	switch (ch) {
	case 1:
		printf("\nВведите длины катетов в м:\n");
		printf("\nКатет 1 = ");
		ptr_array[aaa][0] = corr();
		printf("\nКатет 2 = ");
		ptr_array[aaa][1] = corr();
		break;
	case 2:
		printf("\nВведите высоту и основание треугольного пола в м");
		printf("\nВысота = ");
		ptr_array[aaa][0] = corr();
		printf("\nОснование = ");
		ptr_array[aaa][1] = corr();
		break;
	case 3:
		printf("\nВведите стороны квадрата в м");
		printf("\nСторона 1 = ");
		ptr_array[aaa][0] = corr();
		printf("\nСторона 2 = ");
		ptr_array[aaa][1] = corr();
		break;
	case 4:
		printf("\nВведите длину и ширину пола в м");
		printf("\nДлина = ");
		ptr_array[aaa][0] = corr();
		printf("\nШирина = ");
		ptr_array[aaa][1] = corr();
		break;

	}
	printf("Введите толщину слоя в см до 2х знаков после запятой ");
	ptr_array[aaa][2] = corr();
	return ++aaa;
}

double output(double ptr_array[200][2], int aaa) {   //ВЫВОД ДАННЫХ
	double colclay = 0;
	int n;
	printf("* * * * * Вывод данных * * * * *\n\nСторона 1 | Сторона 2| Толщина слоя\n");
	for (int i = 0; i < aaa; i++)
	{
		printf("%5.2lf        %.2lf        %.2lf\n", ptr_array[i][0], ptr_array[i][1], ptr_array[i][2]);
		printf("Введите номер фигуры из предыдущего пункта = ");
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
int write(double ptr_array[200][2], int index, char* fname) {  //ЗАПИСЬ В ФАЙЛ
	FILE* in = fopen(fname, "wt");
	if (!in) {
		printf("Ошибка");
		return 0;
	}
	for (int i = 0; i < index; i++) {
		fprintf(in, "\n%.2f %.2f %.2f", ptr_array[i][0], ptr_array[i][1], ptr_array[i][2]);
		fprintf(in, "\nКлей Bergauf: %.2f кг", ptr_array[i][0]* ptr_array[i][1]*ptr_array[i][2] * 3.6);
		fprintf(in, "\nКлей Unis: %.2f кг", ptr_array[i][0] * ptr_array[i][1] * ptr_array[i][2] * 1.3);
		fprintf(in, "\nКлей Ceresit: %.2f кг", ptr_array[i][0] * ptr_array[i][1] * ptr_array[i][2] * 4.2);
	}
	fclose(in);
	return 1;
}

int read(char* fname) {                                      //ЧТЕНИЕ ИЗ ФАЙЛА
	double colclay = 0;
	double st1, st2, ex;
	int n;
	FILE* out = fopen(fname, "rt");
	if (out == NULL) {
		printf("Ошибка\n\n");
		return 0;
	}
	printf("* * * * * Вывод данных * * * * *\n\nСторона 1 | Сторона 2| Толщина слоя\n");
	while (1) {
		fscanf(out, "%lf", &st1);
		fscanf(out, "%lf", &st2);
		fscanf(out, "%lf", &ex);
		printf("%.2lf %10.2lf %14.2lf\n", st1, st2, ex);
		printf("Введите номер фигуры из предыдущего пункта = ");
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
		printf("\nОбъём для залития данного пола = %2.f \n", colclay);
		printf("\n");
		printf("\nТри вида клея и сколько кг их будет необходимо, учитывая введённые данные:");
		printf("\nКлей Bergauf: %.2f кг", colclay * 3.6);
		printf("\nКлей Unis: %.2f кг", colclay * 1.3);
		printf("\nКлей Ceresit: %.2f кг", colclay * 4.2);
		printf("\nНажмите Enter для выхода в меню\n");
		getchar();
		getchar();
		system("cls");
		return 1;
	}
}

double corr() {                                                       //КОРРЕКТНОСТЬ
	double saving;
	while (1) {
		int test = scanf("%lf", &saving);
		getchar();
		if ((test != 1) || (saving <= 0)) printf("Ошибка при вводе данных \nПопробуйте снова, введя другие значения ");
		else break;
	}
	return saving;
}
