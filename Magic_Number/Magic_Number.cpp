#include <iostream>
#include <locale.h>
#include <windows.h>    // ��� ��������
#include <stdlib.h>     // ����� �������� ����� � ������ ������ � �� ������
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));                       // ����� ��� �� ���������� ����������, ��������� � ������ ������
    int magicnumber = 0;                     // ��� �������� ����������� �����
    int playernumber = 0;                    // ��� �������� ����� ���������� �������
    int level = 0;
    int attempt = 0;
    int border = 0;
    char answer = 'Y';                       // ��� �������� ������ �� ������ � ����������� ����    
    do
    {
        system("cls");                       // ������� ������ ����� ����� �����
        do
        {
            system("cls");
            cout << "-----------------------------------------------------������ ���������� �����!------------------------------------------------------------" << endl;
            cout << R"(
                                             � ���� ������������� 4 ������ ���������:

                                                           1 - ������
                                                           2 - ����
                                                           3 - ������
                                                           4 - �����
                                                           5 - �������
)" << endl;
            cout << "                                        ������� ����� ��������������� ������ ��������� ����: "; cin >> level;
            switch (level)
            {
            case 1:
                cout << "\n                                                  ������ ������� ��������� ������!" << endl;              // ������ ����� � �����������
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 9;
                break;
            case 2:
                cout << "\n                                                   ������ ������� ��������� ����!" << endl;               // ������� ����� ��������
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 9;
                break;
            case 3:
                cout << "\n                                                  ������ ������� ��������� ������!" << endl;              // ���������� ����� � ���������� �� 0 �� 15
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 15;
                break;
            case 4:
                cout << "\n                                                   ������ ������� ��������� �����!" << endl;              // ������� � ����� ��������� �� 
                Sleep(2000);
                system("cls");
                attempt = 2;
                border = 9;
                break;
            case 5:
                cout << "\n                                                  ������ ������� ��������� �������!" << endl;             //  ������� � ���������� �� 0 �� 9, �� � ������� ���������� �������
                Sleep(3000);
                system("cls");
                cout << "\n                                        ������� �������� ����� �������: "; cin >> attempt;
                border = 9;
                break;
            default:
                cout << "\n                                        �������� ������ ������� ���������!" << endl;
                Sleep(3000);
                break;
            }
        } while (level < 1 || level > 5);

        magicnumber = rand() % border + 1;
        for (int i = 1; i <= attempt; i++)
        {
            do
            {
                cout << "\n                                        ����� ������� " << i << endl;
                cout << "                                        ������� ����� �� 1 �� " << border << ": "; cin >> playernumber;
                if (playernumber < 1 || playernumber > border)
                {
                    cout << "\n                                        ������������ ����, ���������� ��� ���!" << endl;
                    if (i == attempt)break;
                    else i++;
                }

            } while (playernumber < 1 || playernumber > border);

            if (magicnumber == playernumber)
            {
                cout << "\n                                        �����������! �� �������� ����� " << magicnumber << " c " << i << " �������." << endl;
                break;
            }
            else
                if (i == attempt)cout << "\n                                        �� ���������! ���������� �����: " << magicnumber << endl;
                else
                {
                    cout << "\n                                        �� �� �������! � ��� �������� " << attempt - i << " �������(�)." << endl;
                    if (level == 1)
                    {
                        if (magicnumber > playernumber)cout << "\n                                        ���������� ����� ������ ��� ���� �����!" << endl;
                        else cout << "\n                                        ���������� ����� ������ ��� ���� �����!" << endl;
                    }
                }
        }
        Sleep(3000);
        cout << "\n                                        ������� ���? (Y/N)?"; cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    cout << "\n                                        ���� ���������. �� ����� ������!" << endl;
    Sleep(2000);
}