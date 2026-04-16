#include<bits/stdc++.h>
using namespace std;
struct zuobiao{
    int x;int y;
};
int t;
int m,n;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int dx1[8]={1,0,0,-1,1,1,1,-1};
int dy1[8]={0,1,-1,0,-1,-1,1,1};
char mp[53][53];
bool vis[53][53];
bool vis1[53][53];
int cnt=0;
bool flag;
void bfs1(int x,int y){
    queue<zuobiao>q;
    vis[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        zuobiao temp=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a=temp.x+dx1[i];
            int b=temp.y+dy1[i];
            if(a<0||a>m+1||b<0||b>n+1) continue;
            if(mp[a][b]=='1')continue;
            if(vis[a][b])continue;
            vis[a][b]=true;
            q.push({a,b});
        }
    }
}
void bfs2(int x,int y){
    flag=false;
    queue<zuobiao>q;
    vis1[x][y]=true;
    q.push({x,y});
    if(!flag){
    for(int i=0;i<4;i++){
        int a=x+dx[i];
        int b=y+dy[i];
        if(vis[a][b])flag=true;
    }
    }
    while(!q.empty()){
        zuobiao temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=temp.x+dx[i];
            int b=temp.y+dy[i];
            if(a<1||a>m||b<1||b>n) continue;
            if(mp[a][b]=='0')continue;
            if(vis1[a][b])continue;
            vis1[a][b]=true;
            if(!flag){
                  for(int i=0;i<4;i++){
                    int a1=a+dx[i];
                    int b1=b+dy[i];
                    if(vis[a1][b1])
                        flag=true;
                    }
                }
            q.push({a,b});
        }
    }
}
int main (){
    cin>>t;
    while(t--){
        cnt=0;
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        memset(mp,0,sizeof(mp));
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>mp[i][j];
            }
        }
        bfs1(0,0);//泼水
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][j]=='1'&&!vis[i][j]&&!vis1[i][j]){
                    bfs2(i,j);
                    if(flag)cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}