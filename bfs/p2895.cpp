#include<bits/stdc++.h>
using namespace std;
int m,x,y,t;
struct zuobiao{
    int x;
    int y;
    int step;
};
int mp[350][350];
bool vis[350][350];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int bushu;
void bfs(){
    vis[0][0]=true;
    queue<zuobiao>q;
    q.push({0,0,0});
    while(!q.empty()){
        zuobiao temp;
        temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=temp.x+dx[i];
            int b=temp.y+dy[i];
            if(vis[a][b])continue;
            if(a<0||b<0)continue;
            if(mp[a][b]<=temp.step)continue;
            if(mp[a][b]==-1){
                bushu=temp.step+1;
                return ;
            }
            vis[a][b]=true;
            q.push({a,b,temp.step+1});
        }
    }
    bushu=-1;
    return ;
}
int main (){
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
    cin>>m;
    while (m--){//构建地图
        cin>>x>>y>>t;
        if(x<0||x>300||y<0||y>300)continue;
        if(mp[x][y]==-1)mp[x][y]=t;
        else mp[x][y]=min(mp[x][y],t);
        for(int i=0;i<4;i++){
            int a=x+dx[i];
            int b=y+dy[i];
            if(a<0||b<0)continue;
            if(mp[a][b]==-1)mp[a][b]=t;
            else mp[a][b]=min(mp[a][b],t);
        }
    }
    bfs();
    cout<<bushu;
    return 0;
}