#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct Node {
  int t, o, c;
  explicit Node(): t(0), o(0), c(0) {}
};
Node merge(Node& a, Node& b) {
  Node res;
  int tmp = min(a.o, b.c);
  res.t = a.t + b.t + 2 * tmp;
  res.o = a.o + b.o - tmp;
  res.c = a.c + b.c - tmp;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string s; cin >> s;
  int n = sz(s);
  vector<Node> t(n << 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') t[i + n].o = 1;
    else t[i + n].c = 1;
  }
  for (int i = n - 1; i > 0; --i) t[i] = merge(t[i << 1], t[i << 1 | 1]);
  int m; cin >> m;
  while (m--) {
    int l, r; cin >> l >> r;
    --l;
    Node resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = merge(resl, t[l++]);
      if (r & 1) resr = merge(t[--r], resr);
    }
    Node res = merge(resl, resr);
    cout << res.t << '\n';
  }
  return 0;
}