#include<bits/stdc++.h>
using namespace std;
int n;
int dx[8]={1,1,-1,-1,0,0,1,-1};
int dy[8]={1,-1,1,-1,1,-1,0,0};
char mp[105][105];
char ans[105][105];
string daan="yizhong";
int flag=0;
int flag1;
void dfs(int x,int y,int ge,int fangxiang){
    if(ge>=7){
        ans[x][y]=mp[x][y];
        flag=1;
        flag1=1;
        return;
    }
    int a1=x+dx[fangxiang];
    int b1=y+dy[fangxiang];
    if(a1<0||a1>n||b1<0||b1>n)return ;
    if(mp[a1][b1]!=daan[ge])return;
    dfs(a1,b1,ge+1,fangxiang);
    if(flag)ans[a1][b1]=mp[a1][b1];
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]='*';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==daan[0]){
                flag=0;
                flag1=0;
                for(int i1=0;i1<8;i1++){
                    int a=i+dx[i1];
                    int b=j+dy[i1];
                    if(a<0||a>n||b<0||b>n)continue;
                    if(mp[a][b]==daan[1]){
                        dfs(a,b,2,i1);
                        if(flag1){
                            ans[a][b]=mp[a][b];
                            flag1=0;
                        }
                    }
                }
                if(flag){
                    ans[i][j]=mp[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}