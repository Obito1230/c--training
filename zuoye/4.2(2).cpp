#include<bits/stdc++.h>
using namespace std;
class rectangle {
    public :
    rectangle();
    rectangle(double lenth1,double width1);
    void assign(double a,double b);
    double circumference();
    double area();
    void show();
    private:
    double length;
    double width;
};
rectangle::rectangle():length(0.0),width(0.0){}
rectangle::rectangle(double lenth1,double width1):length(lenth1),width(width1){}
void rectangle:: assign(double a,double b){
    if(a<b){
        swap(a,b);
    }
    length=a;
    width=b;
}
double rectangle::circumference(){
    return length*2+width*2;
}
double rectangle::area(){
    return length*width;
}
void rectangle::show(){
    cout<<fixed<<setprecision(2)<<length<<","<<width<<",";
}
int main (){
    rectangle c1,c2(2.0,1.0),c3;
    double x,y;
    cin>>x>>y;
    c1.show();
    cout<<c1.circumference()<<","<<c1.area()<<endl;
    c2.show();
    cout<<c2.circumference()<<","<<c2.area()<<endl;
    c3.assign(x,y);
    c3.show();
    cout<<c3.circumference()<<","<<c3.area()<<endl;
    return 0;
}