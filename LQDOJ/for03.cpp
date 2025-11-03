#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a;
  a.emplace_back(1);
  a.emplace_back(n);
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i != i) {
        a.emplace_back(i);
        a.emplace_back(n / i);
      }
      else a.emplace_back(i);
    }
  }
  sort(all(a));
  for (int i = 0; i < sz(a); i++) cout << a[i] << " ";
  return 0;
}