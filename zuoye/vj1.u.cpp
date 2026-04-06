#include<bits/stdc++.h>
using namespace std;
int n,p;
int arr[5000006];
int cha[5000006];
int main (){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cha[i]=arr[i]-arr[i-1];
    }
    while(p--){
        int l,r,z;
        cin>>l>>r>>z;
        cha[l]+=z;
        cha[r+1]-=z;
    }
    int minans=INT_MAX;
    for(int i=1;i<=n;i++){
        int temp;
        temp+=cha[i];
        minans=min(temp,minans);
    }
    cout<<minans;
}