#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#define size 4
using namespace std;

int Number[size];
int Value[size];

void SetNumber();

void Slice(int);

int Result();

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	int win = 0, digit = 0, level = 0, border = 0;
	char repeat = '+';
	do
	{
		do
		{
			system("cls");
			cout << "------------Игра Быки и Коровы!-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << R"(
В игре представленны 5 уровней сложности:
                1 - Слабак
                2 - Воин
                3 - Рыцарь
                4 - Герой
                5 - Удобный
	Для сдачи нажмите цифру 0. 
)" << endl;
			cout << "Введите число соответствующее уровню сложности игры: "; cin >> level;
			switch (level)
			{
			case 1:
				cout << "\nВыбран уровень сложности Слабак!" << endl;
				Sleep(2000);
				system("cls");
				border = 20;
				break;
			case 2:
				cout << "\nВыбран уровень сложности Воин!" << endl;
				Sleep(2000);
				system("cls");
				border = 13;
				break;
			case 3:
				cout << "\nВыбран уровень сложности Рыцарь!" << endl;
				Sleep(2000);
				system("cls");
				border = 8;
				break;
			case 4:
				cout << "\nВыбран уровень сложности Герой!" << endl;
				Sleep(2000);
				system("cls");
				border = 5;
				break;
			case 5:
				cout << "\nВыбран уровень сложности Удобный!" << endl;
				Sleep(3000);
				system("cls");
				cout << "\nВведите желаемое число попыток: "; cin >> border;
				system("cls");
				break;
			default:
				cout << "\nВыберете верный уровень сложности!" << endl;
				Sleep(3000);
				break;
			}
		} while (level < 1 || level > 5);
		cout << "------------Игра Быки и Коровы!-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Добро пожаловать в игру! На вашем уровне сложности доступно " << border << " попытки(-ок). Удачной игры!" << endl;

		for (int k = 1; k <= border; k++)
		{
			SetNumber();
			do
			{
				do
				{
					cout << "\nВведите " << size << "-значное число, состоящее из разных цифр: ";
					cin >> digit;
					if (digit == 0)break;
					if (digit < pow(10, size - 1)/*1000*/ || digit >= pow(10, size)) /* 10,000		10,000 <= digit < 1000 */
					{
						cout << "Некорректный ввод! Проверьте количество знаков в числе. Число не должно начинаться с нуля." << endl;
						cout << "Потеря попытки. Осталось попыток: " << border - k << endl;
						k++;
						if (k > border)break;
					}
				} while (digit < pow(10, size - 1) || digit >= pow(10, size));
				if (digit == 0)break;
				if (k > border)break;

				cout << "\nПопытка номер: " << k << endl;
				Slice(digit);
				win = Result();
				k++;

				if (k > border)break;

			} while (win != size);	// 4 быка

			if (k > border && win != size)
			{
				cout << "Количество попыток закончилось. Загаданное число: ";
				for (int i = 0; i < size; i++)
				{
					cout << Number[i];
				}
				cout << endl;
				break;
			}
			if (digit == 0)
			{
				cout << "Сдача принята. Загаданное число: ";
				for (int i = 0; i < size; i++)
				{
					cout << Number[i];
				}
				cout << endl;
				break;
			}
			else
			{
				cout << "\nВы угадали! Загаданное число: " << digit << endl;
				break;
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\nСыграем еще? (Y/N)?"; cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << "\nИгра закончена. До новых встреч!" << endl;
	Sleep(2000);
}


void SetNumber()	// работа с загаданным числом (генерация и проверка)
{
	Number[0] = rand() % 9 + 1;
	for (int i = 1; i < size; i++)
	{
		Number[i] = rand() % 10;
		for (int j = 0; j < i; j++)
		{
			if (Number[i] == Number[j])
			{
				i--;
				break;
			}
		}
	}
}

void Slice(int digit)	// работа с числом игрока, ввод числа игрока в массив
{
	for (int i = size - 1; i >= 0; i--)	// 3 2 1 0
	{
		Value[i] = digit % 10;	// 6574
		digit /= 10;
	}	// digit = 0, его число перешло в массив
}

int Result()	// цикл сравнения массивов
{
	int bulls = 0, cows = 0;
	for (int i = 0; i < size; i++)	// 0 1 2 3
	{
		if (Number[i] == Value[i])
		{
			bulls++;
			continue;
		}
		for (int j = 0; j < size; j++)	// 0 1 2 3
		{
			if (Number[i] == Value[j])
			{
				cows++;
				break;
			}
		}
	}
	cout << "Быки: " << bulls << " Коровы: " << cows << endl;
	return bulls;
}