#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[6];
void dfs(int n1){
    if(n1==n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
    for(int i=1;i<=k;i++){
        arr[n1]=i;
        dfs(n1+1);
    }
}
int main (){
    cin>>n>>k;
    dfs(0);
    return 0;
}