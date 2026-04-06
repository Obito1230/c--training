/*先分析
dp[y+1]=y+1=1*(y+1)=2^0*(y+1)
dp[y+2]=dp[y+1]+y+1=2*(y+1)=2^1*(y+1)
dp[y+3]=dp[y+2]+dp[y+1]+y+1=4*(y+1)=2^2*(y+1)
dp[y+4]=dp[y+3]+dp[y+2]+dp[y+1]+y+1=8*(y+1)=2^3*(y+1)
......
dp[x]=dp[y+x-y]=2^(x-y-1)*(y+1)
数据范围x与y均很大，故选用快速幂

当y>=x时，用一个就够了

一定不要忘记开long long,不然会爆int !!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll t,x,y;
ll kpow(ll x,ll n){
    ll temp=1;
    while(n>0){
        if(n%2!=0){
            temp=temp*x%mod;
        }
        x=x*x%mod;
        n/=2;
    }
    return temp%mod;
}
int main (){
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x==0){
            cout<<0<<endl;
            continue;
        }
        if(y>=x)cout<<1<<endl;
        else{
            ll ans=kpow(2,x-y-1)*(y+1)%mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}