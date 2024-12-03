#include <bits/stdc++.h>
using namespace std;
int main() {
int n, m, k;
cin >> n >> m >> k;
vector<int> a(n);
for (int i = 0; i < n; i++)
cin >> a[i];
sort(a.begin(), a.end());
vector<int> b(m);
for (int i = 0; i < m; i++)
cin >> b[i];
sort(b.begin(), b.end());
int next_person = 0, next_apt = 0;
int ctr = 0;
while (next_person != n && next_apt != m) {
if (a[next_person] > b[next_apt] + k)
next_apt++;
else if (a[next_person] < b[next_apt] - k)
next_person++;
else
next_person++, next_apt++, ctr++;
}
cout << ctr;
return 0;
}