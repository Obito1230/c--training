#include<bits/stdc++.h>
using namespace std;
int n,k;
int qianzhuihe=0;
int yu[1005];
int cnt=0;
int main (){
    cin>>n>>k;
    yu[0]++;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        qianzhuihe+=temp;
        qianzhuihe%=k;
        cnt+=yu[qianzhuihe];
        yu[qianzhuihe]++;
    }
    cout<<cnt;
}