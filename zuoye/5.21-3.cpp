#include<bits/stdc++.h>
using namespace std;
class stu{
    public:
    stu(){
        cin>>name>>age>>score;
    }
    void display(){
        cout<<name<<" "<<age<<" "<<score;
    }

    string name;
    int age;
    int score;
};
bool cmp(stu a,stu b){
    return a.score>b.score;
}
class team{
    public:
    team(){};
    void display(){
        for(int i=0;i<3;i++){
            arr[i].display();
            cout<<endl;
        }
    }
    void top(){
        sort(arr,arr+3,cmp);
        arr[0].display();
        cout<<endl;
    }
    float average(){
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=arr[i].score;
        }
        float ans=sum/3.0;
        return ans;
    }
    private:
    stu arr[3];
};
int main()
{
    team t1;
    cout << "Team information:" << endl;
    t1.display();
    cout << "Top student information:" << endl;
    t1.top();
    cout << "Average score:" << endl;
    cout << fixed << setprecision(2);
    float avg = t1.average();
    cout << avg << endl;
    return 0;
}