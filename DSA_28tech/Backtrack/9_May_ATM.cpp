#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, s;
int x[33], a[33];
int res = 1e9;

void backtrack(int i, int st, int sum) {
  for (int j = st; j <= n; j++) {
    x[i] = a[j];
    if (sum + a[j] == s) {
      res = min(res, i);
    }
    else if (sum + a[j] < s) backtrack(i + 1, j + 1, sum + a[j]);
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  backtrack(1, 1, 0);
  cout << res << '\n';
  return 0;
}