#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

vector<string> s(4);
vector<int> pmts = {0, 1, 2, 3};

int cnt = 0;

void calc() {
  string top = s[pmts[0]], right = s[pmts[1]], bot = s[pmts[2]], left = s[pmts[3]];
  // choose top
  for (int topleft = 0; topleft < sz(top); topleft++) {
    for (int topright = topleft + 2; topright < sz(top); topright++) {
      int width = topright - topleft;
      // choose left
      for (int lefttop = 0; lefttop < sz(left); lefttop++) {
        for (int leftbot = lefttop + 2; leftbot < sz(left); leftbot++) {
          int height = leftbot - lefttop;
          if (top[topleft] != left[lefttop]) continue;
          // choose right
          for (int righttop = 0; righttop < sz(right); righttop++) {
            int rightbot = righttop + height;
            if (rightbot >= sz(right)) break;
            if (top[topright] != right[righttop]) continue;
            for (int botleft = 0; botleft < sz(bot); botleft++) {
              int botright = botleft + width;
              if (botright >= sz(bot)) break;
              if (bot[botleft] == left[leftbot] && bot[botright] == right[rightbot]) ++cnt;
            }
          }
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  for (int i = 0; i < 4; i++) cin >> s[i];
  calc();
  while (next_permutation(all(pmts))) calc();
  cout << cnt << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

