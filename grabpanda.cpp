#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> msg;

const string DIVIDER = "===================================================";
const string NEWLINE = "";
const string INPUT_PREFIX = " > ";

/** Prints a vector of string messages line-by-line to the user */
void showToUser(msg message) {
    for (const string& m : message) {
        string ENDLINE = (m == INPUT_PREFIX) ? "" : "\n";
        cout << m << ENDLINE;
    }
}

void showWelcomeMessage() {
    const string MESSAGE_WELCOME = "              WELCOME TO GRABPANDA!";
    showToUser(msg{MESSAGE_WELCOME, NEWLINE});
}

void showResult(string result) {
    showToUser(msg{result, NEWLINE, DIVIDER, NEWLINE});
}

/**
 * Prompts for the command and reads the text entered by the user.
 * @return full line entered by the user
 */
string getUserInput() {
    const string MESSAGE_GET_USER_INPUT = "What would you like to do today?";
    const string MESSAGE_ALL_COMMANDS = "[browse / status / exit]";
    showToUser(msg{MESSAGE_GET_USER_INPUT, MESSAGE_ALL_COMMANDS, INPUT_PREFIX});

    string user_input;
    getline(cin, user_input);
    return user_input;
}

string executeBrowse() {
    return "Browsing menu...";
}

string executeStatus() {
    return "Showing status...";
}

string executeExit() {
    exit(0);
}

/**
 * Executes the user command
 *
 * @param user_command raw input from user
 * @return a string result after executing the command
 */
string executeCommand(string user_command) {
    if (user_command == "browse") {
        return executeBrowse();
    } else if (user_command == "status") {
        return executeStatus();
    } else if (user_command == "exit") {
        return executeExit();
    } else {
        return "Invalid command: " + user_command;
    }
}

int main() {
    showWelcomeMessage();
    while (true) {
        string user_command = getUserInput();
        string result = executeCommand(user_command);
        showResult(result);
    }
}
