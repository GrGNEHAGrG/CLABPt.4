#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    int year;
    float price;
    
public:
    Car(string m = "", int y = 0, float p = 0.0) : model(m), year(y), price(p) {}
    
    virtual ~Car() {
        cout << "Car destroyed: " << model << endl;
    }
    
    void inputBasic() {
        cout << "Enter model: ";
        cin.ignore();
        getline(cin, model);
        
        cout << "Enter year: ";
        cin >> year;
        
        cout << "Enter price: $";
        cin >> price;
    }
    
    void displayBasic() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }
    
    virtual void input() {
        inputBasic();
    }
    
    virtual void display() const {
        displayBasic();
        cout << endl;
    }
};

// ElectricCar class
class ElectricCar : public Car {
private:
    float batterySize;
    
public:
    ElectricCar() : batterySize(0.0) {}
    
    ~ElectricCar() override {
        cout << "Destroying Electric Car: " << model << endl;
    }
    
    void input() override {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
    }
    
    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }
};

// GasCar class
class GasCar : public Car {
private:
    float fuelCapacity;
    
public:
    GasCar() : fuelCapacity(0.0) {}
    
    ~GasCar() override {
        cout << "Destroying Gas Car: " << model << endl;
    }
    
    void input() override {
        inputBasic();
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }
    
    void display() const override {
        displayBasic();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }
};

// HybridCar class
class HybridCar : public Car {
private:
    float batterySize;
    float fuelCapacity;
    
public:
    HybridCar() : batterySize(0.0), fuelCapacity(0.0) {}
    
    ~HybridCar() override {
        cout << "Destroying Hybrid Car: " << model << endl;
    }
    
    void input() override {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }
    
    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
};

int main() {
    int n;
    cout << "Enter total number of cars: ";
    cin >> n;
    
    // Create dynamic arrays
    Car** cars = new Car*[n];
    int* types = new int[n];
    
    // Input car data
    for (int i = 0; i < n; i++) {
        int type;
        cout << "Car " << (i+1) << " type:" << endl;
        cout << "[1] Electric" << endl;
        cout << "[2] Gasoline" << endl;
        cout << "[3] Hybrid" << endl;
        cout << "Enter choice: ";
        cin >> type;
        
        types[i] = type;
        
        // Create appropriate car object
        switch (type) {
            case 1:
                cars[i] = new ElectricCar();
                break;
            case 2:
                cars[i] = new GasCar();
                break;
            case 3:
                cars[i] = new HybridCar();
                break;
            default:
                cout << "Invalid type. Creating default car." << endl;
                cars[i] = new Car();
                break;
        }
        
        // Input car details
        cars[i]->input();
    }
    
    // Display all cars
    cout << "\n--- Fleet Information ---" << endl;
    for (int i = 0; i < n; i++) {
        // Use static_cast to call the correct display function
        switch (types[i]) {
            case 1:
                static_cast<ElectricCar*>(cars[i])->display();
                break;
            case 2:
                static_cast<GasCar*>(cars[i])->display();
                break;
            case 3:
                static_cast<HybridCar*>(cars[i])->display();
                break;
            default:
                cars[i]->display();
                break;
        }
    }
    
    // Clean up memory
    cout << "\n--- Cleaning up fleet ---" << endl;
    for (int i = 0; i < n; i++) {
        delete cars[i]; 
    }
    
    delete[] cars;
    delete[] types;
    
    return 0;
}