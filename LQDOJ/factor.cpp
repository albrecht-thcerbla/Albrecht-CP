#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int nn = n;
  vector<int> num;
  int cnt = 2;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        num.emplace_back(i);
        n /= i;
      }
    }
  }
  if (n != 1) num.emplace_back(n);
  for (int i = 2; i <= sqrt(nn); i++) {
    if (nn % i == 0) {
      if (nn / i != i) cnt += 2;
      else cnt++;
    }
  }
  for (int i = 0; i < sz(num); i++) {
    cout << num[i];
    if (i != sz(num) - 1) cout << "*";
  }
  cout << '\n' << cnt << '\n';
  return 0;
}