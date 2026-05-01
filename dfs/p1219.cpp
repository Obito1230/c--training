#include<bits/stdc++.h>
using namespace std;
int mp[15][15];
int n;
int ans[15],lie[15],d1[50],d2[50];
int cnt=0;
void dfs(int x){
    if(x>n){
        if(cnt<3){
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
        cnt++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(lie[i]==1)continue;
        if(d1[x+i]==1)continue;
        if(d2[x-i+n]==1)continue;
        ans[x]=i;
        lie[i]=1;
        d1[x+i]=1;//次对角线
        d2[x-i+n]=1;//主对角线（+n是为了避免负数）在主对角线 行-列的值恒定 重点！！！
        dfs(x+1);
        lie[i]=0;
        d1[x+i]=0;
        d2[x-i+n]=0;
    }
}
int main (){
    cin>>n;
    dfs(1);
    cout<<cnt;
}