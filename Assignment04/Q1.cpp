// Q1. Write a class for Time and provide the functionality 
// Time() 
// Time(int h,int m,int s) 
// getHour() 
// getMinute() 
// getSeconds() 
// printTime() 
// setHour() 
// setMinute() 
// setSeconds() 
// In main create array of objects of Time. 
// Allocate the memory for the array and the object dynamically. 
// Write a menu driven code which provides below functionality 
// 1. Add Time 
// 2. Display All Time 
// 3. Display only hrs of all time objects 
 
// Q1. Write a class for Time and provide the functionality 
// Time() 
// Time(int h,int m,int s) 
// getHour() 
// getMinute() 
// getSeconds() 
// printTime() 
// setHour() 
// setMinute() 
// setSeconds() 
// In main create array of objects of Time. 
// Allocate the memory for the array and the object dynamically. 
// Write a menu driven code which provides below functionality 
// 1. Add Time 
// 2. Display All Time 
// 3. Display only hrs of all time objects 
 
#include <iostream>
using namespace std;

class Time{
    private:
    int h;
    int m;
    int s;

    public:
    Time() : h(0), m(0), s(0)
    { }
    Time(int h, int m, int s): h(h), m(m), s(s)
    { }

    void setHour(){
        cout<<"ENTER HOUR: "<<endl;
        cin>>h;
    }
    void setMinute(){
        cout<<"ENTER MINUTE: "<<endl;
        cin>>m;
    }
    void setSecond(){
        cout<<"ENTER SECOND: "<<endl;
        cin>>s;
    }
    int getHour(){
        return h;

    }
     int getMinute(){
        return m;

    } int getSecond(){
        return s;

    }
    void printTime(){
        cout<<"TIME: "<<h<<":"<<m<<":"<<s<<endl;
    }
   
};

int menuList() {
    int choice;
    cout << "\nENTER YOUR CHOICE: " << endl;
    cout << "1. Add Time" << endl;
    cout << "2. Display All Times" << endl;
    cout << "3. Display Only Hours of All Time Objects" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    return choice;
}

int main() {
    int n;
    cout << "ENTER THE NUMBER OF OBJECTS YOU WANT TO CREATE: " << endl;
    cin >> n;
    Time* ptr = new Time[n];
    int count = 0;
    int choice = 0;
    while (choice != 4) {
        choice = menuList();
        switch (choice) {
            case 1:
                if (count < n) {
                    cout << "Adding Time for object " << (count + 1) << ":" << endl;
                    ptr[count].setHour();
                    ptr[count].setMinute();
                    ptr[count].setSecond();
                    count++;
                } else {
                    cout << "Array is full! Cannot add more Time objects." << endl;
                }
                break;
            case 2:
                if (count == 0) {
                    cout << "No Time objects to display." << endl;
                } else {
                    for (int i = 0; i < count; i++) {
                        cout << "Object " << (i + 1) << ": ";
                        ptr[i].printTime();
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    cout << "No Time objects to display hours." << endl;
                } else {
                    for (int i = 0; i < count; i++) {
                        cout << "Object " << (i + 1) << " Hour: " << ptr[i].getHour() << endl;
                    }
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    delete[] ptr;
    return 0;
}
