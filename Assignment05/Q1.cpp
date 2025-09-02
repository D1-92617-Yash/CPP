#include <iostream>
using namespace std;

class Product {
protected:
    int id;
    double price;
    string title;

public:
    Product() : id(0), price(0.00), title(" ") 
    {  }
    Product(int id, string title, double price) : id(id), title(title), price(price)
     {  }
    
    void setId(int id) {  
        this->id = id; 
    }
    int getId() const { 
        return id; 
    }
    
    void setTitle(const string& title) {
         this->title = title;
    }
    string getTitle() const {
        return title;
    }

    void setPrice(double price) {
        this->price = price;
    }
    double getPrice() const {
        return price;
    }

    virtual ~Product() { }
    
    virtual void displayRecord() const = 0;
    virtual double getDiscountedPrice() const = 0;
};

class Book : public Product {
protected:
    string author;

public:
    Book() : Product(), author(" ") { }
    Book(int id, string title, double price, string author) 
        : Product(id, title, price), author(author) { }

    void setAuthor(const string& author) { this->author = author; }
    string getAuthor() const { return author; }

    void displayRecord() const override {
        cout << "PRODUCT ID: " << id << endl;
        cout << "BOOK TITLE: " << title << endl;
        cout << "BOOK'S PRICE: $" << price << endl;
        cout << "AUTHOR: " << author << endl;
    }

    double getDiscountedPrice() const override {
        return price * 0.9;
    }
};

class Tape : public Product {
protected:
    string artist;

public:
    Tape() : Product(), artist(" ") { }
    Tape(int id, string title, double price, string artist) 
        : Product(id, title, price), artist(artist) { }

    void setArtist(const string& artist) { this->artist = artist; }
    string getArtist() const { return artist; }

    void displayRecord() const override {
        cout << "PRODUCT ID: " << id << endl;
        cout << "TAPE TITLE: " << title << endl;
        cout << "TAPE'S PRICE: $" << price << endl;
        cout << "ARTIST: " << artist << endl;
    }

    double getDiscountedPrice() const override {
        return price * 0.95;
    }
};

int main() {
    Product* arr[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Enter details for product " << (i + 1) << ":" << endl;
        cout << "Choose product type (1 for Book, 2 for Tape): ";
        int choice;
        cin >> choice;
        cin.ignore();

        int id;
        string title;
        double price;

        cout << "Enter product id: ";
        cin >> id;
        cin.ignore();

        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
        cin.ignore();

        if (choice == 1) {
            string author;
            cout << "Enter author: ";
            getline(cin, author);

            arr[i] = new Book(id, title, price, author);
        } else if (choice == 2) {
            string artist;
            cout << "Enter artist: ";
            getline(cin, artist);

            arr[i] = new Tape(id, title, price, artist);
        } else {
            cout << "Invalid choice. Try again." << endl;
            --i;
            continue;
        }

        cout << "Product recorded successfully.\n\n";
    }

    cout << "\nDisplaying all products:\n";
    double finalBill = 0.0;
    for (int i = 0; i < 3; ++i) {
        arr[i]->displayRecord();
        double discountedPrice = arr[i]->getDiscountedPrice();
        cout << "Price after discount: $" << discountedPrice << endl << endl;
        finalBill += discountedPrice;
    }

    cout << "Final bill amount (after discounts): $" << finalBill << endl;

    for (int i = 0; i < 3; ++i) {
        delete arr[i];
    }
}