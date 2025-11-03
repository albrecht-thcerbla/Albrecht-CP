#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;
  cout << n << " ";
  while (n != 1) {
    if (n & 1) n = (n * 3 + 1);
    else (n >>= 1);
    cout << n << " ";
  }
  return 0;
}