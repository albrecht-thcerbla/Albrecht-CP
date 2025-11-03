#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[101];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ++cnt[x];
  }
  int res = 0;
  for (int i = 1; i <= 100; i++) {
    res += (cnt[i] / 2);
  }
  cout << res;
  return 0;
}