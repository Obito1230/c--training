#include<bits/stdc++.h>
using namespace std;
int n,q;
int cnt2;
int cnt1;
int main (){
    cin>>n>>q;
    vector<vector<int>> mp(n+1,vector<int>(26,0));
    string arr;
    cin>>arr;
    for(int i=1;i<=n;i++){
        mp[i]=mp[i-1];
        mp[i][arr[i-1]-'a']++;
    }
    while (q--){
        int l,r;
        cin>>l>>r;
        cnt2=0;cnt1=0;
        for(int i=0;i<26;i++){
            if((mp[r][i]-mp[l-1][i])%2==0){
                cnt2++;
            }
            else {
                cnt1++;
            }
        }
        cout<<cnt2<<" "<<cnt1<<endl;
    }
    return 0;
}