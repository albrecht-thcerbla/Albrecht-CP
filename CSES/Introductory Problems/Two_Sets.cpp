#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int64_t sum = 1LL * n * (n + 1) / 2;
  if (sum & 1) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  sum /= 2;
  vector<int64_t> s1, s2;
  for (int64_t i = n; i >= 1; i--) {
    if (sum >= i) s1.emplace_back(i), sum -= i;
    else s2.emplace_back(i);
  }
  cout << sz(s1) << '\n';
  for (int i = 0; i < sz(s1); i++) cout << s1[i] << " ";
  cout << '\n' << sz(s2) << '\n';
  for (int i = 0; i < sz(s2); i++) cout << s2[i] << " ";
  return 0;
}