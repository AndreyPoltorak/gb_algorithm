#include <iostream>
#define SIZE_STACK 12

using namespace std;

int stack[SIZE_STACK] = {0};
int tail_stack = 0;
const int n = 6;
int matrix_rez[n][n] = {
    {0,1,0,0,0,0},
    {0,0,1,1,1,0},
    {0,0,0,1,0,1},
    {0,0,0,0,1,0},
    {1,0,0,0,0,1},
    {1,0,0,0,0,0},
};

int matrix[n][n] = {
    {0,1,0,0,0,0},
    {0,0,1,1,1,0},
    {0,0,0,1,0,1},
    {0,0,0,0,1,0},
    {1,0,0,0,0,1},
    {1,0,0,0,0,0},
};

int visiten[n] = { 0 };
int out_v1[n] = { 0 };
int out_v2[n] = { 0 };


bool push(int value)
{
    if (tail_stack == SIZE_STACK)
    {
        cout << "Переполнение стека" << endl;
        return false;
    }
    else
    {
        stack[tail_stack++] = value;
        return true;
    }
}

int pop()
{
    if (tail_stack == 0)
    {
        cout << "Стек пуст" << endl;
        return false;
    }
    else
    {
        int a = stack[--tail_stack];
        stack[tail_stack] = -1;
        return a;
    }

}

int bek()
{
        return stack[tail_stack-1];
}



void depthTravers(int st)
{
    
    visiten[st] = 1;
    push(st);
    cout << bek() << "  "  ;
    for (int i = 0; i < n; i++)
    {
        if (matrix[bek()][i] == 1 && !visiten[i])
        {
            
            depthTravers(i);
        }
    }
    pop();
}

void Task_3(int st)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[st][i])
        {
            out_v1[i]++;
            matrix[st][i] = 0;
            Task_3(i);
        }
    }
}

void Task_4(int st)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix_rez[j][i] == 1)
            {
                out_v2[i]++;
            }
        }
    }
}


int sort_1()
{
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (out_v1[i] > max)
        {
            max = out_v1[i];
            index = i;
        }
    }
    out_v1[index] = -1;
    return index;
}


int sort_2()
{
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (out_v2[i] > max)
        {
            max = out_v2[i];
            index = i;
        }
    }
    out_v2[index] = -1;
    return index;
}

void print()
{
    cout << "Первый способ : ";
    for (int i = 0; i < n; i++)
    {
        cout << sort_1() << " ";
    }
    cout << endl << "Второй способ : ";
    for (int i = 0; i < n; i++)
    {
        cout << sort_2() << " ";
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    depthTravers(0);
   
    cout << endl;
    
    
    Task_3(0);
    Task_4(0);
    print();
    system("pause");
}
