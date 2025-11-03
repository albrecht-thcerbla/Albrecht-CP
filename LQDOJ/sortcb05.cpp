#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1, [](pair<int, int> a, pair<int, int> b) {
    return (a > b);
  });
  cout << a[m].first << " " << a[m].second;
  return 0;
}