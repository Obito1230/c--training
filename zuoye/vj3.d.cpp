#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[8];
int start;
int cnt=0;
void dfs(int x,int start,int sum){
    if(x==k){
        if(sum==n)
        cnt++;
        return ;
    }
    if(start*(k-x)+sum>n)return ;
    for(int i=start;i*(k-x)+sum<=n;i++){
        dfs(x+1,i,sum+i);
    }
}
int main (){
    cin>>n>>k;
    dfs(0,1,0);
    cout<<cnt<<endl;
    return 0;
}