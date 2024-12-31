#include <bits/stdc++.h>

using namespace std;

int find_fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * find_fact(n - 1);
}

int digit_sum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return digit_sum(n / 10) + n % 10;
}

int find_sum_fact(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += find_fact(i);
    return sum;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sum_fact = find_sum_fact(n);
    int digit_sum_fact = digit_sum(sum_fact);

    cout << "Sum of factorials of numbers from 1 to " << n << " is: " << sum_fact << endl;
    cout << "Sum of digits in the factorial sum is: " << digit_sum_fact << endl;

    return 0;
}