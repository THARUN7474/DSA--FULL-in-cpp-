#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int odd = 0, even = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (N % i == 0)
            {
                if (i & 1)
                {
                    odd++;
                }
                else
                {
                    even++;
                }
            }
        }
        cout << odd << " " << even << endl;
    }
    return 0;
}

// This code reads multiple test cases, where each test case consists of an integer n (number of elements) and k (a limit).