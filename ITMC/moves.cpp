#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int q; cin >> q;
  while (q--) {
    int n, d; cin >> n >> d;
    int64_t sum = 0, res = ((n + 1) >> 1) * d;;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      sum += x;
    }
    cout << (sum <= res ? "YES" : "NO") << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}