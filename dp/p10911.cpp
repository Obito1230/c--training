#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll dp[3000][3000][2];
ll f(ll x){
    if(x==0){
        return 0;
    }
    else{
        string arr="";
        while(x>0){
            arr+=(x%2)+'0';
            x/=2;
        }
        ll ans=0;
        for(int i=0;i<arr.size();i++){
            ans=ans*2+(arr[i]-'0');
        }
        return ans;
    }
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    long long sum=0;
    vector<ll>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<ll>brr(n+1);
    for(int i=1;i<=n;i++){
        brr[i]=f(arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j>0){
                dp[i][j][0]=max(dp[i-1][j][0]+arr[i],dp[i-1][j][1]+arr[i]);//i表示枚举到第i个数，j表示此时反转了几次，最后一个[]当等于0时表示这个没反转，等于1时表示反转了
                dp[i][j][1]=max(dp[i-1][j][1]+brr[i],dp[i-1][j-1][0]+brr[i]);//如果第i个数没反转，那么他无论如何都不会消耗j，但如果他反转了，前面的没反转，他会消耗一个j
            }
            if(j==0){
                dp[i][j][0]=max(dp[i-1][j][0]+arr[i],dp[i-1][j][1]+arr[i]);
                dp[i][j][1]=dp[i][j][0];
            }
        }
    }
    cout<<max(dp[n][m][0],dp[n][m][1])<<"\n";
    return 0;
}