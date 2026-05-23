#include<bits/stdc++.h>
using namespace std;
int t,n;
int main (){
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        if(arr[0]!=0){
            cout<<0<<endl;
            continue;
        }
        int flag=1;
        for(int i=1;i<n;i++){
            if(arr[i]==flag){
                flag++;
            }
        }
        cout<<flag<<endl;
        }
    return 0;
}