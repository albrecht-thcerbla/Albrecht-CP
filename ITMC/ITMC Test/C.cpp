#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  array<int, 2> x[3];
  for (int i = 0; i < 3; i++) cin >> x[i][0] >> x[i][1];
  for (int i = 0; i < 100; i++) {
    int fi = i % 3;
    int se = (i + 1) % 3;
    int res = min(x[fi][1], x[se][0] - x[se][1]);
    x[fi][1] -= res;
    x[se][1] += res;
  }
  for (int i = 0; i < 3; i++) cout << x[i][1] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}