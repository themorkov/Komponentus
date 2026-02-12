#include <iostream>
#include <conio.h> 
#include <windows.h>
#include "Model.h"
#include "Controller.h"
#include <limits>

/*
* @brief функция установки цвета текста и фона в консоли windows
* @param text пармаетр цвета текста
* @param bg параметр цвета фона
*/
void SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
/*
* @brief функция отображения логотипа в консоли
*/
void printLabel()
{
    SetColor(13, 0);
    setlocale(LC_ALL, "Russian");
    std::cout << R"( _  _____  __  __ ____   ___  _   _ _____ _   _ _____ _   _ ____  
| |/ / _ \|  \/  |  _ \ / _ \| \ | | ____| \ | |_   _| | | / ___| 
| ' / | | | |\/| | |_) | | | |  \| |  _| |  \| | | | | | | \___ \ 
| . \ |_| | |  | | |__/| |_| | |\  | |___| |\  | | | | |_| |___) |
|_|\_\___/|_|  |_|_|    \___/|_| \_|_____|_| \_| |_|  \___/|____/ 
)";
    SetColor(14, 0);
    std::cout << "             ПЕРЕВОДНАЯ ТАБЛИЦА МИКСОВ АВТОЭМАЛЕЙ";
    std::cout << "\n";
    SetColor(7, 0);
}
/*
* @brief функция отображения текста главного меню в консоли
*/
void printGreeting()
{
    while (true)
    {
        system("cls");
        printLabel();
        SetColor(10, 0);
        std::cout << R"(
     Для перевода из Spies Hecker в Standox нажмите ENTER
          Для выбора производителя нажмите ПРОБЕЛ
                   Для выхода нажмите ESC 
)";
        SetColor(7, 0);

        int key = _getch();

        switch (key)
        {
        case 13:
            compareMixes(0, 1);
            break;
        case 32:
            choiceBrands();
            break;
        case 27:
            exit(0);
        default:
            break;
        }
    }
}

void printCompareText( std::string x, std::string y)
{
    system("cls");
    printLabel();
    SetColor(10, 0);
    std::cout << "   Перевод компонентов из системы " << x << " в систему " << y << "\n";
    std::cout << "            Для выхода в главное меню введите exit" << "\n";
    SetColor(7, 0);
}

void printChoiceBrandsText()
{
    system("cls");
    printLabel();
    std::cout << R"(
[1] Spies Hecker	[13] Baslac 		[25] Hebake	
[2] Standox		[14] Spectral		[26] Kapci	
[3] Brulex		[15] Green Line 	[27] Sikkens	
[4] Profiline		[16] R-M		[28] Lesonal	
[5] Mobihel 		[17] DuPoint		[29] DYNA	
[6] Normex		[18] PPG		[30] Debeer	
[7] Nason 		[19] Quick Line 	[31] Kansai Paint	
[8] Loritone		[20] Autolux		[32] Cardea	
[9] Kiwix		[21] Maxmaeyer		[33] Rock Paint	
[10] Vika		[22] REIZ		[34] KCC	
[11] Duxone		[23] Miramishi		[35] Maxmeyer	
[12] General		[24] Yatu EasiCoat	[36] Glasurit 55 line 	
)";
    SetColor(10, 0);
    std::cout << "      Для выхода в главное меню введите любое значение не из списка" << "\n";
    SetColor(7, 0);
}