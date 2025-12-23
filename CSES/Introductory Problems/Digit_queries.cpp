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
  int q; cin >> q;
  while (q--) {
    int64_t k; cin >> k;
    int64_t d = 1, cnt = 9, st = 1;
    while (k > d * cnt) {
      k -= d * cnt;
      ++d;
      cnt *= 10;
      st *= 10;
    }
    int64_t idx = (k - 1) / d;
    int64_t pos = (k - 1) % d;
    int64_t num = st + idx;
    string s = to_string(num);
    cout << s[pos] << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
