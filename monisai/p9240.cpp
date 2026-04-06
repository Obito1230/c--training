#include<bits/stdc++.h>
using namespace std;
struct arr{
    int a;
    int b;
    int c;
};
arr ans[10005];
bool compare(arr x,arr y){
    return x.c<y.c;
}
int n;
int main (){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ans[i].a>>ans[i].b;
        ans[i].c=ans[i].a/ans[i].b;
    }
    sort(ans,ans+n,compare);
    int max=ans[0].c;
    for(int i=0;i<n;i++){
        ans[i].b++;
        ans[i].c=ans[i].a/ans[i].b;
    }
    sort(ans,ans+n,compare);
    int min=ans[n-1].c+1;
    cout<<min<<" "<<max;
    return 0;
}