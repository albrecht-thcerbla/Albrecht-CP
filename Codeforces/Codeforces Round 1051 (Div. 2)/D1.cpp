#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, M = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], M = max(M, a[i]);
    int S = M;
    vector<vector<int64_t>> cur(S + 1, vector<int64_t>(S + 1, 0));
    cur[0][0] = 1; // day rong
    for (int i = 0; i < n; i++) {
      int v = a[i];
      vector<vector<int64_t>> nxt = cur;
      for (int l1 = 0; l1 <= S; l1++) {
        for (int l2 = 0; l2 <= S; l2++) {
          int64_t ways = cur[l1][l2];
          if (!ways) continue;
          if (v >= l1) (nxt[v][l2] += ways) %= mod;
          else if (v >= l2) (nxt[l1][v] += ways) %= mod;
        }
      }
      swap(cur, nxt);
    }
    int64_t ans = 0;
    for (int l1 = 0; l1 <= S; l1++) {
      for (int l2 = 0; l2 <= S; l2++) {
        (ans += cur[l1][l2]) %= mod;
      }
    }
    cout << (ans % mod) << '\n';
  }
  return 0;
}