#include<bits/stdc++.h>
using namespace std;
int n,q,k,cnt=0,prime[6000000];
bool f[100000005];
int main (){
    scanf("%d%d",&n,&q);
    memset(f,1,sizeof(f));
    f[1]=f[0]=0;
    for(int i=2;i<=n;i++){
        if(f[i]) {
            prime[cnt]=i;
            cnt++;
        }
        for(int j=0;j<cnt&&prime[j]*i<=n;j++){
            f[prime[j]*i]=0;
            if(i%prime[j]==0)break;//只允许被最小质因子筛掉
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&k);
        printf("%d\n",prime[k-1]);
    }
}