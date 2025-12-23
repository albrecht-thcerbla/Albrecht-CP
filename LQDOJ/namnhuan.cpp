#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    if (n % 400 == 0 || n % 4 == 0 && n % 100 != 0) cout << "YES" << '\n';
    else cout << "NO" << '\n'; 
  }
  return 0;
}