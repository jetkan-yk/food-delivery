/**
 * Day 3 (Order) Learning Outcomes
 *  - Interactive I/O
 *  - define vs const string
 *  - escape character
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
            for (auto entry : all_menu) {
                string restaurant = entry.first;
                vector<string> menu = entry.second;

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
            cout << "Which restaurant would you like to order from?" << endl
                 << INPUT;
            string restaurant;
            getline(cin, restaurant);

            if (all_menu.find(restaurant) == all_menu.end()) {
                // Restaurant not found
                result = "Restaurant \"" + restaurant + "\" not found.";
            } else {
                // Get item
                cout << "Which item would you like to order?" << endl
                     << INPUT;
                string item;
                getline(cin, item);

                vs menu = all_menu[restaurant];
                if (find(menu.begin(), menu.end(), item) == menu.end()) {
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
