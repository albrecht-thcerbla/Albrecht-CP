#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct ft {
  int n;
  vector<long long> bit;
  explicit ft(int x) : n(x), bit(x + 1, 0) {};
  void update (int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
  }
  long long sum(int idx) {
    long long res = 0;
    for (; idx; idx -= idx & -idx) res += bit[idx];
    return res;
  }
  long long get(int u, int v) {
    return sum(v) - sum(u - 1); 
  }
};

vector<int> comp(vector<int> a) {
  vector<int> b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  for (auto &x : a) x = lower_bound(all(b), x) - b.begin() + 1;
  return a;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  ft tree(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  //a = comp(a);
  for (int i = 1; i <= n; i++) tree.update(i, a[i]);
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int p, x; cin >> p >> x;
      a[p] += x;
      tree.update(p, x);
    } else {
      int u, v; cin >> u >> v;
      cout << tree.get(u, v) << '\n';
    }
  }
  return 0;
}