// week1 - day7 , generating subsets q3
// link: https://www.usaco.org/index.php?page=viewproblem2&cpid=1276


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cool;
};

struct ac {
    int start, end, power, cost;
};

int N, M;
vector<Cow> cows;
vector<ac> acs;

bool isValid(vector<int>& cool) {
    for (const Cow& cow : cows) {
        for (int i = cow.start; i <= cow.end; ++i) {
            if (cool[i] < cow.cool) {
                return false;
            }
        }
    }
    return true;
}

int cost(int index, vector<int>& cool) {
    if (index == M) {
        return isValid(cool) ? 0 : INT_MAX;
    }

    
    int costWithout = cost(index + 1, cool);

    for (int i = acs[index].start; i <= acs[index].end; ++i) {
        cool[i] += acs[index].power;
    }
    int costWith = cost(index + 1, cool);
    if (costWith != INT_MAX) {
        costWith += acs[index].cost;
    }
    for (int i = acs[index].start; i <= acs[index].end; ++i) {
        cool[i] -= acs[index].power;
    }

    return min(costWithout, costWith);
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

    vector<int> cool(101, 0); 
    int result = cost(0, cool);

    cout << result << endl;

    return 0;
}