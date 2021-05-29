

#include <iostream>
#define SIZE 10
#define SIZE_STACK 32

using namespace std;

typedef struct {
    int key;
    int value;
}Node;

//int head;
int tail;
//int item;
Node* mass[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        mass[i] = NULL;
    }
    int tail = 0;
}

bool insert(int key, int value)
{
    Node* node = new Node;
    node->key = key;
    node->value = value;

    if (tail != SIZE)
    {
        mass[tail++] = node;
        return true;
    }
    else
    {
        cout << "Переполнение массива" << endl;
        return false;
    }
}

Node* remove()
{
    if (tail == 0)
    {
        return NULL;
    }
    else 
    {
        int index = 0;
        int max_key = mass[0]->key;
        for (int i = 1; i < tail; i++)
        {
            if (max_key < mass[i]->key)
            {
                max_key = mass[i]->key;
                index = i;
            }
        }

        Node* tmp = mass[index];
        for (int i = index; i < tail-1; i++)
        {   
            mass[i] = mass[i + 1];
        }
        mass[tail - 1] = NULL;
        tail--;
        return tmp;
    }
}



void print_Node()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (mass[i] != NULL)
        {
            cout << "[" << mass[i]->key << "," << mass[i]->value << "]   ";
        }
        else
        {
            cout << "[*,*] ";
        }
    }
    cout << endl;
}


bool stack[SIZE_STACK];
int tail_stack = 0;

bool push(bool value)
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

bool pop()
{
    if (tail_stack==0)
    {
        cout << "Стек пуст" << endl;
        return false;
    }
    else
    {
        bool a = stack[--tail_stack];
        stack[tail_stack] = NULL;
        return a;
    }
   
}

void trans_dec_bin(unsigned int dec, char * bin)
{
    

    for (int i = 0; i < 32; i++)
    {
        push(dec & 0x01);
        dec = dec >> 1;
    }

    for (int i = 0; i < 32; i++)
    {
        
        if (pop())
            bin[i] = '1';
        else
            bin[i] = '0';
    }

    
}


int main()
{
    setlocale(LC_ALL, "Russian");
    init();
    print_Node();
    insert(1, 44);
    insert(5, 22);
    insert(3, 11);
    print_Node();
    remove();
    print_Node();
    insert(4, 111);
    print_Node();
   

    unsigned int N = 1997;
    char* trans = new char[32];
    trans_dec_bin(N,trans);
   
    cout << trans << endl;

    system("pause");
}


