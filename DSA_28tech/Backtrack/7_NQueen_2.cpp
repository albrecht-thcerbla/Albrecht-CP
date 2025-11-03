#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n = 8, col[10], dia1[10], dia2[10], ans = -1, a[10][10], x[10];

void backtrack(int i) {
  for (int j = 1; j <= n; j++) {
    if (!col[j] && !dia1[i - j + n] && !dia2[i + j - 1]) {
      x[i] = j;
      col[j] = dia1[i - j + n] = dia2[i + j - 1] = 1;
      if (i == n) {
        int sum = 0;
        for (int k = 1; k <= n; k++) sum += a[k][x[k]];
        ans = max(ans, sum);
      } else backtrack(i + 1);
      col[j] = dia1[i - j + n] = dia2[i + j - 1] = 0;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> a[i][j];
    }
  }
  backtrack(1);
  cout << ans << '\n';
  return 0;
}