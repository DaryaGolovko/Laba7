#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;

void full(string& number, vector<int>& num)     //перевод в прямой код
{
    int i = 1;
    int len = number.size();

    if (number[0] == '-')   //число отрицательное
    {
        num[0] = 1;
        for (i = 1; i < (9-len); i++)   
        {
            num[i] = 0;
        }

        for (int j = 1; j < len; i++,j++)
        {
            num[i] = (number[j]-48);
        }
    }
    else                    //число положительное
    {
        num[0] = 0;
        for (i = 1; i < (8 - len); i++)
        {
            num[i] = 0;
        }

        for (int j = 0; j < len; i++, j++)
        {
            num[i] = (number[j] - 48);
        }
    }
}

void summ(vector<int>& n1, vector<int>&n2, vector<int>& sum)
{
    for (int i = 1; i < n1.size(); i++)     //пробег по элементам
    {
        if (n1[i - 1] + n2[i - 1] == 0)
        {
            sum.push_back(0);
            continue;
        }
        if (n1[i - 1] + n2[i - 1] == 1)
        {
            sum.push_back(1);
            continue;
        }
        if (n1[i - 1] + n2[i - 1] == 2)
        {
            sum.push_back(0);
            n1[i]++;
            continue;
        }
        if (n1[i - 1] + n2[i - 1] == 3)
        {
            n1[i]++;
            sum.push_back(1);
            continue;
        }
    }
    sum.push_back(0);
}

void translate(vector<int>& num)
{
    for (int i = 1; i < 8; i++)     
    {
        if (num[i] == 1)
        {
            num[i] = 0;
        }
        else if (num[i] == 0)
        {
            num[i] = 1;
        }
    }
}

void translate2(vector<int>& sum)
{
    for (int i = 1; i < 8; i++)
    {
        if (sum[i] == 1)
        {
            sum[i] = 0;
        }
        else if (sum[i] == 0)
        {
            sum[i] = 1;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string number1, number2;
    vector<int> num1(8), num2(8), sum;

    cout << "Введите 1 число в двоичном коде  ";
    cin >> number1;
    cout << "Введите 2 число в двоичном коде ";
    cin >> number2;

    full(number1, num1);        //перевод в прямой код 1 число
    full(number2, num2);        //перевод в прямой код 2 число

    cout <<"Прямой код 1 числа:"<< endl;
    for (int i = 0; i < 8; i++) //вывод 1 числа
    {
        cout<<num1[i];
    }
    cout <<endl<< "Прямой код 2 числа:" << endl;

    for (int i = 0; i < 8; i++)     //вывод 2 числа
    {
        cout << num2[i];
    }

    if (number1[0] == '-')   //число отрицательное-перевод в обратный(1)
    {
        translate(num1);
    }

    if (number2[0] == '-')   //число отрицательное-перевод в обратный(2)
    {
        translate(num2);
    }

    cout <<endl << "Обратный код 1 числа:" << endl;
    for (int i = 0; i < 8; i++) //вывод 1 числа
    {
        cout << num1[i];
    }
  
    cout << endl << "Обратный код 2 числа:" << endl;
    for (int i = 0; i < 8; i++)     //вывод 2 числа
    {
        cout << num2[i];
    }

    cout <<endl<< "Сумма в прямом:"<<endl;
    summ(num1, num2,sum);
    translate2(sum);
    for (int i=0; i< sum.size(); i++)
    {
        cout << sum[i];
    }

}