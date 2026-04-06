#include<bits/stdc++.h>
using namespace std;
int n,m,l,r;
int arr[100005];
int s[100005];
int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        s[i]=s[i-1]+arr[i];
    }
    cin>>m;
    while(m--){
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}