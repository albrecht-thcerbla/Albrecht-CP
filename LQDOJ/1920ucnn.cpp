#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int a[n + 1];
  int mn = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) return cout << -1, 0;
    mn = min(mn, a[i]);
  }
  // tim cac uoc cua min
  vector<int> v;
  for (int i = 2; i <= sqrt(mn); i++) {
    if (mn % i == 0) {
      if (mn / i != i) {
        v.emplace_back(i);
        v.emplace_back(mn / i);
      } else v.emplace_back(i);
    }
  }
  sort(all(v));
  if (!v.empty()) {
    for (int i = 0; i < sz(v); i++) {
      bool ok = true;
      for (int j = 1; j <= n; j++) {
        if (a[j] % v[i] != 0) ok = false;
      }
      if (ok) return cout << v[i], 0;
    }
    return cout << -1, 0;
  } else for (int i = 1; i <= n; i++) if (a[i] % mn != 0) return cout << -1, 0;
  cout << mn;
  return 0;
}