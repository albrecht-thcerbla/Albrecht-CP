#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> v;
  while (n / 10 >= 1) {
    v.emplace_back(9);
    n -= 9;
  }
  v.emplace_back(n);
  sort(all(v));
  for (int i = 0; i < sz(v); i++) cout << v[i];
  return 0;
}