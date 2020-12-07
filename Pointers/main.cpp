#include <iostream>
#include <string>

using namespace std;

void swap1(int left, int right)
{
    int temp = left;
    left = right;
    right = temp;
}
void swap2(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
void swap3(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}
void enter1(string& pname,string& psurname);
void enter2(string *pname,string *psurname);
int enter(int a,int *b);
int enter(int a,int& b);
void check(int g);
int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int &z_ = z;
    int *pz = &z;
    string name,surname;
    /*
    swap1(x,y);
    cout << x << " " << y << endl;
    swap2(&x,&y);
    cout << x << " " << y << endl;
    swap3(x,y);
    cout << x << " " << y << endl;
    z_ = 100;

    cout << *pz;
    */

    /*
    enter1(name,surname);
    enter2(&name,&surname);

    cout << name << " " << surname;
    */

    /*
    int a = 3;
    int b = 4;
    int product = enter(a,&b);

    cout << "product = " << product << "sum = " << b << endl;

    product = enter(a,&b);

    cout << "product = " << product << "sum = " << b;
    */
    int g = 5;
    check(g);

}
void check(int g)
{
    int a = 11;
    int b = 21;

    if(&g > &a && &g > &b && &a > &b)
    {
        cout << g << " " << a << " " << b << endl;
        cout << &g << " " << &a << " " << &b << endl;
        cout << "IN PROGRESS: " << &b << " " << &a << " " << &g;
    }
    else if(&g > &a && &g > &b && &a < &b)
    {
        cout << g << " " << b << " " << a << endl;
        cout << &g << " " << &b << " " << &a << endl;
        cout << "IN PROGRESS: " << &a << " " << &g << " " << &g;
    }
    //n факториал комбинаций неравенств 3х переменных,лень писать
}
int enter(int a, int *b)
{
    int product = a * (*b);
    *b = a + (*b);

    return product;
}
int enter(int a, int& b)
{
    int product = a * b;
    b = a + b;

    return product;
}
void enter1(string& pname,string& psurname)
{
    string name,surname;

    cin >> name;
    pname = name;
    cin >> surname;
    psurname = surname;
}
void enter2(string *pname,string *psurname)
{
    string name,surname;

    cin >> name;
    *pname = name;

    if(psurname == NULL)
    {
        cin >> surname;
        *psurname = surname;
    }
}
