#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    student();
    void input();
    void display();
    string name;
    int age;
};
student::student(){
    name="";
    age=0;
}
void sortstu(student* s, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(s[j].age > s[j + 1].age) {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void student::input(){
    cin>>name>>age;
}
void student::display(){
    cout<<name<<" "<<age<<endl;
}
int main (){
    int n;
    cin>>n;
    student* arr;
    arr=new student[n];
    for(int i=0;i<n;i++){
        arr[i].input();
    }
    sortstu(arr,n);
    for(int i=0;i<n;i++){
        arr[i].display();
    }
    delete[]arr;
    return 0;
}