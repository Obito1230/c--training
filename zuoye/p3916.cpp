#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int A[100005];
vector<int>arr[100005];
bool vis[100005];
void dfs(int u, int flag) {
    if (vis[u]) return;
    vis[u] = true;
    A[u] = max(A[u], flag);  
    for (int v : arr[u]) {
        dfs(v, flag);
    }
}
int main (){
    ios::sync_with_stdio;
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        A[i]=i;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        arr[b].push_back(a);//有向图
    }
    for (int i = n; i >= 1; i--) {//从后向前遍历，将所有能到达此值的数全部标记为此值
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << A[i]<< " " ;
    }
    return 0;
}