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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[n] == 0) {
      for (int i = 1; i <= n + 1; i++) {
        if (i > 1) cout << " ";
        cout << i;
      }
      cout << '\n';
      continue;
    }
    if (a[1] == 1)   {
      cout << n + 1 << " ";
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    int pos = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        pos = i;
        break;
      }
    }
    if (pos == -1) cout << -1 << '\n';
    else {
      for (int i = 1; i <= pos; i++) cout << i << " ";
      cout << n + 1;
      for (int i = pos + 1; i <= n; i++) cout << " " << i;
      cout << '\n';
    }
  }
  return 0;
}