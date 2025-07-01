#include <bits/stdc++.h>
#include <chrono>

using namespace std;
// The using namespace std; directive tells the compiler to consider everything inside the std namespace as if it were in the global namespace. This means you can use cout, endl, chrono::high_resolution_clock, etc., without prefixing them with std::.

int sum(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i;
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    cout << sum(n) << endl;
    // End measuring time
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // Calculate duration in seconds
    auto duration2 = chrono::duration_cast<chrono::seconds>(end - start);
    cout << "Time taken by code: " << duration2.count() << " seconds" << endl;

    cout << "Time taken by code: " << duration.count() << " microseconds" << endl;
}

// The auto keyword is used for type inference, meaning the compiler will automatically deduce the type of the variable start.

// #include <iostream>
// #include <ctime>

// int main() {
//     clock_t start, end;
//     double cpu_time_used;

//     start = clock(); // Start measuring CPU time

//     // Your code here
//     for (int i = 0; i < 1000000; ++i) {
//         // Some operation
//     }

//     end = clock(); // Stop measuring CPU time

//     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

//     std::cout << "CPU time used: " << cpu_time_used << " seconds" << std::endl;

//     return 0;
// }

// We include the <iostream> and <ctime> headers.
// We use clock_t to store the start and end times for measuring CPU time.
// We use clock() to get the processor time before and after the code execution.
// We calculate the CPU time used by subtracting the start time from the end time and divide by CLOCKS_PER_SEC to get the time in seconds.
// Finally, we print the CPU time used in seconds.
// You can use <ctime> whenever you need to work with time values, measure CPU time, or format dates and times in your C++ programs.


// Here's an overview of some commonly used functionalities provided by the <ctime> header:

// time_t: A type representing calendar time.
// clock_t: A type representing processor time.
// clock(): A function that returns the processor time used by the program since the start of execution.
// time(): A function that returns the current calendar time as a time_t object.
// ctime(): A function that converts a time_t object to a human-readable string representing the local time.
// strftime(): A function to format date and time.