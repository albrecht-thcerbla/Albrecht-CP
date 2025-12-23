#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int calc(int l, int r) {
  if (l >= r) return -1;
  cout << "? " << l + 1 << " " << r + 1 << '\n';
  cout.flush();
  int x; cin >> x;
  return x - 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n; cin >> n;
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    int s = calc(l, r - 1);
    if (s < m) {
      if (calc(l, m - 1) == s) r = m;
      else l = m;
    } else {
      if (calc(m, r - 1) == s) l = m;
      else r = m;
    }
  }
  cout << "! " << l + 1 << '\n';
  cout.flush();
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

