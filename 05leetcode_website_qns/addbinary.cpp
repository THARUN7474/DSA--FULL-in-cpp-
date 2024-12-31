#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        result += to_string(sum % 2);
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string binary1 = "1011";
    string binary2 = "1101";

    string sum = addBinary(binary1, binary2);

    cout << "Binary sum: " << sum << endl;

    return 0;
}

// The addBinary function performs binary addition by iterating through the binary strings from right to left, adding digits along with the carry, and appending the result to a string. After the addition, the result is reversed to get the correct binary representation of the sum. The main() function demonstrates how to use this addBinary function to add two binary numbers and print the result.