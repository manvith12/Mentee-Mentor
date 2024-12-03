// week1-day3 priotityqueue q1, same old appsartment question //


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<int, vector<int>, Compare> apps;
    priority_queue<int, vector<int>, Compare> apts;

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        apps.push(size);
    }

    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        apts.push(size);
    }

    int matches = 0;

    while (!apps.empty() && !apts.empty()) {
        int app = apps.top();
        int apt = apts.top();

        if (apt >= app - k && apt <= app + k) {
            matches++;
            apps.pop();
            apts.pop();
        } else if (apt < app - k) {
            apts.pop();
        } else {
            apps.pop();
        }
    }

    cout << matches << endl;

    return 0;
}

