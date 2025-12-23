include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, s;
int a[22], x[22];
vector<vector<int>> v;

void backtrack(int i, int st, int sum) {
  for (int j = st; j <= n; j++) {
    if (a[j] + sum <= s) {
      x[i] = a[j];
      if (a[j] + sum == s) {
        vector<int> tmp(x + 1, x + i + 1);
        v.emplace_back(tmp);
      }
      else backtrack(i + 1, j, sum + a[j]);
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  backtrack(1, 1, 0);
  if (!sz(v)) cout << 0 << '\n';
  else {
    cout << sz(v) << '\n';
    for (int i = 0; i < sz(v); i++) {
      for (int j = 0; j < sz(v[i]); j++) {
        cout << v[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}