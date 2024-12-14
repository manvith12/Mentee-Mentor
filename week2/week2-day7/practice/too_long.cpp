#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int num = s.size();
        if (num > 10) {
            cout << s[0] << num - 2 << s[num - 1] << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}