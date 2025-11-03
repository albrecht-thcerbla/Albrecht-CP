#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  multiset<int> ms;
  for (int i = 1; i <= k; i++) ms.insert(a[i]);
  cout << *ms.begin() << " " << *ms.rbegin() << '\n';
  for (int i = k + 1; i <= n; i++) {
    ms.insert(a[i]);
    auto it = ms.find(a[i - k]);
    ms.erase(it);
    cout << *ms.begin() << " " << *ms.rbegin() << '\n';
  }
  return 0;
}