#include<bits/stdc++.h>
using namespace std;
int n;double p;
struct shebei{
    double a;
    double b;
};
double sum=0;
shebei arr[100005];
bool check(double x){
    double flag;
    double sump=p*x;
    for(int i=0;i<n;i++){
        flag=max(0.0,arr[i].a*x-arr[i].b);
        sump-=flag;
        if(sump<-1e-8)return false;
    }
    return true;
}
int main (){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b;
        sum+=arr[i].a;
    }
    if(sum<p){
        cout<<-1<<endl;
        return 0;
    }
    else{
        double l=0,r=10000005;
        while(l+1e-8<r){
            double mid=(l+r)/2;
            if(check(mid)){
                l=mid;
            }
            else{
                r=mid;
            }
        }

        if(check(r))cout<<fixed<<setprecision(10)<<r<<endl;
        cout<<setprecision(10)<<l<<endl;
    }
    return 0;
}