/*马在中国象棋以日字形规则移动。

请编写一段程序，给定n*m大小的棋盘，以及马的初始位置(x，y)，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

Input
第一行为整数T(T < 10)，表示测试数据组数。
每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n,m,x,y。(0<=x<=n-1,0<=y<=m-1, m < 10, n < 10)
Output
每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。*/
//Sample
//input
//1
//5 4 0 0
//output
//32
//可以设一个n作为遍历的步数，当遍历的步数等于棋盘大小-1时，视为可以遍历所有点
//减1是因为初始坐标占据一点但不算步数
#include<iostream>
#include<cstring>
using namespace std;
int sum=1;
int ans;
int n,m,t;
int dx[8]={2,1,2,-1,-1,-2,1,-2};
int dy[8]={1,2,-1,2,-2,-1,-2,1};
bool vis[12][12];
struct zuobiao{
    int x;
    int y;
};
int cnt=0;
void dfs(int ix,int iy){
    if(sum==ans){
        cnt++;
        return ;
    }
    for(int i=0;i<8;i++){
        int da=ix+dx[i];
        int db=iy+dy[i];
        if(da<0||da>=n||db<0||db>=m)continue;
        if(vis[da][db])continue;
        vis[da][db]=true;
        sum++;
        dfs(da,db);
        vis[da][db]=false;
        sum--;
    }
}
zuobiao qi;
int main (){
    cin>>t;
    while(t--){
        memset(vis,false,sizeof(vis));
        cnt=0;
        cin>>n>>m>>qi.x>>qi.y;
        ans=m*n;
        vis[qi.x][qi.y]=true;
        dfs(qi.x,qi.y);
        cout<<cnt<<endl;
    }
    return 0;
}