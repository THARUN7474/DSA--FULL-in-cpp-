#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10;
    int A[3] = {1, 2, 3};
    char V[3] = {'a', 'c', 'd'};
    string s = "tharun";

    cout << A << endl;
    cout << V << endl;

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cout << A[i] << " " << V[i] << endl;
    }

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
    cout << s << endl;
    // ===============================================================vector============================================

    // In C++, a vector is a dynamic array that can resize itself automatically when elements are added or removed.
    // Vectors are part of the Standard Template Library (STL) and provide a convenient way to work with collections of elements.
    // #include <vector>
    // vector<int> vec;
    // vector<int> vec = {1, 2, 3, 4, 5};
    // for (int num : vec) {
    //     std::cout << num << " ";  // Output each element separated by space
    // }
    // // Resize the vector to contain 10 elements, filling with default-initialized values
    // vec.resize(10);

    // // Resize the vector to contain 10 elements, filling with a specific value
    // vec.resize(10, 0);  // Fill with 0

    //     // Declare a vector of strings
    //     vector<string> stringVector;
    //     // Add strings to the vector
    // stringVector.push_back("Hello");
    //     stringVector.push_back("World");

    //     // Access and print elements of the vector
    //     for (const string& str : stringVector) {
    //         cout << str << " "; // Output: Hello World
    //     }

    //     // Declare a vector of characters
    //     vector<char> charVector;

    //     // Add characters to the vector
    //     charVector.push_back('A');
    //     charVector.push_back('B');
    //     charVector.push_back('C');

    //     // Access and print elements of the vector
    //     for (char ch : charVector) {
    //         cout << ch << " "; // Output: A B C
    //     }

    vector<int> AA(10, 100);
    // 10 elements and each s=is 100
    AA[9] = 1000;
    AA.push_back(199);
    for (int i = 0; i < AA.size(); i++)
    {
        cout << AA[i] << " ";
    }

    // ======================================================stack==========================================================
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    int *ptr1 = new int(10);
    int *ptr2 = new int(20);

    std::stack<int *> pointerStack; // Declare an empty stack of pointers to integers

    pointerStack.push(ptr1); // Push pointer ptr1 onto the stack
    pointerStack.push(ptr2); // Push pointer ptr2 onto the stack

    int *topPtr = pointerStack.top(); // Access the top element of the stack (ptr2)

    // Don't forget to delete the dynamically allocated memory
    delete ptr1;
    delete ptr2;

    // ======================================================queue==========================================================

    queue<int> qu;

    qu.push(1);
    qu.push(2);

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << "\n";

    unordered_map<int, int> mp;
    mp[10] = 123;
    mp[1] = 143;

    cout << mp[10] << mp[11] << endl;
    cout << mp.size() << endl;

    set<int> stt;
    stt.insert(10);
    stt.insert(10);
    stt.insert(-1);
    cout << *(stt.begin()) << endl;
    // cout<< stt.erase(stt.begin())<<endl;
    // cout<< stt.erase(stt.begin())
}