#include<bits/stdc++.h>

using namespace std;

class Item {
public:
    int quantity;
    int soldQuantity;
    int price;

    Item(int initialQuantity, int itemPrice) : quantity(initialQuantity), soldQuantity(0), price(itemPrice) {}

    bool sellItem(int quant) {
        if (quantity - soldQuantity >= quant) {
            soldQuantity += quant;
            return true;
        } else {
            cout << "\n\tOnly " << quantity - soldQuantity << " remaining.";
            return false;
        }
    }

    int calculateTotal() const {
        return soldQuantity * price;
    }

    int getRemaining() const {
        return quantity - soldQuantity;
    }
};

class Sales {
public:
    Item rooms;
    Item pasta;
    Item burger;
    Item noodles;
    Item shake;
    Item chicken;

    Sales(int initialRooms, int initialPasta, int initialBurger, int initialNoodles, int initialShake, int initialChicken)
        : rooms(initialRooms, 1200), pasta(initialPasta, 250), burger(initialBurger, 120),
          noodles(initialNoodles, 250), shake(initialShake, 250), chicken(initialChicken, 150) {}

    void sellItem(int choice) {
        int quant;
        switch (choice) {
            case 1:
                cout << "\n\n Enter the number of rooms you want: ";
                cin >> quant;
                if (rooms.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " rooms/rooms have been allotted to you!";
                }
                break;

            case 2:
                cout << "\n\n Enter Pasta Quantity: ";
                cin >> quant;
                if (pasta.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " pasta is the order!";
                }
                break;

            case 3:
                cout << "\n\n Enter Burger Quantity: ";
                cin >> quant;
                if (burger.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " burger is the order!";
                }
                break;

            case 4:
                cout << "\n\n Enter Noodles Quantity: ";
                cin >> quant;
                if (noodles.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " Noodles is the order!";
                }
                break;

            case 5:
                cout << "\n\n Enter Shake Quantity: ";
                cin >> quant;
                if (shake.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " shake is the order!";
                }
                break;

            case 6:
                cout << "\n\n Enter Chicken-roll Quantity: ";
                cin >> quant;
                if (chicken.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " chicken-roll is the order!";
                }
                break;

            default:
                cout << "\n Please select the number mentioned above!";
        }
    }

    void displaySalesInfo() const {
        cout << "\n\t\tDetails of sales and collection";
        displayItemInfo("Rooms", rooms);
        displayItemInfo("Pasta", pasta);
        displayItemInfo("Burger", burger);
        displayItemInfo("Noodles", noodles);
        displayItemInfo("Shake", shake);
        displayItemInfo("Chicken-roll", chicken);
        displayTotalCollection();
    }

    void displayItemInfo(const string& itemName, const Item& item) const {
        cout << "\n\n number of " << itemName << " we had: " << item.quantity;
        cout << "\n\n number of " << itemName << " sold: " << item.soldQuantity;
        cout << "\nRemaining " << itemName << ": " << item.getRemaining();
        cout << "\n\n Total " << itemName << " collection for the day: " << item.calculateTotal();
    }

    void displayTotalCollection() const {
        int totalCollection = rooms.calculateTotal() + pasta.calculateTotal() + burger.calculateTotal() +
                              noodles.calculateTotal() + shake.calculateTotal() + chicken.calculateTotal();
        cout << "\n\n Total collection for the day: " << totalCollection;
    }
};

int main() {
    cout << "\n\n\t\tWelcome to HASIN HOLY STAR!";
    cout << "\n\t\tWhere Hospitality Meets Perfection.";

    Sales sales(5, 10, 15, 20, 25, 30);
    int choice;
    do {
        cout << "\n\n\t\t\t Please select from the menu options";
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

        if (choice == 7) {
            sales.displaySalesInfo();
        } else if (choice != 8) {
            sales.sellItem(choice);
        }

    } while (choice != 8);

    return 0;
}
