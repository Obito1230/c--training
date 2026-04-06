//田忌赛马贪心
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
int main (){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ib=0;
    for(int ia=0;ia<n;){
        if(a[ia]>b[ib]){
            ia++;
            ib++;
        }
        else{
            ia++;
        }
    }
    cout<<n-1-ib;
}