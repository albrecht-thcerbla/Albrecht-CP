/// https://luyencode.net/problem/vt09
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

bool check(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  int a[n];
  bool p[1001] = {0};
  set<int> se;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (check(a[i])) p[a[i]] = 1; 
  }
  for (int i = 0; i <= 1000; i++) if (p[i]) cout << i << " ";
  return 0;
}