#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
class Complex{
public:
	Complex operator+(const Complex &a)const;
	Complex operator-(const Complex &b)const;
	void setReal(double realVal);
	void setImag(double imagVal);
	void getReal(){
		cout << real << endl;
	}
	void getImag(){
		cout << imaginary << endl;
	}
	bool operator==(const Complex &a)const{
		return (real == a.real&&imaginary == a.imaginary);
	}
	bool operator!=(const Complex &a)const{
		return (real != a.real || imaginary != a.imaginary);
	}
	bool operator>(const Complex &a)const{
		double ans1, ans2;
		ans1 = sqrt(pow(real, 2) + pow(imaginary, 2));
		ans2 = sqrt(pow(a.real, 2) + pow(a.imaginary, 2));
		return ans1 - ans2>-1e-6;
	}
	bool operator<(const Complex &a)const{
		double ans1, ans2;
		ans1 = sqrt(pow(real, 2) + pow(imaginary, 2));
		ans2 = sqrt(pow(a.real, 2) + pow(a.imaginary, 2));
		return ans1 - ans2<-1e-6;
	}
	void set_complex(double a, double b){
		real = a;
		imaginary = b;
	}
	void get_complex(double &a, double &b) const{
		a = real;
		b = imaginary;
	}
	void input();
	void display();
private:
	double real;
	double imaginary;
};
istream &operator>>(istream &is, Complex &t){
	double real1, imag;
	char c1, c2;
	is >> real1 >> c1 >> imag >> c2;
	if (c1 == '-')imag = -imag;
	t.set_complex(real1, imag);
	return is;
}
ostream &operator<<(ostream &os, const Complex &t){
	double a, b;
	t.get_complex(a, b);
	if (a != 0 && b>0)
		os << fixed << setprecision(2) << a << "+" << b << "i" << endl;
	else if (a != 0 && b == 0)
		os << fixed << setprecision(2) << a << endl;
	else if (a != 0 && b<0)
		os << fixed << setprecision(2) << a << b << "i" << endl;
	else if (a == 0 && b != 0)
		os << fixed << setprecision(2) << b << "i" << endl;
	else
		os << fixed << setprecision(2) << a << endl;
	return os;
}
void Complex::input(){
	cin >> *this;
}
void Complex::display(){
	cout << *this;
}
void Complex::setReal(double realVal){
	real = realVal;
}
void Complex::setImag(double imagVal){
	imaginary = imagVal;
}
Complex Complex::operator+(const Complex&a)const{
	Complex t;
	t.real = real + a.real;
	t.imaginary = imaginary + a.imaginary;
	return t;
}
Complex Complex::operator-(const Complex &a)const{
	Complex t;
	t.real = real - a.real;
	t.imaginary = imaginary - a.imaginary;
	return t;
}
int main()
{
	Complex c1, c2, c3, c4, c5;
	cin >> c1 >> c2;
	c3 = c1 + c2;
	c4 = c1 - c2;
	if (c3 != c4)
	{
		if (c3 < c4)
		{
			cout << "c3 is less than c4";
			c5 = c4 - c3;
		}
		if (c3 > c4)
		{
			cout << "c3 is greater than c4";
			c5 = c3 - c4;
		}
	}
	if (c3 == c4)
	{
		cout << "c3 and c4 are equal";
		c5 = c4;
	}
	cout << endl;
	cout << c5;
	return 0;
}

