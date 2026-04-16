#include<bits/stdc++.h>
using namespace std;
int a,b,c,k,t;
int main (){
    cin>> t;
    while(t--){
        cin>>a>>b>>c>>k;
        while(k){
            int ta=a;
            int tb=b;
            int tc=c;
            a=(floor)((double)(tb+tc)/2);
            b=(floor)((double)(ta+tc)/2);
            c=(floor)((double)(tb+ta)/2);
            if(a==b&&b==c)break;
            k--;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}