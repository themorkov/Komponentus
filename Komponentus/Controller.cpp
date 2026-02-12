#include <iostream>
#include <conio.h> 
#include "Model.h"
#include "WindowsConsoleView.h"
#include <limits>

//динамическая загрузка нужного куска библиотеки <windows.h> для избежания конфилкта имен с "vector_data.h"
extern "C" {
    // Получение дескриптора окна (стандартного вывода)
    __declspec(dllimport) void* __stdcall GetStdHandle(unsigned long nStdHandle);

    // Установка атрибутов текста
    __declspec(dllimport) int __stdcall SetConsoleTextAttribute(void* hConsoleOutput, unsigned short wAttributes);
}

// Константы, которые обычно лежат в windows.h
#define STD_OUTPUT_HANDLE ((unsigned long)-11)


/*
* @brief метод сравнения миксов из разных систем и вывода результата
* @param from переменная хранящая индекс системы из которой выполняется перевод
* @param ещ переменная хранящая индекс системы в которую выполняется перевод
*/
void compareMixes(int from, int to)
{
    std::string selectedMix;
    std::string nameBrandFrom, nameBrandTo;
    nameBrandFrom = nameOfMixes[from];
    nameBrandTo = nameOfMixes[to];
    printCompareText(nameBrandFrom, nameBrandTo);
    while (true)
    {
        std::cout << "\n" << "Введите название компонента " << nameBrandFrom << ": ";
        std::cin >> selectedMix;
        bool isFound = false;

        if (selectedMix == "exit")
        {
            return;
        }
        else
        {
            const int size = 153;
            //цикл проверяет корректность ввода и наличие аналогов в других системах
            for (int i = 0; i < size; i++)
            {
                if (selectedMix == mixes[from][i])
                {
                    if (mixes[to][i] == "")
                    {      
                        std::cout << "\n" << "В системе " << nameBrandTo << " нет аналогов компонента " << selectedMix << "";
                        isFound = true;
                        break;
                        
                    }
                    else
                    {
                        std::cout << nameBrandTo << ": " << mixes[to][i] << "\n";
                        isFound = true;
                        break;
                    }
                }
            }
            if (!isFound)
            {
                std::cout << "Такого компонента нет в " << nameBrandFrom << "\n";
            }      
        }
    }
}
/*
* @bref метод выбора производителей для перевода
* 
* @brief  при вводе некорректного значения: выход в главное меню (любое значение кроме y/Y) 
или продолжение выбора производителей (y/Y)
*/
void choiceBrands()
{
    printChoiceBrandsText();
    std::string userValue;
    int from, to;
    const int size = 35;
    std::cout << "Введите номер производителя из которого будет перевод и нажмите ENTER: ";
    while (!(std::cin >> from) || from < 1 || from > size)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный ввод." << "\n";
        std::cout << "Если вы ошиблись и хотите продолжить введите Y и нажмите ENTER ";
        std::cout << "\n" << "Для выхода в главное меню введите любое значение кроме Y ";
        std::cin >> userValue;
        if (userValue == "y" || userValue == "Y")
        {
            choiceBrands();
            return;
        }
        else
        {
            return;
        }
        
    }

    std::cout << "Введите номер производителя для которого будет перевод и нажмите ENTER: ";
    while (!(std::cin >> to) || to < 1 || to > size || to == from)
    {
        if (to == from)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод: Вы ввели одинаковые значения производителей." << "\n";
            std::cout << "Введите номер производителя для которого будет перевод и нажмите ENTER: ";
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод." << "\n";
            std::cout << "\n" << "Для выхода в главное меню введите любое значение кроме Y ";
            std::cin >> userValue;
            if (userValue != "y" && userValue != "Y")
            {
                return;
            }
            else
            {
                std::cin.clear();
                std::cout << "Введите номер производителя для которого будет перевод и нажмите ENTER: ";
            }
        }
    }

    compareMixes(from-1, to-1);
}


