#include<bits/stdc++.h>
using namespace std;
int n,mudidi,f[1000005],ans1[1000005];
int x,y,ans;
int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void hebing (int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        f[fx]=f[fy];//把x挂在y下面，故下面要+y；
        ans1[fy]+=ans1[fx];
    }
}
int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        f[i]=i;
        ans1[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>mudidi;
        hebing(i,mudidi);
    }
    for(int i=1;i<=n;i++){
		ans=max(ans,ans1[find(i)]);
	}
    for(int i=1;i<n;i++){
        x=find(i);
        y=find(i+1);
        if(x!=y){
            ans=max(ans,ans1[x]+ans1[y]);
        }
    }
    cout<<ans;
}