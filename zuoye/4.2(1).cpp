#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class complex{
public:
	complex();
	complex(double real, double imag);
	void display();
	void input();
	double magnitude();
private:
	double real;
	double imag;
};
complex::complex():real(1.0),imag(1.0){}
complex::complex(double real1,double imag1):real(real1),imag (imag1){}
double complex::magnitude(){
	return 	sqrt(real*real + imag*imag)	 ;
}
void complex::display()	   {
    if(imag>0){
	    cout << fixed<<setprecision(2)<<real << "+" << imag << "i" ;
    }
    else if(imag==0){
        cout<<fixed<<setprecision(2)<<real;
    }
    else{
        cout <<fixed<<setprecision(2)<< real << imag << "i";
    }
}
void  complex::input()	{
	cin>>real>>imag;
}
int main()
{
    complex val1,val2,val3(1.5,2.8);
    val1.input();
    val1.display();
    cout<<"  "<<val1.magnitude()<<endl;
    val2.display();
    cout<<"  "<<val2.magnitude()<<endl;
    val3.display();
    cout<<"  "<<val3.magnitude()<<endl;
    return 0;  
}
