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
  mp[0] = 0;
  long long sum = 0;
  int left = 0, right = 0;
  int res = -1;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (mp.count(sum)) {
      if (i - mp[sum] > res) {
        res = i - mp[sum];
        left = mp[sum];
        right = i;
      }
    }
    if (!mp.count(sum)) mp[sum] = i;
  }
  if (res != -1) for (int i = left + 1; i <= right; i++) cout << a[i] << " ";
  else cout << "NOT FOUND";
  return 0;
}