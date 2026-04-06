#include<bits/stdc++.h>
using namespace std;
int n;
int arr[68];
int s[68];
int main (){
    cin>>n;
    while(n--){
        for(int i=1;i<=6;i++){
            cin>>arr[i];
            s[i]=s[i-1]-arr[i];
        }
        cin>>arr[7];
        s[7]+=arr[7];
        cout<<s[7]<<endl;
    }
    return 0;
}