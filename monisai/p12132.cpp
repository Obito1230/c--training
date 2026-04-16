//除了-1和1以外都可以被分解
//观察数据可知，肯定不能暴力
#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    int cnt;
    while(n--){
        int temp=0;
        cin>>temp;
        if(temp!=1)cnt++;
    }
    cout<<cnt;
}//观察力惊人