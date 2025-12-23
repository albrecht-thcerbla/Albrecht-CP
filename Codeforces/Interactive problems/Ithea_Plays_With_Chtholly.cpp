#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, m, c; cin >> n >> m >> c;
  vector<int> a(n + 1, 0);
  while (m--) {
    int x; cin >> x;
    int i;
    if (x > c / 2) for (i = n; a[i] >= x; i--);
    else for (i = 1; a[i] && a[i] <= x; i++);
    cout << i << '\n';
    cout.flush();
    a[i] = x;
    for (i = 1; i <= n && a[i]; i++);
    if (i > n) break;
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

