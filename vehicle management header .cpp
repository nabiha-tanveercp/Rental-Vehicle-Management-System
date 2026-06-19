#ifndef RENTAL_VEHICLES1_H
#define RENTAL_VEHICLES1_H

#include <string>
#include <iostream>
using namespace std;

// TEMPLATE + implementation of template due to errors
template<typename L>
class List {
private:
    int size;
    L* elements;//dynamic memory allocation
public:
    List(int s) {
        size = s;
        elements = new L[size];
        for (int i = 0; i < size; i++)
            elements[i] = nullptr;
    }

    void setData(int i, L value) {
        if (i >= 0 && i < size)
            elements[i] = value;
    }

    L getData(int i) {
        if (i >= 0 && i < size)
            return elements[i];
        return nullptr;
    }

    int getSize() { return size; }

    ~List() {
        delete[] elements;
    }
};

// VEHICLE 
class Vehicle {
protected:
    string model;
    string manufacturer;
    int year;
    float rent_per_day;
    int VId;
    bool isAvailable;

public:
    Vehicle(string, string, int, float, int, bool);

    int getVId();
    bool getAvailability();
    void setAvailability(bool);
    string getModel();
    float getRent();

   

    virtual float calculaterent(int) = 0;//polymorphism
};
void searchByModel(List<Vehicle*>*, string);
void filterByPrice(List<Vehicle*>*, float, float);

//  CAR 
class Car : public Vehicle {
public:
    Car(string, string, int, float, int, bool);
    float calculaterent(int);
};

//  TRUCK
class Truck : public Vehicle {
public:
    Truck(string, string, int, float, int, bool);
    float calculaterent(int);
};

//  FORWARD TO TELL CUSTOMER THAT THIS CLASS EXSITS
class Transactions;

//  CUSTOMER 
class Customer {
private:
    string name, mobile, cnic;
    int customerId;
    List<Transactions*> history;

public:
    Customer(string, string, string, int);

    int getId();
    void addTransaction(Transactions*);
    void showHistory();
};

//DATE 
class Date {
private:
    int d, m, y;
public:
    Date(int, int, int);
    int operator-(Date);//overloading
    void display();
};

// TRANSACTIONS 
class Transactions {
private:
    int id;
    Customer* customer;
    Vehicle* vehicle;
    Date start, end;
    int days;
    double cost;

public:
    Transactions(int, Customer*, Vehicle*, Date, Date);

    void calculate();
    void show();
};

#endif#pragma once
