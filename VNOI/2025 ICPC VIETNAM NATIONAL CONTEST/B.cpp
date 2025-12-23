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
    int64_t mx = 0;
    map<int64_t, vector<int64_t>> mp;
    for (int i = 0; i < n; i++) {
      int64_t t, v; cin >> t >> v;
      mp[t - 1].emplace_back(v);
      mx = max(mx, t - 1);
    }
    if (mx < 0) {
      cout << 0 << '\n';
      continue;
    }
    vector<int64_t> times;
    for (map<int64_t, vector<int64_t>>::iterator it = mp.begin(); it != mp.end(); it++) times.emplace_back(it->first);
    sort(all(times), greater<int64_t>());
    priority_queue<int64_t> pq;
    int64_t cur = mx + 1;
    for (int i = 0; i < sz(times); i++) {
      int64_t delta = cur - (times[i] + 1);
      if (delta > 0 && sz(pq)) {
        int64_t top = pq.top(); pq.pop();
        top += delta;
        pq.emplace(top);
      }
      for (int j = 0; j < sz(mp[times[i]]); j++) pq.emplace(mp[times[i]][j]);
      cur = times[i] + 1;
    }
    // last
    int64_t last_delta = cur;
    if (last_delta > 0 && sz(pq)) {
      int64_t top = pq.top(); pq.pop();
      top += last_delta;
      pq.emplace(top);
    }
    int64_t sum = 0;
    while (sz(pq)) {
      int64_t top = pq.top(); pq.pop();
      sum += top * top;
    }
    cout << sum << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

