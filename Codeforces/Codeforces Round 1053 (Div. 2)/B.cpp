#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<int> se;
    for (int i = 0; i < m; i++) {
      int x; cin >> x;
      se.insert(x);
    }
    int pos = 1;
    for (char c : s) {
      if (c == 'A') ++pos;
      else {
        auto it = se.upper_bound(pos);
        if (it == se.end()) pos = 1000000000LL;
        else pos = *it - 1;
      }
      se.insert(pos);
    }
    cout << sz(se) << '\n';
    for (set<int>::iterator it = se.begin(); it != se.end(); it++) cout << *it << " ";
    cout << '\n';
  }
  return 0;
}