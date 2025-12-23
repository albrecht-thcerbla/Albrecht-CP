// https://codeforces.com/problemset/problem/1447/B
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
    int n, m; cin >> n >> m;
    int sum = 0, mn = 1e9, cnt_neg = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x; cin >> x;
        sum += abs(x);
        if (x < 0) ++cnt_neg;
        mn = min(mn, abs(x));
      }
    }
    if (cnt_neg & 1) cout << sum - 2 * mn << '\n';
    else cout << sum << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}