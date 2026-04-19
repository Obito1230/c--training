#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
char mp[205][205];
int disY[205][205], disM[205][205];
int n, m;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct Node {
    int x, y, step;
};
void bfs(int sx, int sy, int dis[][205]) {
    memset(dis, 0x3f, sizeof(int)*205*205);
    queue<Node> q;
    q.push({sx, sy, 0});
    dis[sx][sy] = 0;
    while (!q.empty()) {
        Node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (mp[nx][ny] == '#') continue;
            if (dis[nx][ny] > now.step + 1) {
                dis[nx][ny] = now.step + 1;
                q.push({nx, ny, dis[nx][ny]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        int yx, yy, mx, my;
        for (int i = 0; i < n; i++) {
            cin >> mp[i];
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 'Y') {
                    yx = i; yy = j;
                } else if (mp[i][j] == 'M') {
                    mx = i; my = j;
                }
            }
        }
        bfs(yx, yy, disY);
        bfs(mx, my, disM);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == '@') {
                    ans = min(ans, disY[i][j] + disM[i][j]);
                }
            }
        }
        cout << ans * 11 << "\n";
    }
    return 0;
}