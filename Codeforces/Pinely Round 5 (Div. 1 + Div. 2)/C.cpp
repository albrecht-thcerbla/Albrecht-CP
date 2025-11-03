#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int get(int s, int x) {
  return (s % x == 0 ? x : (x - (s % x)));
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, x; cin >> n >> x;
    vector<int> a(n), od, od2;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> s, l;
    for (int i = 0; i < n; i++) {
      if (a[i] >= x) l.emplace_back(a[i]);
      else s.emplace_back(a[i]);
    }
    sort(all(s));
    sort(all(l), greater<int>());
    int S = 0, bonus = 0;
    for (int i = 0; i < sz(s); i++) {
      int Prev = S / x;
      S += s[i];
      int New = S / x;
      if (New > Prev) bonus += s[i];
      od.emplace_back(s[i]);
    }
    int S2 = 0, bonus2 = 0;
    for (int i = 0; i < sz(l); i++) {
      int Prev = S2 / x;
      S2 += l[i];
      int New = S2 / x;
      if (New > Prev) bonus2 += l[i];
      od2.emplace_back(l[i]);
    }
    for (int i = 0; i < sz(s); i++) {
      int Prev = S2 / x;
      S2 += s[i];
      int New = S2 / x;
      if (New > Prev) bonus2 += s[i];
      od2.emplace_back(s[i]);
    }
    if (bonus2 > bonus) {
      cout << bonus2 << '\n';
      for (int i = 0; i < sz(od2); i++) cout << od2[i] << " ";
    } else {
      cout << bonus << '\n';
      for (int i = 0; i < sz(od); i++) cout << od[i] << " ";
    }
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}