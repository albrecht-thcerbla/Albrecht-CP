#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[1000005];
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    ++cnt[a[i]];
    if (cnt[a[i]] > 1) return cout << "YES", 0;
  }
  for (int i = k + 1; i <= n; i++) {
    cnt[a[i - k]]--; cnt[a[i]]++;
    if (cnt[a[i]] > 1) return cout << "YES", 0;
  }
  cout << "NO";
  return 0;
}