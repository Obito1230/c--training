#include<bits/stdc++.h>
using namespace std;
int main (){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int cnt=1;
    char a=s[s.end()-s.begin()];
    for(int i=s.end()-s.begin()-1;i>0;i--){
        if(a!=s[i]){
            break;
        }
        cnt++;
    }
    for(int i=0;i<cnt;i++){
        cout<<a;
    }
}