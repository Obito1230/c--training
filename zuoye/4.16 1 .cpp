#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    student();
    void display();
    static int count;
    static int total_age;
    private:
    string name;
    int age;
    int id;
};
student::student(){
    cin>>name>>age;
    id=count++;
    total_age+=age;
}
void student:: display(){
    cout<<id<<" "<<name<<" "<<age<<endl;
}
int student::count=1;
int student::total_age=0;

int main (){
    student s[5];
    float avg = 0.0;
    for(int i=0;i<5;i++)
    {
        s[i].display();
    }
    cout<<fixed<<setprecision(2)<<(double)student::total_age/5.0<<endl;
    return 0;
}

