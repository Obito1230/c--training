#include<bits/stdc++.h>
using namespace std;
int m,n;
int main (){
    cin>>m>>n;
    int **a=new int *[m];
    int **b=new int *[m];
    int **ans=new int *[m];
    for(int j=0;j<m;j++){
        *(a+j)=new int [n];
        *(b+j)=new int [n];
        *(ans+j)=new int [n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>*(*(a+i)+j);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>*(*(b+i)+j);
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            *(*(ans+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        cout<<*(*(ans+i)+j)<<" ";
        cout<<endl;
    }
    for(int j=0;j<m;j++){
        delete []*(a+j);
        delete []*(b+j);
        delete []*(ans+j);
    }
    delete []a;
    delete []b;
    delete []ans;
    return 0;
}