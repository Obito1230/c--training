//贪心+模拟
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,w;
struct qingkuang{
    ll f;
    ll a;
};
qingkuang arr[1000005];
bool compare(const qingkuang &x,const qingkuang &y){
    return x.f<y.f;
}
int main (){
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x>>y>>w;
    for(int i=0;i<n;i++){
        cin>>arr[i].f>>arr[i].a;
    }
    sort(arr,arr+n,compare);
    ll firstf=-1;//定义为-1，在循环中找到第一次的楼层
    ll cnt;
    ll weizhi=w;//保证在第一次时电梯里没人
    for(ll i=0;i<n;i++){
        ll louceng=arr[i].f;
        ll ren=arr[i].a;
        if(ren<=0)continue;
        if(weizhi<w){
            ll temp=min(weizhi,ren);//看看位置和该楼层的人哪个多
            weizhi-=temp;
            ren-=temp;
            if(weizhi==0)weizhi=w;//如果位置满了，则重置位置
        }
        if(ren==0)continue;
        if(ren>=w){
            ll ci=ren/w;
            ll laihui=2*(y-louceng);//一来一回，一开始默认从顶到选中的楼层，循环完之后再减去即可（y→楼层→y）
            cnt+=ci*laihui;
            if(firstf==-1)
                firstf=louceng;
            ren-=ci*w;
        }
        if(ren>0){
            cnt+=2*(y-louceng);
            if(firstf==-1)
                firstf=louceng;
            weizhi=w-ren;//看载完这一层的人有没有空位置，如果有的话就往上走带人
            ren=0;
        }
    }
    if(firstf<=x){
        cnt=cnt-(y-x);//减去多走的
    }
    else if(firstf>x){
        cnt=cnt-(y-firstf)+(firstf-x);//减去多走的，加上少走的
    }
    cout<<cnt;
    return 0;
}