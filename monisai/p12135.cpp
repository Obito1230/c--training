#include<bits/stdc++.h>
using namespace std;
string arr[2];
int mp[2][1000005];
int dp[2][1000005];
void solve(){
    int len;
    for(int i=0;i<2;i++){
        cin>>arr[i];
        len=arr[i].size();
        for(int j=1;j<=len;j++){
            if(arr[i][j-1]=='.')mp[i][j]=0;
            else mp[i][j]=1;
        }
    }
    int tou=len+1,wei=-1;
    for(int i=1;i<=len;i++){
        for(int j=0;j<2;j++){
            if(mp[j][i]){
               tou=min(i,tou);
               wei=max(i,wei);
            }
        }
    }
    if(!mp[0][tou])dp[0][tou]=1;
    else dp[1][tou]=1;
    for(int i=tou+1;i<=wei;i++){
        dp[0][i]=min(dp[0][i-1]+(1-mp[0][i]),dp[1][i-1]+(1-mp[1][i])+(1-mp[0][i]));
        dp[1][i]=min(dp[1][i-1]+(1-mp[1][i]),dp[0][i-1]+(1-mp[0][i])+(1-mp[1][i]));
    }
    cout<<min(dp[0][wei],dp[1][wei]);

}
int main (){
    solve();
}