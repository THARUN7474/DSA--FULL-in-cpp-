#include <bits/stdc++.h>

using namespace std;

// #print all the digits in integer

void printdigits(int n)
{
    vector<int> digtis;
    while (n)
    {
        digtis.push_back(n % 10);
        n = n / 10;
    }
    // digtis.reserve();
    reverse(digtis.begin(), digtis.end());
    for (int x : digtis)
    {
        cout << x << " ";
    }
}

void makeint(vector<int> arr)
{
    int r = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        r = r * 10 + arr[i];
    }

    cout << "the final number made form diguts is" << r << endl;
}

void km_miles_cov(float km)
{
    cout << km * 0.62 << "miles";
}

void deci_bin(long long int a)
{
    vector<int> aa;
    int ans = 0;

    // using bit wise as -----the 101&1 means output is 1 it can give whats is last bit
    while (a > 0)
    {
        aa.push_back(a & 1);
        a >>= 1; // rightshift means evertime se shifting forward to get all the bits
    }

    // normal method
    while (a)
    {
        aa.push_back(a % 2);
        a = a / 2;
    }

    cout << "**********8";
    // we can use this
    while (!aa.empty())
    {
        cout << aa.back(); // Print the last element of the vector
        aa.pop_back();     // Remove the last element from the vector
    }
    cout << "**********8";

    // using for loop mAKING IT LOOP AND REVSERING AT A TIME
    cout << "Binary equivalent: ";
    for (int i = aa.size() - 1; i >= 0; i--)
    {
        cout << aa[i];
    }

    cout << "**********8";
    // other way of doing
    reverse(aa.begin(), aa.end());
    cout << "Binary equivalent: ";
    for (int bit : aa)
    {
        cout << bit;
    }
    cout << endl;
}

int binaryToDecimal(string binary)
{
    return bitset<32>(binary).to_ulong();
}

int binaryToDecimal2(string binary)
{
    stringstream ss;
    ss << binary;
    int decimal;
    ss >> std::hex >> decimal;
    return decimal;
}

int binaryToDecimal3(string binary)
{
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int binaryToDecimal5(int binary)
{
    int decimal = 0;
    int power = 0;
    while (binary != 0)
    {
        decimal += (binary & 1) << power;
        binary >>= 1;
        power++;
    }
    return decimal;
}

vector<int> decimalToBinary4(int decimal)
{
    vector<int> binary;
    while (decimal != 0)
    {
        binary.push_back(decimal & 1);
        decimal >>= 1;
    }
    return binary;
}

int binarytooctal(int n){
    int octal=0;
    int x =1;
    while(n>0){
        int y = n%10;
        octal += x*y;
        x=x*8;
        n=n/10;
    }
    return octal;
}

int createNumber(int digits[], int size)
{
    string numberStr;
    for (int i = 0; i < size; i++)
    {
        numberStr += to_string(digits[i]);
    }
    return stoi(numberStr);
}
int createNumber(int digits[], int size)
{
    string numberStr;
    for (int i = 0; i < size; i++)
    {
        numberStr += to_string(digits[i]);
    }
    return stoi(numberStr);
}

int createNumber2(vector<int> &digits)
{
    int number = 0;
    int power = digits.size() - 1;
    for (int digit : digits)
    {
        number += digit * pow(10, power);
        power--;
    }
    return number;
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
// Set bits, also known as 1-bits
// When a bit is set to 1, it is considered a set bit, and when it is set to 0, it is considered a clear bit.
// In the binary number 101101, there are four set bits.
// In the binary number 010010, there are two set bits.
// In the binary number 111111, all bits are set, so there are six set bits.
// bitwise operations, such as counting the number of set bits in a number, flipping bits, or performing logical operations on individual bits.

int main()
{
    int x;
    cout << "enter the number to cobvert to digits";
    cin >> x;
    printdigits(x);
    cout << "***************************" << endl;
    int a;
    vector<int> arra;
    cout << "how many you digits you want to enter!";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int b;
        cin >> b;
        arra.push_back(b);
    }
    makeint(arra);
    cout << "***************************" << endl;

    int km;
    cout << "enter the kms to covert to miles";
    cin >> km;
    km_miles_cov(km);

    cout << "***************************" << endl;

    int digits[] = {1, 2, 3, 4, 5}; // Example digits
    int size = sizeof(digits) / sizeof(digits[0]);
    int number = createNumber(digits, size);
    cout << "Number created: " << number << endl;

    cout << "***************************" << endl;

    int numDigits;
    cout << "Enter the number of digits for your number: ";
    cin >> numDigits;
    vector<int> digitss;
    cout << "Enter " << numDigits << " digits, one by one: ";
    for (int i = 0; i < numDigits; ++i)
    {
        int digit;
        cin >> digit;
        digitss.push_back(digit);
    }
    int number = createNumber2(digitss);
    cout << "Number created: " << number << endl;
}