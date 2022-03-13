/**
 * Copyright @ 2022 Ripple Group Holdings Pte Ltd | www.ripplecreate.com
 * Day 3 (Order) Homework
 *  - Display all available options when prompting for user input
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
                        // Show confirmation message
                        result = "Order confirmed: " + restaurant + " - " + item + " (" + quantity_str + ")";
                    }
                }
            }
        } else if (user_input == "status") {
            result = "Execute status...";
        } else if (user_input == "exit") {
            result = "Execute exit...";
        } else {
            result = "Invalid command: " + user_input;
        }

        // Show result
        cout << result << endl
             << DIVIDER << endl;
    }
}
