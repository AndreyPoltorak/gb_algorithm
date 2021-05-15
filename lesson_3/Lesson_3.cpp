#include <iostream>


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число:\n";
    int a;
    cin >> a;
    int d = a / 2;
    while (d > 1)
    {
        if (a % d == 0)
            break;
        d--;
    }

    if (d <= 1)
        cout << " Число = " << a << " - простое!" << endl;
    else
        cout << " Число = " << a << " не является простым!" << endl;
    system("pause");
}
