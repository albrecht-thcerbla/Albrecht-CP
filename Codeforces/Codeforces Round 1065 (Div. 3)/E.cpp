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
    if (n <= 6) {
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << '\n';
    } else {
      vector<int> res = {5, 4, 1, 6, 3, 2};
      for (int i = 7; i <= n; i++) res.emplace_back(i);
      for (int i = 0; i < sz(res); i++) cout << res[i] << " ";
      cout << '\n';
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

