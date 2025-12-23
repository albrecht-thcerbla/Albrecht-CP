#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int MAXN = 300000;
const int64_t inf = 1e18;

int64_t X[MAXN], Y[MAXN], C[MAXN];
vector<int> idxs, cand;

bool cmpX(int a, int b) {
  if (X[a] != X[b]) return X[a] < X[b];
  return Y[a] < Y[b];
}
bool cmpY(int a, int b) {
  if (Y[a] != Y[b]) return Y[a] < Y[b];
  return X[a] < X[b];
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> Y[i];
    int64_t tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> C[i];
      tot += C[i];
    }
    if (n <= 8) {
      int64_t best = LLONG_MIN;
      int lim = 1 << n;
      for (int mask = 1; mask < lim; mask++) {
        int64_t xmin = LLONG_MAX, xmax = LLONG_MIN;
        int64_t ymin = LLONG_MAX, ymax = LLONG_MIN;
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i)) {
            xmin = min(xmin, X[i]);
            xmax = max(xmax, X[i]);
            ymin = min(ymin, Y[i]);
            ymax = max(ymax, Y[i]);
            sum += C[i];
          }
        }
        int64_t peri = 2 * ((xmax - xmin) + (ymax - ymin));
        best = max(best, peri - sum);
      }
      cout << tot + best << "\n";
      continue;
    }
    idxs.resize(n);
    for (int i = 0; i < n; i++) idxs[i] = i;
    cand.clear();
    sort(all(idxs), cmpX);
    for (int i = 0; i < min(5, n); i++) cand.push_back(idxs[i]);
    for (int i = 0; i < min(5, n); i++) cand.push_back(idxs[n - 1 - i]);
    sort(all(idxs), cmpY);
    for (int i = 0; i < min(5, n); i++) cand.push_back(idxs[i]);
    for (int i = 0; i < min(5, n); i++) cand.push_back(idxs[n - 1 - i]);
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());
    int m = sz(cand);
    int64_t best = LLONG_MIN;
    for (int i = 0; i < m; i++) {
      int id0 = cand[i];
      int64_t peri = 0;
      int64_t sum = C[id0];
      best = max(best, peri - sum);
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        int id0 = cand[i], id1 = cand[j];
        int64_t xmin = min(X[id0], X[id1]);
        int64_t xmax = max(X[id0], X[id1]);
        int64_t ymin = min(Y[id0], Y[id1]);
        int64_t ymax = max(Y[id0], Y[id1]);
        int64_t peri = 2 * ((xmax - xmin) + (ymax - ymin));
        int64_t sum = C[id0] + C[id1];
        best = max(best, peri - sum);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          int id0 = cand[i], id1 = cand[j], id2 = cand[k];
          int64_t xmin = min(X[id0], min(X[id1], X[id2]));
          int64_t xmax = max(X[id0], max(X[id1], X[id2]));
          int64_t ymin = min(Y[id0], min(Y[id1], Y[id2]));
          int64_t ymax = max(Y[id0], max(Y[id1], Y[id2]));
          int64_t peri = 2 * ((xmax - xmin) + (ymax - ymin));
          int64_t sum = C[id0] + C[id1] + C[id2];
          best = max(best, peri - sum);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          for (int l = k + 1; l < m; l++) {
            int id0 = cand[i], id1 = cand[j], id2 = cand[k], id3 = cand[l];
            int64_t xmin = min(min(X[id0], X[id1]), min(X[id2], X[id3]));
            int64_t xmax = max(max(X[id0], X[id1]), max(X[id2], X[id3]));
            int64_t ymin = min(min(Y[id0], Y[id1]), min(Y[id2], Y[id3]));
            int64_t ymax = max(max(Y[id0], Y[id1]), max(Y[id2], Y[id3]));
            int64_t peri = 2 * ((xmax - xmin) + (ymax - ymin));
            int64_t sum = C[id0] + C[id1] + C[id2] + C[id3];

            best = max(best, peri - sum);
          }
        }
      }
    }
    cout << tot + best << "\n";
  }
  return 0;
}