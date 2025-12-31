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
  string s; cin >> s;
  vector<int> a(26, 0);
  for (char c : s) a[c - 'A']++;
  for (int f : a) {
    if (f > (sz(s) + 1) / 2) return cout << -1 << '\n', 0;
  }
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < 26; i++) {
    if (a[i] > 0) pq.emplace(a[i], -int(i + 'A'));
  }
  string ans;
  while (sz(pq) > 1) {
    auto p1 = pq.top(); pq.pop();
    auto p2 = pq.top(); pq.pop();
    ans.push_back(-p1.second);
    ans.push_back(-p2.second);
    if (--p1.first > 0) pq.emplace(p1);
    if (--p2.first > 0) pq.emplace(p2);
  }
  if (sz(pq)) ans.push_back(-pq.top().second);
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

