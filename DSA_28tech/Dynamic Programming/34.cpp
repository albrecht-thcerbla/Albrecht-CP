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
  int n; cin >> n;
  vector<int> a(n + 1), inc(n + 1, 0), dec(n + 1, 0);
  int res = 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  inc[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) inc[i] = inc[i - 1] + 1;
    else inc[i] = 1;
    res = max(res, inc[i]);
  }
  dec[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] < a[i + 1]) dec[i] = dec[i + 1] + 1;
    else dec[i] = 1;
  }
  // delete
  for (int i = 2; i <= n - 1; i++) {
    if (a[i - 1] < a[i + 1]) res = max(res, inc[i - 1] + dec[i + 1]);
  }
  cout << res << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
