#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string number;

    cout << "Введите число в дополнительном коде:";
    cin >> number;

    int i = 7;
    if (number[0] == '0')
    {
        cout << "Oбратный и дополнительный код равны, число положительное:";
    }
    else
    {
        if (number[7] == '1')
        {
            number[7] = '0';
        }
        else
        {
            while (number[i] == '0')
            {
                number[i] = '1';
                i--;
            }
            if (number[i] == '1')
            {
                number[i] = '0';
            }
        }
    }
    cout << number;
}