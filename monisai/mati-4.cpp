#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll ans=0;
int main (){
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        int temp1;
        temp1=temp%16;
        temp/=16;
        ans+=temp1*16+temp;
    }
    cout<<ans;
    return 0;
}