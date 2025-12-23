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
    int n, a, b; cin >> n >> a >> b;
    bool ok = true;
    if (a + b > n) ok = false;
    if (min(a, b) == 0 && max(a, b) != 0) ok = false;
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << '\n';
    vector<int> B(n + 1);
    for (int i = 1; i <= a + b; i++) B[i] = ((i + a - 1) % (a + b)) + 1;
    for (int i = a + b + 1; i <= n; i++) B[i] = i;
    for (int i = 1; i <= n; i++) cout << B[i] << " ";
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
