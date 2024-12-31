#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAliceWin(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<int> middleRow = grid[1];
    sort(middleRow.begin(), middleRow.end());
    for (int i = 0; i < n; ++i) {
        if (middleRow[i] <= 0) return false;
        if (i > 0 && middleRow[i] == middleRow[i - 1]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(3, vector<int>(n));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        if (canAliceWin(grid)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
