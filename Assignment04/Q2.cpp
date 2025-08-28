// Q1. Create a class Date with data memebrs day,month and year. 
// Cretae a class Person with data members name,address and birthdate. The birthdate should be of 
// type Date. 
// Create a class Student with data members id, marks, course and joining date, end date. The joining 
// date and end date should be of type date. 
// Implement above classes. Test all functionalities in main(). 
// (Note - Only Perform the Association in the above case. No need of Inheritance) 
#include <iostream>
using namespace std;


class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};


class Person {
private:
    string name;
    string address;
    Date birthDate;   

public:
    Person() : name(""), address(""), birthDate() {}
    Person(const string& n, const string& addr, const Date& dob)
        : name(n), address(addr), birthDate(dob) {}

    void printPerson() const {
        cout<<"Name: " << name<<endl;
        cout<<"Address: "<< address<<endl;
        cout<<"Birthdate: "<<endl;
        birthDate.printDate();
        cout << endl;
    }
};


class Student {
private:
    int id;
    int marks;
    string course;
    Date* joinDate;   
    Date* endDate;    

public:
    Student(int i, int m, const string& c, Date* jd, Date* ed)
        : id(i), marks(m), course(c), joinDate(jd), endDate(ed) {}

    void printStudent() const {
        cout <<"Student ID: "<<id<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Joining Date: ";
        if(joinDate) joinDate->printDate();
        cout<<"\nEnd Date: ";
        if(endDate) endDate->printDate();
        cout << endl;
    }
};


int main() {
    cout<<"TEsting date functionalities: "<<endl;
    Date d1(1, 1, 2000);
    cout << "Date d1: ";
    d1.printDate();
    cout << endl << endl;

    cout<<"Testing person functionalities: "<<endl;

    Person p1("Yash", "Pune", d1);
    cout << "--- Person Info ---" << endl;
    p1.printPerson();
    cout << endl;

    cout<<"Testing student: "<<endl;
    Date join(15, 6, 2022);
    Date end(15, 6, 2025);

    Student s1(101, 90, "Computer Science", &join, &end);
    s1.printStudent();


    return 0;
}
