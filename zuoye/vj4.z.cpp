//洛谷p1141
//预处理
#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[1005][1005];
bool vis[1005][1005];
int id[1005][1005];
int comp_size[1000005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, int id1) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    id[x][y] = id1;
    int size = 1;
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        int cx = temp.first, cy = temp.second;
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if(nx<1||nx>n||ny<1||ny>n)continue;
            if(vis[nx][ny])continue;
            if(mp[nx][ny]==mp[cx][cy])continue;
            vis[nx][ny] = true;
            id[nx][ny] = id1;
            size++;
            q.push({nx, ny});
        }
    }
    comp_size[id1] = size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            mp[i][j] = s[j - 1] - '0';
        }
    }
    memset(vis, false, sizeof(vis));
    memset(id, 0, sizeof(id));
    int cid = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, cid++);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cout << comp_size[id[x][y]] << endl;
    }
    return 0;
}