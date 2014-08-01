///#############################################################################################
///###                   Program weryfikujacy date                                           ###
///###                   Bartosz Gebura                                                      ###
///#############################################################################################

#include <iostream>

using namespace std;

typedef struct Date /// tworzenie struktury Date
{
    short int day, month, year; /// short w celu zmniejszenia zapotrzebowania na pamiec
} Date;

void add_date(Date *date) /// wczytywanie wartosci zmiennych z konsoli
{
    cout << "Podaj dzien: ";
    cin >> date->day;
    cout << "Podaj miesiac: ";
    cin >> date->month;
    cout << "Podaj rok: ";
    cin >> date->year;
}

bool testing_date(Date *date) /// metoda testujaca date
{
    if(date->month < 1 || date->month > 12) /// sprawdzamy, czy wprowadzony miesiac nie jest ujemny, 0, lub powyzej 12.
    {
        cout << "Data nie jest poprawna. Niepoprawny miesiac!";
        return false; /// jesli bledny miesiac to zwroc false
    }
    if(date->month == 2) /// sprawdzamy warunki dla lutego.
    {
        if((date->year % 4 == 0) && (date->year % 100 != 0)||(date->year % 400 == 0)) /// gdy luty jest przestepny.
        {
            if(date->day <= 0 || date->day > 29) /// jesli ma mniej niz 1 dzien lub wiecej niz 29 dni. 29 moze byc.
            {
                cout << "Data nie jest poprawna. Niepoprawny dzien lutego w roku przestepnym!";
                return false; /// jesli luty przestepny ma wiecej niz 29dni to zwroc false
            }
        }
        else /// warunek dla lutego w roku zwyklym.
        {
            if(date->day <= 0 || date->day >= 29) /// false, gdy mniej niz 1 dzien lub wiecej niz 28 dni.
            {
                cout << "Data nie jest poprawna. Niepoprawny dzien lutego w roku zwyklym!";
                return false; /// jesli w zwyczajnym lutym dni jest wiecej niz 28 to zwroc false
            }
        }
    }
    if(date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) /// warunki dla miesiecy, ktore moga miec 30 dni.
    {
        if(date->day <= 0 || date->day >= 31) /// jesli ilosc dni jest mniejsza niz 1 lub wieksza od 30
        {
            cout << "Data nie jest poprawna. Niepoprawny dzien!";
            return false; /// zwracamy na false
        }
    }
    else
    {
        if(date->day <= 0 || date->day > 31)
        {
            cout << "Data nie jest poprawna. Niepoprawny dzien!";
            return false; /// jesli bledny miesiac to zwroc false
        }
    }
    cout << "Wprowadziles poprawne dane. Wpisana data to: "
         << date->day << " "
         << date->month << " "
         << date->year;
}

int main()
{
    Date _new[3];
    add_date(_new);
    testing_date(_new);
    return 0;
}
