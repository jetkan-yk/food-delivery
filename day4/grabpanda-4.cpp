/**
 * Day 4 (Status) Learning Outcomes
 *  - std::map of std::map
 *  - check item exist before updating map
 *  - rand() and modulo
 *  - to_string()
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<string> vs;

#define BULLET " - "
#define DIVIDER "\n===================================================\n"
#define INPUT_SYMBOL " > "

int main() {
    // Initialize database
    map<string, vs> all_menu;
    all_menu["McDonalds"] = vs{"McChicken", "Filet-O-Fish", "Big Mac", "McSpicy"};
    all_menu["Ya Kun"] = vs{"Kopi", "Teh", "Kaya Butter Toast"};
    all_menu["Starbucks"] = vs{"Espresso", "Frappuccino", "Cold Brew", "Tea Latte"};

    map<string, map<string, int>> cart;
    unordered_map<string, int> eta;
    // cart["Starbucks"] = map<string, int>();
    // cart["Starbucks"]["Espresso"] = 2;
    // cart["Starbucks"]["Cold Brew"] = 1;
    // eta["Starbucks"] = 22;
    // cart["McDonalds"] = map<string, int>();
    // cart["McDonalds"]["McSpicy"] = 3;
    // eta["McDonalds"] = 33;

    // Show a welcome message
    cout << "              WELCOME TO GRABPANDA!\n"
         << endl;

    // Get username
    cout << "Enter username: ";
    string username;
    getline(cin, username);
    cout << endl;

    const string INPUT = " " + username + INPUT_SYMBOL;

    // Repeat this loop until the program terminates
    while (true) {
        // Get user input
        cout << "What would you like to do today?" << endl
             << "[browse / order / status / exit]" << endl
             << INPUT;
        string user_input;
        getline(cin, user_input);

        // Execute command
        string result;
        if (user_input == "browse") {
            // Loop each restaurant->menu entry from database
            for (auto& am : all_menu) {
                string restaurant = am.first;
                vector<string> menu = am.second;

                cout << restaurant << endl;
                // Sort all item in the menu
                sort(menu.begin(), menu.end());
                // Print all item in the menu
                for (string item : menu) {
                    cout << BULLET << item << endl;
                }
                cout << endl;
            }
            result = "All menu displayed.";
        } else if (user_input == "order") {
            // Get restaurant
            cout << "Which restaurant would you like to order from?" << endl;
            // Get available options
            vs options;
            for (auto& am : all_menu) {
                options.push_back(am.first);
            }
            // Show options
            cout << "[";
            for (int i = 0; i < options.size(); i++) {
                if (i > 0) cout << " / ";
                cout << options[i];
            }
            cout << "]" << endl
                 << INPUT;
            string restaurant;
            getline(cin, restaurant);

            if (find(options.begin(), options.end(), restaurant) == options.end()) {
                // Restaurant not found
                result = "Restaurant \"" + restaurant + "\" not found.";
            } else {
                // Get item
                cout << "Which item would you like to order?" << endl;
                // Get available options
                vs options;
                for (string item : all_menu[restaurant]) {
                    options.push_back(item);
                }
                cout << "[";
                for (int i = 0; i < options.size(); i++) {
                    if (i > 0) cout << " / ";
                    cout << options[i];
                }
                cout << "]" << endl
                     << INPUT;
                string item;
                getline(cin, item);

                if (find(options.begin(), options.end(), item) == options.end()) {
                    // Item not found
                    result = "Item \"" + item + "\" not found.";
                } else {
                    // Get quantity
                    cout << "How many \"" + item + "\" would you like to order?" << endl
                         << INPUT;
                    string quantity_str;
                    getline(cin, quantity_str);
                    int quantity = stoi(quantity_str);

                    if (quantity <= 0) {
                        // Invalid quantity number
                        result = "Invalid quantity: " + quantity_str;
                    } else {
                        // Update cart
                        if (cart.find(restaurant) == cart.end()) {
                            // Create new restaurant in cart
                            cart[restaurant] = map<string, int>();
                            cart[restaurant][item] = quantity;
                        } else {
                            // Restaurant already exist in cart
                            if (cart[restaurant].find(item) == cart[restaurant].end()) {
                                // Create new item in order
                                cart[restaurant][item] = quantity;
                            } else {
                                // Item already exist in order
                                cart[restaurant][item] += quantity;
                            }
                        }

                        // Update ETA
                        if (eta.find(restaurant) == eta.end()) {
                            // Create new restaurant in eta
                            eta[restaurant] = 10 + rand() % 50;
                        } else {
                            // Update restaurant eta
                            eta[restaurant] += 1 + rand() % 5;
                        }

                        // Show confirmation message
                        result = "Order confirmed: " + restaurant + " - " + item + " (" + to_string(cart[restaurant][item]) + ").";
                        result += " ETA " + to_string(eta[restaurant]) + " mins";
                    }
                }
            }
        } else if (user_input == "status") {
            // Loop each restaurant->order entry from database
            for (auto& c : cart) {
                string restaurant = c.first;
                auto& order = c.second;

                cout << restaurant << " ETA " << eta[restaurant] << " mins" << endl;
                // Print all item in the order
                for (auto& o : order) {
                    string item = o.first;
                    int quantity = o.second;

                    cout << BULLET << item << " (" << quantity << ")" << endl;
                }
                cout << endl;
            }
            result = "All status displayed.";
        } else if (user_input == "exit") {
            exit(0);
        } else {
            result = "Invalid command: " + user_input;
        }

        // Show result
        cout << result << endl
             << DIVIDER << endl;
    }
}
