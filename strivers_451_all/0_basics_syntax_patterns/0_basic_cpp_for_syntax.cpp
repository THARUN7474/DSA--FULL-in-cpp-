#include <bits/stdc++.h>
#include <regex>

using namespace std;
#define M_PI 3.14159265358979323846 /* pi */

// ## Basic Problems
// 1. Write a program to print "Hello, World!".
// 2. Write a program to add two numbers.
// 3. Calculate the area of a circle.
// 4. Swap two variables without using a temporary variable.
// 5. Convert Celsius to Fahrenheit.

void printhello()
{
    cout << "Hello world!" << endl;
    cout << "hello Tharun!!" << "\n";
}

void adding2num(int a, int b)
{
    // adding integers here but we can add float,decimal---same type
    // infact we can take function as --doing addition as per given type---like something auto , or instead of fixing we can make something as template

    int sum = a + b;
    cout << (a + b) << "\n";
    cout << "sum of a " << a << " and b " << b << " is " << sum << endl;
}

void areaofcircle(float rad)
{
    float area = M_PI * rad * rad;
    cout << " area of circle with radius " << rad << " is " << area << endl;
}

void swapping(int a, int b)
{

    cout << " a and b " << a << b << "\n";
    a = a * b;
    b = a / b;
    a = a / b;
    cout << " a and b " << a << b << "\n";
    a = a + b;
    b = a - b;
    a = a - b;
    cout << " a and b " << a << b << "\n";

    // remember this is done by pass by  values but not pass of reference , actual values are not at all affected
}

void cel_to_far()
{
    //  // Variable to hold temperature in Celsius
    float celsius, fahrenheit;

    // // Ask the user for input
    // cout << "Enter temperature in Celsius: ";
    // cin >> celsius;
    celsius = 37.5;
    fahrenheit = 104;

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    celsius = (fahrenheit - 32) * 5.0 / 9.0;

    // Output the result
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    cout << "Temperature in celsius: " << celsius << endl;
}

// ## Decision Making
// 1. Check if a number is even or odd.
// 2. Check if a string is a palindrome.
// 3. Check if a number is positive, negative, or zero.
// 4. Create a simple calculator (addition, subtraction, multiplication, division).
// 5. Check if a year is a leap year.
// 6. Check if two strings are anagrams.
// 7. Check if a number is an Armstrong number or not.
// 8. Check if a number is a prime number.

void even_odd(int n)
{
    if (n % 2 == 0 and n & 1 == 0)
    { // any one cond is enough actually
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << "\n";
    }
}

void is_palindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    bool check = true;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            check = false;
            break;
        }
        i++;
        j--;
    }
    if (check)
    {
        cout << "yes it is a palindrome" << "\n";
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}

void check_num(int n)
{
    if (n > 0)
    {
        cout << "positive number" << "\n";
    }
    else if (n < 0)
    {
        cout << "negative number" << "\n";
    }
    else
    {
        cout << "it is zero" << endl;
    }
}

void cal_simple(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        cout << "the sum is " << a + b << endl;
        break;
    case '-':
        cout << "the subtraction is " << a - b << endl;
        break;
    case '*':
        cout << "the multiplaction is " << a * b << endl;
        break;
    case '/':
        if (b != 0)
        {
            cout << "the division " << a / b << endl;
        }
        else
        {
            cout << " b is 0 , it results not defined!" << endl;
        }
        break;

    default:
        cout << "this is only for + - * /" << endl;
        break;
    }
}

void leap_check(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                cout << "yes a leap year" << "\n";
            }
            else
            {
                cout << "not a leap year" << "\n";
            }
        }
        else
        {
            cout << "a leap year" << "\n";
        }
    }
    else
    {

        cout << "not a leap year" << "\n";
    }
}

void are_anagrams(string a, string b)
{

    // i can also use hashmaps to solve this
    // Remove spaces from both strings
    a.erase(remove_if(a.begin(), a.end(), ::isspace), a.end());
    b.erase(remove_if(b.begin(), b.end(), ::isspace), b.end());

    // Convert both strings to lowercase
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    // If lengths don't match, they can't be anagrams
    if (a.length() != b.length())
    {
        cout << "They are not anagrams" << "\n";
        return;
    }

    // Sort both strings and compare
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
    {
        cout << "They are anagrams" << endl;
    }
    else
    {
        cout << "They are not anagrams" << endl;
    }
}

void is_amstorng(int n)
{
    int safe = n;
    int sum = 0;
    int digis = 0;

    while (safe != 0)
    {
        digis++;
        safe = safe / 10;
    }

    safe = n;

    while (safe != 0)
    {
        sum = sum + pow(safe % 10, digis);
        safe = safe / 10;
    }

    if (sum == n)
    {
        cout << "they are amstrong numbers" << "\n";
    }
    else
    {
        cout << "they are not amstrong numbers" << "\n";
    }
}

void is_prime(int n)
{
    if (n == 0 || n == 1)
    {
        cout << " its 0 or 1 --not a prime or is a prime" << endl;
        return;
    }
    bool check = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "is a prime" << endl;
    }
    else
    {
        cout << "is not a prime" << "\n";
    }
}

// ## Loops
// 1. Find the factorial of a number.
// 2. Reverse a number using a loop.
// 3. Sum of Digits of a number (e.g., 123: 1 + 2 + 3).
// 4. Check if a number is a palindrome using a loop.
// 5. Count the number of digits in an integer.
// 6. Print multiplication table using a loop.
// 7. Calculate the sum of natural numbers using a loop.
// 8. Find the LCM and GCD of two numbers using loops.
// 9. Print the Fibonacci sequence using a loop.
// 10. Calculate the power of a number using a loop.
// 11. Calculate the sum of natural numbers up to a given limit.
// 12. Print the Fibonacci sequence up to a certain limit.
// 13. Calculate the power of a number using a loop.
// 14. Find the factors of a number.
// 15. Determine the number of days between two dates.

void factorial(int n)
{
    if (n <= 0)
    {
        cout << "factorial of n " << n << " is not possible coz it is -ve number " << endl;
        return;
    }
    if (n == 0)
    {
        cout << "factorial of n " << n << " is " << 0 << endl;
        return;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "factorial of n " << n << " is " << fact << endl;

    // or we use recurrison too
    // or we use memorisation storing results and using them
}

void revnumber(int n)
{
    int safe = n;
    int ans = 0;
    while (safe != 0)
    {
        // cout<<"d"<<safe<<"t"<<ans<<endl;
        ans = ans * 10 + safe % 10;
        safe /= 10;
        // cout<<"dd"<<safe<<"tt"<<ans<<endl;
    }
    cout << " The inital number and reversed number is " << n << " and " << ans << "\n";
}

void sumofdigits(int n)
{
    int safe = n;
    int ans = 0;
    while (safe != 0)
    {
        // cout<<"d"<<safe<<"t"<<ans<<endl;
        ans = ans + safe % 10;
        safe /= 10;
        // cout<<"dd"<<safe<<"tt"<<ans<<endl;
    }
    cout << " The inital number and sum of digits is " << n << " and " << ans << "\n";
}

void is_palindrome2(string s)
{
    int i = 0;
    int j = s.length() - 1;
    bool check = true;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            check = false;
            break;
        }
        i++;
        j--;
    }
    if (check)
    {
        cout << "yes it is a palindrome" << "\n";
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}

void count_digits(int n)
{
    int safe = n;
    int sum = 0;
    int digis = 0;

    while (safe != 0)
    {
        digis++;
        safe = safe / 10;
    }

    cout << "the number of digtis in n " << digis << endl;
}

void table_mul(int n)
{

    for (int i = 0; i <= 20; i++)
    {
        cout << n << " * " << i << " = " << n * i << endl;
    }
    return;
}

void sum_of_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    cout << "the sum of n " << n << " numbers " << sum << endl;
}

void gcd_lcm(int num1, int num2)
{
    // Find GCD using a loop
    int gcd = 1, lcm;
    for (int i = 1; i <= num1 && i <= num2; ++i)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }

    // LCM can be calculated using the relation: LCM(a, b) = (a * b) / GCD(a, b)
    lcm = (num1 * num2) / gcd;

    // Output the results
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;
    return;
}

// The Euclidean algorithm is based on the principle that the GCD of two numbers does not change if the larger number is replaced by its difference with the smaller number. This can be done iteratively by replacing a with b and b with a % b until b becomes zero.
// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b; // Replace b with the remainder
        a = temp;  // Replace a with the previous b
    }
    return a; // When b becomes 0, a is the GCD
}

// Function to compute LCM using the relation between GCD and LCM
int lcm(int a, int b, int gcd_value)
{
    return (a * b) / gcd_value;
}

void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << 0 << " " << 1 << " ";
    while (n - 2)
    {
        // cout << a + b << " ";
        int t = a + b;
        a = b;
        b = t;
        n--;
    }
    cout<<b<<endl;//it will be the  nth fibbo number 
}

void power_number(int n, int a)
{
    int ans = 1;
    int aa = a;
    while (a)
    {
        ans = ans * n;
        a--;
    }
    cout << "the n=" << n << " power a=" << aa << " is " << ans << endl;
}

void allfactors(int n)
{
    cout << 1 << " ";
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " and its " << n / i << " " << endl;
        }
    }
}

// Function to check if a given year is a leap year
bool is_leap_year(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    return false;
}

// Function to get the number of days in a month for a given year
int days_in_month(int month, int year)
{
    switch (month)
    {
    case 1:
        return 31; // January
    case 2:
        return is_leap_year(year) ? 29 : 28; // February (Leap year check)
    case 3:
        return 31; // March
    case 4:
        return 30; // April
    case 5:
        return 31; // May
    case 6:
        return 30; // June
    case 7:
        return 31; // July
    case 8:
        return 31; // August
    case 9:
        return 30; // September
    case 10:
        return 31; // October
    case 11:
        return 30; // November
    case 12:
        return 31; // December
    default:
        return 0; // Invalid month
    }
}

// Function to count the total number of days from 1/1/0001 to the given date
int days_from_start(int day, int month, int year)
{
    int total_days = 0;

    // Count all complete years from 1 to the given year - 1
    for (int y = 1; y < year; ++y)
    {
        total_days += is_leap_year(y) ? 366 : 365;
    }

    // Count all complete months of the current year
    for (int m = 1; m < month; ++m)
    {
        total_days += days_in_month(m, year);
    }

    // Add the days of the current month
    total_days += day;

    return total_days;
}

// Function to calculate the number of days between two dates
void days_between_dates(int day1, int month1, int year1, int day2, int month2, int year2)
{
    //here we need kttp try and catch type things to give valid inpusts to funciton --liek month should be 1-12 only and year can not be lesssthan 0 and date must be < 31 like those or else invalid case 
    int total_days_1 = days_from_start(day1, month1, year1);
    int total_days_2 = days_from_start(day2, month2, year2);

    cout << "days are ==" << abs(total_days_1 - total_days_2) << endl;
}

// ## String Manipulation
// 1. Reverse a string.
// 2. Count the number of vowels in a string.
// 3. Find the length of a string.
// 4. Count the number of occurrences of a character in a string.
// 5. Convert a string to lowercase.
// 6. Concatenate two strings.
// 7. Count the number of words in a sentence.
// 8. Convert a list of strings to uppercase.
// 9. Determine if a given string is a pangram.
// 10. Check if a given string is a valid email address.

void rev_string(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
    cout << "Reversed string: " << s << endl;
}

void count_vowels(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            count++;
        }
    }
    cout << "Number of vowels: " << count << endl;
}

void len_string(string s)
{
    int c = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        c++;
        i++;
    }
    cout << "Length of the string: " << c << endl;
}

void no_of_occ_char(string s)
{
    unordered_map<char, int> mp;
    int i = 0;
    while (s[i] != '\0')
    {
        mp[s[i]]++;
        i++;
    };

    for (auto ele : mp)
    {
        cout << ele.first << " count of that char =" << ele.second << endl;
    }
}
void covert_lowercase(string s)
{
    cout << s << "\n";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
}

void concat_strings(string s1, string s2)
{
    string ans = s1 + s2;
    cout << ans << endl;
}

void word_count(string sen)
{
    // Create a stringstream object
    stringstream ss(sen);

    // Variable to hold each word
    string word;

    // Vector to store the words
    vector<string> words;

    // Extract words from the sentence
    // getline(ss, word, ' ')
    while (ss >> word)
    {

        // Add the word to the vector
        words.push_back(word);
    }

    // Initial index position
    size_t start = 0;

    // Variable to store the position of space
    size_t end;

    while ((end = sen.find(' ', start)) != sen.npos)
    {
        words.push_back(sen.substr(start, end - start));
        // Update the starting index
        start = end + 1;
    }

    // Add the last word to the vector
    words.push_back(sen.substr(start));

    for (string w : words)
    {
        cout << w << endl;
    }
}

void to_upper(vector<string> ss)
{
    for (string w : ss)
    {
        transform(w.begin(), w.end(), w.begin(), ::toupper);
    }

    for (string w : ss)
    {
        cout << w << endl;
    }
}

void valid_pangram(string s)
{
    // Convert the string to lowercase for case insensitivity
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Check if the string has at least 26 characters
    if (s.length() < 26)
    {
        cout << "Given string \"" << s << "\" is not a pangram." << "\n";
        return;
    }

    // Initialize a boolean array to track the presence of each letter
    bool letter_present[26] = {false}; // 'a' to 'z' (26 letters)

    // Loop through each character in the string
    for (char c : s)
    {
        if (isalpha(c))
        { // Only consider alphabetic characters
            letter_present[c - 'a'] = true;
        }
    }

    // Check if all 26 letters are present
    for (int i = 0; i < 26; i++)
    {
        if (!letter_present[i])
        {
            cout << "Given string \"" << s << "\" is not a pangram." << "\n";
            return;
        }
    }

    // If we reach here, the string is a pangram
    cout << "Given string \"" << s << "\" is a pangram!" << "\n";
}

bool is_valid_email(const string &email)
{
    // Define a regular expression for valid email
    const regex pattern(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z]{2,6}$))");

    // Check if the email matches the pattern
    return regex_match(email, pattern);
}

// ## Functions
// 1. Write a function to calculate the factorial of a number.
// 2. Write a function to check if a number is prime.
// 3. Write a function to calculate the nth Fibonacci number.
// 4. Write a function to reverse a string.
// 5. Write a function to find the maximum and minimum of an array.
// 6. Write a function to sort an array.
// 7. Write a function to check if a string is a palindrome.
// 8. Write a function to concatenate two strings.
// 9. Create a function to calculate the nth Fibonacci number.

int fact(int n)
{
    if (n == 1)
    {
        cout << "fact is " << 1 << endl;
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

void is_prime2(int n)
{
    if (n == 0 || n == 1)
    {
        cout << " its 0 or 1 --not a prime or is a prime" << endl;
        return;
    }
    bool check = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "is a prime" << endl;
    }
    else
    {
        cout << "is not a prime" << "\n";
    }
}

int fibonacci2(int n)
{
    if (n <= 1)
        return n;
    return fibonacci2(n - 1) + fibonacci2(n - 2);
}

void reverse_string(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}

pair<int, int> find_max_min(vector<int> &arr)
{
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    return {max_val, min_val};
}

void sort_array(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

bool is_palindrome(const string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

string concatenate_strings(const string &s1, const string &s2)
{
    return s1 + s2;
}

// ## Lists/Arrays
// 1. Find the largest element in a list/array.
// 2. Calculate the average of a list/array of numbers.
// 3. Remove duplicates from a list/array.
// 4. Find the intersection of two lists/arrays.
// 5. Sort a list/array of numbers in ascending order.
// 6. Find the maximum and minimum elements in a list/array.
// 7. Check if a list/array is empty.
// 8. Iterate over a list/array.
// 9. Check if a list/array is sorted in ascending order.
// 10. Find the index of the first occurrence of an element in a list/array.
// 11. Implement a basic binary search algorithm.

void max_in_list(vector<int> v)
{
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    cout << "the maxm element " << max << endl;
}

void avg_in_list(vector<int> v)
{
    float avg = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    avg = (float)sum / v.size();
    cout << "the avg of elements" << avg << endl;
}

void remove_duplicates(vector<int> v)
{
    unordered_map<int, int> mp;

    // Traverse the vector and count each element's frequency
    for (auto i : v)
    {
        mp[i]++; // Correct: increment frequency of each element
    }

    // Print the unique elements (keys from the map)
    for (auto ele : mp)
    {
        cout << ele.first << " "; // Only printing the keys (unique elements)
    }
    cout << endl;
}

void intersection(vector<int> v1, vector<int> v2)
{
    vector<int> v;
    for (int key : v1)
    {
        auto it = find(v2.begin(), v2.end(), key);
        if (it != v2.end())
        {
            v.push_back(key);
        }
    }
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void sort_asc(vector<int> v)
{
    // sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[i])
            {
                swap(v[i], v[j]);
            }
        }
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void min_max(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "the min and max are " << min << max << endl;
}

void is_empty_list(int arr[])
{
    if (arr[0])
    {
        cout << "not empty list" << endl;
    }
    else
    {
        cout << "an empty list" << endl;
    }
}

void print_list(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void sort_asc_check(vector<int> v)
{
    bool is_sort = is_sorted(v.begin(), v.end());
    if (is_sort)
    {
        cout << "yes it is sorted" << endl;
    }
    bool is_check = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            is_check = false;
        }
    }
}

void find_index_num(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            cout << "index is " << i << endl;
        }
    }
}

void bs(vector<int> v, int x)
{
    int low = 0;
    int high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (v[mid] == x)
        {
            cout << "found at " << mid << endl;
            return;
        }
        else if (v[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "ele not found" << endl;
}

int main()
{
    // printhello();
    // adding2num(10, 129);
    // areaofcircle(3.2);
    // swapping(5, 4);
    // cel_to_far();

    // even_odd(20);
    // is_palindrome("i");
    // check_num(2);
    // cal_simple(34, 20, '*');
    // leap_check(1604);
    // are_anagrams("tharun1","tharun1");
    // is_amstorng(37);
    // is_prime(0);

    // factorial(10);
    // revnumber(347);
    // sumofdigits(143);
    // is_palindrome2("navya");
    // count_digits(100022020);
    // table_mul(13);
    // gcd_lcm(6,19);
    // fibonacci(16);
    // power_number(4, 3);
    // allfactors(36);
    // days_between_dates(27, 7, 2004, 21, 04, 2005);

    // rev_string("tharun_navya");
    // count_vowels("tharun_navya");
    // len_string("tharun");
    // no_of_occ_char("tharun_hero_123_navya");
    // covert_lowercase("THarUn");
    // concat_strings("tharun","navya");
    // word_count("i am tharun and i am an organiser");
    // to_upper({"tharun","is","great"});
    // valid_pangram("the quick brown fox jumps over the lazy dog");
    // string email;
    // cout << "Enter an email address: ";
    // getline(cin, email);

    // if (is_valid_email(email)) {
    //     cout << "The email address \"" << email << "\" is valid." << endl;
    // } else {
    //     cout << "The email address \"" << email << "\" is not valid." << endl;
    // }

    // max_in_list({1, 20, 3, 4, 55});
    // avg_in_list({1, 2, 3, 4, 5});
    // remove_duplicates({11, 2, 3, 4, 2, 2, 3});
    // intersection({1, 2, 3, 4}, {3, 4, 6, 7});
    // sort_asc({12, 2, 5, 23, 4, 34});
    // min_max([ 1, 22, 3, 143 ], 4);
    // is_empty_list([1,2,3]);
    // print_list({1, 2, 3, 4});
    // sort_asc_check({1, 2, 3, 4, 5});
    // find_index_num({23, 4, 1, 2, 3, 5}, 4);
    // bs({1, 2, 3, 45, 55}, 3);

    int ans = fact(10);
    cout << "factorial of number is " << ans << endl;

    int n;
    cout << "Enter the position of Fibonacci number: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci2(n) << endl;

    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverse_string(str);
    cout << "Reversed string: " << str << endl;

    // vector<int> arr = {1, 5, -3, 9, 0, 7, -2};
    // auto [max_val, min_val] = find_max_min(arr);
    // cout << "Maximum value: " << max_val << endl;
    // cout << "Minimum value: " << min_val << endl;

    vector<int> arr = {1, 5, -3, 9, 0, 7, -2};
    sort_array(arr);
    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // string str;
    // cout << "Enter a string: ";
    // getline(cin, str);
    // if (is_palindrome(str))
    //     cout << "\"" << str << "\" is a palindrome." << endl;
    // else
    //     cout << "\"" << str << "\" is not a palindrome." << endl;

    string s1, s2;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);
    string result = concatenate_strings(s1, s2);
    cout << "Concatenated string: " << result << endl;

    return 0;
}