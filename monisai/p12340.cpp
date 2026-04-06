#include<bits/stdc++.h>
using namespace std;
int h,w;
int pian,zhen;
string arr="LANQIAO";
int cnt=0;
int main (){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        zhen=0;
        pian=i%7;
        for(int j=0;j<w;j++){
            zhen=(j+pian)%7;
            if(arr[zhen]=='A')
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}