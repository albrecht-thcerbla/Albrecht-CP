#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n, a, b; cin >> n >> a >> b;
  long long s1 = 0, s2 = 0;
  if (n % 2 == 0) {
    s1 = (n / 2 * b);
    s2 = n * a;
    cout << min(s1, s2);
  } else {
    s1 = (n / 2 * b) + a;
    s2 = n * a;
    cout << min(s1, s2);
  }
  return 0;
}