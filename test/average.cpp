#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int dp[200][2000] , a[200] , pos[200];
int n,k;
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    int x; cin >> x;
    a[i] = 200 + (k - x);
  }
  dp[0][0] = 1;
  for(int i=1;i<=n;i++){
    for(int s = 0;s<=400;s++){
      dp[i][s] = dp[i-1][s];
      if(s>=a[i]) dp[i][s] = (dp[i-1][s] + dp[i-1][s-a[i]])%mod;
    }
  }
  for(int i=1;i<=n;i++){
    for(int s = 190;s<=210;s++){
      cout << dp[i][s] << ' ';
    }
    cout << endl;
  }
  cout << dp[n][200];
  return 0;
}