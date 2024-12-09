#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int total_pieces = 0;
        int happy_days = 0;
        int layer = 0;
        int pieces_needed_for_layer = 1;

        for (int i = 0; i < n; i++) {
            total_pieces += v[i];
            while (total_pieces >= pieces_needed_for_layer) {
                total_pieces -= pieces_needed_for_layer;
                layer++;
                pieces_needed_for_layer = 8 * layer;
            }
            if (total_pieces == 0) {
                happy_days++;
            }
        }

        cout << happy_days << endl;
    }

    return 0;
}