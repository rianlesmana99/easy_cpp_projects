#include <iostream>
#include <limits>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cctype>
#include <unistd.h>

using namespace std;

void userRegister() {
    string username;
    string fullName;
    string password;
    int age;
    char gender;
    string hobby;
    char optional;

    system("clear");
    try {
        cout << "Please fill in all data properly!\n";
        cout << "Enter username you want to use\t: ";
        cin >> username;
        cin.ignore();

        string path = username + ".txt";

        if (filesystem::exists(path)) {
            throw runtime_error("Username already used, please select another username!");
        }

        cout << "Enter the new password\t\t: ";
        getline(cin, password);

        cout << "Enter your full name\t\t: ";
        getline(cin, fullName);

        cout << "Enter your age\t\t\t: ";
        cin >> age;

        cout << "Enter your gender (M/F)\t\t: ";
        cin >> gender;
        cin.ignore();

        cout << "Enter your hobby\t\t: ";
        getline(cin, hobby);

        ofstream newFile(path);

        newFile << password << endl << fullName << endl << age << endl << gender << endl << hobby;

        newFile.close();

        cout << "Successfully to register account!\n";

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Do you want to try again (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        userRegister();
    }
}

void userLogin() {
    string username;
    string password;
    string textData;
    vector<string> data;
    char optional;

    system("clear");
    try {
        cout << "Enter username\t: ";
        cin >> username;
        cin.ignore();

        string path = username + ".txt";

        if (!filesystem::exists(path)) {
            throw runtime_error("Username not registered!");
        }

        cout << "Enter password\t: ";
        getline(cin, password);

        ifstream userFile(path);

        while (getline(userFile, textData)) {
            data.push_back(textData);
        }

        if (password != data[0]) {
            throw runtime_error("Please enter the correct password!");
        }
        
        system("clear");
        cout << "Account Information!\n";

        cout << "Full Name\t: " << data[1] << endl;
        cout << "Age\t\t: " << data[2] << endl;
        cout << "Gender\t\t: " << data[3] << endl;
        cout << "Hobby\t\t: " << data[4] << endl;

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Do you want to try again (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        userLogin();
    }
}

void removeUser() {
    string username;
    string password;
    string path;
    string textData;
    vector<string> saveData;
    char optional;

    system("clear");
    try {
        cout << "Enter username\t: ";
        getline(cin, username);

        path = username + ".txt";

        if (!filesystem::exists(path)) {
            throw runtime_error("Username not registered!");
        }

        cout << "Enter password\t: ";
        getline(cin, password);

        ifstream userFile(path);

        while (getline(userFile, textData)) {
            saveData.push_back(textData);
        }

        if (password != saveData[0]) {
            throw runtime_error("Please enter the correct password!");
        }

        filesystem::remove(path);
        cout << "Success to remove account!\n";

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Do you want to try again (Y/N): ";
    cin >> optional;
    cin.ignore();

    if (tolower(optional) == 'y') {
        removeUser();
    }
}

int main() {
    int userChoice;
    while (true) {
        system("clear");
        try {
            cout << "Welcome to Abyss!\n";
            cout << "1. Login\n2. Register\n3. Remove Account\n4. Quit\nSelect one option: ";
            cin >> userChoice;
            cin.ignore();

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Please select the valid option!");
            }

            if (userChoice == 1) {
                userLogin();
            } else if (userChoice == 2) {
                userRegister();
            } else if (userChoice == 3) {
                removeUser();
            } else if (userChoice == 4) {
                cout << "Thank you!\n";
                break;
            } else {
                throw runtime_error("Please select the valid option!");
            }

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        for (int i = 0; i < 3; i++) {
            cout << "Loading...\n";
            sleep(1);
        }
    }
    

    return 0;
}