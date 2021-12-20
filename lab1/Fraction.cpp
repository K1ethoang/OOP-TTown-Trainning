#include <iostream>
#include <fstream>
using namespace std;

class Fraction
{
private:
    int numerator, denominator; // tu so, mau so

public:
    Fraction();
    Fraction(const int &numerator_, const int &denominator_);
    // void input();
    // void output();

    // nạp chồng toán tử //
    friend istream &operator>>(istream &is, Fraction &obj);
    friend ostream &operator<<(ostream &os, Fraction obj);
    Fraction operator+(Fraction obj);
    Fraction operator-(Fraction obj);
    Fraction operator*(Fraction obj);
    Fraction operator/(Fraction obj);
};

int main()
{
    Fraction a, b, c;

    cout << "\n\tNhap phan so a" << endl;
    cin >> a;
    cout << "\n\tNhap phan so obj" << endl;
    cin >> b;

    cout << "\n\t2 Phan so vua nhap" << endl;
    cout << a;
    cout << b;

    cout << "\n\n\t\tPhep cong" << endl;
    c = a + b;
    cout << c;

    cout << "\n\n\t\tPhep tru" << endl;
    c = a - b;
    cout << c;

    cout << "\n\n\t\tPhep nhan" << endl;
    c = a * b;
    cout << c;

    cout << "\n\n\t\tPhep chia" << endl;
    c = a / b;
    cout << c;
    return 0;
}

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(const int &numerator_, const int &denominator_)
    : numerator(numerator_), denominator(denominator_) {}

// void Fraction::input()
// {
//     cout << "\nNhap tu so: ";
//     cin >> this->numerator;
//     cout << "\nNhap mau so: ";
//     cin >> this->denominator;
// }

istream &operator>>(istream &is, Fraction &obj)
{
    cout << "\nNhap tu so: ";
    is >> obj.numerator;
    cout << "\nNhap mau so: ";
    is >> obj.denominator;
    return is;
}

// void Fraction::output()
// {
//     cout << this->numerator << "/" << this->denominator << endl;
// }

ostream &operator<<(ostream &os, Fraction obj)
{
    cout << obj.numerator << "/" << obj.denominator << endl;
    return os;
}
Fraction Fraction::operator+(Fraction obj)
{
    Fraction c;
    if (this->denominator == obj.denominator)
    {
        c.numerator = this->numerator + obj.numerator;
        c.denominator = this->denominator;
    }
    else
    {
        c.numerator = this->numerator * obj.denominator + obj.numerator * this->denominator;
        c.denominator = this->denominator * obj.denominator;
    }
    return c;
}

Fraction Fraction::operator-(Fraction obj)
{
    Fraction c;
    if (this->denominator == obj.denominator)
    {
        c.numerator = this->numerator + obj.numerator;
        c.denominator = this->denominator;
    }
    else
    {
        c.numerator = this->numerator * obj.denominator - obj.numerator * this->denominator;
        c.denominator = this->denominator * obj.denominator;
    }
    return c;
}

Fraction Fraction::operator*(Fraction obj)
{
    Fraction c;
    c.numerator = this->numerator * obj.numerator;
    c.denominator = this->denominator * obj.denominator;
    return c;
}

Fraction Fraction::operator/(Fraction obj)
{
    Fraction c;
    c.numerator = this->numerator * obj.denominator;
    c.denominator = this->denominator * obj.numerator;
    return c;
}