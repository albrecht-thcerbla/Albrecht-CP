#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int g = gcd(n, m);
    vector<vector<int>> posa(g), posb(g);
    for (int i = 0; i < n; i++) posa[i % g].emplace_back(i);
    for (int i = 0; i < m; i++) posb[i % g].emplace_back(i);
    for (int i = 0; i < g; i++) {
      int na = sz(posa[i]);
      int nb = sz(posb[i]);
      if (na + nb == 0) continue;
      vector<int> basea(na), baseb(nb);
      for (int j = 0; j < na; j++) basea[j] = (posa[i][j] - i) / g;
      for (int j = 0; j < nb; j++) baseb[j] = (posb[i][j] - i) / g;
      int sta = n / g;
      int stb = m / g;
      vector<pair<int, int>> seq;
      int ia = 0, ib = 0;
      int cura = (ia < na ? basea[ia] : 1e18);
      int curb = (ib < nb ? baseb[ib] : 1e18);
      ia = 0, ib = 0;
      while (ia < na || ib < nb) {
        if (ib == nb) {
          seq.emplace_back('A', posa[i][ia++]);
        } else if (ia == na) {
          seq.emplace_back('B', posb[i][ib++]);
        } else {
          long double left = (long double)basea[ia] * (long double)stb, right = (long double)baseb[ib] * (long double)sta;
          if (left <= right) {
            seq.emplace_back('A', posa[i][ia++]);
          } else seq.emplace_back('B', posb[i][ib++]);
        }
      }
      int kr = 0;
      if (k > i) kr = ((k - i - 1) / g) + 1;
      int L = sz(seq);
      int tmp;
      if (kr <= L) tmp = kr;
      else {
        int rem = (kr - L) % L;
        tmp = L + rem;
      }
      for (int j = 0; j < tmp; j++) {
        int idx = (j % L);
        auto pr = seq[idx];
        if (pr.first == 'A') int ai_idx = pr.second;
      }
      for (int j = 0; j < tmp; j++) {
        int i_g = i + g * j;
        int ia_idx = i_g % n;
        int ib_idx = i_g % m;
        if (a[ia_idx] > b[ib_idx]) swap(a[ia_idx], b[ib_idx]);
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
    for (int i = 0; i < m; i++) cout << b[i] << " ";
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}