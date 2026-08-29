#include <iostream>
#include <string>
using  std::string;


class Vehicle{
protected: 
    string manufacturer;
    int year;
    string color;
public: 
    
    string getManufacturer() {
        return manufacturer;
    }
    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    int getYear(){
        return year;
    }
    void setYear(int year) {
        this->year = year;
    }

    string getColor(){
        return color;
    }
    void setColor(string color){
        this->color = color;
    }
    
    Vehicle(){
        std::cout << "\nAn instance has been derived from Vehicle class.\n";
    }

    Vehicle(string manufacturer, int year, string color): Vehicle(){
        
        std::cout << "\nAn instance with full parameters has been derived from Vehicle class.\n";
        this->manufacturer = manufacturer;
        this->year = year;  
        this->color = color;

    }

    virtual void start(){
            std::cout << "Vehicle has started............" << std::endl;
    }
    virtual void stop(){
        std::cout << "Vehicle has stopped............" << std::endl;
    }
    virtual void drive(){
        std::cout << "Vehicle is driving............" << std::endl;
    }

    virtual string ToString(){
    return  this->manufacturer + " -- " + std::to_string(this->year) + " -- "  + this->color;
}    

};

class Car : public Vehicle{
    
    public:
    Car(){
        std::cout << "\nAn instance has been derived from Car class.\n";
    }

    Car(string manufacturer, int year, string color)
    : Vehicle(manufacturer, year, color) {
        std::cout << "\nAn instance full parameters has been derived from Car class.\n";
        
    }

    void openSunroof(){
        std::cout << "Sunroof is open." << std::endl;
    }

    void start() override{
        std::cout << "The car manufacturer " << this->manufacturer << " has started............" << std::endl;
    }

};

class Truck : public Vehicle{

    public:
    Truck(){
        std::cout << "\nAn instance has been derived from Truck class.\n";
    }
    
    Truck(string manufacturer, int year, string color)
    : Vehicle(manufacturer, year, color) {
        std::cout << "\nAn instance full parameters has been derived from Truck class.\n";   
    }

    void Transport(){
        std::cout << "Transporting goods." << std::endl;
    }

    void start() override{
        std::cout << "The truck manufacturer " << this->manufacturer << " has started............" << std::endl;
    }
};

class Bus : public Vehicle{

    public:
    Bus(){
        std::cout << "\nAn instance has been derived from Bus class.\n";
    }
    
    Bus(string manufacturer, int year, string color)
    : Vehicle(manufacturer, year, color) {
        std::cout << "\nAn instance full parameters has been derived from Bus class.\n";   
    }

    void Scheduling(){
        std::cout << "Scheduling trips for people." << std::endl;
    }

    void start() override{
        std::cout << "The bus manufacturer " << this->manufacturer << " has started............" << std::endl;
    }
};

class SchoolBus : public Bus{

    public:
    SchoolBus(){
        std::cout << "\nAn instance has been derived from SchoolBus class.\n";
    }
    
    SchoolBus(string manufacturer, int year, string color)
    : Bus(manufacturer, year, color) {
        std::cout << "\nAn instance full parameters has been derived from SchoolBus class.\n";   
    }

    void TransportStudents(){
        std::cout << "Transporting students." << std::endl;
    }

    void start() override{
        std::cout << "The school bus manufacturer " << this->manufacturer << " has started............" << std::endl;
    }
};

int main() {
    
    Vehicle item1 = Vehicle("Skoda", 2024, "Black");
    std::cout << "Vehicle " << item1.getManufacturer() << std::endl;
    
    Car item2 = Car();
    item2.setManufacturer("TOG");
    std::cout << "Vehicle " << item2.getManufacturer() << std::endl;
    std:: cout << item2.ToString() << std::endl;
    item2.start();
    item2.drive();
    item2.openSunroof();
    item2.stop();

    Car item3 = Car("Opel", 2026, "Blue");
    std::cout<< "Vehicle " << item3.getManufacturer() << std::endl;
    std::cout << item3.ToString() << std::endl;
    item3.start();
    item3.drive();  
    item3.openSunroof();
    item3.stop();

    SchoolBus item4 = SchoolBus("Mercedes", 2025, "White");
    std::cout<< "Vehicle " << item4.getManufacturer() << std::endl;
    std::cout << item4.ToString() << std::endl;
    item4.start();
    item4.drive();
    item4.Scheduling();
    item4.TransportStudents();
    item4.stop();

    char c = getchar();
    return 0;
}
