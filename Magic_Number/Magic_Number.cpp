#include <iostream>
#include <locale.h>
#include <windows.h>    // для задержки
#include <stdlib.h>     // чтобы очистить экран в нужный момент и не только
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));                       // сдвиг ГСЧ на количество милисекунд, прошедших с начала времен
    int magicnumber = 0;                     // для хранения загаданного числа
    int playernumber = 0;                    // для хранения числа введенного игроком
    int level = 0;
    int attempt = 0;
    int border = 0;
    char answer = 'Y';                       // для хранения ответа на вопрос о продолжении игры    
    do
    {
        system("cls");                       // очистка экрана перед новой игрой
        do
        {
            system("cls");
            cout << "-----------------------------------------------------Угадай загаданное число!------------------------------------------------------------" << endl;
            cout << R"(
                                             В игре представленны 4 уровня сложности:

                                                           1 - Слабак
                                                           2 - Воин
                                                           3 - Рыцарь
                                                           4 - Герой
                                                           5 - Удобный
)" << endl;
            cout << "                                        Введите число соответствующее уровню сложности игры: "; cin >> level;
            switch (level)
            {
            case 1:
                cout << "\n                                                  Выбран уровень сложности Слабак!" << endl;              // легкий режим с подсказками
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 9;
                break;
            case 2:
                cout << "\n                                                   Выбран уровень сложности Воин!" << endl;               // Средний режим нынешний
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 9;
                break;
            case 3:
                cout << "\n                                                  Выбран уровень сложности Рыцарь!" << endl;              // Повышенный режим с диапазоном от 0 до 15
                Sleep(2000);
                system("cls");
                attempt = 5;
                border = 15;
                break;
            case 4:
                cout << "\n                                                   Выбран уровень сложности Герой!" << endl;              // Высокий с двумя попытками от 
                Sleep(2000);
                system("cls");
                attempt = 2;
                border = 9;
                break;
            case 5:
                cout << "\n                                                  Выбран уровень сложности Удобный!" << endl;             //  Удобный с диапазоном от 0 до 9, но с выбором количества попыток
                Sleep(3000);
                system("cls");
                cout << "\n                                        Введите желаемое число попыток: "; cin >> attempt;
                border = 9;
                break;
            default:
                cout << "\n                                        Выберете верный уровень сложности!" << endl;
                Sleep(3000);
                break;
            }
        } while (level < 1 || level > 5);

        magicnumber = rand() % border + 1;
        for (int i = 1; i <= attempt; i++)
        {
            do
            {
                cout << "\n                                        Номер попытки " << i << endl;
                cout << "                                        Введите число от 1 до " << border << ": "; cin >> playernumber;
                if (playernumber < 1 || playernumber > border)
                {
                    cout << "\n                                        Некорректный ввод, попробуйте еще раз!" << endl;
                    if (i == attempt)break;
                    else i++;
                }

            } while (playernumber < 1 || playernumber > border);

            if (magicnumber == playernumber)
            {
                cout << "\n                                        Поздравляем! Вы отгадали число " << magicnumber << " c " << i << " попытки." << endl;
                break;
            }
            else
                if (i == attempt)cout << "\n                                        Вы проиграли! Загаданное число: " << magicnumber << endl;
                else
                {
                    cout << "\n                                        Вы не угадали! У вас осталось " << attempt - i << " попытки(а)." << endl;
                    if (level == 1)
                    {
                        if (magicnumber > playernumber)cout << "\n                                        Загаданное число больше чем ваше число!" << endl;
                        else cout << "\n                                        Загаданное число меньше чем ваше число!" << endl;
                    }
                }
        }
        Sleep(3000);
        cout << "\n                                        Сыграем еще? (Y/N)?"; cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    cout << "\n                                        Игра закончена. До новых встреч!" << endl;
    Sleep(2000);
}