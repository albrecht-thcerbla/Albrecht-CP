#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  vector<char> c = {'T','E','N','F','O','R','Y','S','I','X'};
  vector<int> d(10);
  for (int i = 0; i < 10; i++) d[i] = i + 1;
  bool timThay = false;
  while (next_permutation(all(d))) {
    int T = d[0], E = d[1], N = d[2], F = d[3], O = d[4], R = d[5], Y = d[6], S = d[7], I = d[8], X = d[9];
    if (T == 0 || F == 0 || S == 0) continue;
    int64_t TEN = 100 * T + 10 * E + N;
    int64_t FORTY = 10000 * F + 1000 * O + 100 * R + 10 * T + Y;
    int64_t SIXTY = 10000 * S + 1000 * I + 100 * X + 10 * T + Y;

    if (TEN + TEN + FORTY == SIXTY) {
      int64_t ONE = 100 * O + 10 * N + E;
      int64_t SIX = 100 * S + 10 * I + X;
      cout << "Tim thay nghiem: " << '\n';
      for (int i = 0; i < 10; i++) cout << c[i] << " = " << d[i] << '\n';
      cout << "TEN = " << TEN << "\n";
      cout << "FORTY = " << FORTY << "\n";
      cout << "SIXTY = " << SIXTY << "\n";
      cout << "ONE = " << ONE << "\n";
      cout << "SIX = " << SIX << "\n";
      timThay = true;
      break;
    }
  }
  if (!timThay) cout << "Khong co nghiem nao phu hop" << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
