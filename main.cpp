#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Max_Users = 20;

struct User {
    string username;
    string password;
};

vector<User> users;
int score = 0;
int i, z;

int LoginMenu();
void SignUp();
void LogIn();
int MainMenu();
void Add();
void Minus();
void Times();
void Divide();
void update(const string &username, int score, const string &game);
void Leaderboard();

int main() {
    srand(time(0));
    while (true) {
        switch (LoginMenu()) {
            case 1:
                SignUp();
                break;
            case 2:
                LogIn();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid Input\n";
        }
    }
    return 0;
}

int LoginMenu() {
    system("cls");
    int input;
    cout << "Welcome to the Arithmetic Practice Program! \n";
    cout << "1.) Sign up \n";
    cout << "2.) Login \n";
    cout << "3.) Exit \n";
    cout << "Select(1-3): ";
    cin >> input;
    return input;
}

void SignUp() {
    system("cls");
    ofstream file("Accounts.txt", ios::app);
    User newUser;
    cout << "Sign In for New Account \n";
    cout << "Input Username: ";
    cin >> newUser.username;
    cout << "Input Password: ";
    cin >> newUser.password;
    file << newUser.username << " " << newUser.password << "\n";
    cout << "Your account has been registered to our system \n";
    cout << "Press the Enter key to continue... \n";
    cin.ignore();
    cin.get();
}

void LogIn() {
    system("cls");
    string oldUser, oldPass;
    ifstream file("Accounts.txt");
    if (!file.is_open()) {
        cerr << "FILE ERROR\n";
        return;
    }
    bool found = false;
    cout << "Log In Account \n";
    cout << "Input Username: ";
    cin >> oldUser;
    cout << "Input Password: ";
    cin >> oldPass;

    User user;
    while (file >> user.username >> user.password) {
        if (oldUser == user.username && oldPass == user.password) {
            cout << "Login Success! \n";
            system("pause");
            found = true;
            while (true) {
                switch (MainMenu()) {
                    case 1:
                        Add();
                        break;
                    case 2:
                        Minus();
                        break;
                    case 3:
                        Times();
                        break;
                    case 4:
                        Divide();
                        break;
                    case 5:
                        Leaderboard();
                        break;
                    case 6:
                        return;
                    default:
                        cout << "Invalid Input\n";
                }
            }
            break;
        }
    }
    if (!found) {
        cout << "It seems that your username or password is incorrect.\n";
        cout << "Press the Enter key to return to the menu...";
        cin.ignore();
        cin.get();
    }
}

int MainMenu() {
    system("cls");
    int input;
    cout << "Select Operation to Play \n";
    cout << "1.) Addition \n";
    cout << "2.) Subtraction \n";
    cout << "3.) Multiplication \n";
    cout << "4.) Division \n";
    cout << "5.) Leaderboard \n";
    cout << "6.) Log Out \n";
    cout << "Select(1-6): ";
    cin >> input;
    return input;
}

void Add() {
    system("cls");
    time_t startTime = time(0);
    cout << "ITS ADDITION TIME!! \n";
    cout << "You have 40 seconds to solve every equation. GOOD LUCK!\n";
    while (difftime(time(0), startTime) < 40) {
        int a = rand() % 15 + 1;
        int b = rand() % 15 + 1;
        cout << a << " + " << b << " = ";
        cin >> z;
        if (z == a + b) {
            cout << "\tTHAT IS CORRECT!\n";
            score++;
        } else {
            cout << "\tTHAT IS INCORRECT!\n";
        }
    }
    cout << "\nTime's up! You got " << score << " correct answers.\n";
    update(users[i].username, score, "Addition");
    cout << "You took " << difftime(time(0), startTime) << " seconds \n";
    cout << "Press Enter key to return to the menu...";
    cin.ignore();
    cin.get();
}

void Minus() {
    system("cls");
    time_t startTime = time(0);
    cout << "ITS SUBTRACTION TIME!! \n";
    cout << "You have 40 seconds to solve every equation. GOOD LUCK!\n";
    while (difftime(time(0), startTime) < 40) {
        int a = rand() % 21 + 10;
        int b = rand() % 9 + 1;
        cout << a << " - " << b << " = ";
        cin >> z;
        if (z == a - b) {
            cout << "\tTHAT IS CORRECT!\n";
            score++;
        } else {
            cout << "\tTHAT IS INCORRECT!\n";
        }
    }
    cout << "\nTime's up! You got " << score << " correct answers.\n";
    update(users[i].username, score, "Subtraction");
    cout << "You took " << difftime(time(0), startTime) << " seconds\n";
    cout << "Press Enter key to return to the menu...";
    cin.ignore();
    cin.get();
}

void Times() {
    system("cls");
    time_t startTime = time(0);
    cout << "ITS MULTIPLICATION TIME!! \n";
    cout << "You have 40 seconds to solve every equation. GOOD LUCK!\n";
    while (difftime(time(0), startTime) < 40) {
        int a = rand() % 15 + 1;
        int b = rand() % 15 + 1;
        cout << a << " x " << b << " = ";
        cin >> z;
        if (z == a * b) {
            cout << "\tTHAT IS CORRECT!\n";
            score++;
        } else {
            cout << "\tTHAT IS INCORRECT!\n";
        }
    }
    cout << "\nTime's up! You got " << score << " correct answers.\n";
    update(users[i].username, score, "Multiplication");
    cout << "You took " << difftime(time(0), startTime) << " seconds\n";
    cout << "Press Enter key to return to the menu...";
    cin.ignore();
    cin.get();
}

void Divide() {
    system("cls");
    time_t startTime = time(0);
    cout << "ITS DIVISION TIME!! \n";
    cout << "You have 40 seconds to solve every equation. GOOD LUCK!\n";
    while (difftime(time(0), startTime) < 40) {
        int divisor = rand() % 5 + 1;
        int num = rand() % 30 + 1;
        int x = num * divisor;
        cout << x << " / " << divisor << " = ";
        cin >> z;
        if (z == x / divisor) {
            cout << "\tTHAT IS CORRECT!\n";
            score++;
        } else {
            cout << "\tTHAT IS INCORRECT!\n";
        }
    }
    cout << "\nTime's up! You got " << score << " correct answers.\n";
    update(users[i].username, score, "Division");
    cout << "You took " << difftime(time(0), startTime) << " seconds\n";
    cout << "Press Enter key to return to the menu...";
    cin.ignore();
    cin.get();
}

void update(const string &username, int newScore, const string &game) {
    ifstream file("Leaderboard.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open leaderboard file.\n";
        return;
    }

    struct LeaderboardEntry {
        string name;
        int score;
        string game;
    };

    vector<LeaderboardEntry> entries;
    LeaderboardEntry entry;
    while (file >> entry.name >> entry.score >> entry.game) {
        entries.push_back(entry);
    }
    file.close();

    bool found = false;
    for (auto &e : entries) {
        if (e.name == username && e.game == game) {
            e.score += newScore;
            found = true;
            break;
        }
    }

    if (!found) {
        entries.push_back({username, newScore, game});
    }

    ofstream outFile("Leaderboard.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open leaderboard file for writing.\n";
        return;
    }

    for (const auto &e : entries) {
        outFile << e.name << " " << e.score << " " << e.game << "\n";
    }
}

void Leaderboard() {
    ifstream file("Leaderboard.txt");
    if (!file.is_open()) {
        cout << "There is no file to open leaderboard file.\n";
        return;
    }

    struct LeaderboardEntry {
        string name;
        int score;
        string game;
    };

    vector<LeaderboardEntry> entries;
    LeaderboardEntry entry;
    while (file >> entry.name >> entry.score >> entry.game) {
        entries.push_back(entry);
    }
    file.close();

    if (entries.empty()) {
        cout << "No leaderboard data found.\n";
        cout << "Press Enter key to return to menu...";
        cin.ignore();
        cin.get();
        return;
    }

    sort(entries.begin(), entries.end(), [](const LeaderboardEntry &a, const LeaderboardEntry &b) {
        return b.score < a.score; // Sort in descending order by score
    });

    cout << "\tARITHMETIC PRACTICE LEADERBOARD \n";
    cout << "RANK\tNAME\t\tSCORE\t\tGAME\n";
    for (size_t j = 0; j < entries.size(); ++j) {
        cout << "Rank " << j + 1 << ". " << entries[j].name << "\t\t" << entries[j].score << "\t\t" << entries[j].game << "\n";
    }

    cout << "Press Enter key to return to menu...";
    cin.ignore();
    cin.get();
}
