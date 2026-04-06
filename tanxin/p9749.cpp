#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll arr[100005];
ll juli [100005];
int main(){
    cin>>n>>d;
    arr[0]=0;
    for(int i=1;i<n;i++){
        cin>>juli[i];
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll mintemp=arr[1];
    ll ans=0;
    ll shengyu=0;//一定要定义一个剩余变量，用于维护多走出的距离！！
    for(int i=1;i<n;i++){
        ll needlong=juli[i]-shengyu;//距离-剩余可能<0
        if(needlong>0){
            ans+=(ceil)((double)needlong/d)*mintemp;
            shengyu=shengyu+(ceil)((double)needlong/d)*d-juli[i];
        }
        if(needlong<=0){
            shengyu-=juli[i];
        }
        mintemp=min(mintemp,arr[i+1]);
    }
    cout<<ans;
    return 0;
}