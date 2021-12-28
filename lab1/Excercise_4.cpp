#include <iostream>
#include <string>
using namespace std;

// abstraction class
class Employee
{
private:
    string fullname;
    int age;
    double baseSalary;

public:
    Employee();
    Employee(string _fullname, int _age, double _baseSalary);
    void input();
    void output();
    double getBaseSalary() const;
};

// inheritance class
class Programmer : public Employee
{
private:
    double overtimeMoney;

public:
    Programmer();
    Programmer(string _fullname, int _age, double _baseSalary, double _overtimeMoney);
    void input();
    void output();
    double calculatingSalary() const;
};

class Designer : public Employee
{
private:
    double bonusMoney;

public:
    Designer();
    Designer(string _fullname, int _age, double _baseSalary, double bonusMoney);
    void input();
    void output();
    double calculatingSalary() const;
};

int main()
{
    Programmer *programmer = new Programmer("Phat Nguyen", 19, 10000000, 2000000);
    programmer->output();
    cout << "Tong luong: " << size_t(programmer->calculatingSalary());

    cout << endl;

    Designer *designer = new Designer("Hoang Gia Kiet", 18, 1000000, 500000);
    designer->output();
    cout << "Tong luong: " << size_t(designer->calculatingSalary());

    delete programmer;
    delete designer;
    return 0;
}

// Abstraction class
Employee::Employee()
{
    this->fullname = "";
    this->age = 0;
    this->baseSalary = 0.0;
}

Employee::Employee(string _fullname, int _age, double _baseSalary)
    : fullname(_fullname), age(_age), baseSalary(_baseSalary) {}

void Employee::input()
{
    fflush(stdin);
    cout << "\nNhap ho ten: ";
    getline(cin, fullname);
    cout << "\nNhap tuoi: ";
    cin >> age;
    cout << "\nNhap luong co ban: ";
    cin >> baseSalary;
}

void Employee::output()
{
    cout << "\nHo ten: " << fullname << endl;
    cout << "Tuoi: " << age << endl;
    cout << "Luong co ban: " << size_t(baseSalary) << endl;
}

double Employee::getBaseSalary() const
{
    return this->baseSalary;
}

// inheritance class
Programmer::Programmer()
{
    Employee();
    this->overtimeMoney = 0.0;
}

Programmer::Programmer(string _fullname, int _age, double _baseSalary, double _overtimeMoney)
    : Employee(_fullname, _age, _baseSalary), overtimeMoney(_overtimeMoney)
{
}

void Programmer::input()
{
    Employee::input();
    cout << "\nNhap so tien tang ca: ";
    cin >> overtimeMoney;
}

void Programmer::output()
{
    Employee::output();
    cout << "So tien tang ca: " << size_t(overtimeMoney) << endl;
}

double Programmer::calculatingSalary() const
{
    return Employee::getBaseSalary() + overtimeMoney;
}

Designer::Designer()
{
    Employee();
    this->bonusMoney = 0;
}

Designer::Designer(string _fullname, int _age, double _baseSalary, double _bonusMoney)
    : Employee(_fullname, _age, _baseSalary), bonusMoney(_bonusMoney) {}

void Designer::input()
{
    Employee::input();
    cout << "\nNhap so tien thuong them: ";
    cin >> bonusMoney;
}

void Designer::output()
{
    Employee::output();
    cout << "So tien thuong them: " << size_t(bonusMoney) << endl;
}

double Designer::calculatingSalary() const
{
    return Employee::getBaseSalary() + bonusMoney;
}
