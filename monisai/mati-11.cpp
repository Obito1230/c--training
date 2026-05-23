#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int a,n;
ll ans=0;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>n;
    int cur=a;
    while(n--){
        ans=(ans+cur)%mod;
        cur=(cur*10+a)%mod;
    }
    cout<<ans;
    return 0;
}