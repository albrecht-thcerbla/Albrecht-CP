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
  sort(all(a), greater<int>());
  long long ans = 0;
  for (int i = 0; i < n; i += 3) ans += a[i] + a[i + 1];
  cout << ans;
  return 0;
}