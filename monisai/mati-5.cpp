#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1005];
int brr[1005];
int maxflag=INT_MIN;
int ansflag=INT_MAX;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i]>>brr[i];
    }
    for(int i=0;i<n;i++){
        int maxflag=INT_MIN;
        for(int j=0;j<n;j++){
            int temp;
            temp=abs(arr[i]-arr[j])+abs(brr[i]-brr[j]);
            maxflag=max(maxflag,temp);
        }
        ansflag=min(ansflag,maxflag);
    }
    cout<<ansflag;
    return 0;
}