#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; 
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string result = "";
        while (!str.empty()) {
            int x;
            if (str.back() == 'a' || str.back() == 'e') {
                x = 2;
            } else {
                x = 3;
            }
            while (x--) {
                result += str.back();
                str.pop_back();
            }
            result += '.';
        }
        result.pop_back();
        reverse(result.begin(), result.end());
        cout << result << '\n';
    }
    return 0;
}