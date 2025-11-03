#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

/**
  Cho mang A co N phan tu va so nguyen K, nhiem vu cua ban la tim mang con lien tiep ngan nhat co tong cac phan tu bang K.
  input: 
  6 4
  1 1 1 3 2 4
  output:
  1
**/

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  map<long long, int> mp;
  mp[0] = 0;
  long long sum = 0;
  int minans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (mp.count(sum - k)) minans = min(minans, i - mp[sum - k]);
    mp[sum] = i;
  }
  cout << minans << '\n';
  return 0;
}