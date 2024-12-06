# Goal
- Today we will be upsolving yesterday's [Div 3](https://codeforces.com/contest/2050)
# Problems
### [A. Line Breaks](https://codeforces.com/contest/2050/problem/A)
> [!hint]- Hint 1
> Keep subtracting the current string length from $x$.

> [!success]- Solution
> Keep subtracting the size of the current string from $x$.
> If $x \ge 0$, the means the current string can fit on the first strip.
> ```cpp
> #include <bits/stdc++.h>
> using namespace std;
> 
> #define all(x) (x).begin(), (x).end()
> #define rall(x) (x).rbegin(), (x).rend()
> #define sz(x) (int)(x).size()
> #define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
> 
> typedef long long ll;
> typedef vector<int> vint;
> typedef pair<int, int> pint;
> 
> void solve() {
>     int n, x; cin >> n >> x;
>     int ctr = 0;
>     for (int i = 0; i < n; i++) {
>         string s; cin >> s;
>         x -= s.size();
>         if (x >= 0)
>             ctr++;
>     }
>     cout << ctr;
> }
> 
> int main() {
>     int T = 1;
>     cin >> T;
>     while (T--) {
>         solve();
>         cout << "\n";
>     }
>     return 0;
> }
> ```

### [B. Transfusion](https://codeforces.com/contest/2050/problem/B)
> [!hint]- Hint 1
> - Operations performed at odd indices don't affect even indices and vice versa.
> - So the problem can be reduces to two lists one with all the elements at odd positions and the other with even.
> - For each of these lists you you can choose two adjacent elements, increment one and decrement the other.

> [!hint]- Hint 2
> - If it is possible to make them all equal what will the value be?
> - Each operation doesn't effect the sum of all the elements.

> [!hint]- Hint 3
> - If possible the value will be equal to the average.

> [!success]- Solution
> - Make sure that the average is integral.
> - Make sure the the average is the same for the odd and the even lists.
> ```cpp
> #include <bits/stdc++.h>
> using namespace std;
> 
> #define all(x) (x).begin(), (x).end()
> #define rall(x) (x).rbegin(), (x).rend()
> #define sz(x) (int)(x).size()
> #define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
> 
> typedef long long ll;
> typedef vector<int> vint;
> typedef pair<int, int> pint;
> 
> void solve() {
>     int n; cin >> n;
>     ll odd_sum = 0, even_sum = 0;
>     int odd_count = 0, even_count = 0;
>     FOR(i, n) {
>         int x; cin >> x;
>         if (i % 2) {
>             odd_sum += x;
>             odd_count++;
>         }
>         else {
>             even_sum += x;
>             even_count++;
>         }
>     }
> 
>     int odd_rem = odd_sum % odd_count;
>     int even_rem = even_sum % even_count;
> 
>     int odd_val = odd_sum / odd_count;
>     int even_val = even_sum / even_count;
> 
>     if (odd_rem == 0 && even_rem == 0 && odd_val == even_val)
>         cout << "YES";
>     else
>         cout << "NO";
> }
> 
> int main() {
>     int T = 1;
>     cin >> T;
>     while (T--) {
>         solve();
>         cout << "\n";
>     }
>     return 0;
> }
> ```
### [C. Uninteresting Number](https://codeforces.com/contest/2050/problem/C)
> [!hint]- Hint 1
> - Squaring $0$ and $1$ has no effect.
> - Squares of $3, 4, \ldots$ are too large.
> - Our only options are $2^2 \to 4$ and $3^2 \to 9$.

> [!hint]- Hint 2
> - The divisibility rule for $9$ is that the sum of the digits should be divisible by $9$.
> - Changing $2 \to 4$ gives changes the sum by $+2$.
> - Changing $3 \to 9$ gives changes the sum by $+6$.
> - So we need to decide how many of the above changes should be made.

> [!hint]- Hint 3
> - Bruteforcing through all counts of twos and threes to be changes will take $O(n^2)$ time.
> - We can make 2 observation to help reduce the time complexity of the bruteforce.
> 1) After we convert $2 \to 4$ $9$ times, we are only repeating old conditions by adding more $2$s.
> 2) After we convert $3 \to 9$ $3$ times, we are only repeating old conditions by adding more $6$s.

> [!success]- Solution
> - Reduce the time complexity by capping `two_count` at $9$ and `three_count` at $3$.
> ```cpp
> #include <bits/stdc++.h>
> using namespace std;
> 
> #define all(x) (x).begin(), (x).end()
> #define rall(x) (x).rbegin(), (x).rend()
> #define sz(x) (int)(x).size()
> #define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
> 
> typedef long long ll;
> typedef vector<int> vint;
> typedef pair<int, int> pint;
> 
> bool solve() {
>     string s; cin >> s;
>     int two_count = 0, three_count = 0;
>     int dig_sum = 0;
>     for (char c : s) {
>         dig_sum += c - '0';
>         if (c == '2')
>             two_count++;
>         else if (c == '3')
>             three_count++;
>     }
>     two_count = min(two_count, 9);
>     three_count = min(three_count, 3);
>     for (int i = 0; i <= two_count; i++) {
>         for (int j = 0; j <= three_count; j++) {
>             if ((dig_sum + 2 * i + 6 * j) % 9 == 0)
>                 return true;
>         }
>     }
>     return false;
> }
> 
> int main() {
>     int T = 1;
>     cin >> T;
>     while (T--) {
>         if (solve()) cout << "YES";
>         else cout << "NO";
>         cout << "\n";
>     }
>     return 0;
> }
> ```

### [D. Uninteresting Number](https://codeforces.com/contest/2050/problem/C)
> [!hint]- Hint 1
> - Think of each operation as swapping the current digit with the one at a higher position at a cost of 1.
> - So the swap is only useful if `current_digit > other_digit + 1`

> [!hint]- Hint 2
> - We want the lexicographically largest number at the end.
> - So we should work from left to right, getting the maximum possible digit at each position.

> [!hint]- Hint 3
> - To check the max possible value for the current digit, we need to compare it with the next $8$ digits.
> - We want to check whether the `digit - dist > current digit`.

> [!success]- Solution
> - If the current digit is $i$.
> - Check the next $8 - i$ digits.
> - Valid swap if `new_digit - dist > current_digit`.
> - Find the largest `new_digit - dist` perform the required swaps.
> ```cpp
> #include <bits/stdc++.h>
> using namespace std;
> 
> #define all(x) (x).begin(), (x).end()
> #define rall(x) (x).rbegin(), (x).rend()
> #define sz(x) (int)(x).size()
> #define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
> 
> typedef long long ll;
> typedef vector<int> vint;
> typedef pair<int, int> pint;
> 
> void solve() {
>     string s; cin >> s;
>     vint a;
>     for (char c : s)
>         a.push_back(c - '0');
>     FOR(i, sz(s)) {
>         // max_index is the position where the new max digit can be found
>         int max_index = 0;
>         FOR(j, min(8 - a[i], sz(s) - i - 1)) {
>             // current digit is a[i + j + 1]
>             if (a[i + max_index] - max_index < a[i + j + 1] - j - 1)
>                 max_index = j + 1;
>         }
>         // moving it up to the current position
>         int temp = a[i + max_index] - max_index;
>         FOR(j, max_index)
>             a[i + max_index - j] = a[i + max_index - j - 1];
>         a[i] = temp;
>     }
>     for (int x : a)
>         cout << x;
> }
> 
> int main() {
>     int T = 1;
>     cin >> T;
>     while (T--) {
>         solve();
>         cout << "\n";
>     }
>     return 0;
> }
> ```