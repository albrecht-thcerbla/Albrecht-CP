#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, c[101][101], x[101], ans = 1e9, vis[101];
int cmin = 1e9;

void backtrack(int i, int dist) {
  for (int j = 1; j <= n; j++) {
    if (!vis[j]) {
      x[i] = j;
      vis[j] = 1;
      dist += c[x[i - 1]][x[i]];
      if (i == n) {
        dist += c[x[n]][1];
        ans = min(ans, dist);                
      }
      else if (dist + (n - i + 1) * cmin < ans) backtrack(i + 1, dist);
      vis[j] = 0;
      dist -= c[x[i - 1]][x[i]];
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
      if (c[i][j]) cmin = min(cmin, c[i][j]);
    }
  }
  x[1] = 1;
  vis[1] = 1;
  backtrack(2, 0);
  cout << ans << '\n';
  return 0;
}