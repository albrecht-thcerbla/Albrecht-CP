#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n, [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  int carry = a[0].second, cnt = 1;

  for (int i = 0; i < n; i++) {
    if (a[i].first > carry) {
      cnt++;
      carry = a[i].second; 
    }
  }
  cout << cnt << '\n';
  return 0;
}