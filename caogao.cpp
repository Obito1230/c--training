#include<bits/stdc++.h>
using namespace std;
class Date{
    public:
    Date();
    Date operator+(int days)const;
    Date operator*(int days)const;
    private:
    int year;
    int month;
    int day;
};
Date::Date(){
    year=0;
    month=0;
    day=0;
}
Date Date:: operator+(const int &days)const{
    Date temp;
    temp.day=day+days;
    return temp;
}
int main (){

}