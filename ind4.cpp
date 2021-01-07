#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

string nplus(string n1, string n2)  //расчет суммы
{
    string sum;
    int l1 = n1.size();
    int l2 = n2.size();

    while (l1 > l2) //добавление знака при разном размере
    {
       n2 = '0' + n2;
    }
    while (l1 < l2)
    {
       n1 = '0' + n1;
    }

    int nsum = 0;
    bool check = false;
    for (int i = (l1-1); i >= 0; i--)   //изменяю значение при цифрах
    {
        if (n1[i] != 'a' && n1[i] != 'b' && n1[i] != 'c' && n1[i] != 'd' && n1[i] != 'e' && n1[i] != 'f')
        {
            nsum += (int)n1[i] - 48;
        }
        if (n2[i] != 'a' && n2[i] != 'b' && n2[i] != 'c' && n2[i] != 'd' && n2[i] != 'e' && n2[i] != 'f')
        {
            nsum += (int)n2[i] - 48;
        }

        if (n1[i] == 'a')   //пробег по буквам
        {
            nsum += 10;
        }
        if (n2[i] == 'a')
        {
            nsum += 10;
        }
        if (n1[i] == 'b')
        {
            nsum += 11;
        }
        if (n2[i] == 'b')
        {
            nsum += 11;
        }
        if (n1[i] == 'c')
        {
            nsum += 12;
        }
        if (n2[i] == 'c')
        {
            nsum += 12;
        }
        if (n1[i] == 'd')
        {
            nsum += 13;
        }
        if (n2[i] == 'd')
        {
            nsum += 13;
        }
        if (n1[i] == 'e')
        {
            nsum += 14;
        }
        if (n2[i] == 'e')
        {
            nsum += 14;
        }
        if (n1[i] == 'f')
        {
            nsum += 15;
        }
        if (n2[i] == 'f')
        {
            nsum += 15;
        }

        if (nsum == 10) //добавление букв
        {
            sum = 'a' + sum;
        }
        else if (nsum == 11)
        {
            sum = 'b' + sum;
        }
        if (nsum == 12)
        {
            sum = 'c' + sum;
        }
        else if (nsum == 13)
        {
            sum = 'd' + sum;
        }
        if (nsum == 14)
        {
            sum = 'e' + sum;
        }
        else if (nsum == 14)
        {
            sum = 'f' + sum;
        }
        else if (nsum < 10)
        {
            sum = to_string(nsum) + sum;
        }

        if (nsum > 11 && (nsum - 12) < 10)
        {
            sum = to_string(nsum - 12) + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 10)
        {
            sum = 'a' + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 11)
        {
            sum = 'b' + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 12)
        {
            sum = 'c' + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 13)
        {
            sum = 'd' + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 14)
        {
            sum = 'e' + sum; check = true;
        }
        else if (nsum > 11 && (nsum - 12) == 15)
        {
            sum = 'f' + sum; check = true;
        }

        if ((nsum - 16) < 0)
        {
            check = false;
        }
        if (check == true)
        {
            nsum = 1; 
        }
        else
        {
            nsum = 0;
        }
    }
    if (nsum == 1)
    {
        sum = '1' + sum;
    }

    return sum;
}

string nminus(string n1, string n2) //расчет разности
{
    string raz;
    int l1 = n1.size();
    int l2 = n2.size();
    if (n1 == n2)
    {
        raz = '0';
        return raz;
    }

    while (l1 > l2)     //добавление знака для расчетов при разной длине
    {
        n2 = '0' + n2;
    }
    while (l1 < l2)
    {
        n1 = '0' + n1;
    }

    int temp = 0;
    bool check = false;
    for (int i = (l1-1); i >= 0; i--)
    {
        if (n1[i] != 'a' && n1[i] != 'b' && n1[i] != 'c' && n1[i] != 'd' && n1[i] != 'e' && n1[i] != 'f')
        {
            temp += (int)n1[i] - 48;
        }
        if (n2[i] != 'a' && n2[i] != 'b' && n2[i] != 'c' && n2[i] != 'd' && n2[i] != 'e' && n2[i] != 'f')
        {
            temp -= (int)n2[i] - 48;
        }

        if (n1[i] == 'a')   //пробег по буквам
        {
            temp += 10;
        }
        if (n2[i] == 'a')
        {
            temp -= 10;
        }

        if (n1[i] == 'b')
        {
            temp += 11;
        }
        if (n2[i] == 'b')
        {
            temp -= 11;
        }

        if (n1[i] == 'c')
        {
            temp += 12;
        }
        if (n2[i] == 'c')
        {
            temp -= 12;
        }

        if (n1[i] == 'd')
        {
            temp += 13;
        }
        if (n2[i] == 'd')
        {
            temp -= 13;
        }

        if (n1[i] == 'e')
        {
            temp += 14;
        }
        if (n2[i] == 'e')
        {
            temp -= 14;
        }

        if (n1[i] == 'f')
        {
            temp += 15;
        }
        if (n2[i] == 'f')
        {
            temp -= 15;
        }

        if (temp > 0)
        {
            check = false;
        }
        if (temp < 0)
        {
            temp += 16; check = true;
        }

        if (temp == 10)
        {
            raz = 'a' + raz;
        }
        else if (temp == 11)
        {
            raz = 'b' + raz;
        }
        if (temp == 12)
        {
            raz = 'c' + raz;
        }
        else if (temp == 13)
        {
            raz = 'c' + raz;
        }       
        if (temp == 14)
        {
            raz = 'e' + raz;
        }
        else if (temp == 15)
        {
            raz = 'f' + raz;
        }
        else if (temp < 10 && temp >= 0)
        {
            raz = to_string(temp) + raz;
        }


        if (check == true)
        {
            temp = -1;
        }
        else
        {
            temp = 0;
        }
    }
    return raz;
}

int main() 
{
	setlocale(LC_ALL, "Russian");

    string number1, number2;    //наши 2 числа

    cout << "Введите 1 число: ";
    cin >> number1;
    cout << "Введите 2 число: ";
    cin >> number2;

    char choice;
    cout << "Выберите действие: +/-  "; //выбор +/-
    cin >> choice;

    if (choice == '+')
    {
       cout<<nplus(number1, number2);   //выбор +
    }
    else if (choice == '-')
    {
       cout<<nminus(number1, number2);      //выбор -
    }

    return 0;
}