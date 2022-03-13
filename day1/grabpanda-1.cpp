/**
 * Copyright @ 2022 Ripple Group Holdings Pte Ltd | www.ripplecreate.com
 * Day 1 (Frontend) Learning Outcomes
 *  - CLI application
 *  - While & If loop
 *  - Basic I/O & std::getline()
 */
#include <iostream>
using namespace std;

const string DIVIDER = "\n===================================================\n";
const string INPUT = " > ";

int main() {
    // Show a welcome message
    cout << "              WELCOME TO GRABPANDA!\n"
         << endl;

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
            result = "Execute browse...";
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
