#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    res += mp[k - a[i]];
    ++mp[a[i]];
  }
  cout << res;
  return 0;
}