/*有一个 n×m 的棋盘，在某个点 (x,y) 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步。

输入格式
输入只有一行四个整数，分别为 n,m,x,y。

输出格式
一个 n×m 的矩阵，代表马到达某个点最少要走几步（不能到达则输出 −1）。*/
#include<bits/stdc++.h>
using namespace std; 
int n,m,x,y;
int dx[8]={1,-1,1,-1,2,2,-2,-2};
int dy[8]={2,2,-2,-2,1,-1,1,-1};
int mp[405][405];
struct zuobiao{
    int x;
    int y;
};
void bfs(int x,int y){
    queue<zuobiao>q;
    zuobiao temp;
    temp.x=x,temp.y=y;
    q.push(temp);
    while (!q.empty()){
        zuobiao flag=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a=flag.x+dx[i];
            int b=flag.y+dy[i];
            if(a<1||a>n||b<1||b>m)continue;
            if(mp[a][b]!=-1)continue;
            mp[a][b]=mp[flag.x][flag.y]+1;
            q.push({a,b});
        }
    }
}
int main (){
    memset(mp,-1,sizeof(mp));
    cin>>n>>m>>x>>y;
    mp[x][y]=0;
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}