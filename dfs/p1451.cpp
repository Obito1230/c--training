/*# P1451 求细胞数量

## 题目描述

一矩形阵列由数字 0 到 9 组成，数字 1 到 9 代表细胞，细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞，求给定矩形阵列的细胞个数。

## 输入格式

第一行两个整数代表矩阵大小 n 和 m。

接下来 n 行，每行一个长度为 m 的只含字符 `0` 到 `9` 的字符串，代表这个 n * m 的矩阵。

*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
char mp[105][105];
bool vis[105][105];
int ix[4]={0,1,0,-1};
int iy[4]={1,0,-1,0};
int cnt=0;
void dfs(int x,int y){
    if(mp[x][y]=='0')return ;
    if(!vis[x][y]){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int a=x+ix[i];
            int b=y+iy[i];
            if(a<1||a>n||b<1||b>m)continue;
            if(vis[a][b])continue;
            if(mp[a][b]==0)continue;
            dfs(a,b);
        }
    }
    if(vis[x][y])return ;
}
int main (){
    memset(vis,false,sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!='0'&&!vis[i][j])cnt++;
            dfs(i,j);
            
        }
    }
    cout<<cnt;
    return 0;
}