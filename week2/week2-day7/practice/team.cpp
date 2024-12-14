#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;

    int n;
    cin >> n;
    while (n--) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}