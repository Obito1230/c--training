#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
vector<int> t[100005];
int sum=0;
bool vis[100005];
void dfs(int jiedian,int lenth){
    sum+=a[jiedian];
    vis[jiedian]=true;
    for(int i=0;i<t[jiedian].size();i++){
        if((lenth+1<=2*k)&&(!vis[t[jiedian][i]])){
            vis[t[jiedian][i]]=true;
            dfs(t[jiedian][i],lenth+1);
        }
    }
}
int main (){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1,0);
    cout<<sum;
}