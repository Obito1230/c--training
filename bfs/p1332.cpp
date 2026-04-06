#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,tx,ty;
struct zuobiao{
    int x;
    int y;
};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int mp[505][505];
queue<zuobiao>q;//利用多源bfs同时入队，避免TLE！！！
vector<zuobiao>lingzhu;
void bfs(){
    while (!q.empty()){
        zuobiao temp;
        temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int na=temp.x+dx[i];
            int nb=temp.y+dy[i];
            if(na<1||na>n||nb<1||nb>m)
                continue;
            if(mp[na][nb]!=-1)//bfs时首次被访问的一定是最小的，不要再加多余判断！！！bfs在处理以访问过的点时，如果可能会重复回头，造成MLE！！！
                continue;
            mp[na][nb]=mp[temp.x][temp.y]+1;
            q.push({na,nb});
        }
    }
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(mp,-1,sizeof(mp));//定义-1为未访问过
    cin>>n>>m>>a>>b;
    for(int i=0;i<a;i++){
        cin>>tx>>ty;
        mp[tx][ty]=0;//感染者为0
        q.push({tx,ty});//检测到直接入队，省空间
    }
    for(int i=0;i<b;i++){
        zuobiao temp;
        cin>>temp.x>>temp.y;
        lingzhu.push_back(temp);//这里推荐用数组，感觉重复使用vector会浪费时间
    }
    bfs();
    for(int i=0;i<lingzhu.size();i++){
        cout<<mp[lingzhu[i].x][lingzhu[i].y]<<endl;
    }
    return 0;
}