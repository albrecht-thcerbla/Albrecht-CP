#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  map<long long, int> mp;
  mp[0] = 1;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (mp[sum]) return cout << 1, 0;
    mp[sum] = 1;
  }
  cout << 0;
  return 0;
}