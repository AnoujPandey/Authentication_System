#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
public:
    string username;
    string password;

    User(string u, string p)
    {
        username = u;
        password = p;
    }

    string toLine() const
    {
        return username + "," + password;
    }

    static User fromLine(string line)
    {
        int pos = line.find(',');

        string user = line.substr(0, pos);
        string pass = line.substr(pos + 1);
        return User(user, pass);
    }
};