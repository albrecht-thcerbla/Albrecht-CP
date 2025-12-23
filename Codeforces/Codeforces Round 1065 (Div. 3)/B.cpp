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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int64_t ans = 0;
    int l = (a[0] != -1), r = (a[n - 1] != -1);
    if (l && r) ans = abs(a[n - 1] - a[0]);
    if (!l && !r) a[0] = a[n - 1] = 0;
    else if (!l && r) a[0] = a[n - 1];
    else if (l && !r) a[n - 1] = a[0];
    for (int i = 1; i < n - 1; i++) if (a[i] == -1) a[i] = 0;
    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

