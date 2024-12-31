#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to precompute prime ASCII values in the range [32, 126]
vector<int> computePrimes() {
    vector<int> primes;
    for (int i = 32; i <= 126; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
    return primes;
}

/*
 * Function to map input characters to nearest prime ASCII characters
 */
vector<char> nearest_prime_char(vector<char> input_chars) {
    // Precompute prime ASCII values
    vector<int> primes = computePrimes();

    vector<char> result;
    for (char c : input_chars) {
        int ascii_val = (int)c;  // Get ASCII value of character

        // Find the nearest prime greater than or equal to the current ASCII value
        auto it = lower_bound(primes.begin(), primes.end(), ascii_val);
        int nearest_prime = *it;  // Prime value greater than or equal to ASCII

        result.push_back((char)nearest_prime);  // Convert prime ASCII back to char
    }

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    // Input: number of characters and list of characters
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(n_temp);

    string chars_temp_temp;
    getline(cin, chars_temp_temp);
    vector<string> chars_temp = split(chars_temp_temp);

    vector<char> input_chars(n);
    for (int i = 0; i < n; i++) {
        input_chars[i] = chars_temp[i][0];
    }

    // Invoke function to map characters to nearest prime ASCII characters
    vector<char> output = nearest_prime_char(input_chars);

    // Output result
    for (size_t i = 0; i < output.size(); i++) {
        fout << output[i];
        if (i != output.size() - 1) fout << ",";
    }

    fout << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0, end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
