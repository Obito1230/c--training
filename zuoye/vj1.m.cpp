#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[50005];
ll arr[50005];
ll n;
ll q;
ll i,l;
int main (){
    cin>>n;
    for(ll i1=1;i1<=n;i1++){
        cin>>arr[i1];
        s[i1]=s[i1-1]+arr[i1];
    }
    cin>>q;
    while(q--){
        cin>>i>>l;
        ll r=i+l-1;
        cout<<s[r]-s[i-1]<<endl;
    }
    return 0;
}
