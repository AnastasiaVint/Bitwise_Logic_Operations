#define _CRT_SET_NO_WARNING
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void pack()
{
    int word = 0;
    int h, t, s;
    cout << "Введіть h-номер головки, від 0 до 3 : ";
    cin >> h;
    while (h < 0 || h > 3)
    {
        cout << "Невірно введено значення, повторіть ще раз від 0 до 3 : ";
        cin >> h;
    }
    cout << "Введіть t-номер доріжки, від 0 до 511 : ";
    cin >> t;
    while (t < 0 || t > 511)
    {
        cout << "Невірно введено значення, повторіть ще раз від 0 до 511 : ";
        cin >> t;
    }
    cout << "Введіть s-номер сектора, від 0 до 31 : ";
    cin >> s;
    while (s < 0 || s > 31)
    {
        cout << "Невірно введено значення, повторіть ще раз від 0 до 31 : ";
        cin >> s;
    }

    cout << "Пакування диску.";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << "." << endl;
    Sleep(1000);
    cout << endl;
    word = h;
    word = (word << 9) | t;
    word = (word << 5) | s;
    cout << "Хеш код диску : ";
    cout << word;
    cout << endl;
}

void unpack()
{
    int word = 0;
    int h, t, s;

    cout << "Введіть хеш код диску : ";
    cin >> word;
    cout << endl;
    s = word & 31;
    t = (word >> 5) & 511;
    h = (word >> 9) & 3;
    Sleep(250);
    cout << "s " << s << endl;
    Sleep(500);
    cout << "t " << t << endl;
    Sleep(500);
    cout << "h " << h;
    cout << endl;

}

void convert1()
{
    cout << endl;
    int bin[100], dec, i;
    cout << "Введіть число в десятковій системі для переведення : ";
    cin >> dec;
    for (i = 0; dec > 0; i++)
    {
        bin[i] = dec % 2;
        dec = dec / 2;
    }
    cout << endl;
    cout << "Це число в двійковій системі : ";
    for (i = i - 1; i >= 0; i--)
    {
        cout << bin[i];
    }
    cout << endl << endl;
}

void convert2()
{
    cout << endl;
    int bin;
    cout << "Введіть число в двійковій системі для переведення : ";
    cin >> bin;
    int dec = 0;
    int base = 1;
    int temp = bin;
    while (temp)
    {
        int lastDigit = temp % 10;
        temp = temp / 10;
        dec += lastDigit * base;
        base = base * 2;
    }
    cout << "Це число в десятковій системі : " << dec << endl;
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    bool exit = false;
    cout << "Що бажаєте зробити ?" << endl;
    while (!exit)
    {
        cout << "1 - Упаковка даних" << endl << "2 - Розпаковка даних" << endl << "3 - Переведення (десяткова -> двійкова)" << endl << "4- Переведення (двійкова -> десяткова)" << endl;
        cout << "Вибір:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            pack();
            cout << "Для завершення роботи системи натисніть 0, інше значення продовження роботи" << endl;
            cout << "Вибір:";
            cin >> choice;
            if (choice == 0)
            {
                cout << "Завершення роботи";
                return 0;
            }
            break;
        case 2:
            unpack();
            cout << "Для завершення роботи системи натисніть 0, інше значення продовження роботи" << endl;
            cout << "Вибір:";
            cin >> choice;
            if (choice == 0)
            {
                cout << "Завершення роботи";
                return 0;
            }
            break;
        case 3:
            convert1();
            cout << "Для завершення роботи системи натисніть 0, інше значення продовження роботи" << endl;
            cout << "Вибір:";
            cin >> choice;
            if (choice == 0)
            {
                cout << "Завершення роботи";
                return 0;
            }
            break;
        case 4:
            convert2();
            cout << "Для завершення роботи системи натисніть 0, інше значення продовження роботи" << endl;
            cout << "Вибір:";
            cin >> choice;
            if (choice == 0)
            {
                cout << "Завершення роботи";
                return 0;
            }
            break;
        default:
            cout << "Така команда відсутня, спробуйте ще" << endl;
            break;
        }
    }
}