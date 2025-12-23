#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[p[i]] = i;
    int l = pos[n], r = pos[n];
    bool ok = true;
    for (int val = n; val >= 1; val--) {
      l = min(l, pos[val]);
      r = max(r, pos[val]);
      int need = n - val + 1;
      if (r - l + 1 != need) {
        ok = false;
        break;
      }
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}