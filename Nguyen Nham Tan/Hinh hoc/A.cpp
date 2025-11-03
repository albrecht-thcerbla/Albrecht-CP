#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

// Cho n duong thang tren mp truc Oxy, dem so cap duong thang cat nhau

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    int a, b, c; cin >> a >> b >> c;
    int g = gcd(a, b);
    if (g) {
      a /= g;
      b /= g;
    }
    if (b < 0 || (b == 0 && a < 0)) {
      a = -a;
      b = -b;
    }
    mp[{a, b}]++;
  }
  int sum = n * (n - 1) >> 1;
  for (auto k : mp) {
    sum -= k.second * (k.second - 1) >> 1;
  }
  cout << sum << '\n';
  return 0;
}