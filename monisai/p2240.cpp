#include<bits/stdc++.h>
using namespace std;
int n,t;
struct baozang{
    double m;
    double v;
    double jiazhi;
};
baozang dong[105];
bool compare(const baozang & a,const baozang & b){
    return a.jiazhi>b.jiazhi;
}
double ans=0.0;
int main (){
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>dong[i].m>>dong[i].v;
        dong[i].jiazhi=dong[i].v/dong[i].m;
    }
    sort(dong,dong+n,compare);
    for(int i=0;i<n;i++){
        if(t>=dong[i].m){
            ans+=dong[i].v;
            t-=dong[i].m;
        }
        else{
            ans+=t*dong[i].jiazhi;
            t-=t;
        }
        if(t==0)break;
    }
    printf("%.2f",ans);
}