#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll mp[1005][1005];
ll s[1005][1005];
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--;
        ll ans=s[x2][y2]-s[x1][y2]-s[x2][y1]+s[x1][y1];
        cout<<ans<<"\n";
    }
    return 0;
}