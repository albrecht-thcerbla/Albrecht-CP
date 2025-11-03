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
    int n; cin >> n;
    vector<int> a(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = (pref[i - 1] + a[i]) % 3;
    }
    bool ok = false;
    for (int l = 1; l < n && !ok; l++) {
      for (int r = l + 1; r < n && !ok; r++) {
        int s1 = pref[l];
        int s2 = (pref[r] - pref[l] + 3) % 3;
        int s3 = (pref[n] - pref[r] + 3) % 3;
        if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s3 != s1)) {
          cout << l << " " << r << '\n';
          ok = true;
        }
      }
    }
    if (!ok) cout << "0 0" << '\n';
  }
  return 0;
}