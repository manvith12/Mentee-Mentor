#include <iostream>
#include <set>

using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    
    cout << s.size() << endl;
    return 0;
}