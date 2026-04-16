#include<bits/stdc++.h>
using namespace std;
int N,A,B;
int arr[205];
bool vis[205];
int jishu[205];
void bfs(int lou){
    memset(jishu,-1,sizeof(jishu));
    queue<int>q;
    q.push(lou);
    vis[lou]=true;
    jishu[lou]=0;
    while(!q.empty()){
        int temp;
        temp=q.front();
        q.pop();
        if(temp==B){
            return ;
        }
        int a=temp+arr[temp];
        int b=temp-arr[temp];
        if(a>0&&a<=N&&!vis[a]){
            q.push(a);
            vis[a]=true;
            jishu[a]=jishu[temp]+1;
        }
        if(b>0&&b<=N&&!vis[b]){
            q.push(b);
            vis[b]=true;
            jishu[b]=jishu[temp]+1;
        }
    }
}
int main (){
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    bfs(A);
    cout<<jishu[B];
    return 0;
}