# Authentication System (Assignment 2)

The purpose of this code is to build a C++ authentication system that allows users to sign up, save their credentials in a text file, and log in by verifying their username and password.

## Project Description

This project is a simple Authentication System developed using C++.

It allows users to create a new account (Sign Up) and log in (Login) using their username and password.

User information is stored in a text file named `users.txt`, so registered accounts remain saved even after the program is closed.

## Features

- **Sign Up:** Allows new users to create an account.
- **Login:** Checks the entered username and password against saved information.
- **File Handling:** Stores and retrieves user information using file handling.
- **Data Persistence:** Keeps existing user information when new users sign up.
- **Exit:** Allows users to safely exit the program.

## Classes

### 1. User Class
- Stores username and password.
- `toLine()` converts user information into a text line.
- `fromLine()` converts a saved text line into a User object.

### 2. AuthSystem Class
- Stores the filename.
- `signup()` saves new user information.
- `login()` checks whether the entered login details are correct.

## Project Structure

```text
Authentication_System/
│
├── main.cpp
├── users.txt
└── README.md
```

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Classes and Objects
- Constructors
- Conditional Statements and Loops

## How to Compile and Run

Compile the program:

```bash
g++ main.cpp -o main
```

Run the program:

```bash
./main
```

## How to Use

1. Select **1** to create a new account.
2. Enter a username and password.
3. Select **2** to log in.
4. Enter your registered username and password.
5. Select **3** to exit the program.

## Author

Developed as part of Object-Oriented Programming II (OOP-II), Assignment 2.