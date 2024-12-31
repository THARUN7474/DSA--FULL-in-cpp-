#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string tripleToString(int a, int b, int c)
{
    return to_string(a) + "," + to_string(b) + "," + to_string(c);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        unordered_map<string, vector<int>> tripleMap;

        for (int j = 0; j <= n - 3; ++j)
        {
            string triple = tripleToString(a[j], a[j + 1], a[j + 2]);
            tripleMap[triple].push_back(j);
        }

        long long bp = 0;

        for (auto it1 = tripleMap.begin(); it1 != tripleMap.end(); ++it1)
        {
            for (auto it2 = next(it1); it2 != tripleMap.end(); ++it2)
            {

                string t1 = it1->first;
                string t2 = it2->first;

                int diffCount = 0;
                for (int k = 0; k < 3; ++k)
                {
                    if (t1[k * 2] != t2[k * 2])
                        ++diffCount;
                }

                if (diffCount == 1)
                {
                    bp += (long long)it1->second.size() * it2->second.size();
                }
            }
        }

        cout << bp << endl;
    }

    return 0;
}