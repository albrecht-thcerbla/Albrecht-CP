#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

vector<int> pr, lp(10000001, 0);

void sieve() {
  for (int i = 2; i <= 10000000; i++) {
    if (!lp[i]) lp[i] = i, pr.emplace_back(i);
    for (int j = 0; i * pr[j] <= 10000000; j++) {
      lp[i * pr[j]] = pr[j];
      if (lp[i] == pr[j]) break;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b; cin >> a >> b;
  sieve();
  for (int i = 0; i < sz(pr); i++) {
    if (pr[i] >= a && pr[i] <= b) cout << pr[i] << '\n';
    if (pr[i] > b) break;
  }
  return 0;
}