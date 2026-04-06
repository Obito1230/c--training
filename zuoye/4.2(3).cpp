#include<bits/stdc++.h>
using namespace std;
int mon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
class Date{
    public:
    Date(int year,int month,int day);
    void assign(int year1, int month1, int day1);
    void display();
    bool leap_year();
    void increment();
    void increment(int n);
    private:
    int year;
    int month;
    int day;
};
Date::
Date(int year1=2008,int month1=1,int day1=1):
year(year1),month(month1),day(day1){}
void Date::assign(int year1, int month1, int day1){
    year=year1;
    month=month1;
    day=day1;
}
void Date::display(){
    cout<<year<<"-"<<month<<"-"<<day<<endl;
}
bool Date::leap_year(){
    if(year%4==0&&year%100!=0)return true;
    else if(year%400==0)return true;
    else return false;
}
void Date::increment(){
    if(leap_year()){
        mon[2]=29;
        day++;
        if(day>mon[month]){
            day-=mon[month];
            month++;
        }
        if(month>12){
            month-=12;
            year++;
        }
    }
    else{
        mon[2]=28;
        day++;
        if(day>mon[month]){
            day-=mon[month];
            month++;
        }
        if(month>12){
            month-=12;
            year++;
        }
    }
}
void Date::increment(int n){
    day+=n;
    while(1){
        int days;
        if(leap_year())days=29;
        else days=28;
        if(month!=2)days=mon[month];
        if(day<days)break;
        day-=days;
        month++;
        if(month>12){
            month=1;
            year++;
        }
    }
}
int main()
{
    Date date1, date2(2016,5,1),date3;
    int n,day,month,year;
    date1.display();
    date2.display();
    cin>>year>>month>>day;
    date3.assign(year,month,day);
    date3.display();
    cin>>n;
    date3.increment(n);
    date3.display();
    return 0;
}