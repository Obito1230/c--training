#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int mod=(int)(1e9+7);
ll dp[105][105][105];
//dp[i][j][k],i个店,j朵花,k容量的酒
//因为最后要喝完，所以k<=j;
int main (){
    cin>>n>>m;
    dp[0][0][2]=1;//开始有容量为2的酒
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){//遍历到达每一种情况时的走法的个数
            for(int k=0;k<=m;k++){//枚举当前也就是经过i个店和j朵花后所具有k容量的酒
                if(!dp[i][j][k])continue;
                if(k*2<=m&&i<n){//i为0不考虑，k*2>m不考虑，喝不完，
                    dp[i+1][j][k*2]=(dp[i+1][j][k*2]+dp[i][j][k])%mod;
                }
                if(k>0&&j<m){
                    dp[i][j+1][k-1]=(dp[i][j+1][k-1]+dp[i][j][k])%mod;
                }
            }
        }
    }
    cout<<dp[n][m-1][1];//最后一次必须是花（题意）
}