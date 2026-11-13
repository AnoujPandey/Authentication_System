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

    // Constructor
    User(string u, string p)
    {
        username = u;
        password = p;
    }

    // Converts user information into username,password format
    string toLine() const
    {
        return username + "," + password;
    }

    // Converts a saved line into a User object
    static User fromLine(string line)
    {
        int pos = line.find(',');
        string user = line.substr(0, pos);
        string pass = line.substr(pos + 1);

        return User(user, pass);
    }
};

// AuthSystem handles signup and login
class AuthSystem
{
private:
    string filename;

public:
    // Constructor stores the filename
    AuthSystem(string fname)
    {
        filename = fname;
    }

    // Saves a new user without deleting existing users
    void signup(const User& user)
    {
        ofstream fout(filename, ios::app);
        fout << user.toLine() << endl;
        fout.close();
    }

    // Checks whether the entered login details match a saved user
    bool login(string name, string pass)
    {
        ifstream fin(filename);
        string line;

        while (getline(fin, line))
        {
            User u = User::fromLine(line);
            if (u.username == name && u.password == pass)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
};