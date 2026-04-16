#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int temp;
    while(b>0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
class fraction{
    public:
    fraction();
    fraction(int a,int b);
    void output();
    void input();
    private:
    bool zheng;
    int fenzi;
    int fenmu;
};
fraction::fraction(){
    fenzi=0;
    fenmu=1;
}
fraction::fraction(int a,int b){
    fenzi=abs(a);
    fenmu=abs(b);
    if((a<0&&b>0)||(a>0&&b<0))zheng=false;
    else zheng=true;
}
void fraction::output(){
    if(fenzi==0){
        cout<<fenzi<<endl;
    }
    else{
        int gcdid=gcd(fenzi,fenmu);
        fenzi/=gcdid;
        fenmu/=gcdid;
        if(fenmu==1){
            if(!zheng){
               cout<<"-";
            }
           cout<<fenzi<<endl;
       }
       else {
           if(!zheng){
             cout<<"-";
           }
          cout<<fenzi<<"/"<<fenmu<<endl;
      }
    }
}
void fraction::input(){
    int a,b;
    cin>>a>>b;
    if(a<0&&b>0||a>0&&b<0)
    zheng=false;
    else zheng=true;
    fenzi=abs(a);
    fenmu=abs(b);
}
int main()
{
   int a, b;
   cin >> a >> b;
   fraction x1, x2(a,b);
   x1.output();
   x2.output();
   x2.input();
   x2.output();
   return 0;
}

