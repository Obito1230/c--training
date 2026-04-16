#include<bits/stdc++.h>
using namespace std;
int main (){
    double r=sqrt(233*233+666*666);
    double hudu=atan(double(666)/233);
    cout<<(int)(hudu*r+r);
}
//牢记数学函数atan，然后弧度乘以半径等于弧长。atan求出来的直接就是弧度。
//本题不能以曲代直的根本原因是圆弧被限制了必须以原点为圆心