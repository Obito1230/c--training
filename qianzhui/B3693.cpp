#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;
int n,m,t,q;
int u,v,x,y;
ll mp[1005][1005];
ll ans;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        memset(mp,0,sizeof(mp));
        ans=0;
        cin>>m>>n>>q;
        for (int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ll temp;
                cin>>temp;
                mp[i][j]=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]+temp;
            }
        }
        while(q--){
            cin>>u>>v>>x>>y;
            ans=ans^(mp[x][y]-mp[x][v-1]-mp[u-1][y]+mp[u-1][v-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}