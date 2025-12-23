#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int cnt = 2;   
    if (a[i] == 1) {
      cout << 1 << '\n';
      continue;
    }
    for (int j = 2; j <= sqrt(a[i]); j++) {
      if (a[i] % j == 0) {
        if (a[i] / j != j) cnt += 2;
        else cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}