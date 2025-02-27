#include <iostream>
#include <vector>
using namespace std;

class CoffeeShop {
    private:
        string name;
        vector<pair<string, double>> menu;
        vector<string> orders;
    public:
        CoffeeShop(string shopName, vector<pair<string, double>> menuItems) : name(shopName), menu(menuItems) {}
        
        string AddOrder(string item) {
            for (auto &m : menu) {
                if (m.first == item) {
                    orders.push_back(item);
                    return "Order added: " + item;
                }
            }
            return "This item is currently unavailable!";
        }
        
        string FulfillOrder() {
            if (!orders.empty()) {
                string item = orders.front();
                orders.erase(orders.begin());
                return "The " + item + " is ready!";
            }
            return "All orders have been fulfilled";
        }
        
        vector<string> ListOrders() {
            return orders;
        }
        
        double DueAmount() {
            double total = 0;
            for (auto &order : orders) {
                for (auto &m : menu) {
                    if (m.first == order) {
                        total += m.second;
                    }
                }
            }
            return total;
        }
        
        string CheapestItem() {
            string cheapest = "";
            double minPrice = 1e9;
            for (auto &m : menu) {
                if (m.second < minPrice) {
                    minPrice = m.second;
                    cheapest = m.first;
                }
            }
            return cheapest;
        }
        
        vector<string> DrinksOnly() {
            vector<string> drinks;
            for (auto &m : menu) {
                if (m.first.find("Drink") != string::npos) {
                    drinks.push_back(m.first);
                }
            }
            return drinks;
        }
        
        vector<string> FoodOnly() {
            vector<string> foods;
            for (auto &m : menu) {
                if (m.first.find("Drink") == string::npos) {
                    foods.push_back(m.first);
                }
            }
            return foods;
        }
};

void CoffeeShopTest() {
    vector<pair<string, double>> menu = {{"Coffee", 2.5}, {"Burger", 5.0}, {"Tea", 1.5}, {"Pizza", 7.0}};
    CoffeeShop shop("Cafe", menu);
    cout << shop.AddOrder("Coffee") << endl;
    cout << shop.AddOrder("Burger") << endl;
    cout << shop.FulfillOrder() << endl;
    cout << "Due Amount: $" << shop.DueAmount() << endl;
    cout << "Cheapest Item: " << shop.CheapestItem() << endl;
}

int main() {
    CoffeeShopTest();
    return 0;
}
