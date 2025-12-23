#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

struct Node {
  int64_t sum, pref, suff, best;
};
Node make_node(int64_t x) {
  Node res;
  res.sum = x;
  res.pref = res.suff = res.best = max(int64_t(0), x);
  return res;
}
Node calc(Node& l, Node& r) {
  Node res;
  res.sum = l.sum + r.sum;
  res.pref = max(l.pref, l.sum + r.pref);
  res.suff = max(r.suff, r.sum + l.suff);
  res.best = max({l.best, r.best, l.suff + r.pref});
  return res;
}
struct SegmentTree {
  int n;
  int N;
  vector<Node> t;
  explicit SegmentTree(int n) : n(n) {
    N = 1 << (32 - __builtin_clz(n - 1));
    t.assign(N << 1, make_node(0));
  }
  void build(vector<int64_t>& a) {
    for (int i = 0; i < n; i++) t[i + N] = make_node(a[i]);
    for (int i = N - 1; i; i--) t[i] = calc(t[i << 1], t[i << 1 | 1]);
  }
  void update(int p, int64_t val) {
    for (t[p += N] = make_node(val); p > 1; p >>= 1) t[p >> 1] = calc(t[p >> 1 << 1], t[p >> 1 << 1 | 1]);
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, q; cin >> n >> q;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  SegmentTree st(n);
  st.build(a);
  cout << st.t[1].best << '\n';
  while (q--) {
    int x; cin >> x;
    int64_t val; cin >> val;
    st.update(x, val);
    cout << st.t[1].best << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

