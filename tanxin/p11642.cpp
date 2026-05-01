#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
ll arr[100005];
ll maxans=0;
ll sum=0;
int main (){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(cnt>=0){
            cnt+=(x-arr[i]);
        }
        else if(cnt<0){
            cnt=0;
            cnt+=(x-arr[i]);
        }
        maxans=max(maxans,cnt);
    }
    cout<<sum+maxans;
}