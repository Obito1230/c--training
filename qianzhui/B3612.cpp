#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100005];
typedef long long ll;
ll ans[100005];
int main (){
    cin>>n;
    ans[0]=0;
    for(int i=1;i<n;i++){
        cin>>arr[i];
        ans[i]=arr[i]+ans[i-1];
    }
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}