#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll maxans=LONG_MIN;
ll arr[100005];
bool check(ll x){
    int ans=0;
    for(int i=0;i<n;i++){
        int len=arr[i];
        ans+=(len/x);
    }
    if(ans>=k) return true;
    else return false;
}
int main (){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxans=max(maxans,arr[i]);
    }
    int l=0;int r=maxans+1;
    while(l+1<r){
        ll temp=(l+r)/2;
        if(check(temp)){
            l=temp;
        }
        else {
            r=temp;
        }
    }
    if(check(r))cout<<r;
    else cout<<l;
}