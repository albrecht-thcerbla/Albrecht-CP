#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 50005;

int n, m, p, diff[maxn], st[21][maxn];

int get(int l, int r) {
  int k = log2(r - l + 1);
  return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> m;
  while (m--) {
    int u, v, k; cin >> u >> v >> k;
    diff[u] += k; diff[v + 1] -= k;
  }
  for (int i = 1; i <= n; i++) {
    diff[i] += diff[i - 1];
    st[0][i] = diff[i];
  }
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      st[l][i] = max(st[l - 1][i], st[l - 1][i + (1 << l - 1)]);
    }
  }
  cin >> p;
  while (p--) {
    int u, v; cin >> u >> v;
    cout << get(u, v) << '\n';
  }
  return 0;
}