//贪心
#include<bits/stdc++.h>
using namespace std;
int m,n,k;
struct node{
    int i;
    int j;
    int value;
};
bool cmp(node x,node y){
    return x.value>y.value;
}
bool first=true;
vector<node> arr;
int main (){
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x>0)
            arr.push_back({i,j,x});
        }
    }
    sort(arr.begin(),arr.end(),cmp);
    int x1=0,y1=0,v;
    int nx=0,ny=0;
    int t=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        x1=arr[i].i;
        y1=arr[i].j;
        v=arr[i].value;
        int cost=0;
        if(first){
            cost=x1+1;
        }
        else{
            cost=abs(x1-nx)+abs(y1-ny)+1;//+1是为了采摘花生
        }
        if(t+cost+x1>k)continue;//这题题目里说了，必须每次采摘花生最多的植株，故此处不能用continue
        t+=cost;
        ans+=v;
        nx=x1;
        ny=y1;
        first=false;
    }
    cout<<ans<<endl;
}