#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zhuan (string s){
    ll temp=0;
    for(int i=s.size();i>0;i++){
        temp=temp*10+(s[i]-'0');
    }
    return temp;
}
bool prime(string s){
    ll x = zhuan(s);
    if(x<=1)return 1;
    for(ll i=2;i*i<x;i++){
        if(x%i==0)
        return 0;
    }
    return 1;
}
void dfs(int n,string s){

}
int t;
int main (){
    cin>>t;
    while (t--){
        string arr;
        cin>>arr;
        for(int i=0;i<arr.size();i++){
            
        }
    }
}