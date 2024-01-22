#include <iostream>

using namespace std;

int main() {
    int quant;
    int choice;
    int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;
    int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;
    int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;

    cout << "\n\t Quantity of items we have";
    cout << "\n  Rooms available: ";
    cin >> Qrooms;
    cout << "\n Quantity of pasta: ";
    cin >> Qpasta;
    cout << "\n Quantity of burger: ";
    cin >> Qburger;
    cout << "\n Quantity of noodles: ";
    cin >> Qnoodles;
    cout << "\n Quantity of shake: ";
    cin >> Qshake;
    cout << "\n Quantity of chicken: ";
    cin >> Qchicken;

m:
    cout << "\n\t\t\t Please select from the menu options";
    cout << "\n1) Rooms";
    cout << "\n2) Pasta";
    cout << "\n3) Burger";
    cout << "\n4) Noodles";
    cout << "\n5) Shake";
    cout << "\n6) Chicken-roll";
    cout << "\n7) Information regarding sales and collection";
    cout << "\n8) Exit";

    cout << "\n\n Please Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\n\n Enter the number of rooms you want: ";
        cin >> quant;
        if (Qrooms - Srooms >= quant) {
            Srooms = Srooms + quant;
            Total_rooms = Total_rooms + quant * 1200;
            cout << "\n\n\t\t" << quant << " rooms/rooms have been allotted to you!";
        } else
            cout << "\n\tOnly " << Qrooms - Srooms << " Rooms Remaining in the hotel";
        break;

    case 2:
        cout << "\n\n Enter Pasta Quantity: ";
        cin >> quant;
        if (Qpasta - Spasta >= quant) {
            Spasta = Spasta + quant;
            Total_pasta = Total_pasta + quant * 250;
            cout << "\n\n\t\t" << quant << " pasta is the order!";
        } else
            cout << "\n\tOnly " << Qpasta - Spasta << " pasta Remaining in hotel";
        break;

    case 3:
        cout << "\n\n Enter Burger Quantity: ";
        cin >> quant;
        if (Qburger - Sburger >= quant) {
            Sburger = Sburger + quant;
            Total_burger = Total_burger + quant * 120;
            cout << "\n\n\t\t" << quant << " burger is the order!";
        } else
            cout << "\n\tOnly " << Qburger - Sburger << " burger Remaining in hotel";
        break;
    }
