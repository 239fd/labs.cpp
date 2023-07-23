#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <string.h>
using namespace std;

struct person {
    string name;
    int number;
    int physics;
    int math;
    int inf;
    double avg;
};
person* pupil;
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
        if (n - (int)n == 0 && !(n <= 0) && n <= 10)
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
            save << pupil[i].name << " " << pupil[i].number << " " << pupil[i].physics << " " << pupil[i].math << " " << pupil[i].inf << " " << pupil[i].avg << endl;
        }
        save.close();
    }
    else cout << "Error";
}
void addtoarr(person ppl, int& number)
{
    if (pupil != 0)
    {
        person* newppl = new person[number + 1];
        for (int i = 0; i < number; i++)
        {
            newppl[i] = pupil[i];
        }
        newppl[number] = ppl;
        delete[] pupil;
        pupil = newppl;
        number++;
    }
    else
    {
        pupil = new person[1];
        pupil[0] = ppl;
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
            person ppl;
            ppl.name = spacecheck(SRead, " ");
            ppl.number = atoi(spacecheck(SRead, " ").c_str());
            ppl.physics = atoi(spacecheck(SRead, " ").c_str());
            ppl.math = atoi(spacecheck(SRead, " ").c_str());
            ppl.inf = atoi(spacecheck(SRead, " ").c_str());
            ppl.avg = atof(spacecheck(SRead, " ").c_str());
            addtoarr(ppl, number);
        }
        load.close();
    }
    else cout << "Error";
}
void add(int& number)
{
    person ppl;
    cout << "Name\n";
    cin >> ppl.name;
    cout << "Number\n";
    ppl.number = check();
    cout << "Physics\n";
    ppl.physics = dime1();
    cout << "Math\n";
    ppl.math = dime1();
    cout << "Info\n";
    ppl.inf = dime1();
    ppl.avg = (ppl.inf + ppl.math + ppl.physics) / 3;
    addtoarr(ppl, number);
    saveppl(number);
}
void checkppl(int& number)
{
    if (number == 0)
    {
        cout << "There is no students, add new\n";
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            cout << i + 1 << " " << pupil[i].name << " " << pupil[i].number << " " << pupil[i].physics << " " << pupil[i].math << " " << pupil[i].inf << " " << pupil[i].avg << endl;
        }

    }
}
void deleteppl(int& number)
{
    if (number == 0)
    {
        cout << "There are no students, add one al least\n";
    }
    else {
        cout << "Input the position of student\n";
        checkppl(number);
        int k;
        int j = 0;
        k = dime1();
        k--;
        if (k < number && k >= 0)
        {
            person* newppl = new person[number - 1];
            for (int i = 0; i < number; i++)
            {
                if (k != i) {
                    newppl[j] = pupil[i];
                    j++;
                }
            }
            delete[] pupil;
            pupil = newppl;
            number--;
            saveppl(number);

        }
    }
}
void task(char& letter, int& number)
{
    int o = number;
    int mas[100];
    int k;
    int m=0;
    for (int i = 0; i < o; i++)
    {
        if (pupil[i].inf >= 9)
        {
            m++;
            k = i;
            cout << k + 1 << " " << pupil[k].name << " " << pupil[k].number << " " << pupil[k].physics << " " << pupil[k].math << " " << pupil[k].inf << " " << pupil[k].avg << endl;
        }

    }

    if (m == 0) {
   
        cout << "net takix";
    }
    

}
void updtoarr(person ppl, int& number, int k)
{
    if (k < number && k >= 0)
    {
        person* newppl = new person[number];
        for (int i = 0; i < number; i++)
        {
            if (k == i)
            {
                newppl[k] = ppl;
            }
        }
        delete[] pupil;
        pupil = newppl;
        saveppl(number);
    }
}
void updppl(int& number)
{
    cout << "Input the number of the student you want to change\n";
    checkppl(number);
    int k = dime1();
    k--;
    person ppl;
    cout << "Name\n";
    cin >> ppl.name;
    cout << "Number\n";
    ppl.number = check();
    cout << "Physics\n";
    ppl.physics = dime1();
    cout << "Math\n";
    ppl.math = dime1();
    cout << "Info\n";
    ppl.inf = dime1();
    ppl.avg = (ppl.inf + ppl.math + ppl.physics) / 3;
    updtoarr(ppl, number, k);
}


int main()
{
    int k = 0;
    int number = 0;
    int a;
    char b;
    readppl(number);
    while (true) {
        cout << "What you want to do?(Put only numbers)\n";
        cout << "Add(1)\n";
        cout << "Edit(2)\n";
        cout << "Delete (3)\n";
        cout << "Check previous(4)\n";
        cout << "Solving the task(5)\n";
        cout << "Exit(6)\n";
        a = dime1();
        switch (a)
        {
        case 1:
            add(number);
            break;
        case 2:
            updppl(number);
            break;
        case 3:
            deleteppl(number);
            break;
        case 4:
            checkppl(number);
            break;
        case 5:
           
            task(b, number);
            break;
        case 6:
            return 0;
        default:
            cout << "Error\n";
            break;
        }
    }
}

