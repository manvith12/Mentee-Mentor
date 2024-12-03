// week1-day3 stack q1 //

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s1;
    stack<int> s2;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s1.push(x);
    }

    while (s1.size() > 0) {
        int current = s1.top();
        s1.pop();
        cout << current << endl; 

        if (s2.size() == 0 || s2.top() < current) {
            s2.push(current);
        }
    }

    while (s2.size() > 0) {
        cout << s2.top() << endl;
        s2.pop();
    }

    return 0;
}

