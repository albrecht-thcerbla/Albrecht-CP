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
  long long sum = 0;
  int l = 1, res = 1e9;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum >= k) { // ok
      while (sum - a[l] >= k) {
        sum -= a[l++];
      } 
      res = min(res, i - l + 1);
    }
  }
  cout << res << '\n';
  return 0;
}