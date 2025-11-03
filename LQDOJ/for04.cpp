#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int cnt = 2;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i != i) cnt += 2;
      else ++cnt;
    }
  }
  cout << cnt;
  return 0;
}