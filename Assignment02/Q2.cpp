// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll. 
// Mostly they do, but sometimes a car goes by without paying. 
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money 
// collected. Model this tollbooth with a class called tollbooth. 
// The two data items are a type unsigned int to hold the total number of cars, and a type double to 
// hold the total amount of money collected. 
// A constructor initializes all data members to 0. A member function called payingCar() increments 
// the car total and adds 0.50 to the cash total. An other function, called nopayCar() 
// increments the car total but adds nothing to the cash total. Finally, a member function called 
// printOnConsole() displays the two totals and number of paying as well as non paying cars total. 

 
#include <iostream>
using namespace std;

class tollbooth {
private:
    int totalCars;
    int payCars;
    int noPayCars;
    double totalCash;

public:
    // Constructor
    tollbooth() : totalCars(0), payCars(0), noPayCars(0), totalCash(0.0) { }

    // When a car pays
    void payingCar() {
        totalCars++;
        payCars++;
        totalCash += 0.50;
    }

    // When a car does not pay
    void nopayCar() {
        totalCars++;
        noPayCars++;
    }

    // Display result
    void printOnConsole() {
        cout << "\n===== Tollbooth Report =====\n";
        cout << "Total Cars Passed : " << totalCars << endl;
        cout << "Paying Cars       : " << payCars << endl;
        cout << "Non-Paying Cars   : " << noPayCars << endl;
        cout << "Total Cash Collected: $" << totalCash << endl;
        cout << "============================\n";
    }
};

int main() {
    tollbooth tb;

    int choice;
    do {
        cout << "\n--- TOLLBOOTH MENU ---\n";
        cout << "1. Car Paid Toll\n";
        cout << "2. Car Did Not Pay\n";
        cout << "3. Show Report\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tb.payingCar();
            break;
        case 2:
            tb.nopayCar();
            break;
        case 3:
            tb.printOnConsole();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
