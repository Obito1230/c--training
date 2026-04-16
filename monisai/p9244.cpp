#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main (){
    int k;
    cin>>k;
    string arr;
    char c1,c2;
    cin>>arr>>c1>>c2;
    int j;
    for(int i=0;i<arr.size()-k;i++){
        for(j=i+k-1;j<arr.size();j++){
            if(arr[i]==c1&&arr[j]==c2)cnt++;
        }
    }
    cout<<cnt;
}//效率太低过不了。
//可以选择同时向后枚举i和j，遇到c1则cnt++，遇到c2则+=cnt。