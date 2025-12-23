#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1025;
int n;
long long a[MAXN][MAXN];
long long seg[4 * MAXN][4 * MAXN];

// truy vấn theo trục Y
long long sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return 0;
    if (ly == tly && ry == try_) return seg[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}

// truy vấn theo trục X
long long sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx) return 0;
    if (lx == tlx && rx == trx)
        return sum_y(vx, 1, 1, n, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}

// cập nhật theo trục Y
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, long long val) {
    if (ly == ry) {
        if (lx == rx)
            seg[vx][vy] = val;
        else
            seg[vx][vy] = seg[vx * 2][vy] + seg[vx * 2 + 1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, val);
        seg[vx][vy] = seg[vx][vy * 2] + seg[vx][vy * 2 + 1];
    }
}

// cập nhật theo trục X
void update_x(int vx, int lx, int rx, int x, int y, long long val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, val);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, val);
    }
    update_y(vx, lx, rx, 1, 1, n, x, y, val);
}

int main() {
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(seg, 0, sizeof(seg));

        string cmd;
        while (cin >> cmd) {
            if (cmd == "END") break;

            if (cmd == "SET") {
                int x, y, val;
                cin >> x >> y >> val;
                x++; y++; // chuyển về 1-based
                a[x][y] = val;
                update_x(1, 1, n, x, y, val);
            } else if (cmd == "SUM") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                cout << sum_x(1, 1, n, x1, x2, y1, y2) << "\n";
            }
        }
    }
}
