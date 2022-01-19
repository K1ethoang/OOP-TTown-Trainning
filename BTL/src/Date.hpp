class Date
{
public:
    int day, month, year;

public:
    Date();
    ~Date();
};

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 1945;
}

Date::~Date()
{
}
