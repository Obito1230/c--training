#include<bits/stdc++.h>
using namespace std;
int t;
int main (){
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int l=500,r=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                l=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=t[i]){
                r=i;
                break;
            }
        }
        bool flag=true;
        if(l>r){
            flag=true;
        }
        
        else{
            for(int i=l,j=r;i<=r&&j>=l;i++,j--){
                if(s[i]!=t[j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}