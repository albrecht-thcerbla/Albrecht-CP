#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct Trie {
  bool end;
  unordered_map<char, Trie*> next;
  Trie() : end(false) {}
};
void insert(Trie* root, string word) {
  Trie* node = root;
  for (char c : word) {
    if (!node->next.count(c)) node->next[c] = new Trie();
    node = node->next[c];
  }
  node->end = true;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string s; cin >> s;
  int n = sz(s);
  int k; cin >> k;
  Trie* root = new Trie();
  for (int i = 0; i < k; i++) {
    string w; cin >> w;
    insert(root, w);
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!dp[i]) continue;
    Trie* node = root;
    for (int j = i; j < n; j++) {
      char c = s[j];
      if (!node->next.count(c)) break;
      node = node->next[c];
      if (node->end) dp[j + 1] = (dp[j + 1] + dp[i]) % mod;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}