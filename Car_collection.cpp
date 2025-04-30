#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;
    
public:
    Car(string m = "", int y = 0, double p = 0.0) : model(m), year(y), price(p) {
        // Removed the cout from here to prevent initial message
    }
    
    // Destructor to clean up
    ~Car() {
        if (model != "") {  // Only print when model has been set
            cout << "Car destroyed: " << model << endl;
        }
    }
    
    // Method to input car details
    void input() {
        cout << "Enter car model: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, model);
        
        cout << "Enter car year: ";
        cin >> year;
        
        cout << "Enter car price: $";
        cin >> price;
        
        cout << "Car created: " << model << " (" << year << ") - $" << price << endl;
    }
    
    // Method to display car details
    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }
};

class CarCollection {
private:
    Car* cars; // Dynamically allocated array of Car objects
    int count; // Number of cars in the collection
    
public:
    CarCollection() {
        cout << "How many cars do you want to enter? ";
        cin >> count;
        
        cars = new Car[count]; // Allocate memory for the cars
        
        // Input details for each car
        for (int i = 0; i < count; i++) {
            cout << "Enter details for car " << (i+1) << ":\n";
            cars[i].input();
        }
    }
    
    ~CarCollection() {
        delete[] cars; // Free memory allocated for the cars
        cout << "Car collection destroyed\n";
    }
    
    void displayCars() const {
        cout << "\n--- Car Collection ---\n";
        for (int i = 0; i < count; i++) {
            cars[i].display();
        }
    }
};

int main() {
    cout << "Welcome to the Car Collection Program\n";
    
    CarCollection myCollection; // Create a CarCollection object
    
    myCollection.displayCars(); 
    
    return 0;
}
