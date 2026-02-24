#include "Appliance."

Appliance::Appliance() {}

Appliance::Appliance(string n, double p, double h) {
    name = n;
    power = p;
    hours = h;
}

string Appliance::getName() { return name; }
double Appliance::getPower() { return power; }
double Appliance::getHours() { return hours; }

double Appliance::calculateEnergy() {
    return (power * hours) / 1000;
}