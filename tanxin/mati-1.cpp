/*
现在把这场杀局的“出手先后”抽作一份清单：你手里有三行同样长为n的正整数——可看作三种关键因素的强弱
•第一行为a1∼an：专诸出手的“劲力”；
接下来两行依次为b1~bn；c1~cn
你从这三行里各挑一个数，组成一个三元组（ai,bk,ck）这一套配合的“杀招分量”定义为它们的乘积
问其中值最小的前m个分别是多少（也就是第1小、第2小……直到第m小的乘积值）
*/
//贪心，小根堆，bfs，set判重
//小根堆
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int m,n;
struct node {
    ll val;
    int i,j,k;
    bool operator >(const node &temp)const{
        return val>temp.val;//小根堆
    }
};
struct state{
    int i,j,k;
    bool operator < (const state &temp)const{
        if(i!=temp.i)return i<temp.i;
        if(j!=temp.j)return j<temp.j;
        return k<temp.k;
    }
};
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll>a(n),b(n),c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        priority_queue<node,vector<node>,greater<node>>pq;//小根堆
        set <state>vis;
        pq.push({a[0]*b[0]*c[0],0,0,0});
        vis.insert({0,0,0});
        while(m--){
            node cur=pq.top();
            pq.pop();
            cout<<cur.val<<" ";
            int i=cur.i;
            int j=cur.j;
            int k=cur.k;
            if(i+1<n&&!vis.count({i+1,j,k})){
                pq.push({a[i+1]*b[j]*c[k],i+1,j,k});
                vis.insert({i+1,j,k});
            }
            if(j+1<n&&!vis.count({i,j+1,k})){
                pq.push({a[i]*b[j+1]*c[k],i,j+1,k});
                vis.insert({i,j+1,k});
            }
            if(k+1<n&&!vis.count({i,j,k+1})){
                pq.push({a[i]*b[j]*c[k+1],i,j,k+1});
                vis.insert({i,j,k+1});
            }
        }
        cout<<'\n';
    }
    return 0;
}