#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum = 0, mx = -1e9;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    mx = max(mx, sum);
    if (sum < 0) sum = 0;
  }
  cout << mx;
  return 0;
}