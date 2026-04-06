//此题根据标签提示可知考点为二分答案+bfs
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ix,iy;//全局变量，方便寻找起点路标并入队
struct zuobiao{
    int x;
    int y;
};
int cnt=1,cntsum=0;
int mp[505][505];
bool vis[505][505];
int lubiao[505][505];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int m1){//就是bfs
    queue<zuobiao>q;
    memset(vis,false,sizeof(vis));
    q.push({ix,iy});
    vis[ix][iy]=1;
    cnt=1;
    while(!q.empty()){
        zuobiao temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=temp.x+dx[i];
            int b=temp.y+dy[i];
            if(a<0||a>=n||b<0||b>=m)continue;
            if(vis[a][b])continue;
            if(abs(mp[a][b]-mp[temp.x][temp.y])>m1)continue;
            vis[a][b]=true;
            q.push({a,b});
            if(lubiao[a][b]==1){
                cnt++;
                if(cnt==cntsum){
                    return true;
                }
            }
        }
    }
    return false;
}
int main (){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>lubiao[i][j];
            if(lubiao[i][j]==1){
                cntsum++;//统计路标个数，便于最终判断
            }
        }
    }
    bool flag=false;//用于跳出第二层循环
    for(int i=0;i<n;i++){//寻找起点
        for(int j=0;j<m;j++){
            if(lubiao[i][j]==1){
                ix=i;
                iy=j;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    int l=0,r=999999999;
    while(l+1<r){//经典二分答案
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    if(check(l)){
        cout<<l;
    }
    else{
        cout<<r;
    }
    return 0;
}