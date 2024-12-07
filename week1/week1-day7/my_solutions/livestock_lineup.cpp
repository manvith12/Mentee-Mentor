// week1 day 7 , permutation q4
// link: http://www.usaco.org/index.php?page=viewproblem2&cpid=965



#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<pair<string, string>> cs;

bool isValid(const vector<string>& lineup) {
    for (const auto& c : cs) {
        auto it1 = find(lineup.begin(), lineup.end(), c.first);
        auto it2 = find(lineup.begin(), lineup.end(), c.second);
        if (abs(distance(it1, it2)) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    int N;
    fin >> N;
    fin.ignore(); 
    cs.resize(N);
    for (int i = 0; i < N; ++i) {
        string cow1, cow2, temp;
        fin >> cow1 >> temp >> temp >> temp >> temp >> cow2;
        cs[i] = {cow1, cow2};
    }

    sort(cows.begin(), cows.end());
    vector<string> order;

    do {
        if (isValid(cows)) {
            if (order.empty() || cows < order) {
                order = cows;
            }
        }
    } while (next_permutation(cows.begin(), cows.end()));

    for (const auto& cow : order) {
        fout << cow << endl;
    }

    return 0;
}