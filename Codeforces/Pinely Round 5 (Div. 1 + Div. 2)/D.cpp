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
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    int top1_val = 0, top2_val = 0;
    int top1_key = INT_MIN, top2_key = INT_MIN;
    for (int x : a) {
      int u = (top1_key == x - 1 ? top2_val : top1_val);
      int cur = 1 + u;
      if (mp.count(x)) cur = max(cur, mp[x] + 1);
      mp[x] = max(mp[x], cur);
      if (top1_key == x) {
        top1_val = mp[x];
      } else if (top2_key == x) {
        top2_val = mp[x];
        if (top2_val > top1_val) {
          swap(top1_val, top2_val);
          swap(top1_key, top2_key);
        }
      } else {
        if (mp[x] > top1_val) {
          top2_val = top1_val;
          top2_key = top1_key;
          top1_val = mp[x];
          top1_key = x;
        } else if (mp[x] > top2_val) {
          top2_val = mp[x];
          top2_key = x;
        }
      }
    }
    int best = 0;
    for (auto &p : mp) best = max(best, p.second);
    cout << n - best << "\n";
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}