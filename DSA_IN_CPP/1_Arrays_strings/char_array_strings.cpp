#include <bits/stdc++.h>

using namespace std;

void findlen(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;
    cout << "Length of the string: " << count << endl;
}

void reverse_str(char str[])
{
    cout << "initail " << str << endl;
    int i = 0;
    int j = strlen(str) - 1;
    // cout << i << " " << j << endl;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    cout << " revsred " << str << endl;
}

void palindrome_str(char str[])
{
    cout << "initail " << str << endl;
    int i = 0;
    int j = strlen(str) - 1;
    // cout << i << " " << j << endl;
    char temp;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            cout << "Not a palindrome" << endl;
            return;
        }
    }

    cout << "yes it is palindrome" << str << endl;
}

void to_caps(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
        // str[i] = toupper(str[i]);
        // or we can use ----ascii values and add---it 65--> 90 something right we need to find exact diff and add it
        // str[i] = str[i] -'a' + 'A';---this works --and better too ---lower to higher case
        // str[i] = str[i] -'A' + 'a';---this works --and better too---higher to lower case
    }
}

void replace_spaces(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '$';
        }
    }

    cout << "final" << str << endl;
}

bool cmp(char f, char s)
{
    return f < s;
} // ascending compare

bool cmp_desc(char f, char s)
{
    return f > s;
} // descending compare

bool cmp1(int a, int b)
{
    return a > b;
} // decresing order compare

bool cmp2(int a, int b)
{
    return a < b;
} // increasing order compare

bool cmpp(string s1, string s2)
{
    return s1[0] < s2[0];
}

int findsum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }
    return sum;
}

bool cmmp(string s1, string s2)
{
    return findsum(s1) < findsum(s2);
}

int main()
{
    // int n;
    // cin >> n;
    // char str[n];
    // char str1[n];E

    // cin >> str;
    // // getline(cin, str);--works too
    // // cin.getline(str,50);

    // // for (int i = 0; i < n; i++)
    // // {
    // //     // str1[i] = tolower(str[i]);
    // //     cin >> str1[i];
    // // }

    // // below are wrong
    // // str = "tharun";
    // // str1 = "tharun";

    // cout << str << " stirng direct" << endl;
    // cout << str1 << " stirng loop" << endl;

    // int val = (int)str[1];
    // findlen(str);
    // reverse_str(str);

    // char s[100];
    // cin.getline(s, 100);
    // cout << "string from getline: " << s << endl;
    // replace_spaces(s);

    string s = "THARUN";
    cout << s << endl;
    sort(s.begin(), s.end());
    // sort(s.begin(), s.end(), [](char a, char b) { return a < b; });
    cout << s << endl;
    sort(s.begin(), s.end(), cmp);
    cout << s << endl;
    sort(s.begin(), s.end(), cmp_desc);
    cout << s << endl;

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "sorted string1: " << s << endl;
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "sorted string2: " << s << endl;
    sort(v.begin(), v.end(), cmp2);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "sorted string3: " << s << endl;

    vector<string> vs = {"apple", "banana", "zcherry", "date", "elderberry"};
    sort(vs.begin(), vs.end(), cmpp);
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << "sorted strings"<< endl;

    sort(vs.begin(), vs.end(), cmmp);
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << "sorted strins"<< endl;
}