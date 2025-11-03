/// https://www.spoj.com/problems/MATSUM/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1025;

int n;
int64_t bit[maxn][maxn], a[maxn][maxn];

void update(int x, int y, int64_t val) {
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= n; j += j & -j) {
      bit[i][j] += val;
    }
  } 
}
int64_t get(int x, int y) {
  int64_t res = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      res += bit[i][j];
    }
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    cin >> n;
    memset(bit, 0, sizeof(bit));
    memset(a, 0, sizeof(a));
    string s;
    while (cin >> s) {
      if (s == "END") break;
      else if (s == "SET") {
        int x, y; cin >> x >> y;
        x++; y++;
        int64_t val; cin >> val;
        int64_t diff = val - a[x][y];
        a[x][y] = val;
        update(x, y, diff);
      } else {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; x2++; y1++; y2++;
        cout << get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1) << '\n';
      }
    }    
  }
  return 0;
}