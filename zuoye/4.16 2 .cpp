#include<bits/stdc++.h>
using namespace std;
class dianti{
    public:
    void display();
    void yidong(char flag);
    dianti();
    private:
    int floor;
};
dianti::dianti(){
    floor=1;
}
void dianti::display(){
    cout<<"current floor:"<<floor<<endl;
}
void dianti::yidong(char flag){
    if(flag=='+'){
        if(floor<10){
        floor++;
            display();
        }
    }
    else if(flag=='-') {
        if(floor>1){
            floor--;
            display();
        }
    }
    else if(flag=='S'){
        while(floor!=1){
            floor--;
            display();
        }
    }
}
int main (){
    dianti arr;
    char flag;
    while(cin>>flag){
        arr.yidong(flag);
        if(flag=='S')break;
    }
    return 0;
}
