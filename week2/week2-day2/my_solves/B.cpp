#include <bits/stdc++.h>
using namespace std;

char find(vector<string>& grid, int row, int col) {
    set<char> letters = {'A', 'B', 'C'};
    for (int i = 0; i < 3; ++i) {
        letters.erase(grid[row][i]);
        letters.erase(grid[i][col]);
    }
    return *letters.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<string> grid(3);
        int row = -1, col = -1;
        for (int i = 0; i < 3; ++i) {
            cin >> grid[i];
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == '?') {
                    row = i;
                    col = j;
                }
            }
        }
        char x = find(grid, row, col);
        cout << x << "\n";
    }
    return 0;
}