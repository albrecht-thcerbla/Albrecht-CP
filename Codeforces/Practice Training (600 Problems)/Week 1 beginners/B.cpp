// https://codeforces.com/problemset/problem/1469/B
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
    int n; cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    int prefR = 0, sumR = 0;
    for (int i = 0; i < n; i++) {
      sumR += r[i];
      prefR = max(prefR, sumR);
    }
    int prefB = 0, sumB = 0;
    for (int i = 0; i < m; i++) {
      sumB += b[i];
      prefB = max(prefB, sumB);
    }
    cout << prefR + prefB << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}