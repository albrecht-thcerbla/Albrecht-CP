#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, m;
vector<int> a, r, t;
void build() {
  for (int i = 0; i < sz(a); i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void update(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}
int get(int x) {
  if (t[1] < x) return -1;
  int idx = 1;
  while (idx < n) {
    if (t[idx << 1] >= x) idx = idx << 1;
    else idx = idx << 1 | 1;
  }
  return idx - n;
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> m;
  a.resize(n); r.resize(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> r[i];
  n = 1 << (32 - __builtin_clz(n - 1));
  t.assign(n << 1, 0);
  build();
  for (int i = 0; i < m; i++) {
    int p = get(r[i]);
    if (p == -1) {
      cout << 0 << " ";
      continue;
    } 
    a[p] -= r[i];
    update(p, a[p]);
    cout << (p + 1) << " ";
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}