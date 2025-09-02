#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}

    Employee(int id, double salary) : id(id), salary(salary) {}

    int getId() {
        return id;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    double getSalary() {
        return salary;
    }

    virtual void display() {
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public Employee {
private:
    double bonus;

public:
    Manager() : Employee(), bonus(0.0) {}

    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) {
        this->bonus = bonus;
    }

    double getBonus() {
        return bonus;
    }

    void display() override {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }

    void displayManager() {
        display();
    }
};

class Salesman : virtual public Employee {
private:
    double commission;

public:
    Salesman() : Employee(), commission(0.0) {}

    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) {
        this->commission = commission;
    }

    double getCommission() {
        return commission;
    }

    void accept() {
        cout << "Enter commission for Salesman: ";
        cin >> commission;
    }

    void display() override {
        Employee::display();
        cout << "Commission: " << commission << endl;
    }

    void displaySalesman() {
        display();
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Employee(), Manager(), Salesman() {}

    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void display() override {
        Employee::display();
        cout << "Bonus: " << Manager::getBonus() << endl;
        cout << "Commission: " << Salesman::getCommission() << endl;
    }
};

int main() {
    Employee emp(101, 50000);
    cout << "Employee details:" << endl;
    emp.display();
    cout << endl;

    Manager mgr(102, 75000, 15000);
    cout << "Manager details:" << endl;
    mgr.displayManager();
    cout << endl;

    Salesman sal(103, 45000, 5000);
    cout << "Salesman details:" << endl;
    sal.displaySalesman();
    cout << endl;

    SalesManager sm(104, 90000, 20000, 7000);
    cout << "Sales Manager details:" << endl;
    sm.display();
    cout << endl;

    return 0;
}
