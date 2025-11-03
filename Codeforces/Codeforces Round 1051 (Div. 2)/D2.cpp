#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 7;

struct BIT {
  int n;
  vector<int64_t> bit;
  BIT() {}
  BIT(int n_) {
    init(n_);
  }
  void init(int n_) {
    n = n_;
    bit.assign(n + 1, 0);
  }
  void add(int idx, int64_t val) {
    while (idx <= n) {
      bit[idx] += val;
      if (bit[idx] >= MOD) bit[idx] -= MOD;
      idx += idx & -idx;
    }
  }
  int64_t sum(int idx) {
    int64_t s = 0;
    while (idx > 0) {
      s += bit[idx];
      if (s >= MOD) s -= MOD;
      idx -= idx & -idx;
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 2;
    }
    int M = (int)vals.size() + 1;
    vector<BIT> BIT_col(M + 1), BIT_row(M + 1);
    for (int i = 1; i <= M; i++) {
      BIT_col[i].init(M);
      BIT_row[i].init(M);
    }
    // dp[sentinel][sentinel] = 1
    BIT_col[1].add(1, 1);
    BIT_row[1].add(1, 1);
    int64_t ans = 1;
    for (int v : a) {
      vector<int64_t> colsum(M + 1);
      for (int j = 1; j <= M; j++) {
        colsum[j] = BIT_col[j].sum(v);
      }
      vector<int64_t> rowsum(M + 1);
      for (int i = v + 1; i <= M; i++) {
        rowsum[i] = BIT_row[i].sum(v);
      }
      for (int j = 1; j <= M; j++) if (colsum[j]) {
        BIT_col[j].add(v, colsum[j]);
        BIT_row[v].add(j, colsum[j]);
        ans += colsum[j];
        if (ans >= MOD) ans -= MOD;
      }
      for (int i = v + 1; i <= M; i++) if (rowsum[i]) {
        BIT_col[v].add(i, rowsum[i]);
        BIT_row[i].add(v, rowsum[i]);
        ans += rowsum[i];
        if (ans >= MOD) ans -= MOD;
      }
    }
    cout << ans % MOD << "\n";
  }
  return 0;
}
