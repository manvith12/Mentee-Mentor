#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int flag=0;
  vector<long long> a(1024,0);
  a[0]++;
  long long result=0;
  for(auto &nx : s){

    flag^=(1<<(nx-'0'));
    result+=a[flag];
    a[flag]++;

  }
  cout << result << "\n";
  return 0;
}
