#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// User structure to store user information
struct User {
    string username;
    string password;
};

// Hash table to store user data (key: username, value: User object)
unordered_map<string, User> userDatabase;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    
    // Check if the user already exists
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "User already exists. Try a different username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Add the new user to the database
    userDatabase[username] = {username, password};
    cout << "User registered successfully!\n";
}

// Function to login a user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    // Check if the user exists
    if (userDatabase.find(username) == userDatabase.end()) {
        cout << "User not found. Please register first.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Validate the password
    if (userDatabase[username].password == password) {
        cout << "Login successful!\n";
    } else {
        cout << "Incorrect password.\n";
    }
}

// Function to search for a user
void searchUser() {
    string username;
    cout << "Enter username to search: ";
    cin >> username;

    // Check if the user exists
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "User found: " << username << "\n";
    } else {
        cout << "User not found.\n";
    }
}

// Function to delete a user
void deleteUser() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    // Check if the user exists
    if (userDatabase.find(username) != userDatabase.end()) {
        userDatabase.erase(username);
        cout << "User deleted successfully.\n";
    } else {
        cout << "User not found.\n";
    }
}

// Main menu
void menu() {
    int choice;
    do {
        cout << "\nUser Management System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Search User\n";
        cout << "4. Delete User\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                searchUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);
}

// Main function
int main() {
    menu();
    return 0;
}
