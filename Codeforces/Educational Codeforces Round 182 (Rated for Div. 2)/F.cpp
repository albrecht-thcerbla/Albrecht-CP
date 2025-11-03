#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int INF = 1e9;
int n, k;
vector<string> s;

void gen(int o, int c, string cur, vector<string>& res, int k) {
  if (sz(cur) == k) {
    if (o == k >> 1 && c == k >> 1) res.emplace_back(cur);
    return;
  }
  if (o < (k >> 1)) gen(o + 1, c, cur + "(", res, k);
  if (c < o) gen(o, c + 1, cur + ")", res, k);
}
int main() {
  
  cin >> n >> k;
  s.resize(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<string> all;
  gen(0, 0, "", all, k);
  int m = sz(all);
  vector<int> cover(m, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (all[i].find(s[j]) == string::npos) cover[i] |= (1 << j);
    }
  }
  for (int j = 0; j < n; j++) {
    bool ok = false;
    for (int i = 0; i < m; i++) {
      if (cover[i] & (1 << j)) ok = true;
    }
    if (!ok) return cout << -1 << '\n', 0;
  }
  int full = (1 << n) - 1;
  vector<int> dp(1 << n, INF), parent(1 << n, -1), choice(1 << n, -1);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (dp[mask] == INF) continue;
    for (int i = 0; i < m; i++) {
      int next = mask | cover[i];
      if (dp[next] > dp[mask] + 1) {
        dp[next] = dp[mask] + 1;
        parent[next] = mask;
        choice[next] = i;
      }
    }
  }
  cout << dp[full] << '\n';
  vector<int> pick;
  int cur = full;
  while (cur) {
    pick.emplace_back(choice[cur]);
    cur = parent[cur];
  }
  reverse(all(pick));
  int used = 0, done = 0;
  vector<int> as(n, -1);
  for (int idx = 0; idx < sz(pick); idx++) {
    int i = pick[idx];
    vector<int> elems;
    for (int j = 0; j < n; j++) {
      if (!(done & (1 << j)) && (cover[i] & (1 << j))) {
        elems.emplace_back(j);
        as[j] = idx;
        done |= (1 << j);
      }
    }
    cout << all[i] << '\n';
    cout << sz(elems) << '\n';
    for (int j = 0; j < sz(elems); j++) {
      cout << elems[j] + 1 << ((j + 1 == sz(elems)) ? '\n' : ' ');
    }
  }
  return 0;
}