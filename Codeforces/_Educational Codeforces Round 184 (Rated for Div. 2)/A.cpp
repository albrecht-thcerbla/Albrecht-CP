#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int64_t BMIN = 0;
const int64_t BMAX = 2000000000LL;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; int64_t a; cin >> n >> a;
    vector<int64_t> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<int64_t, int>> ev;
    for (int i = 0; i < n; i++) {
      int64_t d = llabs(v[i] - a);
      if (d == 0) continue;
      int64_t l = v[i] - (d - 1);
      int64_t r = v[i] + (d - 1);
      if (r < BMIN || l > BMAX) continue;
      l = max(l, BMIN);
      r = min(r, BMAX);
      ev.emplace_back(l, +1);
      if (r + 1 <= BMAX + 1) ev.emplace_back(r + 1, -1);
    }
    if (ev.empty()) {
      cout << 0 << '\n';
      continue;
    }
    sort(all(ev));
    int64_t cur = 0;
    int64_t bestCnt = -1;
    int64_t bestL = -1, bestR = -1;
    int64_t bestLen = 0;
    int idx = 0;
    while (idx < sz(ev)) {
      int64_t pos = ev[idx].first;
      int delta = 0;
      while (idx < sz(ev) && ev[idx].first == pos) {
        delta += ev[idx].second;
        ++idx;
      }
      cur += delta;
      int64_t nxtpos = (idx < ev.size() ? ev[idx].first : (BMAX + 1));
      int64_t segL = pos;
      int64_t segR = nxtpos - 1;
      if (segL > segR) continue;
      if (segL < BMIN) segL = BMIN;
      if (segR > BMAX) segR = BMAX;
      int64_t segLen = segR - segL + 1;
      if (segLen <= 0) continue;
      if (cur > bestCnt || (cur == bestCnt && segLen > bestLen)) {
        bestCnt = cur;
        bestL = segL;
        bestR = segR;
        bestLen = segLen;
      }
    }
    if (bestCnt <= 0) {
      cout << 0 << '\n'; 
    } else {
      int64_t ans = (bestL + bestR) / 2;
      cout << ans << '\n';
    }
  }
  return 0;
}