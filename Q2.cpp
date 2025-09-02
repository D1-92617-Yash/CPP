#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    void initDate() {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDate() {
        cout << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole() {
        cout << "ENTER DAY: ";
        cin >> day;
        cout << "ENTER MONTH: ";
        cin >> month;
        cout << "ENTER YEAR: ";
        cin >> year;
    }

    bool isLeapYear() {
        if (year % 400 == 0) return true;
        else if (year % 100 == 0) return false;
        else if (year % 4 == 0) return true;
        else return false;
    }

    int getYear() {   
        return year;
    }
};

int main() {
    Date d;
    int choice;
    d.initDate();

    do {
        cout << "\n===== Date Menu (Using Class & if-else) =====\n";
        cout << "1. Initialize Date\n";
        cout << "2. Accept Date\n";
        cout << "3. Print Date\n";
        cout << "4. Check Leap Year\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            d.initDate();
            cout << "Date initialized successfully!\n";
        }
        else if (choice == 2) {
            d.acceptDateFromConsole();
        }
        else if (choice == 3) {
            d.printDate();   
        }
        else if (choice == 4) {
            if (d.isLeapYear())
                cout << d.getYear() << " is a Leap Year.\n";   
            else
                cout << d.getYear() << " is NOT a Leap Year.\n";
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
