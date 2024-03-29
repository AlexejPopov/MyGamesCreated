﻿#include <iostream>
#include <time.h>
#include <cstdlib>
#define size 4				// именование литерала
/* Есть библиотеки с окончанием ".h" и начинающиеся на "с..." (time.h и ctime,...). ".h" пришли из "C", а "с..." были добавлены для С++ уже с встроенными в них "С" биб-
лиотеками. Если зайти внутрь библиотеки С++, в ней будет подключена соответствующая ей библиотека языка С. */
using namespace std;

/* 3578
   1768 => 1 бык и 1 корова
Если одна и таже цифра друг под другом, например 8, то это 1 бык, а если в обоих числах присутствует одна и тажк цифра, но в разных позициях в числе, то это корова. По
количеству быков и коров в веденном числе пользователь должен угадать загаданное число. Сравнение идет по каждой цифре числа. 4 быка скажут что число угадано.

   Требования:
1. Число должно быть четырехзначным. Ноль в начале в счет не идет и не вводится в игру (0137 число трехзначное)
2. Одинаковых цифр быть не должно (7732 вводить нельзя)

		Техническое задание:
   Пользовательский интерфейс (меню)
   Проверка ввода	-	do_while
   Хранение чисел	-	массивы
F1 Загадывание числа
F2 Разделение числа на цифры
F3 Сравнение чисел
F3 Результат сравнения
   Результат игры
   Учет попыток
   Цикл повторной игры
   Псевдографика

Сравниваться числа будут по цифрам, и след, храниться числа будут В МАССИВЕ УЖЕ РАЗДЕЛЕННОМ НА ОТДЕЛЬНЫЕ ЦИФРЫ. Сравниваться будут 2 глоб.массива ПОЭЛЕМЕНТНО. Глоб.мас-
сив(М.) в функцию передавать не надо. Пусть размер массива тоже будет глоб.к., чтобы и его не надо было передавать в функцию.
(!) позже узнаю как можно создавать массивы переменной длины чтобы можно было выбирать длину числа.

Пользовательское число необходимо нарезать, а загаданное число будет создаваться в массиве.
Создам глоб.к. через define size. Создам глоб.М., хранящий загаданное число (глоб.объекты по умолчанию пустые). */
int Number[size];					// для загаданного числа
int Value[size];					// для введенного числа

void SetNumber();					/* Функция загадывания числа.
Т.к. массив изменяется в функции, число будет сразу в массив помещаться, в каждую ячейку каждая цифра. Передавать в функцию ничего не надо т.к. Number М.глобальный, а
size это define (там где будет size, будет 4). Функция не будет ничего возвращать. */

void Slice(int);					/* Функция преобразования (нарезки) числа.
Будет преобразовывать число, введенное игроком в массив цифр. */

int Result();						/* Функция сравнения и определения результата.
Будет возвращать быков и коров. return может вернуть только одно значение, а для программы важны лишь быки, по которым ей будет ясно победил ли игрок. Если количество
быков совпадет с количеством цифр в числе, то игрок победил. Для игрока быки и коровы просто выведутся на экран. Вернет функция количество быков.

(!) не надо все делать в самой функции, лучше ввод значений и работу со значениями сделать отдельно, чтобы в одну функцию все не смешивать (за исключением если в функ-
ции нужно вводить число с клавиатуры). */

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	cout << "-------------------------------------------------------Игра Быки и Коровы!----------------------------------------------------------------------\n" << endl;
	int win = 0, digit = 0;
	SetNumber();
	/*
	for (int i = 0; i < size; i++)													// тестовый вывод загаданного числа на экран
	{
		cout << Number[i];
	}
	cout << endl;
	*/
	do																				// цикл игры до победы
	{
		/* Проверка пользовательского ввода:
		1.вариант: если нужно ограничиться 4-х значным числом, то можно прописать условие Digit < 1000 || Digit >= 10000. Это значит что число не четырехзначное. А если
		число не в 4 знака, а в 5 или 6, то этот вариант не подойдет.
		2.вариант: чтобы проверить size-значное число нужно проанализировать логику и найти закономерность:
		двухзначное число:		10   <= digit < 100			10^1 <= digit < 10^2
		трехзначное число:		100  <= digit < 1000		10^2 <= digit < 10^3
		четырехзначное число:	1000 <= digit < 10000		10^3 <= digit < 10^4, т.о.
		size-значное число получается от
											10^size-1 <= digit < 10^size */
		do
		{
			cout << "Введите " << size << "-значное число, состоящее из разных цифр: ";
			cin >> digit;

			if (digit < pow(10, size - 1) || digit >= pow(10, size))				// если пользователь ввел нечетырехзначное число:
				cout << "Некорректный ввод! Проверьте количество знаков в числе. Число не должно начинаться с нуля." << endl;
		} while (digit < pow(10, size - 1) || digit >= pow(10, size));
		// Если digit меньше чем 1000 или больше/равен 10000 при size == 4, повторю цикл.

		Slice(digit);																// как только игрок ввел правильное число, нарежу его в функции
		win = Result();																// считаю количество быков и коров и помещаю количество быков в переменную win
	} while (win != size);															// играем пока количество быков не равно количеству цифр в загаданном числе
	/* Если мы вышли из цикла do_while это значит что игрок угадал, а именно то число, которое он вводил совпало с загаданным. Игрок вводит digit. Победа игрока будет
	когда digit совпадет с тем что в number хранится. Игрок вводит число, помещаемое в digit. Далее его функция режет, сравнивает, и если количество быков совпало, то
	победа. */
	cout << "Вы угадали! Загаданное число: " << digit << endl;						// когда игрок угадал, его digit совпадает с заг.числом, его и выведем для простоты
	system("pause");
}

void SetNumber()
/* Т.к. надо заг.число помещать в массив, надо каждую цифру загадывать по-отдельности [][][][]. Т.к. 1-ая цифра не должна быть нулем, ее надо загадать отдельно. Генера-
ция каждой последующей цифры будет в ц.for т.к. не отличается от предыдущей. Там может быть 0 и не 0. После того как была сгенерирована след.цифра, надо проверить не
совпала ли она с предыдущими, пройти в цикле и проверить предыдущие цифры (ЗАНОВО ПРОЙТИСЬ ПО ВСЕМУ МАССИВУ). */
{
	Number[0] = rand() % 9 + 1;														// числа от 1 до 9 включительно
	for (int i = 1; i < size; i++)													// генерация оставшихся цифр в числе
	{
		Number[i] = rand() % 10;
		for (int j = 0; j < i; j++)													// проверка всех цифер перед j.
		{
			if (Number[i] == Number[j])												// новая цифра совпала с ОДНОЙ из ПРЕДЫДУЩИХ
			{
				i--;																// нужно i-ю цифру заново сгенерировать и вернуться к циклу генерации
				break;																// операторы break и continue сработают на ближ.цикл, в котором они были объявлены
			}
		}
	}
}
/* continue пропускает все действия, указанные после него и компилятор переходит к проверке условия и увеличению счетчика, а break прерывает полностью цикл. continue
пропускает какой-то шаг цикла (3-й, 5-й,...), т.е. пропуск одной итерации цикла, а break полностью остановит весь цикл и выйдет из него. */

void Slice(int digit)				/* Функция нарезки числа будет применима к числу любой длины, но при этом нужен соответствующий размер массива.
   Принимать в качестве параметра она будет число, которое будет порезано. Чтобы взять отдельную цифру из числа есть два варианта:

1. Если известно точное количество цифр в числе. Например их 4 (3578). Делю на 1000 и получаю первою цифру 3. Далее беру остаток от деления 3578 на 1000 и получаю 578.
   А после 578 делю на 100 и получаю 5. Далее беру остаток от деления 578 на 100 и получаю 78. Потом делю 78 на 10 и получаю 7, беру остаток от деления 78 на 10 и полу-
   чаю 8. Это алгоритм деления на 10 в степени размер-1, где размер постоянно уменьшается.
   Этот способ неудобен для цикла и лучше с малым числом. Приведем в степени: 1000 это 10^3, где 3 это size-1 (если 4-х значное число). Далее будет ц.for:
   for (int i = size; i > 0; i--)
   {
		digit/pow(10,i-1);
   }
   Последняя восьмерка встает поперек горла и необходимо еще что-то для нее придумать и усложнить алгоритм.

2. Деление на 10 с отщипыванием последних цифр, а не первых. Но это и не важно ибо тут массив и есть возможность перевернуть последовательность цифр. Второй вариант
   проще. Если такой возможности нет, то придется обходиться 1-м вариантом. А в массив можно в любую ячейку поместить любое значение. Сложим массив в обратном порядке,
   начав не с нулевого элемента, а с третьего. И так далее сам алгоритм:
		3578 % 10 = 8
		3578 / 10 = 357
		357 % 10 = 7
		357 / 10 = 35
		35 % 10 = 5
		35 / 10 = 3
		3 % 10 = 3
		3 / 10 = 0
   Все операции удобны и из них я буду выбирать лишь нужные цифры: 8; 7; 5; 3; В третий элемент положу 8, во второй 7..., в нулевой 3. Нарезать можно с любого края, но
   чаще всего это удобнее делать с конца с необходимостью разворачивать последовательность полученных цифр. С массивом это удобно. */
{
	for (int i = size - 1; i >= 0; i--)								// seze-1 т.к. нужен сразу 3-й индекс элемента (всего 4 элемента), а последний будет нулевой
	{
		Value[i] = digit % 10;										// записываем цифру в массив
		digit /= 10;												// "отрезаем" записанную цифру от числа
	}
}

int Result()
/* Функция поиска быков и коров, сравнивая цифры друг с другом. Надо обратить внимание на механику сравнения. Пользовательский ввод непредсказуем и от него оттал-
киваться тяжело и неверно ибо в пользовательском вводе числа могут повторяться, поэтому нужно из загаданного числа брать цифры и искать их в пользовательском. При взя-
тии цифры из загаданного числа первым делом проверяется приоритетный бык, а если бык не найден, то проверяется корова. Если бык найден, то перехожу к сле-
дующей цифре загаданного числа. Если бык не найден, а попалась корова, то также перехожу к следующей цифре загаданного числа. Одна цифра не может быть одновременно
и быком, и коровой - что-то одно. Брать в расчет одинаковые в пользовательском ряду цифры не имеет смысла, т.к. от этого цифра не изменится и ее количество в за-
гаданном числе не увеличится. */
{
	int bulls = 0, cows = 0;
	for (int i = 0; i < size; i++)			// цикл прохода по загаданному числу
	{
		if (Number[i] == Value[i])			// если цифра из заг.числа стоит в таком же разряде как и у введенном игроком числа (если текущая цифра из заг.числа бык)
		{
			bulls++;
			continue;						// переходим к след.цифре в заг.числе
		}
		for (int j = 0; j < size; j++)		// цикл поиска коровы - цифры из заг.числа, введенного игроком (с каждой цифрой от начала числа)
		{
			if (Number[i] == Value[j])		// если текущая цифра из заг.числа где-то есть в числе игрока
			{
				cows++;
				break;						// если корова найдена, то больше корову искать не надо (выходим из цикла поиска коровы и переходим к след.цифре заг.числа)
			}
		}
	}
	cout << "Быки: " << bulls << " Коровы: " << cows << endl;
	return bulls;
}						// ДЗ 2.34 и 2.51