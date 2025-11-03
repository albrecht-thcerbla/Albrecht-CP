#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int window = 0;
  for (int i = 1; i <= k; i++) window += a[i];
  int mx = -1, st, fn;
  for (int i = k + 1; i <= n; i++) {
    window += a[i] - a[i - k];
    if (window > mx) {
      mx = window;
      st = i - k + 1;
      fn = i;
    }
  }
  cout << mx << '\n';
  for (int i = st; i <= fn; i++) cout << a[i] << " ";
  return 0;
}