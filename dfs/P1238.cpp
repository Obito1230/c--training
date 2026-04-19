#include<bits/stdc++.h>
using namespace std;
struct zuobiao{
    int x;
    int y;
};
int m,n;
zuobiao beg,ed;
int mp[18][18];
bool vis[18][18];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
zuobiao ans[120];
bool flag;
void dfs(int ix,int iy,int n1){
    if((ix==ed.x)&&(iy==ed.y)){
        flag=true;
        cout<<"("<<ans[0].x<<","<<ans[0].y<<")";
        for(int i=1;i<n1;i++){
            cout<<"->"<<"("<<ans[i].x<<","<<ans[i].y<<")";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        int da=ix+dx[i];
        int db=iy+dy[i];
        if(vis[da][db])continue;
        if(da<1||da>m||db<1||db>n)continue;
        vis[da][db]=true;
        ans[n1].x=da;
        ans[n1].y=db;
        dfs(da,db,n1+1);
        vis[da][db]=false;
    }
}
int main (){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            if(mp[i][j]==0) vis[i][j]=1;
        }
    }
    cin>>beg.x>>beg.y;
    vis[beg.x][beg.y]=true;
    ans[0].x=beg.x;
    ans[0].y=beg.y;
    cin>>ed.x>>ed.y;
    dfs(beg.x,beg.y,1);
    if(!flag)
    cout<<"-1"<<endl;
    return 0;
}