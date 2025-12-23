#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
/**
  Cho mang A co N phan tu va so nguyen duong K. Hay tim khoang cach lon nhat giua hai chi so i, j sao cho |A[i] - A[j]| = K.
**/
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  map<int, int> mp;
  int res = -1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (mp.count(a[i] - k)) res = max(res, i - mp[a[i] - k]);
    if (mp.count(a[i] + k)) res = max(res, i - mp[a[i] + k]);
    if (mp.count(a[i]) == 0) mp[a[i]] = i;
  }
  cout << res << '\n';
  return 0;
}