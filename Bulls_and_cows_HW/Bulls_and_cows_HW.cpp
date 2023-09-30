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
			cout << "------------���� ���� � ������!-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << R"(
� ���� ������������� 5 ������� ���������:
                1 - ������
                2 - ����
                3 - ������
                4 - �����
                5 - �������
	��� ����� ������� ����� 0. 
)" << endl;
			cout << "������� ����� ��������������� ������ ��������� ����: "; cin >> level;
			switch (level)
			{
			case 1:
				cout << "\n������ ������� ��������� ������!" << endl;
				Sleep(2000);
				system("cls");
				border = 20;
				break;
			case 2:
				cout << "\n������ ������� ��������� ����!" << endl;
				Sleep(2000);
				system("cls");
				border = 13;
				break;
			case 3:
				cout << "\n������ ������� ��������� ������!" << endl;
				Sleep(2000);
				system("cls");
				border = 8;
				break;
			case 4:
				cout << "\n������ ������� ��������� �����!" << endl;
				Sleep(2000);
				system("cls");
				border = 5;
				break;
			case 5:
				cout << "\n������ ������� ��������� �������!" << endl;
				Sleep(3000);
				system("cls");
				cout << "\n������� �������� ����� �������: "; cin >> border;
				system("cls");
				break;
			default:
				cout << "\n�������� ������ ������� ���������!" << endl;
				Sleep(3000);
				break;
			}
		} while (level < 1 || level > 5);
		cout << "------------���� ���� � ������!-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "����� ���������� � ����! �� ����� ������ ��������� �������� " << border << " �������(-��). ������� ����!" << endl;

		for (int k = 1; k <= border; k++)
		{
			SetNumber();
			do
			{
				do
				{
					cout << "\n������� " << size << "-������� �����, ��������� �� ������ ����: ";
					cin >> digit;
					if (digit == 0)break;
					if (digit < pow(10, size - 1)/*1000*/ || digit >= pow(10, size)) /* 10,000		10,000 <= digit < 1000 */
					{
						cout << "������������ ����! ��������� ���������� ������ � �����. ����� �� ������ ���������� � ����." << endl;
						cout << "������ �������. �������� �������: " << border - k << endl;
						k++;
						if (k > border)break;
					}
				} while (digit < pow(10, size - 1) || digit >= pow(10, size));
				if (digit == 0)break;
				if (k > border)break;

				cout << "\n������� �����: " << k << endl;
				Slice(digit);
				win = Result();
				k++;

				if (k > border)break;

			} while (win != size);	// 4 ����

			if (k > border && win != size)
			{
				cout << "���������� ������� �����������. ���������� �����: ";
				for (int i = 0; i < size; i++)
				{
					cout << Number[i];
				}
				cout << endl;
				break;
			}
			if (digit == 0)
			{
				cout << "����� �������. ���������� �����: ";
				for (int i = 0; i < size; i++)
				{
					cout << Number[i];
				}
				cout << endl;
				break;
			}
			else
			{
				cout << "\n�� �������! ���������� �����: " << digit << endl;
				break;
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		cout << "\n������� ���? (Y/N)?"; cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << "\n���� ���������. �� ����� ������!" << endl;
	Sleep(2000);
}


void SetNumber()	// ������ � ���������� ������ (��������� � ��������)
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

void Slice(int digit)	// ������ � ������ ������, ���� ����� ������ � ������
{
	for (int i = size - 1; i >= 0; i--)	// 3 2 1 0
	{
		Value[i] = digit % 10;	// 6574
		digit /= 10;
	}	// digit = 0, ��� ����� ������� � ������
}

int Result()	// ���� ��������� ��������
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
	cout << "����: " << bulls << " ������: " << cows << endl;
	return bulls;
}