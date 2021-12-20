/* . class Student gồm các thuộc tính:
- id, name, mark

- Khởi tạo, nhập, xuất
- Viết phương thức xếp loại học sinh.  */

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string id;
    string name;
    float mark;

public:
    Student();                                                           // hàm khởi tạo mặc định
    Student(const string &id_, const string &name_, const float &mark_); // hàm khởi tạo có tham số

    void input();
    void output();
    void setMark(float mark_);
    void grading(); // xếp loại học sinh
};

int main()
{
    Student *student = new Student("1", "kiet", 1);
    student->output();
    student->setMark(9);
    student->output();

    delete student;
    return 0;
}

Student::Student()
{
    this->id = "";
    this->name = "";
    this->mark = 1;
}

Student::Student(const string &id_, const string &name_, const float &mark_)
    : id(id_), name(name_), mark(mark_) {}

void Student::input()
{
    fflush(stdin);
    cout << "\nNhap ma sinh vien: ";
    getline(cin, id);
    cout << "\nNhap ten sinh vien: ";
    getline(cin, name);
    cout << "\nNhap diem: ";
    cin >> mark;
}

void Student::output()
{
    cout << "\nMa sinh vien: " << id << endl;
    cout << "Ten sinh vien: " << name << endl;
    cout << "Diem: " << mark << endl;
}

void Student::setMark(float mark_)
{
    if (mark_ <= 0 || mark_ > 10)
        cout << "\nDiem khong hop le !";
    else
        this->mark = mark_;
}

void Student::grading()
{
    if (mark >= 8)
        cout << "Hoc sinh gioi";
    else if (mark >= 5)
        cout << "Hoc sinh kha";
    else
        cout << "Hoc sinh trung binh";
}