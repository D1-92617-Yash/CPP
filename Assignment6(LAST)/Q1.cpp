#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    double salary;
public:
    Employee() : id(0), salary(0) {}
    Employee(int i, double s) : id(i), salary(s) {}

    virtual void accept() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() const {
        cout << "ID: " << id << ", Salary: " << salary;
    }

    virtual string getDesignation() const {
        return "Employee";
    }

    int getId() const { return id; }
};

class Manager : virtual public Employee {
protected:
    double bonus;
public:
    Manager() : Employee(), bonus(0) {}
    Manager(int i, double s, double b) : Employee(i, s), bonus(b) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void display() const override {
        cout << "Manager -> ";
        Employee::display();
        cout << ", Bonus: " << bonus << endl;
    }

    string getDesignation() const override {
        return "Manager";
    }
};

class Salesman : virtual public Employee {
protected:
    double commission;
public:
    Salesman() : Employee(), commission(0) {}
    Salesman(int i, double s, double c) : Employee(i, s), commission(c) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display() const override {
        cout << "Salesman -> ";
        Employee::display();
        cout << ", Commission: " << commission << endl;
    }

    string getDesignation() const override {
        return "Salesman";
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Employee(), Manager(), Salesman() {}

    void accept() override {
        cout << "Enter details for Sales Manager:\n";
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> Manager::bonus;
        cout << "Enter Commission: ";
        cin >> Salesman::commission;
    }

    void display() const override {
        cout << "SalesManager -> ID: " << id << ", Salary: " << salary
             << ", Bonus: " << Manager::bonus << ", Commission: " << Salesman::commission << endl;
    }

    string getDesignation() const override {
        return "SalesManager";
    }
};

vector<Employee*> employees;

void addManager() {
    Manager* m = new Manager();
    m->accept();
    employees.push_back(m);
}

void addSalesman() {
    Salesman* s = new Salesman();
    s->accept();
    employees.push_back(s);
}

void addSalesManager() {
    SalesManager* sm = new SalesManager();
    sm->accept();
    employees.push_back(sm);
}

void countByDesignation() {
    int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;
    for (auto e : employees) {
        string des = e->getDesignation();
        if (des == "Manager")
            managerCount++;
        else if (des == "Salesman")
            salesmanCount++;
        else if (des == "SalesManager")
            salesManagerCount++;
    }
    cout << "Count of Employees:\n";
    cout << "Managers: " << managerCount << endl;
    cout << "Salesmen: " << salesmanCount << endl;
    cout << "SalesManagers: " << salesManagerCount << endl;
}

void displayAllManagers() {
    cout << "Displaying all Managers:\n";
    for (auto e : employees) {
        if (e->getDesignation() == "Manager")
            e->display();
    }
}

void displayAllSalesmen() {
    cout << "Displaying all Salesmen:\n";
    for (auto e : employees) {
        if (e->getDesignation() == "Salesman")
            e->display();
    }
}

void displayAllSalesManagers() {
    cout << "Displaying all SalesManagers:\n";
    for (auto e : employees) {
        if (e->getDesignation() == "SalesManager")
            e->display();
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Manager\n";
        cout << "2. Add Salesman\n";
        cout << "3. Add SalesManager\n";
        cout << "4. Display count of employees with respect to designation\n";
        cout << "5. Display all Managers\n";
        cout << "6. Display all Salesmen\n";
        cout << "7. Display all SalesManagers\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addManager();
            break;
        case 2:
            addSalesman();
            break;
        case 3:
            addSalesManager();
            break;
        case 4:
            countByDesignation();
            break;
        case 5:
            displayAllManagers();
            break;
        case 6:
            displayAllSalesmen();
            break;
        case 7:
            displayAllSalesManagers();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    for (auto e : employees) {
        delete e;
    }
    employees.clear();

    return 0;
}
