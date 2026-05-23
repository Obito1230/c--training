#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,q;
ll arr1[500005];
ll arr2[500005];
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        ll temp;
        cin>>temp;
        arr1[i] = (arr1[i-1] + temp) % mod;
        arr2[i] = (arr2[i-1] + temp % mod * i) % mod;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        ll sum1 = (arr1[r] - arr1[l-1] + mod) % mod;
        ll sum2 = (arr2[r] - arr2[l-1] + mod) % mod;//加mod后求余mod可以避免前面求mod导致出现的负值
        ll ans = (sum2 - (l-1) % mod * sum1 % mod + mod) % mod;
        cout<<ans<<endl;
    }
    return 0;
}