#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct Node {
  int64_t sum, pref, suff, ans;
};
int n, m, h = 1;
int64_t a[maxn];
Node t[maxn << 1];

Node calc(Node l, Node r) {
  Node res;
  res.sum = l.sum + r.sum;
  res.pref = max(l.pref, l.sum + r.pref);
  res.suff = max(r.suff, r.sum + l.suff);
  res.ans = max({l.ans, r.ans, l.suff + r.pref});
  return res;
}



void build() {
  for (int i = 0; i < n; i++) t[i + h] = {a[i], a[i], a[i], a[i]};
  for (int i = h - 1; i > 0; i--) t[i] = calc(t[i << 1], t[i << 1 | 1]);
}
     

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  h = (1 << __log(n));   
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  cout << t[1].ans << '\n';
  while (m--) {
    int p; cin >> p;
    int64_t val; cin >> val;
    update(p, val);
    cout << t[1].ans << '\n';
  }
  return 0;
}