#include<bits/stdc++.h>
using namespace std;
class matrix{
    public:
    matrix(int m,int n);
    int  at(int i);
    int  at(int i,int j);
    int sum();
    private:
    int hang;
    int lie;
    int juzhen[12][12];
};
matrix::matrix(int m,int n){
    int count=1;
    hang=m;
    lie=n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            juzhen[i][j]=count++;
        }
    }
}
int  matrix::at(int i){
    int hangt=1;
    int liet=i;
    return juzhen[hangt][liet];
}
int matrix::sum(){
    int sum=0;
    for(int i=1;i<=hang;i++){
        for(int j=1;j<=lie;j++){
            sum+=juzhen[i][j];
        }
    }
    return sum;
}
int  matrix::at(int i,int j){
    return juzhen[i][j];
}
int main()
{
    int rowNum,colNum;
    cin>>rowNum>>colNum;
    matrix mat(rowNum,colNum);
    cout<<mat.at(4)<<' '<<mat.at(3,4)<<' '<<mat.sum();
}
