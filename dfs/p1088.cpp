#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100005];
int ans[100005];
bool vis[100005];
int cnt=0;
bool flag;
void dfs(int x){
    if(flag)return ;
    if(x>n){
        cnt++;
        if(cnt==m+1){
            flag=1;
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<' ';
            }
            cout<<endl;
            return ;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(cnt==0){
            i=arr[x];
        }
        if(vis[i])continue;
        ans[x]=i;
        vis[i]=true;
        dfs(x+1);
        vis[i]=false;
    }
}
int main (){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dfs(1);
    return 0;
}