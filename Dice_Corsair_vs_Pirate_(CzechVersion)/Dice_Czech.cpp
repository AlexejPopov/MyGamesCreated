#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    system("chcp 1250");
    system("cls");
    srand(time(NULL));
    int cash = 0, bet = 0, strike_pc = 0, strike_player = 0, level = 0, dice_pc = 0, dice_pl = 0, change_pc = 0, change_pl = 0, N = 9;

    cout << "\n\tNámořník: \"Vidím zemi, kapitáne! Hospodu!\" " << endl;
    Sleep(3000);

    // Краша
    for (int i = 0; i < N; i++)																								// цикл по строкам
    {
        for (int j = 0; j < N; j++)																							// цикл по столбцам
        {
            if (N % 2 == 0)																									// если ширина четная
            {
                if ((i == 3 * N / 4 - 1 || i == 3 * N / 4 + 1) && (j == N / 2 || j == N / 2 - 1))cout << "  |   ";			// вертикальная рама окошка
                else
                    if (i == 3 * N / 4 && j == N / 2 - 2)cout << " - - -";													// левая центральная рама окошка
                    else
                        if (i == 3 * N / 4 && j == N / 2 + 1)cout << " - -  ";												// правая центральная рама окошка
                        else
                            if (i == 3 * N / 4 && (j == N / 2 || j == N / 2 - 1))cout << " -|- -";							// перекрестия окна
                            else
                                if ((i >= N / 2 - 1 && i <= N / 2 + 2) && (j == N / 2 + 2))cout << "|###| ";				// труба из кирпичей
                                else
                                    if (i >= j && i + j >= N - 1)cout << "|===| ";											// черепица в крыше
                                    else cout << "      ";																	// небо
            }
            else																											// если ширина нечетная
            {
                if ((i == 3 * N / 4 - 1 || i == 3 * N / 4 + 1) && j == N / 2)cout << "  |   ";								// вертикальная рама окошка
                else
                    if (i == 3 * N / 4 && j == N / 2 - 1)cout << " - - -";													// левая центральная рама окошка
                    else
                        if (i == 3 * N / 4 && j == N / 2 + 1)cout << " - -  ";												// правая центральная рама окошка
                        else
                            if (i == 3 * N / 4 && j == N / 2)cout << " -|- -";												// перекрестье окна
                            else
                                if ((i >= N / 2 - 1 && i <= N / 2 + 2) && (j == N / 2 + 2))cout << "|###| ";				// труба из кирпичей
                                else
                                    if (i >= j && i + j >= N - 1)cout << "|===| ";											// черепица в крыше
                                    else cout << "      ";																	// небо
            }
        }
        cout << endl;
    }

    // Стены
    for (int i = 0; i < N; i++)																								// цикл по строкам
    {
        for (int j = 0; j < N; j++)																							// цикл по столбцам
        {
            if ((i >= N / 2 - 1 && i <= N / 2 + 1) && (j == N - 3 || j == N - 4))cout << "  |   ";							// центральные вертикальные рамы
            else
                if ((i >= N / 2 - 1 && i <= N / 2 + 1) && j == N - 2)cout << "    | ";										// правая вертикальная рама
                else
                    if ((i >= N / 2 - 1 && i <= N / 2 + 1) && j == N - 5)cout << "|     ";									// левая вертикальная рама
                    else
                        if ((i == N / 2 - 2 || i == N / 2 + 2) && (j >= N - 5 && j <= N - 2))cout << "- - - ";				// верхняя и нижняя рамы
                        else
                            if (i == 2 && (j == 1 || j == 2))cout << "_ _ _ ";												// верх двери
                            else
                                if (i == N - 1 && j == 1)cout << "|_ _ _";													// левая половина порога
                                else
                                    if (i == N - 1 && j == 2)cout << " _ _| ";												// правая половина порога
                                    else
                                        if (i >= 3 && j == 1)cout << "|     ";												// левая сторона двери
                                        else
                                            if ((i == N / 2 + 1) && j == 2)cout << "  O | ";								// ручка на одну строку ниже середины стены
                                            else
                                                if (i >= 3 && j == 2)cout << "    | ";										// правая сторона двери
                                                else cout << "|###| ";														// кирпичи в стене
        }
        cout << endl;
    }
    Sleep(4000);
    cout << "\n\tKapitán: \"Konečně jsme našli tohle místo...\"" << endl;
    Sleep(4000);
    cout << "\n\tKapitán: \"Spust'te čluny!\"" << endl;
    Sleep(4000);
    cout << "\n\tKapitán: \"Korzáři, námořníci, přátelé, poslouchejte mě!" << endl;
    Sleep(4000);
    cout << "\n\t         \"Vsichni jsme statecne bojovali, bojovali a jeste jednou bojovali ve jménu koruny!\" " << endl;
    Sleep(4000);
    cout << "\n\t         \"Dneska vecer máte volno! Chyt'te devcatky, pivo, rum, hrajte kostky..., vecer je vás!\" " << endl;
    Sleep(4000);
    cout << "\n\t         \"Ale, vyplouváme zítra v poledne! Kazdy má byt za hodynu do vyplouvání uz na palube! To je rozkaz!\" " << endl;
    Sleep(4000);
    cout << "\n\t         \"A ted' vsichni do clunu!\" " << endl;
    Sleep(10000);
    system("cls");
    cout << "--------U Hospody!--------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n\tKorzár Smith: \"Tak, uz jsem se stestím dávno nehrál.\" " << endl;
    Sleep(4000);
    cout << "\n\tKorzár Lock: \"Podívej se vedle sudu, vzdy jsou tam davy pirátu. Nedoporucoval bych ti tam jít!\" " << endl;
    Sleep(4000);
    cout << "\n\tKorzár Smith: \"Stestí je vzdy v mé kapse! Podívám se kdo jsou tyhle piráty a co umí!\" " << endl;
    Sleep(10000);
    system("cls");
    cout << "--------U sudu!-----------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n\tKorzár Smith: \"Je tady nejaky odvazny muz, ktery by bojoval se mnou v kostky?\" " << endl;
    Sleep(5000);
    cout << "\n\tPirát Black: \"Kdo je tu! Koukni se do toho! Tamhle! K prasatum! Tenhle je taky chtel bojovat se mnou!, Agrch!\" " << endl;
    Sleep(3000);
    cout << "\t            <<Piráti se smejou!>> " << endl;
    Sleep(5000);
    cout << "\n\tKorzár Smith: \"Urcite si tam nekdo z nás udela pohodlí. Muzeme zacít?\" " << endl;
    Sleep(5000);
    cout << "\n\n\tKorzár Smith (sám sobe): \"At' pomuze mi Pab Buh!\" " << endl;
    Sleep(20000);
    system("cls");

    do
    {
        cout << "----------------------------------------------------------Korzári! Hra v kostky!-----------------------------------------------------------------\n" << endl;

        cout << R"(                                                     Vyberte si úroven obtíznosti hry:

                                                             1. Férová hra
                                                             2. Pirát podvádí
                                                             3. Korzár podvádí
                                                             4. Oba podvádí

                                                     Zadejte úroven obtíznosti hry: )"; cin >> level;

        switch (level)
        {
        case 1:
            dice_pc = 11;
            change_pc = 2;
            dice_pl = 11;
            change_pl = 2;
            break;
        case 2:
            dice_pc = 7;
            change_pc = 6;
            dice_pl = 11;
            change_pl = 2;
            break;
        case 3:
            dice_pc = 11;
            change_pc = 2;
            dice_pl = 7;
            change_pl = 6;
            break;
        case 4:
            dice_pc = 7;
            change_pc = 6;
            dice_pl = 7;
            change_pl = 6;
            break;
        default:
            cout << "\n                                                     Zadejte správnou úroven obtíznosti hry!" << endl;
            Sleep(3000);
            system("cls");
            break;
        }
    } while (level < 1 || level>4);
    do
    {
        system("cls");
        cout << "----------------------------------------------------------Korzári! Hra v kostky!-----------------------------------------------------------------" << endl;
        cout << "\n                                                     Pirát Black: \"Dej ty piastry na sud! Pri sazce '0' muzes ukoncit hru.\" "; cin >> cash;
        if (cash < 0)cout << "\n                                                     Pirát Black: \"Char! Kapsy jsou plné der, chudácku!\"" << endl;
    } while (cash < 0);

    if (cash == 0)
    {
        cout << "\n                                                     Pirát Black: \"Char! Penezenka je prazdna! Vezmeme ho a vyhodim ho k prasatum!\"" << endl;
        Sleep(3000);
    }
    else
    {
        do
        {
            system("cls");
            cout << "----------------------------------------------------------Korzári! Hra v kostky!-----------------------------------------------------------------" << endl;
            cout << "\n                                                     V pytle korzáre je " << cash << " piastru!" << endl;

            do
            {
                cout << "\n                                                     Pirát Black: \"Kolik piastru das?\" "; cin >> bet;
                if (bet < 0)
                {
                    cout << "\n                                                     Pirát Black: \"Ach! nemas penize? Sazis lod'?\"" << endl;
                    Sleep(3000);
                    cout << "\n                                                     Korzár Smith: \"Lod'..? Radeji poslu vás k morskému d'ablu!\"" << endl;
                    Sleep(3000);
                }
                if (bet > cash)cout << "\n                                                     Pirát Black: \"Agrch, hrom me! Rozhodl jsi zaplatit zivotem?\"" << endl;
            } while (bet<0 || bet>cash);

            if (bet == 0)
            {
                cout << "\n                                                     Pirát Black: \"Ach, kryso! Vypadni odtud!\"" << endl;
                break;
            }
            else
            {
                do
                {
                    strike_pc = rand() % dice_pc + change_pc;;
                    strike_player = rand() % dice_pl + change_pl;
                    cout << "\n                                                     Pirát má: ";
                    Sleep(3000);
                    switch (strike_pc)
                    {
                    case 2:
                        cout << R"(
                                                                                                                        _ _ _ 
             _ _ _                                                                                                     |     |
            |     |                                                                                                    |  *  |
            |  *  |                                                                                                    |_ _ _|
            |_ _ _|
)";
                        break;
                    case 3:
                        cout << R"(
                                                     _ _ _
                                                    |     |                                                  _ _ _
                                                    |  *  |                                                 |   * |
                                                    |_ _ _|                                                 |     |
                                                                                                            |_*_ _|
)";
                        break;
                    case 4:
                        cout << R"(
                          _ _ _
                         |   * |
                         |     |                                                    _ _ _
                         |_*_ _|                                                   |   * |
                                                                                   |     |
                                                                                   |_*_ _|
)";
                        break;
                    case 5:
                        cout << R"(
                                                                 _ _ _
                                                                |   * |                                               _ _ _
                                                                |     |                                              |   * |
                                                                |_*_ _|                                              |  *  |
                                                                                                                     |_*_ _|
)";
                        break;
                    case 6:
                        cout << R"(
                                                                                                     _ _ _
                                                                                                    |   * |
     _ _ _                                                                                          |  *  |
    |   * |                                                                                         |_*_ _|
    |  *  |
    |_*_ _|
)";
                        break;
                    case 7:
                        cout << R"(
                                         _ _ _
                                        | * * |                                                                          _ _ _
                                        | * * |                                                                         |     |
                                        |_*_*_|                                                                         |  *  |
                                                                                                                        |_ _ _|
)";
                        break;
                    case 8:
                        cout << R"(
                                                                             _ _ _
                                                                            | * * |                          _ _ _
                                                                            |     |                         | * * |
                                                                            |_*_*_|                         |     |
                                                                                                            |_*_*_|
)";
                        break;
                    case 9:
                        cout << R"(
                                                         _ _ _
                                                        | * * |
                                                        |     |                                                                _ _ _
                                                        |_*_*_|                                                               | * * |
                                                                                                                              |  *  |
                                                                                                                              |_*_*_|
)";
                        break;
                    case 10:
                        cout << R"(
             _ _ _
            | * * |
            |  *  |                                                                          _ _ _
            |_*_*_|                                                                         | * * |
                                                                                            |  *  |
                                                                                            |_*_*_|
)";
                        break;
                    case 11:
                        cout << R"(
                                                                    _ _ _
                                                                   | * * |
                                             _ _ _                 | * * |
                                            | * * |                |_*_*_|
                                            |  *  |
                                            |_*_*_|
)";
                        break;
                    case 12:
                        cout << R"(
                                                                                     _ _ _
                                                                                    | * * |                                    _ _ _
                                                                                    | * * |                                   | * * |
                                                                                    |_*_*_|                                   | * * |
                                                                                                                              |_*_*_|
)";
                        break;
                    }
                    Sleep(3000);
                    cout << "\n\n                                                     Korzár má: ";
                    Sleep(3000);
                    switch (strike_player)
                    {
                    case 2:
                        cout << R"(
          _ _ _                                   
         |     |                                  _ _ _
         |  *  |                                 |     |
         |_ _ _|                                 |  *  |
                                                 |_ _ _|
)";
                        break;
                    case 3:
                        cout << R"(
                                                                                                               _ _ _
                                                                                _ _ _                         |     |
                                                                               |   * |                        |  *  |
                                                                               |     |                        |_ _ _|
                                                                               |_*_ _|                            
)";
                        break;
                    case 4:
                        cout << R"(
                                                                                                                        _ _ _
                                                                                                                       |   * |
                                 _ _ _                                                                                 |  *  |
                                |     |                                                                                |_*_ _|
                                |  *  |            
                                |_ _ _|        
)";
                        break;
                    case 5:
                        cout << R"(
                                                                                                           _ _ _
                                                                                                          |     |
         _ _ _                                                                                            |  *  |
        | * * |                                                                                           |_ _ _|
        |     |
        |_*_*_|
)";
                        break;
                    case 6:
                        cout << R"(
                                                             _ _ _         
                                                            | * * |                          
                                                            |     |                           _ _ _
                                                            |_*_*_|                          |   * |
                                                                                             |     |
                                                                                             |_*_ _|       
)";
                        break;
                    case 7:
                        cout << R"(
                                                                                                                           _ _ _
                                             _ _ _                                                                        |   * |
                                            | * * |                                                                       |     |
                                            |  *  |                                                                       |_*_ _|
                                            |_*_*_|
)";
                        break;
                    case 8:
                        cout << R"(
                                                                             _ _ _                     
                                                                            |   * |                              
                                                                            |  *  |                               _ _ _
                                                                            |_*_ _|                              | * * | 
                                                                                                                 |  *  |
                                                                                                                 |_*_*_|           
)";
                        break;
                    case 9:
                        cout << R"(
   _ _ _     
  | * * |    
  | * * |    
  |_*_*_|                                             _ _ _
                                                     |   * |       
                                                     |  *  |       
                                                     |_*_ _|       
)";
                        break;
                    case 10:
                        cout << R"(
                                                                                                          _ _ _
                                                                                                         | * * |
                     _ _ _                                                                               | * * |
                    | * * |                                                                              |_*_*_|
                    |     |
                    |_*_*_|
)";
                        break;
                    case 11:
                        cout << R"(
                                                                                           _ _ _                    
                                                                                          | * * |                   
                                                                                          | * * |                    _ _ _
                                                                                          |_*_*_|                   | * * |
                                                                                                                    |  *  |
                                                                                                                    |_*_*_|
)";
                        break;
                    case 12:
                        cout << R"(
                                     _ _ _                                                  
                                    | * * |                                                  _ _ _
                                    | * * |                                                 | * * |
                                    |_*_*_|                                                 | * * |
                                                                                            |_*_*_|
)";
                        break;
                    }
                    Sleep(3000);

                    if (strike_pc == strike_player)cout << "\n                                                     Pirát Black: \"Agrch, hodime kostky jeste jednou!\"\n" << endl;
                } while (strike_pc == strike_player);


                if (strike_pc > strike_player)
                {
                    cout << "\n                                                     Pirát Black: \"Vítr, char, nefouká do tvych plachet!\"" << endl;
                    cash -= bet;
                    cout << "\n                                                     V pytle u korzáru je: " << cash << " piastru!" << endl;
                }
                else
                {
                    cout << "\n                                                     Pirát Black: \"Mas stesti cizince!\"" << endl;
                    cash += bet;
                    cout << "\n                                                     V pytle u korzáru je: " << cash << " piastru!" << endl;
                }
                if (cash == 0)
                {
                    cout << "\n                                                     Pirát Black: \"Stesti, vidim, nemas, cizince! Vypadni!\"" << endl;
                    break;
                }
                Sleep(6000);
            }
        } while (cash > 0);
    }
    Sleep(8000);
}