#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd (ll a,ll b){
    a=abs(a);
    b=abs(b);//实现处理负数
    ll temp;
    while(b>0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
class fraction{
    public:
    fraction ();
    fraction (ll a,ll b);
    fraction operator+(const fraction &a)const;
    fraction operator-(const fraction &a)const;
    fraction operator*(const fraction &a)const;
    fraction operator/(const fraction &a)const;
    void yuefen();
    void input();
    void output();
    private:
    ll fenzi;
    ll fenmu;
};
void fraction::yuefen(){
    ll temp=gcd(fenzi,fenmu);
    fenzi/=temp;
    fenmu/=temp;
}
fraction ::fraction(){
    fenzi=0;
    fenmu=1;
}
fraction::fraction(ll a,ll b){
    fenzi=a;
    fenmu=b;
}
fraction fraction::operator+(const fraction &a)const{
    fraction ans,ans1;
    ans=*this;
    ans1=a;
    ll temp=lcm(ans.fenmu,a.fenmu);
    ans.fenmu=temp;
    ans.fenzi=fenzi*(temp/fenmu);
    ans1.fenzi=a.fenzi*(temp/a.fenmu);
    ans.fenzi+=ans1.fenzi;
    ans.yuefen();
    return ans;
}
fraction fraction::operator-(const fraction &a)const{
    fraction ans,ans1;
    ans=*this;
    ans1=a;
    ll temp=lcm(ans.fenmu,a.fenmu);
    ans.fenmu=temp;
    ans.fenzi=fenzi*(temp/fenmu);
    ans1.fenzi=a.fenzi*(temp/a.fenmu);
    ans.fenzi-=ans1.fenzi;
    ans.yuefen();
    return ans;
}
fraction fraction::operator*(const fraction &a)const{
    fraction ans=*this;
    ans.fenmu*=a.fenmu;
    ans.fenzi*=a.fenzi;
    ans.yuefen();
    return ans;
}
fraction fraction::operator/(const fraction &a)const{
    fraction ans=*this;
    ans.fenmu*=a.fenzi;
    ans.fenzi*=a.fenmu;
    ans.yuefen();
    return ans;
}
void fraction::input(){
    ll tfenzi,tfenmu;
    cin>>tfenzi>>tfenmu;
    fenzi=tfenzi;
    fenmu=tfenmu;
}
void fraction::output(){
    if(fenmu!=1&&fenzi!=0){
        cout<<fenzi<<"/"<<fenmu;
    }
    else if(fenmu==1){
        cout<<fenzi;
    }
    else if(fenzi==0){
        cout<<0;
    }
    cout<<endl;
}
int main()
{
    fraction x1, x2(2, 7), x3, y1, y2, z1, z2, z3, z4, z5;
    x3.input();
    y1.input();
    y2.input();
    z1 = x3 + y1;
    z1.output();
    z2 = x3 - y1;
    z2.output();    
    z3 = x3*y2;
    z3.output();    
    z4 = x3 / y2;
    z4.output();    
    z5 = x1 + x2;
    z5.output();
    return 0;
}
