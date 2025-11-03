#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

const int cmax = 10000009;
const int nmax = 10000009;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int pr[nmax + 1], ans[cmax + 1];
  for (int i = 0; i <= cmax; i++) ans[i] = -1;
  for (int i = 1; i <= nmax; i++) {
    for (int j = i; j <= nmax; j += i) pr[j] += i;
  }
  for (int i = 1; i <= nmax; i++) if (pr[i] <= cmax && ans[pr[i]] == -1) ans[pr[i]] = i;
  int q; cin >> q;
  while (q--) {
    int c; cin >> c;
    if (c <= cmax) cout << ans[c] << '\n';
    else cout << -1 << '\n';    
  }
  return 0;
}