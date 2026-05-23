#include<bits/stdc++.h>
using namespace std;
int mp[8][8];
int cnt=0;
bool check(){
    int cnt1=0,cnt2=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(mp[i][j]==1)cnt1++;
            if(mp[i][j]==2)cnt2++;
        }
    }
    if(cnt1!=cnt2+1)return true;
    for(int i=1;i<=5;i++){
        bool flag=false;
        for(int j=1;j<=5;j++){
            if(mp[i][j]!=mp[i][1]){
                flag= false;//所有条件均为false时才可retrun false
                break;
            }
        }
        if(flag)
            return true;
    }
    for(int j=1)

}
void dfs(int x,int y){

}
int main (){
    memset(mp,0,sizeof(mp));
    ios::sync_with_stdio(false);
    cin.tie(0);
    dfs(1,1);
    cout<<cnt;
}
