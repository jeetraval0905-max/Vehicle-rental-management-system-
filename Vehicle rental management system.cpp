/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle
{
protected:
    int number;
    string model;
    int rent;

public:
    // Constructor
    Vehicle(int n, string m, int r)
    {
        number = n;
        model = m;
        rent = r;
    }

    // Display vehicle details
    virtual void display()
    {
        cout << "\nVehicle Number: " << number;
        cout << "\nModel: " << model;
        cout << "\nRent Per Day: Rs. " << rent << endl;
    }

    // Calculate rent
    virtual int calculateRent(int days)
    {
        return rent * days;
    }

    int getNumber()
    {
        return number;
    }

    string getModel()
    {
        return model;
    }
};

// Derived class
class Car : public Vehicle
{
public:
    Car(int n, string m, int r) : Vehicle(n, m, r)
    {
    }

    void display() override
    {
        cout << "\nType: Car";
        Vehicle::display();
    }
};

// Main function
int main()
{
    Car c1(101, "Hyundai i20", 1500);
    Car c2(102, "Honda City", 2000);

    int choice, days, number, lateDays;
    int fine, total;
    bool rented1 = false;
    bool rented2 = false;

    do
    {
        cout << "\n===== VEHICLE RENTAL SYSTEM =====";
        cout << "\n1. Display Vehicles";
        cout << "\n2. Rent Vehicle";
        cout << "\n3. Return Vehicle";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            c1.display();
            c2.display();
        }

        else if (choice == 2)
        {
            cout << "\nEnter vehicle number (101 or 102): ";
            cin >> number;

            cout << "Enter rental days: ";
            cin >> days;

            if (days <= 0)
            {
                cout << "Invalid number of days!";
            }
            else if (number == 101 && !rented1)
            {
                total = c1.calculateRent(days);
                rented1 = true;

                cout << "Vehicle rented successfully!";
                cout << "\nRental Amount: Rs. " << total;
            }
            else if (number == 102 && !rented2)
            {
                total = c2.calculateRent(days);
                rented2 = true;

                cout << "Vehicle rented successfully!";
                cout << "\nRental Amount: Rs. " << total;
            }
            else if (number == 101 || number == 102)
            {
                cout << "Vehicle is already rented!";
            }
            else
            {
                cout << "Vehicle not found!";
            }
        }

        else if (choice == 3)
        {
            cout << "\nEnter vehicle number to return: ";
            cin >> number;

            if (number == 101 && rented1)
            {
                cout << "Enter late days (0 if on time): ";
                cin >> lateDays;

                if (lateDays < 0)
                {
                    cout << "Invalid number of late days!";
                    continue;
                }

                fine = lateDays * 1000;

                cout << "\nLate Fine: Rs. " << fine;
                cout << "\nVehicle returned successfully!";

                rented1 = false;
            }
            else if (number == 102 && rented2)
            {
                cout << "Enter late days (0 if on time): ";
                cin >> lateDays;

                if (lateDays < 0)
                {
                    cout << "Invalid number of late days!";
                    continue;
                }

                fine = lateDays * 1000;

                cout << "\nLate Fine: Rs. " << fine;
                cout << "\nVehicle returned successfully!";

                rented2 = false;
            }
            else
            {
                cout << "Vehicle is not currently rented!";
            }
        }

        else if (choice == 4)
        {
            cout << "\nThank you for using Vehicle Rental System!";
        }

        else
        {
            cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}
