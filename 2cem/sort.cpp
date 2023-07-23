#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <string.h>
using namespace std;
struct person {
    string name;
    int group;
    string city;
    int math;
    int physics;
};
person huy;
person* product;
double check()
{
    bool fk = true;
    int n = 0;
    string a = "\0";
    string b = "\0";


    while (fk == true) {

        cin >> b;
        a = b;
        if (a[0] == '0' && a[1] != '.') {
            a[0] = a[1] = '.';
        }
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '.' || a[i] == ',') {
                a[i] = '0';
                n++;

            }
        }if (a[0] == '-' && isdigit(a[1]) && a[1] != '0') {
            a[0] = a[1] = a[2] = '0';
            n++;
        }
        for (int s = 0; s < a.length(); s++) {
            if (isdigit(a[s]) && n < 2 && a[0] != '.' && a[0] != ',') {
                fk = false;
            }
            else {
                cout << "Error, try again" << endl;
                fk = true;
                n = 0;
                break;
            }
        }




    }
    return stod(b);

}
double dime1()
{
    double n;
    do {

        n = check();
        if (n - (int)n == 0 && !(n <= 0))
        {
            break;
        }
        else {
            cout << "Try again" << endl;
        }
    } while (true);
    return n;
}
double dime2()
{
    double n;
    do {

        n = check();
        if (n - (int)n == 0)
        {
            break;
        }
        else {
            cout << "Try again" << endl;
        }
    } while (true);
    return n;
}
string spacecheck(string& SRead, string space)
{
    int i = SRead.find(space);
    if (i == string::npos)
    {
        return SRead;
    }
    string need = SRead.substr(0, i);
    SRead.erase(0, i + 1);
    return need;
}
void saveppl(int& number)
{
    ofstream save;
    save.open("D:\\Текстовики\\ppl.txt");
    if (save.is_open())
    {
        for (int i = 0; i < number; i++)
        {
            save << product[i].name << " " << product[i].group << " " << product[i].city << " " << product[i].math << " " << product[i].physics << endl;
        }
        save.close();
    }
    else cout << "Error";
}
void addtoarr(person prod, int& number)
{
    if (product != 0)
    {
        person* newprod = new person[number + 1];
        for (int i = 0; i < number; i++)
        {
            newprod[i] = product[i];
        }
        newprod[number] = prod;
        delete[] product;
        product = newprod;
        number++;
    }
    else
    {
        product = new person[1];
        product[0] = prod;
        number = 1;
    }
}
void readppl(int& number)
{
    string SRead;
    ifstream load("D:\\Текстовики\\ppl.txt");
    if (load.is_open())
    {
        while (getline(load, SRead))
        {
            person prod;
            prod.name = spacecheck(SRead, " ");
            prod.group = atoi(spacecheck(SRead, " ").c_str());
            prod.city = spacecheck(SRead, " ");
            prod.math = atoi(spacecheck(SRead, " ").c_str());
            prod.physics = atoi(spacecheck(SRead, " ").c_str());
            addtoarr(prod, number);
        }
        load.close();
    }
    else cout << "Ошибка";
}
void add(int& number)
{
    person prod;
    cout << "Имя:\n";
    cin >> prod.name;
    cout << "Номер группы:\n";
    prod.group = check();
    cout << "Город:\n";
    cin >> prod.city;
    cout << "Оценка по математике\n";
    prod.math = dime1();
    cout << "Оценка по физике\n";
    prod.physics = dime1();
    addtoarr(prod, number);
    saveppl(number);
}
void checkppl(int& number)
{
    if (number == 0)
    {
        cout << "Нет записей в файле\n";
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            cout << i + 1 << " " << product[i].name << " " << product[i].group << " " << product[i].city << " " << product[i].math << " " << product[i].physics << endl;
        }

    }
}
void deleteppl(int& number)
{
    if (number == 0)
    {
        cout << "Нет записей, добавьте информацию\n";
    }
    else {
        cout << "Выберите номер студента\n";
        checkppl(number);
        int k;
        int j = 0;
        k = dime1();
        k--;
        if (k < number && k >= 0)
        {
            person* newprod = new person[number - 1];
            for (int i = 0; i < number; i++)
            {
                if (k != i) {
                    newprod[j] = product[i];
                    j++;
                }
            }
            delete[] product;
            product = newprod;
            number--;
            saveppl(number);

        }
    }
}

void QuickSort(int number)
{
    int i = 0;
    int j = number - 1;
    string mid = product[number / 2].name;
    do {
        while (product[i].name < mid) {
            i++;
        }
        while (product[j].name > mid) {
            j--;
        }
        if (i <= j) {
            person tmp = product[i];
            product[i] = product[j];
            product[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        QuickSort(j + 1);
    }
    if (i < number) {
        QuickSort(number - i);
    }
}

person Binary(int number, string name1)
{

    int l = 0;
    int r = number - 1;
    while (r > l)
    {
        int m = (l + r) / 2;
        if (product[m].name < name1)
        {
            l = m + 1;
        }
        else if (product[m].name > name1)
        {
            r = m - 1;
        }
        else {
            return product[m];
        }
    }
    if (product[l].name == name1)
    {
        return product[l];
    }
    else return huy;
}
void Sort(int number)
{
    int a, k = 0;
    person r;
    int m;
    cout << "Выберите тип сортировки:\n";
    cout << "1.Straight choice\n";
    cout << "2.QuickSort\n";
    a = dime1();
    switch (a)
    {
    case 1:
        for (int i = 0; i < number - 1; i++) {
            m = i;
            for (int j = i + 1; j < number; j++)
                if (product[j].name < product[m].name) m = j;
            r = product[m];
            product[m] = product[i];
            product[i] = r;
        }
    case 2:
        QuickSort(number);
    }
}
void Search(int number, string name)
{
    int o = 0;
    person p;
    int i_key = 0, kod = 0;
    int k = 0;
    person r;
    int m;
    int a, b;
    cout << "Выберите тип поиска:\n";
    cout << "1.Linear search\n";
    cout << "2.Binary search\n";
    a = dime1();
    switch (a)
    {
    case 1:
        for (int i = 0; i < number; i++)
            if (product[i].name == name) {
                kod = 1;
                cout << i + 1 << " " << product[i].name << " " << product[i].group << " " << product[i].city << " " << product[i].math << " " << product[i].physics << endl;
                i_key = i;
            }
        if (kod == 0) cout << "Нет такого студента\n";
        break;
    case 2:
        QuickSort(number);
        p = Binary(number, name);
        if (p.name == huy.name && p.group == huy.group && p.city == huy.city && p.math == huy.math && p.physics == huy.physics)
        {
            cout << "Нет такого студента\n";
        }
        else cout << p.name << " " << p.group << " " << p.city << " " << p.math << " " << p.physics << endl;
        break;
    }
}

void Task(int number)
{
    int i_key = 0, kod = 0;
    int k = 0;
    person r;
    int m;
    int a, b;
    for (int i = 0; i < number - 1; i++) {
        m = i;
        for (int j = i + 1; j < number; j++)
            if (product[j].name < product[m].name) m = j;
        r = product[m];
        product[m] = product[i];
        product[i] = r;
    }
    for (int i = 0; i < number; i++)
        if ((product[i].math + product[i].physics)/2 >= 8.5 && product[i].city == "Minsk") {
            kod = 1;
            cout << i + 1 << " " << product[i].name << " " << product[i].group << " " << product[i].city << " " << product[i].math << " " << product[i].physics << endl;
            i_key = i;
        }
    if (kod == 0)
        cout << "Нет таких студентов\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;
    int k = 0;
    int number = 0;
    int a;
    char b;
    readppl(number);
    while (true) {
        cout << "Выберите пункт меню" << endl;
        cout << "1.Добавить" << endl;
        cout << "2.Удалить" << endl;
        cout << "3.Просмотреть" << endl;
        cout << "4.Сортировать" << endl;
        cout << "5.Поиск" << endl;
        cout << "6.Задание" << endl;
        cout << "7.Выход" << endl;
        a = dime1();
        switch (a)
        {
        case 1:
            add(number);
            break;
        case 2:
            deleteppl(number);
            break;
        case 3:
            checkppl(number);
            break;
        case 4:
            Sort(number);
            checkppl(number);
            break;
        case 5:
            cout << "Введите имя" << endl;
            cin >> name;
            Search(number, name);
            break;
        case 6:
            Task(number);
            break;
        case 7:
            return 0;
        default:
            cout << "Ошибка\n";
            break;
        }
    }
}
