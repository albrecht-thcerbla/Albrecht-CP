// https://codeforces.com/problemset/problem/1353/C
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

/**
- gather all to the middle
- this is Chebyshev distance
- call m = (n - 1) / 2 [maximum distance to center]
- call k = 1, 2, 3, ..., m [distance to center]

example:

 k k k k k k k k k
 k . . . . . . . k
 k . 2 2 2 2 2 . k
 k . 2 1 1 1 2 . k
 k . 2 1 0 1 2 . k
 k . 2 1 1 1 2 . k
 k . 2 2 2 2 2 . k
 k . . . . . . . k
 k k k k k k k k k

=> each rim has 8k cells
=> each figure needs (8k * k) steps to reach the center

for (int k = 1; k <= m; k++) sum += (8 * k * k);
or
for (int k = 1; k <= m; k++) sum += (k * k); => ans = sum * 8;

- base case: m = 1 => [1 * (1 + 1) * (2*1 + 1)] / 6 = 1 = m = right-hand side

- induction hypothesis: assume the formula is true for some integer m >= 1. That is, we assume:
  1^2 + 2^2 + ... + m^2 = [m * (m + 1) * (2m + 1)] / 6

- prove it for m + 1:
  we must show: 1^2 + 2^2 + ... + m^2 + (m + 1)^2 = [(m + 1) * (m + 2) * (2m + 3)] / 6
  left-hand side, we have: the sum of k squared from k equals one to m plus one
                         = the sum of k squared from k equals one to m + (m + 1)^2
  using the induction hypothesis: [m * (m + 1) * (2m + 1)] / 6 + (m + 1)^2
  factor (m + 1):                   => (m + 1) * [m * (2m + 1) / 6 + (m + 1)]
  write (m + 1) with denominator 6: => (m + 1) * [m * (2m + 1) / 6 + 6 * (m + 1) / 6]
  combine the fractions:            => 2m^2 + 7m + 6 = (2m + 3) * (m + 2)
  so, the sum of k squared from k equals one to m plus one = (m + 1) * (m + 2) * (2m + 3) / 6
  by mathematical induction, the fomula: m * (m + 1) * (2m + 1) / 6 is true for all integers m >= 1

**/

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    int m = (n - 1) >> 1;
    int ans = 8 * (m * (m + 1) * (2 * m + 1) / 6);
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

