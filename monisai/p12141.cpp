#include<bits/stdc++.h>
using namespace std;
int m,n,k;
bool dfs(int n,int k){
    if(n==1)return true;
    else{
        bool temp=dfs(n-1,ceil(k/2.0));
        if(k%2==0)return !temp;
        if(k%2==1)return temp;
    }
}
int main (){
    cin>>m;
    while(m--){
        cin>>n>>k;
        if(dfs(n,k))cout<<"RED"<<endl;
        else{
            cout<<"BLACK"<<endl;
        }
    }
}