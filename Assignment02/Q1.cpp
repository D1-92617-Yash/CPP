// Q1. Write a menu driven program to calculate volume of the box(length * width * height). 
// Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor. 
// Create the local objects in respective case and call the function to caluclate area. 
// Menu options ->  
// 1. Calculate Volume with default values 
// 2. Calculate Volume with length,breadth and height with same value 
// 3. Calculate Volume with different length,breadth and height values.


#include <iostream> 
using namespace std;

class Box {
private:
    int length;
    int width;
    int height;

public: 
    // Default constructor
    Box() : length(0), width(0), height(0) { }

    // Parameterized constructor (3 params)
    Box(int length, int width, int height) 
        : length(length), width(width), height(height) { }

    // Single parameterized constructor
    Box(int side) 
        : length(side), width(side), height(side) { }

    // void acceptValues(void) {
    //     cout << "ENTER THE LENGTH: ";
    //     cin >> length;
    //     cout << "ENTER THE WIDTH: ";
    //     cin >> width;
    //     cout << "ENTER THE HEIGHT: ";
    //     cin >> height;
    // }

    void printRecord(void) {
        cout << "VOLUME IS: " << (length * width * height) << endl;
    }
};

int main() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Calculate Volume with default values\n";
        cout << "2. Calculate Volume with same values (cube)\n";
        cout << "3. Calculate Volume with different values\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Box b1;   // default constructor
                b1.printRecord();
                break;
            }
            case 2: {
                int side;
                cout << "Enter side value: ";
                cin >> side;
                Box b2(side);   // single parameterixed constructor
                b2.printRecord();
                break;
            }
            case 3: {
                int l, w, h;
                cout << "Enter length, width, height: ";
                cin >> l >> w >> h;
                Box b3(l, w, h);   // 3 parameterized constructor
                b3.printRecord();
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
