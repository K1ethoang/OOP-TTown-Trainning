#pragma once
#include "Node.hpp"
#include "Customer.hpp"
#include <list>
#include <string>
#include <cstring>

class Customers
{
private:
    Node<Customer> *pFront; // con trỏ đầu queue
    Node<Customer> *pBack;  // con trỏ cuối queue
    int size;

private:
    list<Customer> findCustomersWithHighAccumulationPoints(const int &targetPoints);
    void sortAscendingByAccumulationPoints();

public:
    Customers();
    ~Customers();
    Node<Customer> *getPFront();
    Node<Customer> *getPBack();
    void setPFront(Node<Customer> *newPFront);
    void setPBack(Node<Customer> *newPBack);
    bool isEmpty();
    void push(const Customer &value);
    void pop();
    int sizeOf();
    void display();
    void searchCustomerByName(const string &name);
    void removeCustomerByPhoneNumber(const string &phone);
    void printCustomersWithHighAccumulationPoints(const int &targetPoints);
    void removeCustomerWithLowAccumulationPoints(const int &targetPoints);
};

Customers::Customers()
    : pFront(NULL), pBack(NULL), size(0) {}

Customers::~Customers()
{
    Node<Customer> *t = NULL;
    while (pFront != NULL)
    {
        t = pFront;
        pFront = pFront->pNext;
        delete t;
    }
    size = 0;
}

Node<Customer> *Customers::getPFront()
{
    return this->pFront;
}

Node<Customer> *Customers::getPBack()
{
    return this->pBack;
}

void Customers::setPFront(Node<Customer> *newPFront)
{
    this->pFront = newPFront;
}

void Customers::setPBack(Node<Customer> *newPBack)
{
    this->pBack = newPBack;
}

bool Customers::isEmpty()
{
    if (size == 0)
        return 1;
    return 0;
}

void Customers::push(const Customer &value) // thêm vào cuối
{

    Node<Customer> *p = new Node(value);
    if (p == NULL)
    {
        cout << "\n\t\t(!) Not enough memory to allocation (!)" << endl;
        return;
    }
    if (isEmpty())
        pFront = pBack = p;
    else
    {
        pBack->pNext = p;
        pBack = p;
    }
    size++;
}

void Customers::pop()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node<Customer> *t = pFront;
        pFront = pFront->pNext; // cập nhật lại Node đầu là Node kế tiếp
        delete t;
        size--;
    }
}

int Customers::sizeOf()
{
    return this->size;
}

void Customers::display()
{
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    int i = 1;
    for (Node<Customer> *t = pFront; t != NULL; t = t->pNext)
    {
        cout << "\n\n\t\t[ Customer {" << i++ << "} ]" << endl;
        t->data.output();
    }
    cout << "\n\n\tTotal " << size << " customers";
}

void Customers::searchCustomerByName(const string &name)
{
    int i = 1;
    bool exist = false;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }

    for (Node<Customer> *t = pFront; t != NULL; t = t->pNext)
    {
        if (strstr(t->data.getFullname().c_str(), name.c_str()) != NULL)
        {
            cout << "\n\n\t\t[ Employee {" << i++ << "} ]" << endl;
            t->data.output();
            exist = true;
        }
    }
    if (!exist)
        cout << "\n\t\t(*) Do not exist Customers with this name (*)";
}

void Customers::removeCustomerByPhoneNumber(const string &phone)
{
    bool exist = false;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    if (pFront->data.getPhoneNumber().compare(phone.c_str()) == 0) // nằm ở đầu
    {
        pop();
        cout << "\n\t\t(*) Delete successfully (*)" << endl;
        return;
    }
    else
    {
        Node<Customer> *g = new Node<Customer>();
        for (Node<Customer> *t = pFront; t != NULL; t = t->pNext)
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
        cout << "\n\t\t(*) Do not exist customer with this phone number (*)";
}

list<Customer> Customers::findCustomersWithHighAccumulationPoints(const int &targetPoints)
{
    list<Customer> customers;
    for (Node<Customer> *t = pFront; t != NULL; t = t->pNext)
    {
        if (t->data.getAccumulatedPoints() > targetPoints)
            customers.push_back(t->data);
    }
    return customers;
}

void Customers::printCustomersWithHighAccumulationPoints(const int &targetPoints)
{
    list<Customer> customers = findCustomersWithHighAccumulationPoints(targetPoints);
    if (customers.size() > 0)
    {
        int i = 1;
        for (Customer &c : customers)
        {
            cout << "\n\n\t\t [ Customer {" << i++ << "} ]" << endl;
            c.output();
        }
    }
    else
        cout << "\n\t\t(*) Do not exist customer (*)";
}

void swap(Customer &c1, Customer &c2) // hàm ngoài
{
    Customer t = c1;
    c1 = c2;
    c2 = t;
}

void Customers::sortAscendingByAccumulationPoints()
{
    for (Node<Customer> *t = pFront; t != pBack; t = t->pNext)
    {
        Node<Customer> *max = t;
        for (Node<Customer> *g = t->pNext; g != NULL; g = g->pNext)
        {
            if (max->data.getAccumulatedPoints() > g->data.getAccumulatedPoints())
                max = g;
        }
        if (max != t)
            swap(t->data, max->data);
    }
}

void Customers::removeCustomerWithLowAccumulationPoints(const int &targetPoints)
{
    bool exist = false;
    if (isEmpty())
    {
        cout << "\n\t\t(*) Empty list (*)";
        return;
    }
    for (Node<Customer> *t = pFront; t != NULL; t = t->pNext)
    {
        sortAscendingByAccumulationPoints();
        if (t->data.getAccumulatedPoints() < targetPoints)
        {
            exist = true;
            pop(); // xoá
        }
        else
            break;
    }
    if (exist)
        cout << "\n\t\t(*) Delete successfully (*)";
    else
        cout << "\n\t\t(*) Do not exist employees to delete (*)";
}
