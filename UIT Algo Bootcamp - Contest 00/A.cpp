#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int64_t n, m; cin >> n >> m;
  vector<int64_t> a, divi = {2, 2, 2, 3, 5};
  for (int i = 0; i <= 4; i++) a.emplace_back(n + i);
  for (int x : divi) {
    for (int i = 0; i <= 4; i++) {
      if (a[i] % x == 0) {
        a[i] /= x;
        break;
      } 
    }
  }
  int64_t res = 1;
  for (int i = 0; i <= 4; i++) res = res * (a[i] % m) % m;
  cout << res;
  return 0;
}