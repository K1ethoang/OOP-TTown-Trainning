#pragma once
#include "Node.hpp"
#include "Employee.hpp"
#include <list>
#include <string>

// dùng stack để lưu danh sách nhân viên

class Employees
{
private:
    Node<Employee> *pTop; // con trỏ để quản lí stack
    int size;

private:
    list<Employee> findEmployeesHardworking(const int &targetDay);
    void sortAscendingByWorkingDay();

public:
    Employees();
    ~Employees();
    Node<Employee> *getPTop();
    void setPTop(Node<Employee> *newPTop);
    bool isEmpty();
    void push(const Employee &value);
    void pop();
    int sizeOf();
    void display();
    void sortDescendingBySalary();
    void printEmployeesHardWorking(const int &targetDay);
    void removeEmployeesLazy(const int &targetDay);
    void removeEmployeeByPhoneNumber(const string &phone);
};

Employees::Employees()
    : pTop(NULL), size(0) {}

Employees::~Employees()
{
    Node<Employee> *t = NULL;
    while (pTop != NULL)
    {
        t = pTop;
        pTop = pTop->pNext;
        delete t;
    }
    size = 0;
}

Node<Employee> *Employees::getPTop()
{
    return this->pTop;
}

void Employees::setPTop(Node<Employee> *newPTop)
{
    this->pTop = newPTop;
}

bool Employees::isEmpty()
{
    if (size == 0)
        return 1;
    return 0;
}

void Employees::push(const Employee &value)
{
    Node<Employee> *p = new Node(value);
    if (p == NULL)
    {
        cout << "\n\t\t(!) Not enough memory to allocation (!)" << endl;
        return;
    }
    if (isEmpty())
        pTop = p;
    else
    {
        p->pNext = pTop;
        pTop = p;
    }
    size++;
}

void Employees::pop()
{
    if (isEmpty())
        return;
    else
    {
        Node<Employee> *t = pTop;
        pTop = pTop->pNext;
        delete t;
        size--;
    }
}

int Employees::sizeOf()
{
    return this->size;
}

void Employees::display()
{
    int i = 1;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
    {
        cout << "\n\n\t\t[ Employee {" << i++ << "} ]" << endl;
        t->data.output();
    }
    cout << "\n\n\tTotal: " << size << " employees";
}

void swap(Employee &e1, Employee &e2) // hàm ngoài
{
    Employee t = e1;
    e1 = e2;
    e2 = t;
}

void Employees::sortDescendingBySalary()
{
    for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
    {
        for (Node<Employee> *g = t->pNext; g != NULL; g = g->pNext)
        {
            Node<Employee> *max = t;
            if (max->data.getSalary() < g->data.getSalary())
                max = g;
            if (max != t)
                swap(t->data, max->data);
        }
    }
}

list<Employee> Employees::findEmployeesHardworking(const int &targetDay)
{
    list<Employee> employees;
    for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
    {
        if (t->data.getWorkingDayPerMonth() > targetDay)
            employees.push_back(t->data);
    }
    return employees;
}

void Employees::printEmployeesHardWorking(const int &targetDay)
{
    list<Employee> employees = findEmployeesHardworking(targetDay);
    if (employees.size() > 0)
    {
        int i = 1;
        for (Employee &e : employees)
        {
            cout << "\n\n\t\t[ Employee {" << i++ << "} ]" << endl;
            e.output();
        }
    }
    else
        cout << "\n\t\t (*) Do not exist employees (*)" << endl;
}

void Employees::sortAscendingByWorkingDay()
{
    for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
    {
        for (Node<Employee> *g = t->pNext; g != NULL; g = g->pNext)
        {
            Node<Employee> *min = t;
            if (min->data.getWorkingDayPerMonth() > g->data.getWorkingDayPerMonth())
                min = g;
            if (min != t)
                swap(t->data, min->data);
        }
    }
}

void Employees::removeEmployeesLazy(const int &targetDay)
{
    bool exist = false;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    sortAscendingByWorkingDay();
    for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
    {
        if (t->data.getWorkingDayPerMonth() < targetDay)
        {
            exist = true;
            pop(); // xoá
        }
        else
        {
            break;
        }
    }
    if (exist)
        cout << "\n\t\t(*) Delete successfully (*)";
    else
        cout << "\n\t\t(*) Do not exist employees to delete (*)";
}

void Employees::removeEmployeeByPhoneNumber(const string &phone)
{
    bool exist = false;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    if (pTop->data.getPhoneNumber().compare(phone.c_str()) == 0) // nằm ở đầu
    {
        pop();
        cout << "\n\t\t(*) Delete successfully (*)" << endl;
        return;
    }
    else
    {
        Node<Employee> *g = new Node<Employee>();
        for (Node<Employee> *t = pTop; t != NULL; t = t->pNext)
        {
            if (t->data.getPhoneNumber().compare(phone.c_str()) == 0)
            {
                g->pNext = t->pNext;
                delete t;
                size--;
                exist = true;
                cout << "\n\t\t(*) Delete successfully (*)" << endl;
                return;
            }
            g = t;
        }
    }
    if (!exist)
        cout << "\n\t\t(*) Do not exist employee with this phone number (*)";
}
