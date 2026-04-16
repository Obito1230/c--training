#include<bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
int dp[200005];
int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        ans=max(dp[i],ans);
    }
    cout<<ans;
}