#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k; cin >> n >> m >> k;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int res = i * j;
      a.emplace_back(res);
    }
  }
  sort(all(a));
  for (int i = 0; i < sz(a); i++) cout << a[i] << " ";

  return 0;
}