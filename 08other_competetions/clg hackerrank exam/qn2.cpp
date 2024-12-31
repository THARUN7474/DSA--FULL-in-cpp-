#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<bool> results;

    for (int t = 0; t < T; ++t) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> couples(K);
        for (int i = 0; i < K; ++i) {
            cin >> couples[i].first >> couples[i].second;
        }

        unordered_map<int, char> gender;
        bool invalid = false;

        for (const auto& couple : couples) {
            int a = couple.first;
            int b = couple.second;

            if (gender.count(a) && gender.count(b)) {
                if (gender[a] == gender[b]) {
                    invalid = true;  // invalid couple found
                    break;
                }
            } else if (gender.count(a)) {
                gender[b] = (gender[a] == 'M') ? 'F' : 'M';
            } else if (gender.count(b)) {
                gender[a] = (gender[b] == 'M') ? 'F' : 'M';
            } else {
                gender[a] = 'M';
                gender[b] = 'F';
            }
        }

        results.push_back(invalid);
    }

    for (bool result : results) {
        cout << (result ? "True" : "False") << endl;
    }

    return 0;
}




// #include <iostream>
// #include <vector>

// using namespace std;

// class UnionFind {
// public:
//     vector<int> parent, rank, gender;

//     UnionFind(int n) {
//         parent.resize(n);
//         rank.resize(n, 0);
//         gender.resize(n, -1);
//         for (int i = 0; i < n; ++i) {
//             parent[i] = i;
//         }
//     }

//     int find(int x) {
//         if (parent[x] != x) {
//             int original = parent[x];
//             parent[x] = find(parent[x]);
//             gender[x] = (gender[x] + gender[original]) % 2;  // Update gender while compressing path
//         }
//         return parent[x];   
//     }

//     bool unionSet(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX == rootY) {
//             return gender[x] == gender[y];  // Check for same gender conflict
//         }

//         if (rank[rootX] > rank[rootY]) {
//             parent[rootY] = rootX;
//             gender[rootY] = (gender[x] + 1 + gender[y]) % 2;
//         } else if (rank[rootX] < rank[rootY]) {
//             parent[rootX] = rootY;
//             gender[rootX] = (gender[y] + 1 + gender[x]) % 2;
//         } else {
//             parent[rootY] = rootX;
//             gender[rootY] = (gender[x] + 1 + gender[y]) % 2;
//             rank[rootX]++;
//         }
//         return false;  // No conflict
//     }
// };

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int N, K;
//         cin >> N >> K;

//         UnionFind uf(N + 1);  // Create UnionFind instance

//         bool invalidCoupleFound = false;
//         for (int i = 0; i < K; ++i) {
//             int a, b;
//             cin >> a >> b;
//             if (uf.unionSet(a, b)) {
//                 invalidCoupleFound = true;
//             }
//         }

//         if (invalidCoupleFound) {
//             cout << "True" << endl;
//         } else {
//             cout << "False" << endl;
//         }
//     }

//     return 0;
// }
