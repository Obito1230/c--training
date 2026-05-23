#include<bits/stdc++.h>
using namespace std;
class goods{
    public:
    goods(){
        cin>>num>>name;
    }
    void display(){
        cout<<"goodsID="<<num<<" goodsName="<<name;
    }
    private:
    int num;
    string name;
};
class foods :public goods{
    public:
    foods(){
        cin>>days;
    }
    void display(){
        goods::display();
        cout<<" days="<<days;
        cout<<endl;
    }
    private:
    int days;
};
int main()
{
 class goods goods1;
 goods1.display();
 cout<<endl;
 class foods foods1;
 foods1.display();
 cout<<endl;
 return 0;
}