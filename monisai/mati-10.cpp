#include<bits/stdc++.h>
using namespace std;
int n,k;
int main (){
    priority_queue<int>pq;
    cin>>n>>k;
    while(n--){
        int temp;
        cin>>temp;
        pq.push(temp);
    }
    while(k--){
        int a;
        a=pq.top();
        pq.pop();
        a=(int)(floor)(a/2.0);
        pq.push(a);
    }
    long long sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
    return 0;
}