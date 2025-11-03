#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

#define int long long

signed main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  int a[n + 1];
  int cnt = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt += mp[x - a[i]];
    mp[a[i]]++;
  }
  cout << cnt << '\n';
}