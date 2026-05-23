#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1000005];
int ren[2005];
int cnt=0;
int minans=INT_MAX;
int main (){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int l=1;
    int r;
    int al;int ar;
    for(r=1;r<=n;r++){
        if(ren[arr[r]]==0){
            cnt++;
        }
        ren[arr[r]]++;
        while(cnt==m){
            if(minans>r-l+1){
                al=l;
                ar=r;
                minans=r-l+1;
            }
            if(ren[arr[l]]==1){
                cnt--;
            }
            ren[arr[l]]--;
            l++;
        }
    }
    cout<<al<<" "<<ar;
    return 0;
}