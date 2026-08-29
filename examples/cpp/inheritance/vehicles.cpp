#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Vehicle {
public:
    Vehicle(std::string manufacturer, int year, std::string color)
        : manufacturer_(std::move(manufacturer)), year_(year), color_(std::move(color)) {}

    virtual ~Vehicle() = default;

    const std::string& manufacturer() const noexcept { return manufacturer_; }
    int year() const noexcept { return year_; }
    const std::string& color() const noexcept { return color_; }

    virtual void start() const { std::cout << "Arac calisti.\n"; }
    virtual void drive() const { std::cout << "Arac hareket ediyor.\n"; }
    virtual void stop() const { std::cout << "Arac durdu.\n"; }

    virtual std::string description() const {
        std::ostringstream output;
        output << manufacturer_ << " | " << year_ << " | " << color_;
        return output.str();
    }

private:
    std::string manufacturer_;
    int year_;
    std::string color_;
};

class Car final : public Vehicle {
public:
    using Vehicle::Vehicle;

    void drive() const override {
        std::cout << manufacturer() << " otomobil yolda ilerliyor.\n";
    }

    void open_sunroof() const { std::cout << "Acili tavan acildi.\n"; }
};

class Truck final : public Vehicle {
public:
    using Vehicle::Vehicle;

    void drive() const override {
        std::cout << manufacturer() << " kamyon yuk tasiyor.\n";
    }
};

class Bus : public Vehicle {
public:
    using Vehicle::Vehicle;

    void drive() const override {
        std::cout << manufacturer() << " otobus sefer yapiyor.\n";
    }
};

class SchoolBus final : public Bus {
public:
    using Bus::Bus;

    void drive() const override {
        std::cout << manufacturer() << " okul otobusu ogrencileri tasiyor.\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("TOGG", 2024, "Mavi"));
    vehicles.push_back(std::make_unique<Truck>("Ford", 2021, "Beyaz"));
    vehicles.push_back(std::make_unique<Bus>("Mercedes", 2022, "Kirmizi"));
    vehicles.push_back(std::make_unique<SchoolBus>("Isuzu", 2023, "Sari"));

    for (const auto& vehicle : vehicles) {
        std::cout << "\n" << vehicle->description() << '\n';
        vehicle->start();
        vehicle->drive();  // Calisma zamaninda dogru alt sinif metodu secilir.
        vehicle->stop();
    }

    Car car("Opel", 2020, "Siyah");
    std::cout << '\n' << car.description() << '\n';
    car.open_sunroof();
}
