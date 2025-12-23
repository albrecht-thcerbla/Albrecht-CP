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
  int h, m, a, b; cin >> h >> m >> a >> b;
  int d = b - a;
  int h2 = (h + d) % 24;
  if (h2 < 0) h2 += 24;
  cout << h2 << " " << m << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}