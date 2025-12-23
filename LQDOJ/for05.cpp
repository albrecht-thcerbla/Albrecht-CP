#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;
  long long sum = 1 + n;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i != i) sum += (i + n / i);
      else sum += i;
    }
  }
  if (n << 1 == sum) cout << "YES";
  else cout << "NO";
  return 0;
}