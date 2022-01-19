#pragma once
#include <iostream>
#include "Date.hpp"
using namespace std;

class Person
{
private:
    string identityCard;
    string fullname;
    Date dateOfBirth;
    string phoneNumber;
    string address;

public:
    Person();
    string getIdentityCard();
    string getFullname();
    Date getDateOfBirth();
    string getPhoneNumber();
    string getAddress();
    void setIdentityCard(const string &ID);
    void setFullname(const string &fullname);
    void setDateOfBirth(const Date &date);
    void setPhoneNumber(const string &phoneNumber);
    void setAddress(const string &address);
    virtual void input();
    virtual void output();
};

Person::Person()
{
    identityCard = "";
    fullname = "";
    phoneNumber = "";
    address = "";
}

string Person::getIdentityCard()
{
    return this->identityCard;
}

string Person::getFullname()
{
    return this->fullname;
}

Date Person::getDateOfBirth()
{
    return this->dateOfBirth;
}

string Person::getPhoneNumber()
{
    return this->phoneNumber;
}

string Person::getAddress()
{
    return this->address;
}

void Person::setIdentityCard(const string &ID)
{
    this->identityCard = ID;
}

void Person::setFullname(const string &fullname)
{
    this->fullname = fullname;
}

void Person::setDateOfBirth(const Date &date)
{
    this->dateOfBirth = date;
}

void Person::setPhoneNumber(const string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Person::setAddress(const string &address)
{
    this->address = address;
}

void checkIdentityCard(string &ID) // hàm ngoài
{
    if (ID.length() == 9)
        return;
    else
    {
        do
        {
            cout << "\n\t\t(!) Not valid - Try again (!)" << endl;
            cout << "Try here: ";
            cin >> ID;
        } while (ID.length() != 9);
    }
}

bool validDate(int &day, int &month, int &year) // hàm ngoài
{
    if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day <= 31)
            return true;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 30)
            return true;
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        if (day <= 29)
            return 1;
    }
    else
    {
        if (day <= 28)
            return 0;
    }
    return 0;
}

void inputDate(int &day, int &month, int &year) // hàm ngoài
{
    do
    {
        cout << "\nDate of birth (dd): ";
        cin >> day;
        cout << "\nMonth of birth (mm): ";
        cin >> month;
        cout << "\nYear of birht (yyyy): ";
        cin >> year;
        if (!validDate(day, month, year))
        {
            cout << "\n\t\t(!) Not valid - Try again (!)" << endl;
        }
    } while (!validDate(day, month, year));
}

void Person::input()
{
    cout << "\nEnter ID card: ";
    cin >> identityCard;
    checkIdentityCard(identityCard);
    fflush(stdin);
    cout << "\nEnter fullname: ";
    getline(cin, fullname);
    inputDate(dateOfBirth.day, dateOfBirth.month, dateOfBirth.year);
    fflush(stdin);
    cout << "\nEnter phone number: ";
    getline(cin, phoneNumber);
    cout << "\nEnter address: ";
    getline(cin, address);
}

void Person::output()
{
    cout << "\nCMND: " << identityCard << endl;
    cout << "Ho va ten: " << fullname << endl;
    cout << "Ngay sinh: " << dateOfBirth.day << "/" << dateOfBirth.month << "/" << dateOfBirth.year << endl;
    cout << "SDT: " << phoneNumber << endl;
    cout << "Dia chi: " << address;
}