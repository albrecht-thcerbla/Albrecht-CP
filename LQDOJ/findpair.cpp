#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto bs = [&](int x) -> int {
    int left = 1, right = n;
    while (right - left > 1) {
      int mid = (left + right) >> 1;
      if (a[mid] == x) return mid;
      else if (a[mid] < x) left = mid;
      else right = mid;      
    }
    return 0;
  };
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int val = x - a[i];
    if (bs(val)) {
      return cout << min(i, bs(val)) << " " << max(i, bs(val)), 0;
      v.emplace_back(i, bs(val));
    }
  }
  //for (int i = 0; i < sz(v); i++) cout << v[i].first << " " << v[i].second << '\n';
  cout << "No solution";
  return 0;
}