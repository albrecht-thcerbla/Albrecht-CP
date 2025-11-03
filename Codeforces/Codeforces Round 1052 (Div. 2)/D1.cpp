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
  int tt; cin >> tt;
  while (tt--) {
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    int R = n - 1;
    vector<int> ans(n, -1);
    for (int i = R; ~i; --i) {
      if (ans[i] != -1) continue;
      int k = 0;
      while ((1 << k) <= i) ++k;
      int mask = (1 << k) - 1;
      int j = mask ^ i;
      ans[i] = j;
      ans[j] = i;
    }
    int64_t sum = 0;
    for (int i = 0; i <= R; i++) {
      int a = ans[i] + l;
      int b = i + l;
      sum += (a | b);
    }
    cout << sum << '\n';
    for (int i = 0; i <= R; i++) cout << (ans[i] + l) << " ";
    cout << '\n';
  }
  return 0;
}