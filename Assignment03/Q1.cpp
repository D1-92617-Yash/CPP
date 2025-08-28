// Q1. Write a class to find volume of a Cylinder by using following members. (volume of 
// Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI) 
// Class having following member functions: 
// Cylinder() 
// Cylinder(double radius, double height) 
// getRadius() 
// setRadius() 
// getHeight() 
// setHeight() 
// calculateVolume() 
// Initialize members using constructor member initializer list. 
 
#include <iostream>
using namespace std;
class Math{
    public:
    static const float PI;
    double pow(double base, int index){
        float result=1;
        for(int i=1; i<=index; i++){
            result = result*base;
        }
        return result;
    }

};
class Cylinder{
    private:
    double radius;
    double height;
    public:
    
    Cylinder(void): radius(0), height(0)
    {    }

    Cylinder(double radius, double height ):radius(radius), height(height)
    {    }

    void setRadius(int radius){
        this->radius = radius;
    }
    double getRadius(void){
        return this->radius;
    }
    void setHeight(double height){
        this-> height = height;
    }
    double getHeight(void){
        return this->height;

    }
    float calculateVolume(){
        // Math m1;
        // float r = m1.pow(radius, 2);
        // return (Math::PI) * r * height;
        // cout<<"THE VOLUME IS: ";
        return Math::PI*radius*radius*height;
    }


};
const float Math::PI = 3.14;
int main(){
    int choice;
    do{
        cout<<"PROGRAM TO CALCULATE VOLUME OF THE CYLINDER: "<<endl;
        cout<<"ENTER 1 TO PRINT THE VOLUME WITH DEFAULT VALUES: "<<endl;
        cout<<"ENTER 2 TO PRINT THE VOLUME WITH CUSTOM VALUES: "<<endl;
        cout<<"ENTER 3 TO EXIT THE PROGRAM: "<<endl;
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;

        switch(choice){
        case 1: {
        Cylinder c1;
        cout<<"THE VOLUME IS: "<<c1.calculateVolume()<<endl;
        break;
        }

        
        case 2:{
        float r;
        float h;
        cout<<"ENTER RADIUS: "<<endl;
        cin>> r;
        cout<<"ENTER HEIGHT: "<<endl;
        cin>> h;
        Cylinder c1(r,h);
        c1.setRadius(r);
        c1.setHeight(h);
        cout<<"THE VOLUME IS: "<<c1.calculateVolume()<<endl;
        break;
        }

        case 3:{
        cout<<"EXITING PROGRAM..."<<endl;
        break;
        }
        default:{
            cout<<"ENTER A VALID CHOICE!!!"<<endl;
        }
    }

    


    }
    while(choice!=3);
    return 0;
}

