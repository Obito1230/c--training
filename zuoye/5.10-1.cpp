#include<bits/stdc++.h>
using namespace std;
class time24{
    public:
    time24 operator+ (const int& t)const;
    time24 operator++ ();
    time24 operator++(int);
    bool operator==(const time24 t)const{
        return (hours==t.hours&&minutes==t.minutes&&seconds==t.seconds);
    }
    void set_time(int a,int b,int c);
    void display();
    void get_time(int &h,int &m,int &s);
    void input();

    private:
    int hours;
    int minutes;
    int seconds;
};
time24 time24::operator+(const int& x)const{
    time24 temp;
    temp.seconds=seconds+x;
    temp.minutes=temp.seconds/60+minutes;
    temp.seconds%=60;
    temp.hours=temp.minutes/60+hours;
    temp.minutes%=60;
    temp.hours%=24;
    return temp;
} 
time24 time24::operator++(){
    return *this+1;
}
time24 time24::operator++(int){
    time24 temp;
    temp=*this;
    *this=*this+1;
    return temp;
}
void time24::set_time(int a,int b ,int c){
    hours=a;
    minutes=b;
    seconds=c;
}
void time24::get_time(int &h,int &m,int &s){
    h=hours;
    m=minutes;
    s=seconds;
}
void time24::display(){
    int h1,m1,s1;
    get_time(h1,m1,s1);
    printf("%02d:%02d:%02d\n",h1,m1,s1);
}
istream &operator >>(istream &is, time24 &t){
    int h,m,s;
    is>>h>>m>>s;
    t.set_time(h,m,s);
    return is;
}
void time24::input(){
    cin>>*this;
}
int main()
{
    cin.tie(0);
    time24 t1, t2, t3, t4;
    t1.input();
    t2 = t1 + 4;
    t3 = t1++;
    t4 = ++t1;
    if (t3 == t4)
        cout << "t3 == t4" << endl;
    else
        cout << "t3 != t4" << endl;
    t2.display();
    t3.display();
    t4.display();
    return 0;
}