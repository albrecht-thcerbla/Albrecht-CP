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
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n), lp(1000001, 0), pr;
  for (int i = 0; i < n; i++) cin >> a[i];  
  auto sieve = [&]() {
    for (int i = 2; i <= 1000000; i++) {
      if (!lp[i]) lp[i] = i, pr.emplace_back(i);
      for (int j = 0; i * pr[j] <= 1000000; j++) {
        lp[i * pr[j]] = pr[j];
        if (lp[i] == pr[j]) break;
      }
    }
  };
  sieve();
  vector<int> mxseq, curseq;
  int mxlen = 0, mxsum = 0, curlen = 0, cursum = 0;
  for (int i = 0; i < n; i++) {
    if (lp[a[i]] == a[i] && a[i] >= 2) ++curlen, cursum += a[i], curseq.emplace_back(a[i]);
    else {
      if (curlen > mxlen || (curlen == mxlen && cursum > mxsum)) {
        mxlen = curlen;
        mxsum = cursum;
        mxseq = curseq;
      }
      curlen = 0, cursum = 0;
      curseq.clear();
    }
  }
  if (curlen > mxlen || (curlen == mxlen && cursum > mxsum)) mxlen = curlen, mxsum = cursum, mxseq = curseq;
  if (!mxlen) cout << "NOT FOUND" << '\n';
  else {
    cout << mxlen << '\n';
    for (int i = 0; i < sz(mxseq); i++) cout << mxseq[i] << " ";
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}