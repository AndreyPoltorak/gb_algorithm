#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
}TreeNode;

int GetRandomNumber(int min, int max)
{
   
    int num = min + rand() % (max - min + 1);
    return num;
}
TreeNode* AddNode(TreeNode* t, int data)
{
    TreeNode* newNode = new TreeNode;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    TreeNode* current = t;
    if (t->key == NULL)
    {
        t = newNode;
    }
    else 
    {
        while (true)
        {
            if (current->key < data)
            {
                if (current->right == NULL)
                {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
            else 
            {
                if (current->left == NULL)
                {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
        }
    }
    return t;
}

TreeNode* CreatingTree(TreeNode* t)
{

    for (int i = 0; i < 10; i++)
    {
        t = AddNode(t, GetRandomNumber(0, 1000));
    }
    return t;
}

void Height(TreeNode* t, int * height, int *max, int *min)
{
    if (t == NULL)
    {
        
        return;
    }
    else
    {
        *height +=1;
        if (*max < *height)
        {
            *max = *height;
        }
        Height(t->left, height, max,min);
        Height(t->right, height, max,min);
        if (*height < *min)
        {
            *min = *height;
        }
        *height-=1;
    }
}

void PrintTree(TreeNode* t)
{
    if (t)
    {
        cout << t->key;
        if (t->left || t->right)
        {
            cout << "(";
            if (t->left)
                PrintTree(t->left);
            else
                cout << "NULL";
            cout << ",";
            if (t->right)
                PrintTree(t->right);
            else
                cout << "NULL";
            cout << ")";
        }
    }

}
bool Treebalsns(TreeNode* t)
{
    int* lt = new int(0);
    int* max = new int(0);
    int* min = new int(1000);
    Height(t, lt, max,min);
    if (*min + 1 < *max)
        return false;
    return true;
}

bool Poisk(TreeNode* t, int value)
{
    if (t == NULL)
    {
        return false;
    }
    if (t->key == value)
        return true;
    TreeNode* current = t;
    while (current->key != value)
    {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;
        if (current == NULL)
            return false;
    }
    return true;
}

double Task_4()
{
    int koll = 0;
    for (int i = 0; i < 50; i++)
    {
        TreeNode* newNode = new TreeNode;
        newNode->key=NULL;
        newNode = CreatingTree(newNode);
        if (Treebalsns(newNode))
        {
            PrintTree(newNode);
            cout << endl;
            koll++;
        }
        cout<<Poisk(newNode,777)<<endl;
        delete newNode;
    }
    
    return double(koll / 50.0);
}



int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    cout << "процент из созданных деревьев является сбалансированными - "<< Task_4()<<endl;
    system("pause");
}


