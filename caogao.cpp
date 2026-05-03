#include<bits/stdc++.h>
using namespace std;
int n,q;
int arr[1000006];
int lastsum=0;
int sum=0;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        lastsum+=arr[i];
    }
    while(q--){
        int x;
        cin>>x;
        if(x==1||lastsum==0){
            cout<<lastsum<<'\n';
        }
        else{
            sum=0;
            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    arr[i]/=x;
                }
                sum+=arr[i];
            }
            cout<<sum<<'\n';
            lastsum=sum;
        }
    }
    return 0;
}