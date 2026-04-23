#include<bits/stdc++.h>
using namespace std;
int n;
string ans="yizhong";
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
string mp[105];
bool biaoji[105][105];
void dfs(int x,int y, int now,int chang){
    if(chang==ans.size()){
        for(int i=0;i<ans.size();i++){
            biaoji[x-dx[now]*i][y-dy[now]*i]=true;
        }
        return ;
    }
    int ax=x+dx[now];
    int ay=y+dy[now];
    if(ax<0||ax>=n||ay<0||ay>=n)return ;
    if(mp[ax][ay]==ans[chang]){
        dfs(ax,ay,now,chang+1);
    }
    else return ;
}
int main (){
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]==ans[0]){
                for(int k=0;k<8;k++){
                    dfs(i,j,k,1);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(biaoji[i][j]){
                cout<<mp[i][j];
            }
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}