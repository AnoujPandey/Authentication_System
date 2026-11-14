
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// User class stores user information
class User
{
public:
    string username;
    string password;

    // Constructor initializes username and password
    User(string u, string p)
    {
        username = u;
        password = p;
    }

    // Converts user information into username,password format
    // Example: anouj,1234
    string toLine() const
    {
        return username + "," + password;
    }

    // Converts a saved line from the file into a User object
    // Example: anouj,1234 becomes User("anouj", "1234")
    static User fromLine(string line)
    {
        int pos = line.find(',');

        // Extract username before the comma
        string user = line.substr(0, pos);

        // Extract password after the comma
        string pass = line.substr(pos + 1);

        return User(user, pass);
    }
};

// AuthSystem handles signup and login operations
class AuthSystem
{
private:
    string filename;

public:
    // Constructor stores the filename where user information is saved
    AuthSystem(string fname)
    {
        filename = fname;
    }

    // Signup function saves a new user's information
    void signup(const User& user)
    {
        // ios::app adds new information without deleting existing users
        ofstream fout(filename, ios::app);

        // Save username and password in the file
        fout << user.toLine() << endl;

        fout.close();
    }

    // Login function checks whether the entered details are correct
    bool login(string name, string pass)
    {
        // Open the file to read saved user information
        ifstream fin(filename);
        string line;

        // Read the file one line at a time
        while (getline(fin, line))
        {
            // Convert the saved line into a User object
            User u = User::fromLine(line);

            // Compare saved username and password with entered details
            if (u.username == name && u.password == pass)
            {
                fin.close();
                return true;
            }
        }

        // If no matching account is found, return false
        fin.close();
        return false;
    }
};

// Main function starts the Authentication System
int main()
{
    // Create AuthSystem object and specify the file for storing users
    AuthSystem auth("users.txt");

    int choice;
    string username, password;

    // Keep displaying the menu until the user chooses Exit
    while (true)
    {
        cout << "\n------ Authentication System ------" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Option 1: Sign Up
        if (choice == 1)
        {
            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            // Create a new User object with entered details
            User newUser(username, password);

            // Save the new user using the signup function
            auth.signup(newUser);

            cout << "Sign Up Successfully!" << endl;
        }

        // Option 2: Login
        else if (choice == 2)
        {
            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            // Check whether the entered details match a saved account
            if (auth.login(username, password))
            {
                cout << "Logged in Successfully! Welcome, "
                     << username << endl;
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
        }

        // Option 3: Exit
        else if (choice == 3)
        {
            cout << "Exiting Authentication System." << endl;
            break;
        }

        // Handle any invalid menu choice
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}