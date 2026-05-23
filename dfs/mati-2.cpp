/*
你有 n 个点，m 条边。
每条边要选它的两个端点中的一个，分配给这个点。
分配结束后，每个点有一个“被分配到的边的数量”，如果这个数量是奇数，它就是“优秀点”。

问：最多能让多少个点成为优秀点
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>arr[N+1];
int n,m;
int cntnode,cntbian;
bool vis[N+1];
void dfs(int x,int &cntnode,int &cntbian){
    vis[x]=true;
    cntnode++;
    cntbian+=arr[x].size();
    for(int i=0;i<arr[x].size();i++){
        if(vis[arr[x][i]])continue;
        dfs(arr[x][i],cntnode,cntbian);
    }
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x,v;
        cin>>x>>v;
        arr[x].push_back(v);
        arr[v].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cntnode=0;
            cntbian=0;
            dfs(i,cntnode,cntbian);
            cntbian/=2;//因为每条边都被加了两遍，两个端点
        
            if(cntnode<=cntbian&&cntnode%2==cntbian%2){
               ans+=cntnode;
           }
           else ans+=cntnode-1;
        }
    }
    cout<<ans;
    return 0;
}





/*对于每个连通块，如果它边数 ≥ 点数 且 奇偶相同，就加上所有点；否则加上点数−1，最后把这些加起来。
推导过程
每条边恰好分配给一个端点，所以：x1+x2​+⋯+xn=m。右边m的奇偶性正是我们关心的
如果点x上的边数是偶数 → 它对总和的奇偶性贡献 0（因为偶数 mod 2 = 0）
如果是奇数 → 它对总和的奇偶性贡献 1（因为奇数 mod 2 = 1）
(x1 mod 2)+(x2 mod 2)+......+(xv mod 2)==m mod 2;
奇数点数量k 的奇偶性 = 总的被分配边数m 的奇偶性
如果dfs出奇偶不同则需要对总的节点-1，以此控制奇数点与m奇偶性相同
*/