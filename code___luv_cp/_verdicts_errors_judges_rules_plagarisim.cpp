// Verdicts and Errors on Online Coding Websites Explained
// More details available in the DSA page in Notion

// Every problem has the following two buttons:

// a. Compile & Run
// When you click Compile & Run, the code is tested against the sample input and output.
// This ensures that you are able to test your code against predefined sample test cases before you submit your code.

// b. Submit
// When you click Submit, the code is checked extensively against internal test cases. The following parameters are considered while checking the code:

// 1. Time limit: The code should run within the stipulated time; otherwise, it will throw a Time Limit Exceeded (TLE) error.
// 2. Memory limit: The code should run within the given memory size; otherwise, it will throw a Memory Limit Exceeded (MLE) error.
// 3. Errors during runtime: Specific test cases check for Runtime Errors (RE) only.
// 4. Correct answer: If your answer is incorrect, you will see the message "Wrong Answer (WA)" on the screen. This means that your program is not printing the correct answer. Ensure that your program conforms with the output format that is required.

// Different feedback forms and names on websites
// Common errors like Time Limit Exceeded (TLE), Memory Limit Exceeded (MLE), and Runtime Errors (RE) are explained below:

// - **TLE**: Occurs when your code takes longer than the allowed time to execute. 
// - **MLE**: Happens when your program exceeds the memory limit allocated for the problem. 
// - **RE in Recursion**: Recursion can cause a stack overflow if the recursion depth is too large, leading to runtime errors.

// Importance of understanding these errors for competitive programming:
// Pay attention to memory limits while coding online.

// Online compilation may be slow due to memory limitations. Compile and test your code locally, then submit it on online coding websites to avoid performance issues.
// Exceeding memory limits can cause your code to fail on online coding websites. For instance, array declaration in global memory exceeding 10^7 and locally 10^5 will throw a Memory Limit Exceeded error.
// Memory limits are typically around 256 MB or 512 MB, so optimization is crucial.

// Understanding memory optimization in competitive programming:
// Emphasizing the importance of memory optimization in solving hard coding problems.
// Explaining the risks of runtime errors and illegal memory access due to excessive memory consumption.

// Understanding GCC compiler and segmentation fault:
// The GCC compiler may produce a segmentation fault, which occurs when code tries to access a null pointer or accesses memory outside defined limits.

// Runtime errors can be caused by division errors and time/memory limit violations:
// Division errors (e.g., division by zero) can lead to runtime errors, so it's important to check for mistakes in division operations.
// Understanding and adhering to time and memory limits is crucial to avoid runtime errors. Illegal memory access can also cause runtime errors.
// Example: a[-1] -- Negative indexing in C/C++ is not allowed and can cause segmentation faults. Illegal memory access leads to runtime errors in coding competitions.

// Impact of increased compilation time on online coding education:
// Increased compilation time does not affect education time on online coding platforms.
// Time complexity is used to estimate the runtime of the code.
// Header files like `conio.h` and `iostream` can cause increased compilation time. However, this does not affect runtime. It's better to use `#include<bits/stdc++.h>` instead of `iostream` and `conio.h` to reduce compilation time.

// Time limit given in online coding websites is typically 1 second.
// If your code takes more than 1 second to run, it will throw a Time Limit Exceeded (TLE) error.
// You need to optimize your code to ensure that it runs within 1 second. In local coding environments, you may have more time, but online coding platforms enforce stricter time limits.
// Note: The 1-second limit is for runtime, not compilation time. 

// Understanding time limits in competitive programming:
// Explanation of the importance of time limits in coding competitions for educational purposes.
// Example: If your code has a time complexity that exceeds the allowed time, the system will throw a TLE error, and you will need to optimize your algorithm.

// Explanation of Time Limit Exceeded error in programming:
// Discussing the impact of long-running code causing a TLE error.
// Importance of having a proper breaking condition in the code to prevent runtime errors caused by excessive execution time.
// Functions with excessive noise (unnecessary operations or complexity) can cause Time Limit Exceeded errors.
// Exceeding the time limit occurs when code execution takes longer than allowed, leading to a runtime error.
// Runtime errors can occur due to exceeding time limits or memory limits while coding.
// It is important to optimize code to avoid runtime errors and utilize memory efficiently.
// Example: Using a large array in C++ can lead to memory limit exceeded errors. It is better to use vectors or dynamic memory allocation to avoid this issue.

/*
===============================================================
🧠 ONLINE JUDGE BEHAVIOR EXPLAINED
===============================================================

10. ✅ How does the Online Judge determine correctness?

- The judge compares your program's output with pre-generated correct outputs.
- It checks:
  1. If the output **matches exactly**.
  2. If the output is **in the correct order**.

❌ Your program is marked incorrect if:
- Outputs don't match expected outputs.
- Outputs match but are in a different order than expected.

---------------------------------------------------------------

11. ⏱️ How does the Time Limit work?

- Each input file must be processed **within the time limit** specified.
- If input contains **multiple test cases**, all of them must complete within that limit.

---------------------------------------------------------------

12. ⌛ What is Total Execution Time?

- Your code is run on **multiple input files**.
- Displayed time = sum of all file execution times.

🛑 Program gets terminated if:
- Any input file execution exceeds the individual time limit.
- Total execution time exceeds total allowed time.

Total Execution Time ≤ (Time Limit × Number of Input Files)

---------------------------------------------------------------

13. 🧠 How is Memory Consumed calculated?

- Total memory = Memory used in:
    • Stack
    • Data segment
    • Heap
    • BSS (Block Started by Symbol)

📚 Refer to diagrams on address space layout to learn more.

---------------------------------------------------------------

14. ⚠️ My program doesn't compile. Why?

[C/C++]
- Don't use Turbo C++.
- Avoid including 'conio.h'.
- Use a modern standard-compliant compiler.

[Java]
- Multiple classes are allowed.
- Inner classes must be static.
- (This constraint will be removed soon.)

[Other Languages]
- Compilation errors are shown on screen.
- For help: support@hackerearth.com

---------------------------------------------------------------

15. 🚫 What does TLE (Time Limit Exceeded) mean?

- TLE means your code took **too long to execute** and was forcibly stopped.
- ⚠️ It does NOT mean your code is correct but slow.
- It never completed execution → correctness can't be confirmed.

---------------------------------------------------------------

16. ❌ What does WA (Wrong Answer) mean?

- Your code compiled and ran but gave a wrong output.

WA can happen due to:
  • Bugs in the code logic.
  • Misinterpreting the problem statement.
  • Passing only the sample input but failing hidden test cases.

📌 Always test with multiple edge cases beyond the sample!

===============================================================
*/




/*
===================================================================
⚠️ RUNTIME ERRORS — WHY THEY HAPPEN & HOW TO AVOID THEM
===================================================================

22. ❌ Why am I seeing a Runtime Error?

🧠 A Runtime Error means:
- Your code compiled successfully ✅
- But crashed or exited abnormally during execution ❌

🔍 Common Runtime Error Types:

| S.No | Error   | Description                     | Likely Reason |
|------|---------|----------------------------------|----------------|
| 1.   | SIGSEGV | Segmentation Fault              | Accessing out-of-bounds array index (e.g., a[-1]), invalid pointer usage |
| 2.   | SIGXFSZ | Output Limit Exceeded           | Printed too much data to standard output |
| 3.   | SIGFPE  | Floating Point Error            | Division by 0, sqrt of negative number |
| 4.   | SIGABRT | Aborted Program                 | Aborted due to manual abort or memory issues |
| 5.   | NZEC    | Non-Zero Exit Code              | Program exited with value ≠ 0 (e.g., uncaught exception, crash) |
| 6.   | MLE     | Memory Limit Exceeded           | Used more memory than allowed (e.g., large array) |
| 7.   | OTHER   | Misc. memory or logic issues    | Similar to SIGSEGV, or oversized objects |

🔒 How to Avoid Runtime Errors:
- ✅ Always initialize variables before use
- ✅ Check for array bounds before accessing elements
- ✅ Declare large arrays globally (outside functions)
- ✅ Avoid declaring arrays > [100000][100000] (too large!)
- ✅ Catch all exceptions (especially in Python, Java)
- ✅ Avoid excessive memory or output usage
- ✅ Use `try-catch` blocks to handle exceptions gracefully
- ✅ Use `assert` statements to check assumptions in code

Ensure that you are not using variables that haven't been initialized. These may be set to 0 on your computer, but aren't guaranteed to be on the judge.

Check every single occurrence of accessing an array element and see if it could possibly be out of bounds.

Ensure that you are not declaring too much memory. 64 MB is guaranteed, but having an array of size [100000][100000] will never work.

Ensure that you are not declaring too much stack memory. Any large arrays should be declared globally, outside of any functions - putting an array of 100000 ints inside a function probably will not work.
-------------------------------------------------------------------

🔐 17. What happens if I indulge in PLAGIARISM?

🛑 Plagiarism is taken **very seriously** in coding contests.

💥 What happens:
- Your submission may be rejected
- You can be permanently banned from platforms
- Institute/contest organizers may also be notified

🔍 How is plagiarism detected?
Online judges use **automated plagiarism detection tools** such as:
- Moss (Measure of Software Similarity)
- JPlag
- Sherlock
- Similarity Checker Algorithms (token-based, AST-based, etc.)

They check:
- Code structure, logic flow, formatting patterns
- Variable renaming, spacing tricks (they won’t fool the system)
- Even comments or unused variables won’t hide your intent

🚫 What **NOT** to do:
- Don’t copy code from friends, internet, or AI tools blindly
- Don’t submit identical logic with minor edits
- Don’t collaborate or share code during live contests

🤖 AI Usage:
- Using AI for help in **learning** is fine
- But using AI to generate full contest solutions is considered cheating
- AI-generated solutions can be traced and flagged

💡 Safe Practice:
- Learn the concept → Solve on your own
- If using templates/snippets, make sure they are **commonly available**
- Cite references in non-contest environments (interviews, GitHub)

🔥 Tip:
If you can’t explain your own code, it's better not to submit it.

-------------------------------------------------------------------

🧠 Always remember:
“Coding is not just about writing working code — it’s about **problem solving** and **integrity**.”

===================================================================
*/



#include<bits/stdc++.h>
using namespace std;

char upper(char c){
    return 'A' + (c - 'a');
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long product = 1;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            product = product * x;
        }
        int digit = product % 10;
        if(digit == 2 || digit == 3 || digit == 5)
            cout << "YES\n";
        else{
            cout << "NO\n";
        }
    }
}

/***** A *****/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int c = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'c')
                c++;
        }
        cout << c << endl;
    }
}

/***** A *****/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    cout << ans << endl;
}

/***** A *****/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << "EVEN\n";
    } else {
        cout << "ODD\n";
    }
}

/***** A *****/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        cout << arr[n - 1] << endl;  // Maximum
    }
}

/***** A *****/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
}



// ABOVE ALL ARE CORRECT VERDICT--SUCCESS FULL CASES

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int a[N];

int main() {
    for (int i = 0; i < 4 * N; ++i) {
        a[i] = i;
    }
    cout << a[N - 1];
}
//errors throws -- segmentation fault--illegal memory access--runtime error--memory limit exceeded--SIGSEGV--SIGABRT--SIGXFSZ--SIGFPE--NZEC--MLE--OTHER

// This code has undefined behavior, because the array a has size N (i.e., 10,000), but you're trying to access and assign values up to 4 * N = 40,000, which exceeds the array bounds. This can crash the program or cause incorrect output.


#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
vector<int> a(N); // or int a[N]; // This will cause MLE
// This code will throw a memory limit exceeded error because the array size exceeds the memory limit set by the online judge. The maximum size of an array that can be declared globally is usually around 10^7 or 10^8, depending on the platform.

int main() {
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    cout << "Array initialized successfully." << endl;
    return 0;
}
// 1e8 means you're trying to create an array/vector of size 100 million. This will consume a lot of memory (400MB), so most systems might crash unless you have large stack/heap size or use efficient methods.

// If you don't actually need that large a vector, try reducing N to something smaller like 1e6 (1 million).

// If you're working in competitive programming, using int a[N]; globally may work (because of global memory), but inside main() it's safer with vector<int> or dynamic memory.



#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;
const int M = 1e4;
int a[M];  // Assuming you want a smaller array to avoid memory issues

int main() {
    for (int i = 0; i < M; ++i) {
        a[i%N] = i;// THIS THROWS --- TLE as it is not possible to do 10^9 iterations in 1 second 
    }
    cout << a[M - 1];
}


#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;
const int M = 1e4;
int a[M];

void func(int i) {
    if(N <= i) return;  // Base case to prevent infinite recursion
    a[i%N] = i;  // Assign value to the array
    func(i + 1);  // Recursive call to fill the array
}

int main() {
    func(0);
    cout << a[N - 1];  // Output the last value to verify
    return 0;

    //THIS ALSO GIVE TLE --IN RECURSION--AS IT IS NOT POSSIBLE TO DO 10^9 ITERATIONS IN 1 SECOND 
}


#include <bits/stdc++.h>
using namespace std;

void func(int i) {
    func(i + 2);
    func(i + 1);
    func(i - 1);
}

int main() {
    func(0);
    return 0;
}
// } what you've described is an infinite recursion that causes a stack overflow, leading to a segmentation fault (SegFault) or runtime error (RE) — not a Time Limit Exceeded (TLE) — because the call stack blows up way before any timeout.
// This function has no base case, so recursion never stops.

// Calls itself 3 times per level: O(3^n) growth — extreme!

// The system stack overflows very quickly, often in under a second.

// That’s why you get a SegFault/MLE instead of TLE.

