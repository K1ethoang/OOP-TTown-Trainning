#include "Person.hpp"

class Customer : public Person
{
private:
    string favoriteCoffee;
    int accumulatedPoints; // điểm tích luỹ

public:
    Customer();
    string getFavoriteCoffee();
    int getAccumulatedPoints();
    void setFavoriteCoffee(const string &coffee);
    void setAccumulatedPoints(const int &points);
    void input();
    void output();
};

Customer::Customer()
{
    Person();
    favoriteCoffee = "";
    accumulatedPoints = 0;
}

string Customer::getFavoriteCoffee()
{
    return this->favoriteCoffee;
}

int Customer::getAccumulatedPoints()
{
    return this->accumulatedPoints;
}

void Customer::setFavoriteCoffee(const string &coffee)
{
    this->favoriteCoffee = coffee;
}

void Customer::setAccumulatedPoints(const int &accumulatedPoints)
{
    this->accumulatedPoints = accumulatedPoints;
}

void Customer::input()
{
    Person::input();
    cout << "\nEnter favorite coffee: ";
    fflush(stdin);
    getline(cin, favoriteCoffee);
    cout << "\nEnter accumulated points: ";
    cin >> accumulatedPoints;
    do
    {
        if (accumulatedPoints <= 0)
        {
            cout << "\n\t\t(!) Note valid - Try again (!)" << endl;
            cout << "\nTry here: ";
            cin >> accumulatedPoints;
        }
    } while (accumulatedPoints <= 0);
}

void Customer::output()
{
    Person::output();
    cout << "\nFavorite coffee: " << favoriteCoffee << endl;
    cout << "Accumulated points: " << accumulatedPoints;
}