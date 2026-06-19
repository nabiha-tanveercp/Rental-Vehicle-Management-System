# Rental-Vehicle-Management-System
A C++ OOP-based Vehicle Rental Management System with customer booking, transaction records, vehicle filtering, templates, and operator overloading.
# Vehicle Rental Management System

## Overview

The Vehicle Rental Management System is a C++ Object-Oriented Programming (OOP) project developed to manage vehicle rentals, customer records, and transaction history. The system allows customers to book vehicles, view available vehicles, search vehicles by model, filter vehicles by price range, and maintain rental records.

This project demonstrates the practical implementation of OOP concepts and data management techniques through a real-world vehicle rental scenario.



## Features

### Vehicle Management

* Store and manage vehicle records.
* Support for multiple vehicle types such as Cars and Trucks.
* Track vehicle availability status.
* Display all available vehicles with details.

### Customer Management

* Add and manage customer records.
* Store customer information including:

  * Name
  * Mobile Number
  * CNIC
  * Customer ID

### Vehicle Booking System

* Customers can rent available vehicles.
* The system checks vehicle availability before booking.
* If a vehicle is already booked, an error message is displayed.
* Successfully booked vehicles are marked as unavailable.

### Transaction Management

* Create rental transactions for each booking.
* Maintain rental history for customers.
* Calculate rental duration using dates.
* Generate rental costs based on vehicle type and rental period.

### Search and Filtering

* Search vehicles by model.
* Filter vehicles according to a specified price range.
* Display matching vehicles with rental details.

### Rental Cost Calculation

* Calculate rent according to vehicle type.
* Trucks include an additional rental charge.
* Rental duration is calculated automatically using operator overloading.

---

-> Object-Oriented Programming Concepts Implemented

> Inheritance

* `Car` and `Truck` classes inherit from the `Vehicle` base class.

> Polymorphism

* Virtual functions are used to calculate rent differently for different vehicle types.
* Runtime polymorphism is achieved through the `calculaterent()` function.

> Encapsulation

* Class data members are protected and accessed through member functions.

> Abstraction

* Vehicle behavior is defined through an abstract base class using pure virtual functions.

-> Operator Overloading

* Date subtraction operator (`operator-`) is overloaded to calculate rental duration.

-> Templates

* Generic `List<T>` template class is implemented for managing:

  * Vehicles
  * Customers
  * Transactions

-> Dynamic Memory Allocation

* Dynamic arrays and objects are managed using pointers and templates.

-> Pointer-Based Data Management

* Vehicle, Customer, and Transaction records are managed through pointer-based structures.

-> System Workflow

1. Add customer information.
2. View available vehicles.
3. Select a vehicle for booking.
4. Check vehicle availability.
5. Create a rental transaction.
6. Calculate rental duration and cost.
7. Store transaction history.
8. Allow searching and filtering of vehicles.
9. Display customer rental history.


-> Project Structure

text
VehicleRentalSystem.h
VehicleRentalSystem.cpp
main.cpp
README.md

->Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Templates
* Dynamic Memory Allocation
* Operator Overloading
* Polymorphism
* Inheritance
* Encapsulation
* Abstraction


Main Menu

<img width="302" height="378" alt="image" src="https://github.com/user-attachments/assets/de969da8-a3f8-49a8-8762-6af10d3ed535" />


 Vehicle Booking

<img width="353" height="508" alt="image" src="https://github.com/user-attachments/assets/2dc4a592-b190-4329-9be3-e8a19632697f" />


 Search by Model
<img width="317" height="497" alt="image" src="https://github.com/user-attachments/assets/b226a1da-2381-43e9-88e1-1ed75e374490" />


 Filter by Price

<img width="227" height="293" alt="image" src="https://github.com/user-attachments/assets/c3247bc2-1832-4116-9f6a-1e63258b91c6" />


Customer History

<img width="618" height="317" alt="image" src="https://github.com/user-attachments/assets/a0608079-de7f-4121-a18f-e34cf7a5b13e" />


---

> Future Improvements

-> File Handling

* Store customer records permanently in files.
* Store transaction history in files.
* Preserve vehicle availability data between program executions.

-> Data Security

* Implement secure storage of customer information.
* Add validation and protection for sensitive customer data.
* Improve reliability and integrity of stored records.

-> User Authentication

* Add admin and customer login systems.
* Restrict access to sensitive operations.

-> Database Integration

* Replace in-memory storage with a database system.
* Improve scalability and data management.

-> Graphical User Interface (GUI)

* Convert the console-based application into a desktop or mobile application.
* Improve user experience with a modern interface.

-> Mobile Application Development

* Develop a complete vehicle rental application.
* Allow customers to browse and book vehicles directly from mobile devices.

---

## Author
Nabiha Tanveer
Developed as a 2nd Semester Final Project for Object-Oriented Programming using C++.
