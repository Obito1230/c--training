#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int maxarr[N];
int minarr[N];
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<=n;i++){
        maxarr[i]=INT_MIN;
        minarr[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++){
        int flag;
        cin>>flag;
        maxarr[i]=max(maxarr[i-1],flag);
        minarr[i]=min(minarr[i-1],flag);
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=maxarr[i]+minarr[i];
    }
    cout<<sum;
    
}