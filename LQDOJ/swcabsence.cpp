#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[100001];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    ++cnt[x];
  }
  for (int i = 1; i <= n; i++) if (!cnt[i]) cout << i << " ";
  return 0;
}