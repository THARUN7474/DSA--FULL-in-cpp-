#include <bits/stdc++.h>
String stringSum(string &NUM1, string &NUM2)
{
    int carry = 0;
    int n1 = NUM1.length();
    int n2 = NUM2.length();
    int i = n1 - 1, j = n2 - 1;
    string result = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += NUM1[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += NUM2[j] - '0';
            j--;
        }
        carry = sum / 10;
        sum %= 10;
        result = to_string(sum) + result;
    }

    return result;
}
int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    cin.ignore(); // to clear input buffer
    while (t--)
    {
        string input_str;
        cout << "Enter the string: ";
        getline(cin, input_str);
        string result = convertString(input_str);
        cout << "Transformed string: " << result << endl;
    }
    return 0;
}