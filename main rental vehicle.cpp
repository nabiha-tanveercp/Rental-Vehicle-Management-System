#include "rental vehicles1.h"
using namespace std;

int main() {

    List<Vehicle*>* vehicles = new List<Vehicle*>(100);
    vehicles->setData(0, new Car("Civic", "Honda", 2020, 5000, 1, true));
    vehicles->setData(1, new Truck("Mazda", "Mazda", 2018, 8000, 2, true));

    List<Customer*>* customers = new List<Customer*>(50);// customer template 
    List<Transactions*>* records = new List<Transactions*>(50);// transaction template

    int custCount = 0, recCount = 0;
    
    int choice;
    do {
        cout << "\n1.Add Customer\n2.View Vehicles\n3.Book\n4.Search Model\n5.Filter Price\n6.History\n0.Exit"<<endl;
        cin >> choice;

        if (choice == 1) {
           
            string n, m, c;
            int id;

            cout << "Name: "<<endl; 
            cin>>n;
            cout << "Mobile: "<<endl; 
            cin>>m;
            cout << "CNIC:  "<<endl; 
            cin>>c;
            cout << "ID: "<<endl; 
            cin >> id;

            customers->setData(custCount++, new Customer(n, m, c, id));
        }

        else if (choice == 2) {
            for (int i = 0;i < 100;i++) {
                Vehicle* v = vehicles->getData(i);
                if (v) {
                    cout << v->getVId() << " | " << v->getModel()
                        << " | " << v->getRent() << endl;
                    if (v->getAvailability())
                        cout << "Available" << endl;
                    else

                        cout << "Booked" << endl;
                }
            }
        }

        else if (choice == 3) {
            int cid, vid;
            cout << "Customer ID: "<<endl;
            cin >> cid;
            cout << "Vehicle ID: "<<endl; 
            cin >> vid;

            Customer* cust = nullptr;
            Vehicle* veh = nullptr;

            for (int i = 0;i < custCount;i++) {
                if (customers->getData(i)->getId() == cid)
                    cust = customers->getData(i);
            }

            for (int i = 0;i < 100;i++) {
                Vehicle* v = vehicles->getData(i);
                if (v && v->getVId() == vid)
                    veh = v;
            }

            if (!cust || !veh || !veh->getAvailability()) {
                cout << "Error"<<endl;
                continue;
            }

            int d1, m1, y1, d2, m2, y2;
            cout << "Enter start (dd mm yyyy): "<<endl;
            cin >> d1 >> m1 >> y1;
            cout << "Enter end (dd mm yyyy): "<<endl;
            cin >> d2 >> m2 >> y2;

            Date s(d1, m1, y1), e(d2, m2, y2);

            Transactions* t = new Transactions(recCount + 1, cust, veh, s, e);
            t->calculate();

            veh->setAvailability(false);
            records->setData(recCount++, t);
            cust->addTransaction(t);

            cout << "Booking Done!"<<endl;
        }

        else if (choice == 4) {
          
            string m;
            cout << "Enter model: ";
            cin>>m;
            searchByModel(vehicles, m);
        }

        else if (choice == 5) {
            float min, max;
            cout << "Enter min max: "<<endl;
            cin >> min >> max;
            filterByPrice(vehicles, min, max);
        }

        else if (choice == 6) {
            int id;
            cout << "Enter Customer ID: "<<endl;
            cin >> id;

            for (int i = 0;i < custCount;i++) {
                if (customers->getData(i)->getId() == id)
                    customers->getData(i)->showHistory();
            }
        }

    } while (choice != 0);

    return 0;
}