#include<bits/stdc++.h>
using namespace std;
int n;
int temp;
long long  s[100005];
int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        s[i]=s[i-1]+temp;
    }
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}