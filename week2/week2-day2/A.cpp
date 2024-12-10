#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector <int> a(3);
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(a[1]== a[0]){
            cout << a[2]<< "\n";
        }
        else if(a[2] == a[1]){
            cout << a[0]<< "\n";
        }
        else{
            cout <<a[1]<< "\n";

        }
    }
    return 0;
}