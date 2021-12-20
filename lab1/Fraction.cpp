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
    void input();
    void output();

    // nạp chồng toán tử //

    Fraction operator+(Fraction obj);
    Fraction operator-(Fraction obj);
    Fraction operator*(Fraction obj);
    Fraction operator/(Fraction obj);
};

int main()
{
    Fraction a, b, c;

    cout << "\n\tNhap phan so a" << endl;
    a.input();
    cout << "\n\tNhap phan so obj" << endl;
    b.input();

    cout << "\n\t2 Phan so vua nhap" << endl;
    a.output();
    b.output();

    cout << "\n\n\t\tPhep cong" << endl;
    c = a + b;
    c.output();
    cout << "\n\n\t\tPhep tru" << endl;
    c = a - b;
    c.output();
    cout << "\n\n\t\tPhep nhan" << endl;
    c = a * b;
    c.output();
    cout << "\n\n\t\tPhep chia" << endl;
    c = a / b;
    c.output();
    return 0;
}

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(const int &numerator_, const int &denominator_)
    : numerator(numerator_), denominator(denominator_) {}

void Fraction::input()
{
    cout << "\nNhap tu so: ";
    cin >> this->numerator;
    cout << "\nNhap mau so: ";
    cin >> this->denominator;
}

void Fraction::output()
{
    cout << this->numerator << "/" << this->denominator << endl;
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