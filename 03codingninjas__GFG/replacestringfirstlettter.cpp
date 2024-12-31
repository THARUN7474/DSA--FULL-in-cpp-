#include <bits/stdc++.h>
string convertString(string str)
{
    int n = str.length();
    str[0] = toupper(str[0]);
    for (int i = 1; i < n; i++)
    {
        if (str[i - 1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

// def convert_to_title_case(string):
//     return ' '.join(word.capitalize() for word in string.split())

// def main():
//     t = int(input("Enter the number of test cases: "))
//     for _ in range(t):
//         input_str = input().strip()
//         output_str = convert_to_title_case(input_str)
//         print(output_str)

// if __name__ == "__main__":
//     main()
