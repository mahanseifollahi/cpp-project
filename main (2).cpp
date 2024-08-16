#include <iostream>  
#include <string>  
using namespace std;  
class Shape {  
protected:  
    float density;    
    float volume;    
public:  
    Shape(float d, float v) : density(d), volume(v) {}  
    virtual float evalVolume() {  
        return volume;  
    }  
    virtual float evalMass() {  
        return density * evalVolume();  
    }  
    virtual float evalSurface() {  
        return 0; 
    }  
};  
class Device : public Shape {  
public:  
    Device(float d, float v) : Shape(d, v) {}  
    float evalVolume() override {  
        return volume; 
    }  
    float evalMass() override {  
        return density * evalVolume();  
    }  
    float evalSurface() override {  
        return 0; 
    }  
};  
class Automobile : public Device {  
private:  
    string fuelType;  
    int seats;  
    string engineType;  
    string gearboxType;  
public:    
    Automobile(float d, float v, string fuel, int seatCount, string engine, string gearbox)  
        : Device(d, v), fuelType(fuel), seats(seatCount), engineType(engine), gearboxType(gearbox) {}  
    void display() {  
        cout << "Fuel Type: " << fuelType <<endl;  
        cout << "Number of Seats: " << seats <<endl;  
        cout << "Engine Type: " << engineType <<endl;  
        cout << "Gearbox Type: " << gearboxType<<endl;  
        cout << "Mass: " << evalMass() <<" kg"<<endl; 
        cout << "Volume: " << evalVolume() <<" m^3"<<endl;   
        cout << "Surface Area: " << evalSurface() <<" m^2"<<endl;   
    }  
    float evalSurface() override {  
        return 20.0; 
    }  
};  
int main() {  
    Automobile myCar(50.0, 20.0, "Petrol", 5, "V6", "Automatic");  
    myCar.display();     
    return 0;  
}