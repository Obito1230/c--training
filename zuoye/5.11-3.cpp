#include<bits/stdc++.h>
using namespace std;
class matrix{
    public:
    matrix ();
    matrix(int m,int n);
    ~matrix();
    matrix &operator=(const matrix& a);
    matrix(const matrix &temp);
    void set_(const int &a,const int &hang,const int &lie);
    void get_1(int &a,int &b)const;
    int get_cout(const int &thang,const int &tlie)const;
    matrix operator+(const matrix & a)const;
    matrix operator-(const matrix & a)const;
    private:
    int hang ;
    int lie;
    int **data;
};
matrix ::matrix(){
    hang =0;
    lie = 0;
    data=NULL;
}
matrix ::~matrix(){
    if(data!=NULL){
       for(int i=0;i<hang;i++){
          delete[]data[i];
        }
        delete []data;
        data=NULL;
    }
}
matrix::matrix(int m,int n){
    hang=m;
    lie=n;
    data=new int* [hang];
    for(int i=0;i<m;i++){
        data[i]=new int[lie];
        for(int j=0;j<lie;j++){
            data[i][j]=0;
        }
    }
}
matrix &matrix::operator=(const matrix &a){
    if(this!=&a){
        if(data!=NULL){
            for(int i=0;i<hang;i++){
                delete *(data+i);
            }
            delete []data;
            data=NULL;
        }
        hang=a.hang;
        lie=a.lie;
        data=new int *[hang];
        for(int i=0;i<hang;i++){
            data[i]=new int [lie];
            for(int j=0;j<lie;j++){
                data[i][j]=a.data[i][j];
            }
        }
    }
    return *this;
} 
matrix ::matrix (const matrix &temp){
    hang=temp.hang;
    lie=temp.lie;
    if(hang==0||lie==0){
        data=NULL;
    }
    else{
        data=new int *[hang];
        for(int i=0;i<hang;i++){
            data[i]=new int [lie];
            for(int j=0;j<lie;j++){
               data[i][j]=temp.data[i][j];
            }
        }
    }
}
void matrix::set_(const int &a,const int &thang,const int &tlie){
    data[thang][tlie]=a;
}
void matrix::get_1(int &a,int &b)const{
    a=hang;
    b=lie;
}
int matrix::get_cout(const int &thang,const int &tlie)const{
    return data[thang][tlie];
}
istream& operator>>(istream& is,matrix &temp){
    int val,thang,tlie;
    temp.get_1(thang,tlie);
    for(int i=0;i<thang;i++){
        for(int j=0;j<tlie;j++){
            is>>val;
            temp.set_(val,i,j);
        }
    }
    return is;
}
ostream& operator<<(ostream& os, const matrix &ans){
    int val,thang,tlie;
    ans.get_1(thang,tlie);
    for(int i=0;i<thang;i++){
        for(int j=0;j<tlie;j++){
            val=ans.get_cout(i,j);
            os<<val<<" ";
        }
        os<<endl;
    }
    return os;
}
matrix matrix::operator+(const matrix &a)const{
    matrix temp=*this;
    for(int i=0;i<hang;i++){
        for(int j=0;j<lie;j++){
            temp.data[i][j]+=a.data[i][j];
        }
    }
    return temp;
}
matrix matrix::operator-(const matrix&a)const{
    matrix temp=*this;
    for(int i=0;i<hang;i++){
        for(int j=0;j<lie;j++){
            temp.data[i][j]-=a.data[i][j];
        }
    }
    return temp;
}
int main()
{
    int m, n;
    cin >> m >> n;
    matrix mat1(m, n), mat2(m, n), mat3, mat4;
    cin >> mat1 >> mat2;
    mat3 = mat1 + mat2;
    cout << mat3;
    mat4 = mat1 - mat2;
    cout << mat4;
    return 0;
}

