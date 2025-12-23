// https://codeforces.com/problemset/problem/1450/B
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    bool ok = false;
    for (int i = 0; i < n; i++) {
      bool check = true;
      for (int j = 0; j < n; j++) {
        int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        if (dist > k) {
          check = false;
          break;
        }
      }
      if (check) {
        ok = true;
        break;
      }
    }
    cout << (ok ? 1 : -1) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}