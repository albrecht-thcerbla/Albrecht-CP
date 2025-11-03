#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ++mp[a[i]];
  }
  while (k--) {
    int x; cin >> x;
    if (mp[x]) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}