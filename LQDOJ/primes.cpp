#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

bool check(int x) {
  if (x == 2 || x == 3 || x == 5) return true;
  if (x < 2 || x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) return false;
  }
  return true;
}                                                                       
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int a[n + 1];
  int mx = 0;
  vector<int> idx;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (check(a[i])) {
      if (a[i] == mx) {
        idx.emplace_back(i);
      } else if (a[i] > mx) {
        idx.clear();
        idx.emplace_back(i);
        mx = a[i];
      }
    }    
  }
  cout << mx << '\n';
  for (int i = 0; i < sz(idx); i++) cout << idx[i] << " ";
  return 0;
}