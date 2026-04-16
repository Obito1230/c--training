#include<bits/stdc++.h>
using namespace std;
int n,c;
typedef long long ll;
int arr[200005];
ll cnt=0;
int main (){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int a=arr[i];
        int l=lower_bound(arr,arr+n,a-c)-arr;
        int r=upper_bound(arr,arr+n,a-c)-arr;
        cnt+=r-l;
    }
    cout<<cnt;
}
//b=a-c
//a-b=c->a=b+c
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
ll arr[200005];
int main (){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll cnt=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        ll b=arr[i];
        ll l=lower_bound(arr+i,arr+n,b+c)-arr;
        ll r=upper_bound(arr+i,arr+n,b+c)-arr;
        cnt+=(r-l);
    }
    cout<<cnt;
}
//a-b=c->a=b+c*/