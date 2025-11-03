#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> lp(1000001, 0), pr;
  auto sieve = [&]() {
    for (int i = 2; i <= 1000000; i++) {
      if (!lp[i]) lp[i] = i, pr.emplace_back(i);
      for (int j = 0; i * pr[j] <= 1000000; j++) {
        lp[i * pr[j]] = pr[j];
        if (lp[i] == pr[j]) break;
      }
    }
  };
  sieve();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int64_t sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      if (sum >= 2 && lp[sum] == sum) cnt++;
    }
  }
  cout << cnt << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}