#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair <int , pair <int, int >>
#define iiii pair <pair<int, int> , pair <int, int >>
#define bit(n,i) ((n>>i)&1)
int const N=1e3 + 10;
int const MOD = 1e9 + 7;
int const inf = 1e18;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
char huong[] = {'D','U','L','R'};

main(){
      ios::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      int t;
      cin>>t;
      while(t--){
        string n;
        cin >>n;
        int ans=0;
        for(int i=0;i<n.size();i++){
          ans = max(ans, n[i] - '0');
        }
        cout << ans << '\n';
      }
}
