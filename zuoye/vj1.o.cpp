#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int mp[1005][1005];
int qianzhui[1005][1005];
int main (){
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            qianzhui[i][j]=mp[i][j]+qianzhui[i-1][j]+qianzhui[i][j-1]-qianzhui[i-1][j-1];
        }
    }
    int xans,yans;
    int maxans=INT_MIN;
    for(int i=1;i<=n-c+1;i++){
        for(int j=1;j<=m-c+1;j++){
            int temp=qianzhui[i+c][j+c]-qianzhui[i-1][j+c]-qianzhui[i+c][j-1]+qianzhui[i-1][j-1];
            maxans=max(maxans,temp);
            if(maxans==temp){
                xans=i;
                yans=j;
            }
        }
    }
    cout<<xans<<" "<<yans;
}