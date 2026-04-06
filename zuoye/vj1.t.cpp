#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[2005][2005];
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        mp[x1][y1]++;
        mp[x1][y2+1]--;
        mp[x2+1][y1]--;
        mp[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
            if(mp[i][j]%2){
                cout<<"1";
            }
            else{
                cout<<0;
            }
        }
        cout<<"\n";
    }
    return 0;
}