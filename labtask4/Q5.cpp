#include <iostream>
#include <vector>
using namespace std;

class MenuItem {
public:
    string name, type;
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}

    string addOrder(string itemName) {
        for (auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (auto& order : orders) {
            for (auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "";
        MenuItem* cheapest = &menu[0];
        for (auto& item : menu) {
            if (item.price < cheapest->price) cheapest = &item;
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto& item : menu) {
            if (item.type == "drink") drinks.push_back(item.name);
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (auto& item : menu) {
            if (item.type == "food") foods.push_back(item.name);
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Espresso", "drink", 2.5},
        {"Latte", "drink", 3.0},
        {"Muffin", "food", 2.0},
        {"Croissant", "food", 2.8}
    };
    
    CoffeeShop shop("Java Haven", menu);
    
    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Croissant") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    
    cout << "Total Due: $" << shop.dueAmount() << endl;
    
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    
    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (string d : drinks) cout << d << " ";
    cout << endl;
    
    vector<string> foods = shop.foodOnly();
    cout << "Foods: ";
    for (string f : foods) cout << f << " ";
    cout << endl;
    
    return 0;
}
