#include <iostream>

using namespace std;

int pole[5][5] = { 0 };

void perevod_dec_bin(int N)
{
    if (N == 0)
        cout << N << " ";
    else 
    {
        perevod_dec_bin(N >> 1);
        cout << (N & 0x01) << ' ';
    }
}

int recExponentiation(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a * recExponentiation(a, b - 1);
}

int recExponentiationWithParity(int a, int b)
{
    if (b == 1)
        return a;

    if (b % 2)
    {
        return a * recExponentiation(a, b - 1);
    }
    else
    {
        return recExponentiation(a * a, b / 2);
    }    
}

int  waysKings(int x, int y)
{
    if (x == 0 && y == 0 || pole[y][x]==1)
    {
        return 0;
    }
    else if (x == 0)
    {
        if (pole[y - 1][0] == 1)
        {
            pole[y][0] = 1;
            return 0;
        }
          
        return 1;
    }
    else if (y == 0)
    {
        if (pole[0][x - 1] == 1)
        {
            pole[0][x] = 1;
            return 0;
        }
        return 1;
    }
    else
    {
       
        return waysKings(x - 1, y) + waysKings(x, y - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    perevod_dec_bin(8);
    cout << endl << recExponentiation(8, 6) << endl;
  
    cout << endl << recExponentiationWithParity(8, 6) << endl;

    int pole_size = 5;
    
    pole[1][0] = 1;
    
    for (int i = 0; i < pole_size; i++)
    {
        for (int j = 0; j < pole_size; j++)
        {
           cout << waysKings(j, i) << " ";
        }
        cout <<endl;
    }
    system("pause");
}