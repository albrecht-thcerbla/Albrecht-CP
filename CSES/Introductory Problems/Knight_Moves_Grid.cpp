#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n; cin >> n;
  vector<vector<int>> d(n, vector<int>(n, -1));
  queue<pair<int, int>> q;
  d[0][0] = 0;
  q.emplace(0, 0);
  while (sz(q)) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 8; i++) {
      int ix = x + dx[i];
      int iy = y + dy[i];
      if (ix >= 0 && ix < n && iy >= 0 && iy < n && d[ix][iy] == -1) {
        d[ix][iy] = d[x][y] + 1;
        q.emplace(ix, iy);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << d[i][j] << " ";
    }
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
