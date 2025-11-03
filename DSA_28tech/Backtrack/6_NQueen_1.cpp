#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, x[101], col[101], dia1[101], dia2[101], ans;

void backtrack(int i) {
  for (int j = 1; j <= n; j++) {
    if (!col[j] && !dia1[i - j + n] && !dia2[i + j - 1]) {
      x[i] = j;
      col[j] = dia1[i - j + n] = dia2[i + j - 1] = 1;
      if (i == n) {
        ++ans;
        for (int i = 1; i <= n; i++) {
          cout << "Con hau hang " << i << " cot " << x[i] << '\n';
        }
        cout << '\n';
      }
      else backtrack(i + 1);
      col[j] = dia1[i - j + n] = dia2[i + j - 1] = 0;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  backtrack(1);
  cout << ans << '\n';
  return 0;
}