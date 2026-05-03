#include<bits/stdc++.h>
using namespace std;
bool flag=false;
int t=0,cnt;
int pos[12],p;
typedef long long ll;
ll zhuan (string s){
    ll temp=0;
    for(int i=0;i<s.size();i++){
        temp=temp*10+(s[i]-'0');
    }
    return temp;
}
bool prime(string s){
    ll x = zhuan(s);
    if(x<=1)return 0;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)
        return 0;
    }
    return 1;
}
void dfs(int n,string s){
    if(flag)return ;
    if(n==cnt){
        if(prime(s)){
            cout<<s<<endl;
            flag=1;
        }
        return ;
    }
    int c=pos[n];
    if(c==0){//整数首位不能为0，故特判
        for(int i=1;i<10;i++){
            s[c]=i+'0';
            dfs(n+1,s);
        }
    }
    else{
        for(int i=0;i<10;i++){
            s[c]=i+'0';
            dfs(n+1,s);
        }
    }
}
int main (){
    cin>>t;
    while (t--){
        string arr;
        flag=0;
        cnt=0;
        cin>>arr;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='*'){
                pos[cnt]=i;
                cnt++;
            }
        }
        if(cnt==0){
            if(prime(arr))
            cout<<arr<<endl;
            else 
            cout<<-1<<endl;
        }
        else{
            dfs(0,arr);
            if(!flag)
            cout<<-1<<endl;
        }
    }
    return 0;
}