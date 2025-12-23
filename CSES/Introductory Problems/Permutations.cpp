#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  if (n == 1) return cout << 1, 0;
  if (n < 4) return cout << "NO SOLUTION" << '\n', 0;
  if (n == 4) return cout << "2 4 1 3", 0;
  int odd = 1, even = 2;
  int t = n + 1 >> 1;
  int tt = n - t;
  while (t--) {
    cout << odd << " ";
    odd += 2;
  }
  while (tt--) {
    cout << even << " ";
    even += 2;
  }
  return 0;
}