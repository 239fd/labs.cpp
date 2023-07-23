#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include <iostream>

using namespace std;

struct Grid
{
    char* Info;
    int Key;
};

struct Tree
{
    Grid field;           
    Tree* left;  
    Tree* right; 
};
void CheckInp(int* number)
{
    while (!scanf_s("%d", number))
    {
        rewind(stdin);
        cout << "Неверный формат ввода, попробуйте снова: " << endl;
    };
}

char* StringInp(char* String)
{
    rewind(stdin);
    int i = 0, n = 1;
    String = 0;
    do
    {
        String = (char*)realloc(String, n++ * sizeof(char));
        String[i] = getchar();
        i++;
    } while (String[i - 1] != '\n');
    String[i - 1] = 0;
    return String;
}

void Sort(Grid* elems, int size)
{
    int counter;
    Grid arrt;
    for (int i = 1; i < size; i++)
    {
        arrt = elems[i];
        counter = i - 1;
        while (counter >= 0 && elems[counter].Key > arrt.Key)
        {
            elems[counter + 1] = elems[counter];
            elems[counter] = arrt;
            counter--;
        }
    }
}

Tree* AddNode(Grid x, Tree* root)
{
    Tree* tree = root;
    if (tree == NULL)
    {
        tree = (Tree*)calloc(1, sizeof(Tree));
        tree->field = x;
    }
    else  if (x.Key < tree->field.Key)
        tree->left = AddNode(x, tree->left);
    else
        tree->right = AddNode(x, tree->right);
    return tree;
}

void Find(Tree* tree, int Key)
{
    if (tree != NULL)
    {
        if (tree->field.Key == Key)
        {
            cout << tree->field.Info << endl;
            cout << tree->field.Key << endl;
        }
        Find(tree->left, Key);
        Find(tree->right, Key);
    }
}

void Balance(Tree** tree, int first, int last, Grid* elems)
{
    if (first == last)
    {
        *tree = NULL;
        return;
    }
    else
    {
        int m = (first + last) / 2;
        *tree = new Tree;
        (*tree)->field = elems[m];
        Balance(&(*tree)->left, first, m, elems);
        Balance(&(*tree)->right, m + 1, last, elems);
    }
}

void freemem(Tree* tree) {
    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);
        delete tree;
    }
}


Tree* Delete(Tree* root, int key)
{
    Tree* Del, * Prev_Del, * R, * Prev_R;

    Del = root;
    Prev_Del = NULL;

    while (Del != NULL && Del->field.Key != key)
    {
        Prev_Del = Del;
        if (Del->field.Key > key) Del = Del->left;
        else Del = Del->right;
    }
    if (Del == NULL)
    { 
        cout << "Нет ключа!\n" << endl;
        return root;
    }

    if (Del->right == NULL)
        R = Del->left;
    else
        if (Del->left == NULL)
            R = Del->right;
        else
        {

            Prev_R = Del;
            R = Del->left;
            while (R->right != NULL)
            {
                Prev_R = R;
                R = R->right;
            }

            if (Prev_R == Del)
                R->right = Del->right;
            else
            {
                R->right = Del->right;
                Prev_R->right = R->left;
                R->left = Prev_R;
            }
        }
    if (Del == root)
        root = R; 
    else
       
        if (Del->field.Key < Prev_Del->field.Key)
            Prev_Del->left = R; 
        else
            Prev_Del->right = R; 
    delete Del;
    return root;
}

void Task(Tree* root)
{
    if (root != NULL) {

        if (root->field.Info[0] == 'a') {

            cout << root->field.Info << " " << endl;;

        }

        if (root->right != NULL) {

            Task(root->right);

        }

        if (root->left != NULL) {

            Task(root->left);

        }
    }
}

void View(Tree* t, int level) {
    if (t) {
        View(t->right, level + 1);
   
        for (int i = 0; i < level; ++i)
            cout << "    ";
        cout << t->field.Key << endl;
        View(t->left, level + 1);
  
    }
}
void Make_Blns(Tree** p, int n, int k, int* a) {
    if (n == k) {
        *p = NULL;
        return;
    }
    else {
        int m = (n + k) / 2;
        *p = new Tree;
        (*p)->field.Key = a[m];
        Make_Blns(&(*p)->left, n, m, a);
        Make_Blns(&(*p)->right, m + 1, k, a);
    }
}

int main() {
    int kkk=0;
    Tree* root = 0;
    Grid* StringGrid = 0;
    int amount, choice, a = 1;
    setlocale(LC_ALL, "RUS");
    while (a)
    {
        cout << "1.Создать\n2.Добавить\n3.Просмотреть\n4.Сбалансировать\n5.Найти по ключу\n6.Вывести записи, начинающихся на 'a'\n7.Удалить по ключу\n8.Выход\n" << endl;
        cout << "Число: " << endl;
        CheckInp(&a);
        switch (a)
        {
        case 1:
        {
            if (!root)
            {
                cout << "Введите кол-во элементов: \n" << endl;
                CheckInp(&amount);
                kkk = amount;
                StringGrid = (Grid*)calloc(amount+10, sizeof(Grid));
                for (int i = 0; i < amount; i++)
                {
                    cout << "ФИО: " << endl;
                    StringGrid[i].Info = StringInp(StringGrid[i].Info);
                    cout << "Номер паспорта: " << endl;
                    CheckInp(&StringGrid[i].Key);
                   
                }
                for (int i = 0; i < amount; i++)
                    root = AddNode(StringGrid[i], root);
            }
            else
                cout << "Дерево уже создано\n" << endl;
            break;
        }
        case 2:
        {
            Grid* Info = new Grid;
            cout << "ФИО: " << endl;
            Info->Info = StringInp(Info->Info);
            cout << "Номер паспорта: " << endl;
            rewind(stdin);
            CheckInp(&Info->Key);
            for (int i = 0; i < kkk+1; i++) {
                if (StringGrid[i].Key == Info->Key) {
                    cout << "Try againg" << endl;
                    CheckInp(&Info->Key);

                }
            }

            StringGrid[amount].Info = Info->Info;
            StringGrid[amount].Key = Info->Key;
            
            cout << StringGrid[amount].Key;
            root = AddNode(*Info, root);
            amount++;
            kkk++;
            break;
        }
        case 3:
        {
            View(root, kkk);
            break;
        }
        case 4:
        {   

           Sort(StringGrid, amount);
           Balance(&root, 0, amount, StringGrid);

            View(root,kkk);
                
            
            break;

        }
        case 5:
        {
            if (root)
            {
                int key;
                cout << "Ключ: " << endl;
                CheckInp(&key);
                Find(root, key);
            }
            else
                cout << "Дерево пустое\n" << endl;
            break;
        }
        case 6:
        {
            Task(root);
            break;
        }
        case 7:
        {
            int key;
            if (root)
            {
                cout << "Ключ: " << endl;
                CheckInp(&key);
                root = Delete(root, key);
                amount--;
            }
            else
                cout << "Дерево пустое\n" << endl;
            break;
        }
        case 8:
        {
            freemem(root);
            return 0;
        }

        }
    }
}