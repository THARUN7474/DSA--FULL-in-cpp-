#include "bits/stdc++.h"

using namespace std;

void swap1(int *a, int *b)
{
    int t = *(a);
    *(a) = *b;
    *(b) = t;
}

void swap2(int *a, int *b)
{
    *a = *(a) + *b;
    *(b) = *a - *b;
    *a = *a - *b;
}

void swap3(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swap4(int &a, int &b)
{
    a = a * b;
    b = a / b;
    a = a / b;
}

void swap5(int &a, int &b)
{
    swap(a, b);
}

int main()
{
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    swap1(&a, &b);
    cout << a << " " << b << endl;
    swap2(&a, &b);
    cout << a << " " << b << endl;
    swap3(a, b);
    cout << a << " " << b << endl;
    swap4(a, b);
    cout << a << " " << b << endl;
    swap5(a, b);
    cout << a << " " << b << endl;
    return 0;
}