#include<iostream>
#include<cstring>
using namespace std;
char g[105][105];
bool vis[105][105];
int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny] || g[nx][ny] != '@') continue;
        dfs(nx, ny);
    }
}
int main() {
    while (cin >> n >> m && (n || m)) {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@' && !vis[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}