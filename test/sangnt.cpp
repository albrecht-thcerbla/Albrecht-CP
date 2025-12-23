/// https://luyencode.net/problem/sangnt
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

bool p[1000001];

void eratosthenes() {
  for (int i = 0; i <= 1000000; i++) p[i] = true;
  p[0] = p[1] = false;
  for (int i = 2; i * i <= 1000001; i++) {
    if (p[i]) {
      for (int j = 2 * i; j <= 1000001; j += i) {
        p[j] = false;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  eratosthenes();
  for (int i = 1; i <= n; i++) if (p[i]) cout << i << " ";
  return 0;
}