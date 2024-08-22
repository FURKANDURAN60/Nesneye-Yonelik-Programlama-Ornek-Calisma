#include <iostream>
#include <string>


using std::string;

    class Vehicle
    {
    protected :
            string manufacturer ;
            int year ;
            string color ;
        public : 
            string getManufacturer(){ return manufacturer ;} 
            void setManufacturer(string manufacturer){ this->manufacturer = manufacturer ;}

            int getYear(){ return year ;} 
            void setYear(int year){ this->year = year ;}

            string getColor(){ return color ;} 
            void setColor(string color){ this->color = color ;}

            Vehicle(){
                std::cout << "\nAn instance has been derived from Vehicle." << std::endl ;
            }

            Vehicle(string manufacturer , int year , string color) : Vehicle()
            {
                std::cout << "\nAn instance with full parameters has been derived from Vehicle." << std::endl ;
                this->manufacturer = manufacturer;
                this->year = year ;
                this->color = color ;
            }

            virtual void start()
            {
                std::cout << "Vehicle has been started." << std::endl ;
            }
            
            virtual void stop()
            {
                std::cout << "Vehicle has been stopped." << std::endl ;
            }

            virtual void drive()
            {
                std::cout << "Vehicle is being driven." << std::endl ;
            }

            virtual string toString()
            {
                return manufacturer + " - " + std::to_string(year) + " - " + color ;
            }

    };

    class Car : public Vehicle
    {
        public :
            Car()
            {
                std::cout << "\nAn instance has been derived from Car." << std::endl ;
            }
            
            Car(string manufacturer , int year , string color) : Vehicle(manufacturer , year , color)
            {
                std::cout << "\nAn instance with full parameters has been derived from Car." << std::endl ;
                
            }

            void openSunroof()
            {
                std::cout << "The sunroof has been opened." << std::endl ;
            }

            void drive() override
            {
                std::cout << "The car manufacturer by " << this->manufacturer << " is being driven." << std::endl;
            }
    };

    class Truck : public Vehicle
    {
        public : 
            Truck()
            {
                std:: cout << "\nAn instance has been derived from Truck." << std::endl ;
            }

            Truck(string manufacturer , int year , string color) : Vehicle(manufacturer , year , color)
            {
                std:: cout << "\nAn instance with full parameters has been derived from Truck." << std::endl ;
            }

            void transport()
            {
                std::cout<< " The transport took place." << std::endl ;
            }

            void drive() override
            {
                std::cout << "The truck manufacturer by " << this->manufacturer << " is being driven." << std::endl;
            }
    };

    class Bus : public Vehicle
    {
        public :
            Bus()
            {
                std:: cout << "\nAn instance has been derived from Bus." << std::endl ;
            }

            Bus(string manufacturer , int year , string color) : Vehicle(manufacturer , year , color)
            {
                std:: cout << "\nAn instance with full parameters has been derived from Bus." << std::endl ;
            }

            void Schduling()
            {
                std::cout<< "Schduled." << std::endl ;
            }

            void drive() override
            {
                std::cout << "The bus manufacturer by " << this->manufacturer << " is being driven." << std::endl;
            }
    };

    class SchoolBus : public Bus
    {
        public :
            SchoolBus(string manufacturer,int year , string color) : Bus(manufacturer,year,color) 
            {
                std:: cout << "\nAn instance with full parameters has been derived from School Bus." << std::endl ;
            }

            void getFare()
            {
                std:: cout << "getFare has been called." << std::endl ;
            }

            void drive() override
            {
                std::cout << "The school bus manufacturer by " << this->manufacturer << " is being driven." << std::endl;
            }
    };

    int main()
    {
        Vehicle item1 = Vehicle("Ford",2019,"White");
        std::cout << "Vehicle " << item1.toString() << std::endl ;

        Car item2 = Car() ;
        item2.setManufacturer("TOGG") ;
        item2.setYear(2023);
        item2.setColor("Pink");
        std::cout << "Vehicle " << item2.toString() << std::endl ;
        item2.openSunroof();
        

        Car item3 = Car("Opel" ,2020,"Black");
        item3.setManufacturer("TOGG") ;
        std::cout << "Vehicle " << item3.toString() << std::endl ;
        item3.openSunroof();
        

        Bus item4 = Bus("Topcam" ,2016,"Red");
        std::cout << "Vehicle " << item4.toString() << std::endl ;
        item4.Schduling();
        

        SchoolBus item5 = SchoolBus("Isuzu",2015,"Yellow");
        std::cout << "Vehicle " << item5.toString() << std::endl ;
        item5.Schduling();
        item5.getFare();
        

        item2.drive();
        item2.stop();

        item3.drive();
        item3.stop();

        item4.drive();
        item4.stop();

        item5.drive();
        item5.stop();



        
        return 0 ;
    }