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
  int n, m; cin >> n >> m;
  int mul = n * m;
  int cnt = mul / 10;
  int ans = 0;
  while (mul) {
    if (mul % cnt == 0) {
      ans += mul / cnt;
      mul -= (mul / cnt);
    }
    else --cnt;
  }
  cout << ans;
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}