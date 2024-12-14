#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    // Convert to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Remove vowels
    s.erase(remove_if(s.begin(), s.end(), isVowel), s.end());

    // Add dot before each remaining character
    string result;
    for (char c : s) {
        result += '.';
        result += c;
    }

    cout << result << endl;

    return 0;
}