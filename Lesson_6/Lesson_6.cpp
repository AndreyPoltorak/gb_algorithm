#include <iostream>

using namespace std;

void sort(int ** mass, int row, int col)
{
    for (int i = 0; i < (row * col) -1 ; i++)
    {
        for (int j = i + 1; j < (row * col); j++)
        {
            if (mass[i / col][i - ((i / col) * col)] > mass[j / col][j - ((j / col) * col)])
            {
                int tmp = mass[i / col][i - ((i / col) * col)];
                mass[i / col][i - ((i / col) * col)] = mass[j / col][j - ((j / col) * col)];
                mass[j / col][j - ((j / col) * col)] = tmp;
            }
        }
    }
}

void print(int** mass, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "mass[" << i << "][" << j << "]  = " << mass[i][j] << endl;
        }
    }
}

int** initArray(int** mass, const int row, const int col)
{

    for (int i = 0; i < row; i++)
    {
        *(mass + i) = (int*) calloc(sizeof(int), col);
    }
    return mass;
}

void algorithmTrabboPradaKunta()
{
    double mass[11];
    for (int i = 0; i < 11; i++)
    {
        cout << endl << " Введите число № " << i+1 << ":";
        cin >> mass[i];
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        double tmp = mass[i];
        mass[i] = mass[10 - i];
        mass[10 - i] = tmp;
    }

    for (int i = 0; i < 11; i++)
    {
        double a = sqrt(fabs(mass[i])) + 5 * pow(mass[i], 3);
        if (a > 400)
        {
            cout << "Результат вычисления значения под номером "<< 11 - i << " > 400" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int const row = 3;
    int const col = 3;
    int** mass;// = initArray(mass, row, col);
    // ------------------ 
    mass = (int**)calloc(sizeof(int*), row); //перед вызовом функции initArray требует иницилизацию mass
    // ------------------
    mass = initArray(mass, row, col);

    mass[0][0] = 1;
    mass[0][1] = 9;
    mass[0][2] = 2;
    mass[1][0] = 5;
    mass[1][1] = 7;
    mass[1][2] = 6;
    mass[2][0] = 4;
    mass[2][1] = 3;
    mass[2][2] = 8;
    sort(mass, 3, 3);
    print(mass, 3, 3);

    algorithmTrabboPradaKunta();

    system("pause");
}