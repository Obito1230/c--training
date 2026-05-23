//回文字符串，中心拓展法
#include<bits/stdc++.h>
using namespace std;
int sum=0;
int main (){
    string arr,arr1;
    cin>>arr;
    for(int i=0;i<arr.size();i++){
        int l=i,r=i;
        while(l>=0&&r<arr.size()){
            if(arr[l]==arr[r]){
                sum++;
                l--,r++;
            }
            else{
                break;
            }
        }
    }
    for(int i=0;i<arr.size();i++){
        int l=i,r=i+1;
        while(l>=0&&r<arr.size()){
            if(arr[l]==arr[r]){
                sum++;
                l--,r++;
            }
            else{
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}