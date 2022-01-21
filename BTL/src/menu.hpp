#pragma once
#include <iostream>
#include "Employees.hpp"
#include "Customers.hpp"
using std::cin;
using std::cout;
using std::endl;

void menu();
void employee(Employees &employees);
void customer(Customers &customers);
void pressAnykey();

void pressAnykey()
{
    cout << endl;
    system("pause");
    cout << endl;
}

void menu()
{
    Employees e;
    Customers c;
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t###############              AREA               ###############" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t#          [1]. Employee                                      #" << endl;
        cout << "\t\t#          [2]. Customer                                      #" << endl;
        cout << "\t\t#          [0]. Exit                                          #" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t Enter your choose --> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            employee(e);
            break;
        case 2:
            customer(c);
            break;
        case 0:
            cout << "\n\t\t(*) See you again (*)" << endl;
            exit = true;
            pressAnykey();
            break;
        default:
            cout << "\n\t\t(!) Not valid (!)" << endl;
            pressAnykey();
            break;
        }
    } while (!exit);
}

void employee(Employees &employees)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t###############            EMPLOYEE             ###############" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t#  [1]. Display list                                          #" << endl;
        cout << "\t\t#  [2]. Add employee                                          #" << endl;
        cout << "\t\t#  [3]. Remove employee                                       #" << endl;
        cout << "\t\t#  [4]. List of employees according to salary                 #" << endl;
        cout << "\t\t#  [5]. Hardworking employees of the month ( > 18 day)        #" << endl;
        cout << "\t\t#  [6]. Remove employees who go to work little                #" << endl;
        cout << "\t\t#  [0]. Return                                                #" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t Enter your choose --> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            employees.display();
            pressAnykey();
            break;
        case 2:
        {
            Employee e;
            e.input();
            employees.push(e);
            pressAnykey();
            break;
        }
        case 3:
        {
            string phoneNumber;
            cout << "\nEnter employee's number phone: ";
            cin >> phoneNumber;
            employees.removeEmployeeByPhoneNumber(phoneNumber);
            pressAnykey();
            break;
        }
        case 4:
            employees.sortDescendingBySalary();
            employees.display();
            pressAnykey();
            break;
        case 5:
            employees.printEmployeesHardWorking(18);
            pressAnykey();
            break;
        case 6:
            employees.removeEmployeesLazy(5);
            pressAnykey();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "\n\t\t(!) Not valid (!)" << endl;
            pressAnykey();
            break;
        }
    } while (!exit);
}

void customer(Customers &customers)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t###############            CUSTOMER             ###############" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t\t#  [1]. Display list                                          #" << endl;
        cout << "\t\t#  [2]. Add customer                                          #" << endl;
        cout << "\t\t#  [3]. Remove customer                                       #" << endl;
        cout << "\t\t#  [4]. Search customer                                       #" << endl;
        cout << "\t\t#  [5]. Customers with high accumulation points ( > 40)       #" << endl;
        cout << "\t\t#  [6]. Remove customers with low accumulation points ( < 10) #" << endl;
        cout << "\t\t#  [0]. Return                                                #" << endl;
        cout << "\t\t###############################################################" << endl;
        cout << "\t Enter your choose --> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            customers.display();
            pressAnykey();
            break;
        case 2:
        {
            Customer c;
            c.input();
            customers.push(c);
            pressAnykey();
            break;
        }
        case 3:
        {
            string phoneNumber;
            cout << "\nEnter customer's number phone: ";
            cin >> phoneNumber;
            customers.removeCustomerByPhoneNumber(phoneNumber);
            pressAnykey();
            break;
        }
        case 4:
        {
            string name;
            cout << "\nEnter customer's name need to search: ";
            fflush(stdin);
            getline(cin, name);
            customers.searchCustomerByName(name);
            pressAnykey();
            break;
        }
        case 5:
            customers.printCustomersWithHighAccumulationPoints(40);
            pressAnykey();
            break;
        case 6:
            customers.removeCustomerWithLowAccumulationPoints(10);
            pressAnykey();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "\n\t\t(!) Not valid (!)" << endl;
            pressAnykey();
            break;
        }
    } while (!exit);
}