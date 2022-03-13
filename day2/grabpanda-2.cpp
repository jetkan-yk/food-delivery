/**
 * Day 2 (Browse) Learning Outcomes
 *  - std::unordered_map, std::vector, std::string
 *  - typedef, define
 *  - auto, first, second
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<string> vs;

#define BULLET " - "
#define DIVIDER "\n===================================================\n"
#define INPUT " > "

int main() {
    // Initialize database
    unordered_map<string, vs> all_menu;
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

    // Repeat this loop until the program terminates
    while (true) {
        // Get user input
        cout << "What would you like to do today?" << endl
             << "[browse / order / status / exit]" << endl
             << " " + username + INPUT;
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
                // Print all item in the menu
                for (string item : menu) {
                    cout << BULLET << item << endl;
                }
                cout << endl;
            }
            result = "All menu displayed.";
        } else if (user_input == "order") {
            result = "Execute order...";
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
