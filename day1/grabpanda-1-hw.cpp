/**
 * Day 1 (Frontend) Homework
 *  - Ask for username after welcome message
 *  - Show username at the beginning of user input line
 */
#include <iostream>
using namespace std;

const string DIVIDER = "\n===================================================\n";
const string INPUT = " > ";

int main() {
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
