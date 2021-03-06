#include <iostream>
#include <cmath>

//Подпрограмма для прибавления к двоичному числу единицы
int byte_plus(int number)
{
    //Переменная dec обозначает число 10 в той или иной степени
    int dec = 1;
    //check - логическая переменная, принимающая значения 0/1
    bool check = 1;
    //Переменная save принимает значение number, "сохраняя" её
    int save = number;
    //Цикл продолжается, пока переменная check равна единице
    while (check)
    {
        //В этом условии проверяется отстаток от числа save: если он равен единице, от переменной number отнимается переменная dec
        //Если же он равен 0, эта переменная к ней добавляется
        if (save % 10 == 0)
        {
            check = 0;
            number += dec;
        }
        else
        {
            number -= dec;
        }
        dec *= 10;
        save /= 10;
        //Каждый оборот цикла dec умножается на 10, а переменная save - делится на 2
    }
    //Таким образом, цикл проверяет разряды переменной number, начиная с самого младшего, пока не встречает разряд, равный 0
    //Пример: при number = 10001111, получается 10010000
    return number;
}

//Подпрограмма для вычитания единицы из двоичного числа: она очень слабо отличается от предыдущей, так что здесь будет мало
//объяснений
int byte_minus(int number)
{
    int dec = 1;
    bool check = 1;
    int save = number;
    while (check)
    {
        if (save % 10 == 0)
        {
            number += dec;
        }
        else
        {
            check = 0;
            number -= dec;
        }
        dec *= 10;
        save /= 10;
    }
    //Выглядит похоже на предыдущую подпрограмму. Основное отличие в том, что переменная check обнуляется, когда в разряде появляется
    //единица. Все числа до неё заменяются нулями
    return number;
}

//Первое задание: тут всё делается одним из способов, показанных на первой лекции. Я использовала метод sizeof(), так как уже
//работала с ним раньше
void first_task()
{
    std::cout << "\nВы выбрали первое задание!\n";
    std::cout << "Первое задание: Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.\n";
    std::cout << "В типе int " << sizeof(int) << " байта.\n";
    std::cout << "В типе short int " << sizeof(short int) << " байта.\n";
    std::cout << "В типе long int " << sizeof(long int) << " байта.\n";
    std::cout << "В типе float " << sizeof(float) << " байта.\n";
    std::cout << "В типе double " << sizeof(double) << " байтов.\n";
    std::cout << "В типе long double " << sizeof(long double) << " байтов.\n";
    std::cout << "В типе char " << sizeof(char) << " байт.\n";
    std::cout << "В типе bool " << sizeof(bool) << " байт.\n";
}

//Второе задание: с целым числом (int)
void second_task(int number)
{
    //two_in_degree изначально представляет из себя число 2 в 30-й степени
    unsigned int two_in_degree = 1073741824;
    //sign_number ответственен за первый бит (знак числа), cnt - переменная-счётчик, будет использоваться для разделения байтов
    //отступами в числе
    int sign_number, cnt;
    //Данное условие определяет переменную sign_number и преобразует переменную number в положительное число, если она отрияательная
    //Это делается для дальнейшего удобства
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    int save = number;
    cnt = 0;
    //Тут выводится бит, отвечающий за знак числа, и сразу же отделяется его отступом
    std::cout << sign_number << ' ';
    //Финальный цикл, где вычиcляется само двоичное представление number
    while (two_in_degree)
    {
        //Эта часть ответственна за счётчик cnt и, соответственно, отступы
        cnt += 1;
        if (cnt % 8 == 0)
        {
            std::cout << ' ';
        }
        //А эта - за перевод числа в двоичное представление
        //Конечно, обычно такой перевод можно было осуществить, как это учат на уроке информатики и поэтапно делить число на два, пока
        //оно не станет единицей: это можно осуществить, к примеру, если создать массив bool (логических чисел), по умолчанию
        //заполнив его нулями, а затем ставить единицы, каждый раз, когда число не будет делиться нацело, а затем пройтись по 
        //массиву, выводя значения с 23 элемента по 0. Однако массивов в модулях до этой практической нет, да и это долго, так что
        //я решила взять два в максимальной степени, больше которой может быть number. С учётом того, что на integer отводится 32
        //бита, а один бит уходит на указание знака, получается 2 в 30 степени
        //Мы сравниваем number и two_in_degree
        if (number >= two_in_degree)
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
        //А затем мы присваем number остаток от деления на two_in_degree, a two_in_degree делим на 2
        number %= two_in_degree;
        two_in_degree /= 2;
    }
    if (sign_number == 1)
    {
        cnt = 0;
        number = save;
        std::cout << "\nОбратный код: " << sign_number << ' ';
        two_in_degree = 1073741824;
        while (two_in_degree)
        {
            cnt += 1;
            if (cnt % 8 == 0)
            {
                std::cout << ' ';
            }
            if (number >= two_in_degree)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
            number %= two_in_degree;
            two_in_degree /= 2;
        }
        two_in_degree = 1073741824;
        cnt = 0;
        number = save - 1;
        std::cout << "\nДополнительный код: " << sign_number << ' ';
        while (two_in_degree)
        {
            cnt += 1;
            if (cnt % 8 == 0)
            {
                std::cout << ' ';
            }
            if (number >= two_in_degree)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
            number %= two_in_degree;
            two_in_degree /= 2;
            }
    }
    std::cout << '\n';
}

//Третье задание: с дробным числом (float)
void third_task(float number)
{
    //Переменная, обозначающая порядок
    unsigned int order;
    //Переменная sign_number отвечает за знак числа, cnt - за то, в каком месте "запятая" числа (если она от 0 до 23)
    int sign_number, cnt;
    //Переменная d_cnt - счётчик для массива
    int d_cnt = 1;
    //Условие на определение знака числа
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    cnt = 0;
    //Резервная переменная, равная number
    float save = number;
    order = 1111111;
    std::cout << sign_number << ' ';
    //Условие для определение порядка числа
    if (number >= 1)
    {
        //Если модуль числа больше единицы, порядок (находящийся во 2 системе счисления), увеличивается на единицу
        while (save >= 1)
        {
            cnt += 1;
            save /= 2;
            order = byte_plus(order);
        }
        cnt -= 1;
    }
    else
    {
        //Если модуль числа больше единицы, порядок (находящийся во 2 системе счисления), уменьшается на единицу
        while ((save < 1) and (order > 0))
        {
            cnt -= 1;
            save *= 2;
            order = byte_minus(order);
        }
    }
    int dec = 1000000;
    //Этот цикл дополняет нулями порядок до 8 цифр
    while (order < dec)
    {
        std::cout << 0;
        dec /= 10;
    }
    std::cout << order << ' ';
    //Переменная z_part - целая часть переменной number
    float z_part = floor(number);
    //Переменная d_part - целая часть переменной number
    float d_part = number - z_part;
    float two_in_degree = 1;
    d_cnt = 0;
    //Алгоритм схож с тем, который используется в прошлой задаче, но немного изменён в связи с тем, что теперь число дробное
    //В дробном числе нельзя использовать оператор %, так что я заменила эту операцию вычитанием
    //В этом цикле находится максимальная степень числа 2, которая меньше целой части числа
    while ((two_in_degree * 2) <= z_part)
    {
        two_in_degree *= 2;
    }
    //Затем она вычитается из целой части числа (в типе float первая единица не записывается (но подразумевается) для экономии памяти)
    z_part -= two_in_degree;
    two_in_degree /= 2;
    //И начинается цикл, в котором вычисляется двоичное представления целой части числа
    while ((two_in_degree >= 1) and (d_cnt < 23))
    {
        if (z_part >= two_in_degree)
        {
            std::cout << 1;
            z_part -= two_in_degree;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
        two_in_degree /= 2;
    }
    //Тут могла бы быть запятая
    if (d_cnt != 0)
    {
        std::cout << ' ';
    }
    //С целой частью закончено! Теперь приступаем к дробной
    if (cnt < 0)
    {
        //Если изначально число меньше единицы, часть с вычислением целой части числа пропускается, значит надо дойти
        //до состояния первой единицей. Дополнительное условие со счётчиком необходимо на случай, если вводится 0
        //Без него при таком условии получился бы бесконечный цикл
        while (d_part < 1 and cnt < 0)
        {
            cnt += 1;
            d_part *= 2;
        }
        cnt = 0;
        if (d_part >= 1)
        {
            d_part -= 1;
        }
    }
    d_cnt += 9;
    //И дальше вычисляется дробная часть
    while (d_cnt < 32)
    {
        d_part *= 2;
        if (d_part >= 1)
        {
            std::cout << 1;
            d_part -= 1;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
    }
    std::cout << '\n';
}

void forth_task(double number)
{
    int order[11] = { 0,1,1,1,1,1,1,1,1,1,1 };
    int sign_number, cnt;
    int d_cnt = 11;
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    cnt = 0;
    double save = number;
    std::cout << sign_number << ' ';
    if (number >= 1)
    {
        while (save >= 1)
        {
            cnt += 1;
            save /= 2;
            bool check = 1;
            d_cnt = 10;
            while (check)
            {
                if (order[d_cnt] == 0)
                {
                    order[d_cnt] = 1;
                    check = 0;
                }
                else
                {
                    order[d_cnt] = 0;
                }
                d_cnt -= 1;
            }
        }
        cnt -= 1;
    }
    else
    {
        while ((save < 1) and (order > 0))
        {
            cnt -= 1;
            save *= 2;
            bool check = 1;
            d_cnt = 11;
            while (check)
            {
                if (order[d_cnt] == 0)
                {
                    order[d_cnt] = 1;
                }
                else
                {
                    order[d_cnt] = 0;
                    check = 0;
                }
                d_cnt -= 1;
            }
        }
    }
    d_cnt = 1;
    int dec = 100000000;
    for (int i = 0; i < 11; i++)
    {
        std::cout << order[i];
    }
    std::cout << ' ';
    double z_part = floor(number);
    double d_part = number - z_part;
    double two_in_degree = 1;
    d_cnt = 0;
    while ((two_in_degree * 2) <= z_part)
    {
        two_in_degree *= 2;
    }
    z_part -= two_in_degree;
    two_in_degree /= 2;
    while ((two_in_degree >= 1) and (d_cnt < 52))
    {
        if (z_part >= two_in_degree)
        {
            std::cout << 1;
            z_part -= two_in_degree;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
        two_in_degree /= 2;
    }
    if (d_cnt != 0)
    {
        std::cout << ' ';
    }
    if (cnt < 0)
    {
        while (d_part < 1 and cnt < 0)
        {
            cnt += 1;
            d_part *= 2;
        }
        cnt = 0;
        if (d_part >= 1)
        {
            d_part -= 1;
        }
    }
    d_cnt += 9;
    while (d_cnt < 64)
    {
        d_part *= 2;
        if (d_part >= 1)
        {
            std::cout << 1;
            d_part -= 1;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
    }
    std::cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Привет!\n";
    int number;
    int int_num;
    float float_num;
    double double_num;
    number = 7;
    std::cout << "\n1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.\n";
    std::cout << "2) Вывести на экран двоичное представление в памяти(все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.\n";
    std::cout << "3) Вывести на экран двоичное представление в памяти(все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка(если есть), мантиссу и порядок.\n";
    std::cout << "4) Вывести на экран двоичное представление в памяти(все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка(если есть), мантиссу и порядок.\n";
    std::cout << "0) Закончить программу.\n";
    try {
        while (number != 0)
        {
            std::cout << "\nВыбери номер: ";
            std::cin >> number;
            if (!std::cin)
            {
                throw "ex";
            }
            std::cout << '\n';
            switch (number)
            {
            case 1: first_task();
                break;
            case 2: std::cout << "\nВы выбрали второе задание!\n";
                std::cout << "Вывести на экран двоичное представление в памяти(все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.\n";
                std::cout << "Введите число: ";
                std::cin >> int_num;
                second_task(int_num);
                if (!std::cin)
                {
                    throw "ex";
                }
                break;
            case 3: std::cout << "\nВы выбрали третье задание!\n";
                std::cout << "Вывести на экран двоичное представление в памяти(все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка(если есть), мантиссу и порядок.\n";
                std::cout << "Введите число: ";
                std::cin >> float_num;
                third_task(float_num);
                if (!std::cin)
                {
                    throw "ex";
                }
                break;
            case 4: std::cout << "\nВы выбрали четвёртое задание!\n";
                std::cout << "Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)\n";
                std::cout << "Введите число: ";
                std::cin >> double_num;
                if (!std::cin)
                {
                    throw "ex";
                }
                forth_task(double_num);
                break;
            }
        }
    }
    catch (...)
    {
        std::cout << "\nНекорректные данные!\n";
    }
}
