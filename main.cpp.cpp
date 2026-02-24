#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Appliance {
public:
    string name;
    double power;   // in watts
    double hours;   // daily usage

    double calculateEnergy() {
        return (power * hours) / 1000;  // kWh
    }
};

vector<Appliance> appliances;

void saveToFile() {
    ofstream file("appliances.txt");
    for (auto a : appliances) {
        file << a.name << " " << a.power << " " << a.hours << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("appliances.txt");
    Appliance a;
    while (file >> a.name >> a.power >> a.hours) {
        appliances.push_back(a);
    }
    file.close();
}

void registerAppliance() {
    Appliance a;
    cout << "Enter appliance name: ";
    cin >> a.name;

    cout << "Enter power rating (W): ";
    cin >> a.power;

    cout << "Enter daily usage hours: ";
    cin >> a.hours;

    if (a.power <= 0 || a.hours < 0 || a.hours > 24) {
        cout << "Invalid input!\n";
        return;
    }

    appliances.push_back(a);
    cout << "Appliance added successfully!\n";
}

void viewAppliances() {
    for (auto a : appliances) {
        cout << "\nName: " << a.name;
        cout << "\nPower: " << a.power << "W";
        cout << "\nHours: " << a.hours;
        cout << "\nEnergy: " << a.calculateEnergy() << " kWh\n";
    }
}

void calculateBill() {
    double totalEnergy = 0;
    double tariff;

    for (auto a : appliances)
        totalEnergy += a.calculateEnergy();

    cout << "Enter tariff per kWh: ";
    cin >> tariff;

    if (tariff <= 0) {
        cout << "Invalid tariff!\n";
        return;
    }

    double totalCost = totalEnergy * tariff;

    cout << "\nTotal Energy: " << totalEnergy << " kWh";
    cout << "\nTotal Cost: " << totalCost << endl;

    ofstream bill("billing_summary.txt");
    bill << "Total Energy: " << totalEnergy << " kWh\n";
    bill << "Total Cost: " << totalCost << endl;
    bill.close();
}

int main() {
    loadFromFile();
    int choice;

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Calculate Bill\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerAppliance(); break;
            case 2: viewAppliances(); break;
            case 3: calculateBill(); break;
            case 4: saveToFile(); break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}