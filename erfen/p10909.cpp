#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100005];
int cnt;
bool check(int x){
    cnt=0;
    for(int i=1;i<=n;i++){
        int cha=arr[i]-arr[i-1];
        if(cha<=x)continue;
        cnt+=(int)ceil(cha*1.0/x)-1;
        if(cnt>m)return false;
    }
    return true;
}
int main (){
    cin>>n>>m;
    m++;//爆发技能可以看作多放一个检查点
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int l=0,r=1e8+10;
    while(l+1<r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    if(check(l))cout<<l<<endl;
    else cout<<r<<endl;
    return 0;
}