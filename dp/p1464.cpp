//记忆化搜索
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
ll dp[25][25][25];
ll solve(int a,int b,int c){
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return solve(20,20,20);
    if(a<b&&b<c){
        if(!dp[a][b][c-1])//是否有记忆
        dp[a][b][c-1]=solve(a,b,c-1);
        if(!dp[a][b-1][c-1])
        dp[a][b-1][c-1]=solve(a,b-1,c-1);
        if(!dp[a][b-1][c])
        dp[a][b-1][c]=solve(a,b-1,c);
        dp[a][b][c]=dp[a][b][c-1]+dp[a][b-1][c-1]+dp[a][b-1][c];
    }
    else{
        if(!dp[a-1][b][c])//同上
        dp[a-1][b][c]=solve(a-1,b,c);
        if(!dp[a-1][b-1][c])
        dp[a-1][b-1][c]=solve(a-1,b-1,c);
        if(!dp[a-1][b][c-1])
        dp[a-1][b][c-1]=solve(a-1,b,c-1);
        if(!dp[a-1][b-1][c-1])
        dp[a-1][b-1][c-1]=solve(a-1,b-1,c-1);
        dp[a][b][c]=dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
    }
    return dp[a][b][c];
}
int main (){
    while (1){
        cin>>a>>b>>c;
        if(a==b&&b==c&&c==-1)break;
        else {
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<solve (a,b,c);
        }
        cout<<endl;
    }
    return 0;
}