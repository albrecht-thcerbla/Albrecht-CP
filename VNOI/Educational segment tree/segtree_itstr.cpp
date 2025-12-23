#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int MOD = 1007050321;
const int maxn = 1e5 + 7;

int n, q;
string s;
int pow2[maxn];
struct Node {
  int val = 0, len = 0;
};
Node t[maxn << 1];
void build() {
  for (int i = 0; i < n; i++) {
    t[i + n].val = s[i] ^ '0';
    t[i + n].len = 1;
  }
  for (int i = n - 1; i > 0; i--) {
    Node left = t[i << 1], right = t[i << 1 | 1];
    t[i].val = (1LL * left.val * pow2[right.len] + right.val) % MOD;
    t[i].len = left.len + right.len;
  }
}
void update(int p) {
  p += n - 1;
  t[p].val = t[p].len = 0;
  for (p >>= 1; p > 0; p >>= 1) {
    Node left = t[p << 1], right = t[p << 1 | 1];
    t[p].val = (1LL * left.val * pow2[right.len] + right.val) % MOD;
    t[p].len = left.len + right.len;
  }
}
pair<int, int> get(int l, int r) {
  l += n - 1; r += n - 1;
  int res_val = 0, res_len = 0;
  vector<pair<int, int>> rp;
  while (l <= r) {
    if (l % 2 == 1) {
      res_val = (1LL * res_val * pow2[t[l].len] + t[l].val) % MOD;
      res_len += t[l].len;
      l++;
    }
    if (r % 2 == 0) {
      rp.push_back({t[r].val, t[r].len});
      r--;
    }
    l >>= 1; r >>= 1;
  }
  reverse(all(rp));
  for (auto [v, len] : rp) {
    res_val = (1LL * res_val * pow2[len] + v) % MOD;
    res_len += len;
  }
  return {res_val, res_len};
}

int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  n = sz(s);
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) pow2[i] = (2LL * pow2[i - 1]) % MOD;
  build();
  cin >> q;
  vector<int> pos;
  for (int i = 1; i <= n; i++) pos.emplace_back(i);
  while (q--) {
    string ty; cin >> ty;
    if (ty == "-") {
      int p; cin >> p;
      --p;
      int real_pos = pos[p];
      update(real_pos);
      pos.erase(pos.begin() + p);
    } else {
      int l, r; cin >> l >> r;
      --l; --r;
      int pl = pos[l], pr = pos[r];
      cout << get(pl, pr).first << '\n';
    }
  }
  return 0;
}