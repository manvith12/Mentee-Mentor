// week2-day6 (distinct numbers) q1
// Link: https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;  
    bitset <MAX_VAL+1> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.set(x);
    }
    cout << s.count() << endl;




    return 0;
}
