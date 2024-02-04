
#include <iostream>
using namespace std;

class Guest {
public:
    string name;
    int age;
    int rating;

    Guest(const string& guestName, int guestAge) : name(guestName), age(guestAge), rating(-1) {}
};

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
        : rooms(initialRooms, 1000), pasta(initialPasta, 200), burger(initialBurger, 100),
          noodles(initialNoodles, 200), shake(initialShake, 200), chicken(initialChicken, 100) {}

    bool sellItem(int choice) {
        int quant;
        switch (choice) {
            case 1:
                cout << "\n\n Enter the number of rooms you want: ";
                cin >> quant;
                if (rooms.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " rooms/rooms have been allotted to you!";
                    return true;
                }
                break;
            case 2:
                cout << "\n\n Enter Pasta Quantity: ";
                cin >> quant;
                if (pasta.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " pasta is the order!";
                    return true;
                }
                break;
            case 3:
                cout << "\n\n Enter Burger Quantity: ";
                cin >> quant;
                if (burger.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " burger is the order!";
                    return true;
                }
                break;
            case 4:
                cout << "\n\n Enter Noodles Quantity: ";
                cin >> quant;
                if (noodles.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " Noodles is the order!";
                    return true;
                }
                break;
            case 5:
                cout << "\n\n Enter Shake Quantity: ";
                cin >> quant;
                if (shake.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " shake is the order!";
                    return true;
                }
                break;
            case 6:
                cout << "\n\n Enter Chicken-roll Quantity: ";
                cin >> quant;
                if (chicken.sellItem(quant)) {
                    cout << "\n\n\t\t" << quant << " chicken-roll is the order!";
                    return true;
                }
                break;
            default:
                cout << "\n Please select the number mentioned above!";
        }
        return false;
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
        double discount = calculateDiscount(totalCollection);

        cout << "\n\n Total collection for the day: " << totalCollection;
        cout << "\n Discount applied: " << discount;
        cout << "\n Total amount after discount: " << totalCollection - discount;
    }

    double calculateDiscount(int totalAmount) const {
        const double discountThreshold = 100;
        const double discountPercentage = 0.1;

        if (totalAmount > discountThreshold) {
            return totalAmount * discountPercentage;
        } else {
            return 0.0;
        }
    }

    void collectFeedback(Guest& guest) {
        cout << "\n\nDear " << guest.name << ", thank you for choosing HASIN HOLY STAR!";
        cout << "\nPlease provide your feedback (1 to 5, where 5 is excellent): ";
        cin >> guest.rating;

        if (guest.rating >= 4) {
            cout << "\nWe're glad you enjoyed your stay! Looking forward to serving you again.";
        } else {
            cout << "\nWe're sorry to hear that. Please let us know how we can improve.";
        }
    }
};

int getChoice() {
    int choice;
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
    return choice;
}

int main() {
    cout << "\n\n\t\tWelcome to HASIN HOLY STAR!";
    cout << "\n\t\tWhere Hospitality Meets Perfection.";

    string guestName;
    int guestAge;

    cout << "\n\n\t\tGuest Login";
    cout << "\nEnter your name: ";
    cin >> guestName;
    cout << "Enter your age: ";
    cin >> guestAge;

    Guest guest(guestName, guestAge);

    Sales sales(20, 20, 20, 20, 20, 20);

    int choice;
    do {
        choice = getChoice();

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                sales.sellItem(choice);
                break;
            case 7:
                sales.displaySalesInfo();
                break;

            case 8:
                sales.collectFeedback(guest);
                cout << "\n\nThank you for visiting HASIN HOLY STAR. We hope to see you again soon!\n";
                break;
            default:
                cout << "\n Please select a valid option!";
        }

    } while (choice != 8);

    return 0;
}
