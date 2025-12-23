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
  int s1, s2, s3; cin >> s1 >> s2 >> s3;
  vector<int> a(s1 + s2 + s3 + 1, 0);
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      for (int k = 1; k <= s3; k++) {
        a[i + j + k]++;
      }
    }
  }
  int sum = 0, cnt = 0;
  for (int i = 3; i <= s1 + s2 + s3; i++) {
    if (a[i] > cnt) {
      cnt = a[i];
      sum = i;
    }
  }
  cout << sum << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

