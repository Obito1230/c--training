#include<bits/stdc++.h>
using namespace std;
int arr[10];
int i;
int sum=0;
void fen(int x){
    i=1;
    while(x>0){
        arr[i]=x%10;
        x/=10;
        i++;
    }
}
bool check(int arr[]){
    int l=2;
    while(l<i){
       if(arr[l]!=arr[l-1])return false;
       l++;
    }
    return true;
}
int main (){
    int p;
    for(int k=0;k<=(20255202-45)/10;k++){
        memset(arr,0,sizeof(arr));
        int temp=k*10+45;
        fen(temp);
        if(check(arr)){
            sum+=temp;
        }
    }
    cout<<sum;
}