#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**

4
1 2 2 1

**/

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1), pref(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i - 1] + a[i];
  int s1 = 0, s2 = 0, cnt = 0;
  for (int i = 1; i < n; i++) {
    s1 = pref[i];
    s2 = pref[n] - pref[i];
    if (s1 == s2) ++cnt;    
  }
  cout << cnt << '\n';
  return 0;
}