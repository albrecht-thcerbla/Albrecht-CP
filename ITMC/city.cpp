#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

struct Area { 
  int a, b, c;
};
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int x, y, z; cin >> x >> y >> z;
  int n = x + y + z;
  vector<Area> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b >> v[i].c;
  sort(all(v), [](auto& u, auto& v) {
    return (u.a - u.c) > (v.a - v.c);
  });
  priority_queue<int> pq1, pq2;
  vector<int> pref(n), suff(n);
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    pq1.emplace(-(v[i].a - v[i].b));
    s1 += (v[i].a - v[i].b);
    if (sz(pq1) > x) {
      s1 -= -pq1.top(); pq1.pop();
    }
    pref[i] = (sz(pq1) == x ? s1 : -1e18);
  } 
  for (int i = n - 1; ~i; --i) {
    pq2.emplace(-(v[i].c - v[i].b));
    s2 += (v[i].c - v[i].b);
    if (sz(pq2) > z) {
      s2 -= -pq2.top(); pq2.pop();
    }    
    suff[i] = (sz(pq2) == z ? s2 : -1e18);
  }
  int sumb = 0;
  for (int i = 0; i < n; i++) sumb += v[i].b;
  int ans = -1e18;
  for (int i = x - 1; i < n - z; i++) {
    if (pref[i] != -1e18 && suff[i + 1] != -1e18) ans = max(ans, sumb + pref[i] + suff[i + 1]);
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}