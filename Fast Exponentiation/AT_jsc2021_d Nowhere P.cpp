//(p-1)*(p-2)^n-1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,p;
ll fast (ll x,ll n){
    ll temp=1;
    while (n>0){
       if(n%2==1){
            temp=temp*x%mod;
       }
        x=x*x%mod;
        n/=2;
    }
    return temp%mod;
}
int main (){
    cin>>n>>p;
    ll ans=fast(p-2,n-1);
    ans=ans*(p-1)%mod;
    cout<<ans;
    return 0;
}