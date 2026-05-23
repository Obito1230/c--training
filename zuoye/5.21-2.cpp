#include<bits/stdc++.h>
using namespace std;
class vehicle{
    public:
    vehicle(int a,string b):num(a),name(b){}
    void display(){
        cout<<"vehicleID="<<num<<" vehicleName="<<name;
    }
    private:
    int num;
    string name;
};
class bike:public vehicle{
    public:
    bike(int a,string b,int c):vehicle(a,b),weight(c){}
    void display(){
        vehicle::display();
        cout<<" weight="<<weight;
        cout<<endl;
    }
    private:
    int weight;
};

int main()
{
 int ID;
 string name;
 int weight;

 cin>>ID>>name;

 class vehicle vehicle1(ID,name);
 vehicle1.display();
 cout<<endl;
 cin>>ID>>name>>weight;
 class bike bike1(ID,name,weight);
 bike1.display();
 cout<<endl;

    return 0;
}