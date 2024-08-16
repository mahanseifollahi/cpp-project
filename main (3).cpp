#include <iostream>  
#include <string>  
using namespace std;  
class Shape {  
protected:  
    float density;  
    float volume;  
public:  
    Shape(float d, float v) : density(d), volume(v) {}  
    float evalVolume() {  
        return volume;  
    }  
    float evalMass() {  
        return density * evalVolume();  
    }  
    virtual float evalSurface() {  
        return 20.0;  
    }  
};  
class Engine {  
private:  
    string engineType;  
public:  
    Engine(string type) : engineType(type) {}  
    string getEngineType() {  
        return engineType;  
    }  
};  
class Gearbox {  
private:  
    string gearboxType;  
public:  
    Gearbox(string type) : gearboxType(type) {}  

    string getGearboxType() {  
        return gearboxType;  
    }  
};  
class Automobile {  
private:  
    Shape shape;           
    string fuelType;  
    int seats;  
    Engine engine;         
    Gearbox gearbox;        
public:  
    Automobile(float d, float v, string fuel, int seatCount, string engineType, string gearboxType)  
        : shape(d, v), fuelType(fuel), seats(seatCount), engine(engineType), gearbox(gearboxType) {}  
    void display() {  
        cout << "Fuel Type: " << fuelType << endl;  
        cout << "Number of Seats: " << seats << endl;  
        cout << "Engine Type: " << engine.getEngineType() << endl;  
        cout << "Gearbox Type: " << gearbox.getGearboxType() << endl;  
        cout << "Mass: " << shape.evalMass() << " kg" << endl;  
        cout << "Volume: " << shape.evalVolume() << " m^3" << endl;  
        cout << "Surface Area: " << shape.evalSurface() << " m^2" << endl;  
    }  
    float evalSurface() {  
        return 20.0; 
    }  
};  
int main() {  
    Automobile car(50.0, 20.0, "Petrol", 5, "V6", "Automatic");  
    car.display();  
    return 0;  
}