#include<bits/stdc++.h>
using namespace std;
int n;
int main (){
    cin>>n;
    int *p;
    p=new int [n];
    for(int i=0;i<n;i++){
        cin>>*(p+i);
    }
    cout<<"a["<<n<<"]={";
    for(int i=0;i<n-1;i++){
        cout<<*(p+i)<<",";
    }
    cout<<*(p+n-1)<<"}";
    cout<<endl;
    for(int i=0;i<n;i++){
        int temp;
        temp=*(p+i);
        if(temp<0){
            *(p+i)=0;
        }
    }
    cout<<"a["<<n<<"]={";
    for(int i=0;i<n-1;i++){
        cout<<*(p+i)<<",";
    }
    cout<<*(p+n-1)<<"}";
    cout<<endl;
    delete []p;
    return 0;
}