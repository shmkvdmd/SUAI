#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Student

{
private:
    string name;
    string surname;
    int year;

public:
    Student();
    Student(string, string, int);
    ~Student();
    Student(const Student&);
    void getFullName(string, string, int);
    void getCourse();
    void output();
};

Student::Student(string name, string surname, int year)
{
    this->name = name;
    this->surname = surname;
    this->year = year;
}

Student::Student(const Student& ob)
{
    name = ob.name;
    surname = ob.surname;
    year = ob.year;
}

Student::Student()
{
    this->name = "Petr";
    this->surname = "Petrov";
    this->year = 2021;

}
Student::~Student()
{
    name.clear();
    surname.clear();
    cout << "\nДеструктор\n";
}

void Student::getFullName(string n, string s, int year)
{
    name = n;
    surname = s;
    this->year = year;
}

void Student::getCourse()
{
    cout << "\nКурс студента: " << 2022 - year << "\n";
}

void Student::output()
{
    cout << "\nИмя студента: " << name << " " << surname << "\nГод поступления " << year;
}

int main()
{
    system("color F1");
    setlocale(LC_ALL, "ru");
    Student s1;
    Student s3("Ivan", "Ivanov", 2020);
    s3.output();
    s3.getCourse();
    s1.output();
    s1.getCourse();
    Student s2(s3);
    s2.output();
    s2.getCourse();
    return 0;
}