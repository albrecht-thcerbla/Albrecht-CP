#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[100005];
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ++cnt[x];
  }
  for (int i = 1; i <= 100000; i++) if (cnt[i]) res += (cnt[i] * (cnt[i] - 1) >> 1);
  cout << res;
  return 0;
}