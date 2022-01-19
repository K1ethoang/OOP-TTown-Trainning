#include "Person.hpp"

class Employee : public Person
{
private:
    int workingDayPerMonth;
    double salary;

public:
    Employee();
    int getWorkingDayPerMonth();
    double getSalary();
    void setWorkingDayPerMonth(const int &day);
    void setSalary(const double &salary);
    void input();
    void output();
};

Employee::Employee()
{
    Person();
    workingDayPerMonth = 0;
    salary = 0;
}

int Employee::getWorkingDayPerMonth()
{
    return this->workingDayPerMonth;
}

double Employee::getSalary()
{
    return this->salary;
}

void Employee::setWorkingDayPerMonth(const int &day)
{
    this->workingDayPerMonth = day;
}

void Employee::setSalary(const double &salary)
{
    this->salary = salary;
}

void Employee::input()
{
    Person::input();
    cout << "\nEnter number of working day: ";
    cin >> workingDayPerMonth;
    do
    {
        if (workingDayPerMonth <= 0)
        {
            cout << "\n\t\t(!) Not valid - Try again (!)" << endl;
            cout << "\nTry here: ";
            cin >> workingDayPerMonth;
        }
    } while (workingDayPerMonth <= 0);

    cout << "\nEnter Salary: ";
    cin >> salary;
}

void Employee::output()
{
    Person::output();
    cout << "\nNumber of working day: " << workingDayPerMonth << endl;
    cout << "Salary: " << salary;
}