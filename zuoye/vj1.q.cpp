#include<bits/stdc++.h>
using namespace std;
int n,i,h,r;
int R[10005];
int dp[10005];
bool vis[10005][10005];
int main (){
    cin>>n>>i>>h>>r;
    for(int i=0;i<r;i++){
        int l;int r;
        cin>>l>>r;
        if(l>r){
            swap(l,r);
        }
        if(l==r||l+1==r||vis[l][r])continue;
        R[l+1]--;
        R[r]++;
        vis[l][r]=true;
    }
    dp[0]=h;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+R[i];
        cout<<dp[i]<<"\n";
    }
    return 0;
}