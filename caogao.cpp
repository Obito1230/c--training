#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int vis[300005];
queue<int>q;
vector<vector<int>>adj(300005);
void bfs(){
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(vis[adj[u][i]]==-1){
                vis[adj[u][i]]=vis[u]+1;
                q.push(adj[u][i]);
            }
        }
    }
}
int maxans=INT_MIN;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis,-1,sizeof(vis));
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//无向图
    }
    while(k--){
        int temp;
        cin>>temp;
        vis[temp]=0;
        q.push(temp);

    }
    bfs();
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            cout<<"-1"<<endl;
            return 0;
        }
        maxans=max(maxans,vis[i]);
    }
    cout<<maxans;
    return  0;
}