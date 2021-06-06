#include <iostream>

using namespace std;
void sortXora(int* mass, int first, int last)
{
    int i = first;
    int j = last;
    int x = mass[(first + last) / 2];
    do
    {
        while (mass[i] < x) i++;
        while (mass[j] > x) j--;
        if(i<=j)
        {
            int tmp = mass[i];
            mass[i] = mass[j];
            mass[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) sortXora(mass, i, last);
    if (first < j) sortXora(mass, first, j); 
}
void sortVstavka(int* mass, int length)
{
    int tmp;

    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j > 0 && mass[j] < mass[j - 1])
        {
            tmp = mass[j];
            mass[j] = mass[j - 1];
            mass[j - 1] = tmp;
            j--;
        }
    }
}
void improvedQuickSorting(int* mass, int first, int last, int length)
{
    if (length <= 10)
    {
        sortVstavka(mass, length);
    }
    else
    {
        int mass_1[3] = {mass[first], mass[(first + last) / 2], mass[last]};
        int mass_2[3] = {mass[first], mass[(first + last) / 2], mass[last]};
        int tmp;
        sortVstavka(mass_1, 3);
        if (mass_1[1] == mass_2[0])
        {
            tmp = mass[(first + last) / 2];
            mass[(first + last) / 2] = mass[first];
            mass[first] = tmp;
        }
        else if (mass_1[1] == mass_2[2])
        {
            tmp = mass[(first + last) / 2];
            mass[(first + last) / 2] = mass[last];
            mass[last] = tmp;
        }
        
        sortXora(mass, first, last);

    }
}
void sortBlok(int* mass, int lenght)
{
    const int maxx = lenght;
    const int b = 10;
    int korzina[b][maxx+1];
    for (int i = 0; i < b; i++)
    {
        korzina[i][maxx-1] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i = 0; i < maxx; i++)
        {
                int d = (mass[i] / digit) % b;
                korzina[d][korzina[d][maxx-1]++] = mass[i];
        }
        int idx = 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < korzina[i][maxx-1]; j++)
            {
                if (mass[idx] % 2)
                {
                    idx++;
                }
                else
                {
                    if (mass[i] % 2 == 0)
                    {
                        mass[idx++] = korzina[i][j];
                    }
                }
                
            }
            korzina[i][maxx-1] = 0;
        }

    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    int mass[11] = { 2,33,22,54,34,34,66,42,75,99,9 };
    improvedQuickSorting(mass, 0, 10, 11);
    int mass_2[12] = { 0 ,2, 8 ,3 ,4, 6, 5 ,9 ,8 ,2 ,7, 3 };
    sortBlok(mass_2, 12);
    for (int i = 0; i < 11; i++)
    {
        cout << "mass[" << i << "] = " << mass[i] << endl;
    }
    for (int i = 0; i < 12; i++)
    {
        cout << "mass_2[" << i << "] = " << mass_2[i] << endl;
    }
    system("pause");
}