#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q, a[maxn], st[21][maxn];

int get(int l, int r) {
  int k = log2(r - l + 1);
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st[0][i] = a[i];
  }
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      st[l][i] = min(st[l - 1][i], st[l - 1][i + (1 << l - 1)]);
    }
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << get(l, r) << '\n';
  }
  return 0;
}