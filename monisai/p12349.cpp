//dfs暴力解法，无法拿满分，但可骗到部分分，适用于OI赛制
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string>mp(1005);
int ans=INT_MIN;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int zhuanz(const vector<int>&biaoji){
    vector<string>ans=mp;
    int res=0;
    for(int i=0;i<n;i++){
        if(biaoji[i]){
            for(int j=0;j<m;j++){
                ans[i][j]^=1;
            }
        }
    }
    int cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnt=0;
            for(int k=0;k<4;k++){
                int a=i+dx[k];
                int b=j+dy[k];
                if(a<0||a>=n||b<0||b>=m)continue;
                if(ans[a][b]!=ans[i][j])continue;
                cnt++;
            }
            res+=cnt*cnt;
        }
    }
    return res;
}
void dfs(int hang,vector<int>&biaoji){
    if(hang==n){
        ans=max(ans,zhuanz(biaoji));
        return;
    }
    biaoji[hang]=0;
    dfs(hang+1,biaoji);

    biaoji[hang]=1;
    dfs(hang+1,biaoji);
}
int main (){
    cin>>n>>m;
    vector<int>temp(n);
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    dfs(0,temp);
    cout<<ans;
    return 0;
}