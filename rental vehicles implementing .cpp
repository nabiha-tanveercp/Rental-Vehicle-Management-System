#include "rental vehicles1.h"
using namespace std;


Vehicle::Vehicle(string mo, string mf, int y, float r, int i, bool A) {
    model = mo;
    manufacturer = mf;
    year = y;
    rent_per_day = r;
    VId = i;
    isAvailable = A;
}

int Vehicle::getVId() { return VId; }
bool Vehicle::getAvailability() { return isAvailable; }
void Vehicle::setAvailability(bool s) { isAvailable = s; }
string Vehicle::getModel() { return model; }
float Vehicle::getRent() { return rent_per_day; }
//seprate functions to get list and check models and price range

void searchByModel(List<Vehicle*>* vehicles, string m) {
    bool found = false;
    for (int i = 0; i < vehicles->getSize(); i++) {
        Vehicle* v = vehicles->getData(i);
        if (v && v->getModel() == m) {
            cout << v->getModel() << "  " << v->getRent() << endl;
            found = true;
        }
    }
    if (!found) cout << "No vehicle found!"<<endl;
}

void filterByPrice(List<Vehicle*>* vehicles, float min, float max) {
    for (int i = 0; i < vehicles->getSize(); i++) {
        Vehicle* v = vehicles->getData(i);
        if (v && v->getRent() >= min && v->getRent() <= max) {
            cout << v->getModel() << "   " << v->getRent() << endl;
        }
    }
}


Car::Car(string mo, string mf, int y, float r, int i, bool A)
    : Vehicle(mo, mf, y, r, i, A) {
}

float Car::calculaterent(int d) {
    return d * rent_per_day;
}


Truck::Truck(string mo, string mf, int y, float r, int i, bool A)
    : Vehicle(mo, mf, y, r, i, A) {
}

float Truck::calculaterent(int d) {
    float base = d * rent_per_day;
    return base + base * 0.05f;
}


Customer::Customer(string n, string m, string c, int id)
    : history(20) {
    name = n;
    mobile = m;
    cnic = c;
    customerId = id;
}

int Customer::getId() { return customerId; }

void Customer::addTransaction(Transactions* t) {
    static int i = 0;
    history.setData(i++, t);
}

void Customer::showHistory() {
    cout << "Customer History:\n";
    for (int i = 0; i < 20; i++) {
        Transactions* t = history.getData(i);
        if (t) t->show();
    }
}


Date::Date(int d, int m, int y) {
    this->d = d;
    this->m = m;
    this->y = y;
}

int Date::operator-(Date other) {
    return (y * 365 + m * 30 + d) - (other.y * 365 + other.m * 30 + other.d);
}

void Date::display() {
    cout << d << "-" << m << "-" << y;
}


Transactions::Transactions(int id, Customer* c, Vehicle* v, Date s, Date e)
    : start(s), end(e) {
    this->id = id;
    customer = c;
    vehicle = v;
    days = e - s;
    cost = 0;
}

void Transactions::calculate() {
    cost = vehicle->calculaterent(days);
}

void Transactions::show() {
    cout << "ID: " << id
        << " | Vehicle: " << vehicle->getModel()
        << " | Days: " << days
        << " | Cost: " << cost << endl;
}