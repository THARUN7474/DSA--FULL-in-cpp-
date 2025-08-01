#include <bits/stdc++.h>

using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}

int decimalToBinary(int n)
{
    int num = n;
    int binaryNum = 0;
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 2;
        temp = temp / 2;
        binaryNum += last_digit * base;
        base = base * 10;
    }
    return binaryNum;
}

string onesComplement(string binary)
{
    for (int i = 0; i < binary.size(); i++)
    {
        binary[i] = (binary[i] == '0') ? '1' : '0'; // Flip 0 to 1 and 1 to 0
    }
    return binary;
}

string twosComplement(string binary)
{
    string ones = binary;

    // Step 1: Get 1's Complement
    for (int i = 0; i < ones.size(); i++)
    {
        ones[i] = (ones[i] == '0') ? '1' : '0';
    }

    // Step 2: Add 1 to 1's Complement
    int carry = 1;
    for (int i = ones.size() - 1; i >= 0; i--)
    {
        if (ones[i] == '1' && carry == 1)
        {
            ones[i] = '0';
        }
        else if (carry == 1)
        {
            ones[i] = '1';
            carry = 0;
        }
    }

    return ones;
}

string decimalToNegativeBinary(int num)
{
    if (num >= 0)
    {
        cout << "Input must be negative.\n";
        return "";
    }
    int positiveNum = abs(num);                         // Get absolute value
    string binary = bitset<8>(positiveNum).to_string(); // Convert to binary
    return twosComplement(binary);                      // Use 2's complement logic
}

int negativeBinaryToDecimal(string binary)
{
    // If the MSB is 1, it's negative
    if (binary[0] == '1')
    {
        string twos = twosComplement(binary);
        int positiveDecimal = 0;

        for (int i = twos.size() - 1, power = 0; i >= 0; i--, power++)
        {
            if (twos[i] == '1')
            {
                positiveDecimal += pow(2, power);
            }
        }
        return -positiveDecimal;
    }
    else
    { // Otherwise, it's positive
        return stoi(binary, nullptr, 2);
    }
}

bool isPowerOfTwoLoop(int num)
{
    if (num <= 0)
        return false;
    while (num > 1)
    {
        if (num % 2 != 0)
            return false;
        num /= 2;
    }
    return true;
}

bool isPowerOfTwoBitManipulation(int num)
{
    return num > 0 && (num & (num - 1)) == 0;
}

int countSetBits(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int reverseInteger(int num)
{
    int reversed = 0;
    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main()
{
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    cout << "2's Complement: " << twosComplement(binary) << endl;
    return 0;
}
