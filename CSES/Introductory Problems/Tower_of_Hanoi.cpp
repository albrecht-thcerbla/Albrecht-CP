#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

void hanoi(int n, int from, int to, int aux) {
  if (n == 1) return void (cout << from << " " << to << '\n');
  hanoi(n - 1, from, aux, to);
  cout << from << " " << to << '\n';
  hanoi(n - 1, aux, to, from);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  cout << (1LL << n) - 1 << '\n';
  hanoi(n, 1, 3, 2);
  return 0;
}