#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cool;
};

struct AC {
    int start, end, power, cost;
};

int N, M;
vector<Cow> cows;
vector<AC> acs;

bool isValid(vector<int>& cooling) {
    for (const Cow& cow : cows) {
        for (int i = cow.start; i <= cow.end; ++i) {
            if (cooling[i] < cow.cool) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cows.resize(N);
    acs.resize(M);

    for (int i = 0; i < N; ++i) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cool;
    }

    for (int i = 0; i < M; ++i) {
        cin >> acs[i].start >> acs[i].end >> acs[i].power >> acs[i].cost;
    }

    int minCost = INT_MAX;

    for (int mask = 0; mask < (1 << M); ++mask) {
        vector<int> cooling(101, 0);
        int cost = 0;

        for (int i = 0; i < M; ++i) {
            if (mask & (1 << i)) {
                cost += acs[i].cost;
                for (int j = acs[i].start; j <= acs[i].end; ++j) {
                    cooling[j] += acs[i].power;
                }
            }
        }

        if (isValid(cooling)) {
            minCost = min(minCost, cost);
        }
    }

    cout << minCost << endl;

    return 0;
}