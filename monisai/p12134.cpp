#include<bits/stdc++.h>
using namespace std;
int n,m;
long long arr[100005];
int main (){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long temp;
        cin>>temp;
        arr[i]=temp;
    }
    long long minans=LONG_MAX;
    sort(arr+1,arr+n+1);
    for(int i=1,j=m;j<=n;i++,j++){
        minans=min(minans,arr[j]-arr[i]);
    }
    cout<<minans;
}