
#include<bits/stdc++.h>
using namespace std;
struct zuobiao{
    int x;
    int y;
};
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int mp[35][35];
int vis[35][35];
void bfs(int x,int y){
    if(mp[x][y]!=1){
       queue<zuobiao>q;
       q.push({x,y});
       vis[x][y]=1;
       while (!q.empty()){
            zuobiao temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int a=temp.x+dx[i];
                int b=temp.y+dy[i];
                if(a<0||a>n+1||b<0||b>n+1)continue;
                if(mp[a][b]==1)continue;
                if(vis[a][b]!=0)continue;
                vis[a][b]=1;//勿忘标记
                q.push({a,b});
            }
       }
    }
}
int main (){
    ios::sync_with_stdio;
    cin.tie(0);
    cin.tie(0);
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    bfs(0,0);//既然连着墙的不算闭合圈，那就从墙外的一点开始bfs，把和墙外连着的0标记掉，最后判断，没有被标记的0可以被染色。
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==0&&mp[i][j]==0){
                mp[i][j]=2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}