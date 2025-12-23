#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;
  if (n == 1 || n < 0) return cout << "NO", 0;
  for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return cout << "NO", 0;
  cout << "YES";
  return 0;
}