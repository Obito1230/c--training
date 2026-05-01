#include<bits/stdc++.h>
using namespace std;
int m[7];
int n;
long long sum=0;
int ans=0;
int len=0;
int main (){
    memset(m,-1,sizeof(m));
    cin>>n;
    for(int i=0;i<n;i++){
        int flag;
        cin>>flag;
        sum+=flag;
        int temp=sum%7;
        if(temp==0) len =i+1;
        else if(m[temp]==-1) {m[temp]=i;
        }
        else len=i-m[temp];
        ans=max(ans,len);
    }
    cout<<ans;
}