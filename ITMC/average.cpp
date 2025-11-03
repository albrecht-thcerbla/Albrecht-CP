#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, a; cin >> n >> a;
    vector<int> x(n);
    vector<int> dp1(80001, 0);
    for (int i = 0; i < n; i++) cin >> x[i];
    dp1[40000] = 1;
    for (int i = 0; i < n; i++) {
      int tmp = x[i] - a;
      vector<int> dp2 = dp1;
      for (int s = 0; s <= 80000; s++) {
        if (s + tmp >= 0 && s + tmp <= 80000) {
          (dp2[s + tmp] += dp1[s]) %= mod;
        }
      }
      dp1.swap(dp2);
    }
    cout << (dp1[40000] - 1 + mod) % mod << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}