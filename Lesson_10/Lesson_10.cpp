// Lesson_10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


typedef struct Node {
    char symbol;
    int index;
    struct Node* next;
}Node;

typedef struct List {
    Node* head;
    int size;
}List;

void init(List* lst)
{
    lst->head = NULL;
    lst->size = 0;
}

bool insert(List* lst, char symb)
{
    Node* new_1 = new Node;
    new_1->symbol = symb;
    new_1->next = NULL;
    new_1->index = lst->size;

    Node* current = lst->head;
    if (current == NULL)
    {
        lst->head = new_1;
        lst->size++;
        return true;
    }
    else
    {
        while (current->next!=NULL)
        {
            current = current->next;
        }
        current->next = new_1;
        lst->size++;
        return true;
    }
}

Node* remove(List* lst, int idx)
{
    Node* current = lst->head;
    Node* parent = NULL;
    if (current == NULL)
    {
       return NULL;
    }

    while (current->next != NULL && current->index != idx)
    {
        parent = current;
        current = current->next;
    }
    if (current->index != idx)
    {
        return NULL;
    }
    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;


}


bool task_1(char* str, int len)
{
    List* lst = new List;
    lst->head = NULL;
    lst->size = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == '(' || str[i] == ')' || str[i] == '[' ||
            str[i] == ']' || str[i] == '{' || str[i] == '}')
        {
            insert(lst, str[i]);
        }
    }
    if (lst->size % 2)
    {
        delete lst;
        return false;
    }

    Node* current = lst->head;
    if (current == NULL)
    {
        delete lst;
        return true;
    }
    else
    {
        while (current->next != NULL )
        {
            if (current->symbol == '(')
            {
                if (current->next->symbol == ')')
                {
                    remove(lst, current->index);
                    remove(lst, current->next->index);
                    current = lst->head;
                    if (lst->size == 0)
                        break;
                    continue;
                }
               
            }
            else if (current->symbol == '{')
            {
                if (current->next->symbol == '}')
                {
                    remove(lst, current->index);
                    remove(lst, current->next->index);
                    current = lst->head;
                    if (lst->size == 0)
                        break;
                    continue;
                }
            }
            else if (current->symbol == '[')
            {
                if (current->next->symbol == ']')
                {
                    remove(lst, current->index);
                    remove(lst, current->next->index);
                    current = lst->head;
                    if (lst->size == 0)
                        break;
                    continue;
                }
            }
            current = current->next;
        }
        if (lst->size == 0)
        {
            delete lst;
            return true;
        }
        else
        {
            delete lst;
            return false;
        }
            
    }
}

List* CopyList(List* lst)
{
    List* lst_1 = new List;
    lst_1->head = NULL;
    lst_1->size = 0;
    Node* current = lst->head;
    while (current != NULL)
    {
        insert(lst_1, current->symbol);
        current = current->next;
    }
    return lst_1;
}

bool proverkaSort(List* lst)
{
    bool proverka = true;
    Node* current = lst->head;
    while (current->next != NULL)
    {
        if (current->symbol < current->next->symbol)
        {
            proverka = false;
        }
        current = current->next;
    }
    if (proverka)
    {
        return true;
    }
    proverka = true;
    current = lst->head;
    while (current->next != NULL)
    {
        if (current->symbol > current->next->symbol)
        {
            proverka = false;
        }
        current = current->next;
    }
    return proverka;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    char s[14] = "[2/{5{(4+})}]";
    if (task_1(s, 14))
    {
        cout << "Верно!" << endl;
    }
    else
    {
        cout << "Неверно!" << endl;
    }


    List* lst = new List;
    lst->head = NULL;
    lst->size = 0;
    insert(lst, '4');
    insert(lst, '5');
    insert(lst, '4');
    insert(lst, '4');

    if (proverkaSort(lst))
    {
        cout << "Отсортирован!" << endl;
    }
    else
    {
        cout << "Не отсортирован!" << endl;
    }
    List* lst_1 = CopyList(lst);
    delete lst;
    delete lst_1;
    system("pause");
}


