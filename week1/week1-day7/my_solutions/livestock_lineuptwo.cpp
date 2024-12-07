//week1 day7 permutations q4
// link: http://www.usaco.org/index.php?page=viewproblem2&cpid=965


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<pair<string, string>> constraints;
vector<string> order;

bool isValid(const vector<string>& lineup) {
    for (const auto& constraint : constraints) {
        auto it1 = find(lineup.begin(), lineup.end(), constraint.first);
        auto it2 = find(lineup.begin(), lineup.end(), constraint.second);
        if (abs(distance(it1, it2)) != 1) {
            return false;
        }
    }
    return true;
}

void generatePermutations(vector<string>& lineup, int index) {
    if (index == lineup.size()) {
        if (isValid(lineup)) {
            if (order.empty() || lineup < order) {
                order = lineup;
            }
        }
        return;
    }

    for (int i = index; i < lineup.size(); ++i) {
        swap(lineup[index], lineup[i]);
        generatePermutations(lineup, index + 1);
        swap(lineup[index], lineup[i]);
    }
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    int N;
    fin >> N;
    fin.ignore(); // Ignore the newline character after the number

    constraints.resize(N);
    for (int i = 0; i < N; ++i) {
        string cow1, cow2, temp;
        fin >> cow1 >> temp >> temp >> temp >> temp >> cow2;
        constraints[i] = {cow1, cow2};
    }

    sort(cows.begin(), cows.end());
    generatePermutations(cows, 0);

    for (const auto& cow : order) {
        fout << cow << endl;
    }

    return 0;
}