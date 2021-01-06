#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string number1;     //это наше число

    cout << "Введите число:\n";
    getline(cin, number1);

    int len = 0;   
    while (number1[len]) //считываем длину
    {
        len++;
    }

    int dec = 0;
    for (int i = 0; i < len; i++)       //перевод в десятичную
    {

        dec += (number1[i]-'0') * pow(6, len - i - 1);   
    }

    char* number2 = new char[len];      //перевод в тринадцатеричную
    int i;
    for (i = 0; dec != 0; i++)
    {
        if (dec % 13 == 10)
            number2[i] = 'A';
        else if (dec % 13 == 11)
            number2[i] = 'B';
        else if (dec % 13 == 12)
            number2[i] = 'C';
        else
            number2[i] = dec % 13 +'0';
        dec /= 13;
    }

    for (int j = i - 1; j > -1; j--)        //вывод на консоль переведенного числа
    {
        cout << number2[j];
    }
}


