//Ivan Arroyo  7/10/24
//Chada Tech Project One

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// Clock Borders
void clockBorderPrinter() {
    for (int i = 0; i < 16; ++i) {
        cout << " ";
    }
    // 12 hour clock border
    for (int i = 0; i < 27; ++i) {
        cout << "*";
    }
    for (int i = 0; i < 5; ++i) {
        cout << " ";
    }
    // 24 hour clock border
    for (int i = 0; i < 27; ++i) {
        cout << "*";
    }
    cout << endl;
}

// Main Menu Display
void mainMenu() {
    cout << endl;
    cout << "********************************" << endl;
    cout << "* 1- Add One Hour              *" << endl;
    cout << "* 2- Add One Minute            *" << endl;
    cout << "* 3- Add One Second            *" << endl;
    cout << "* 4- Exit                      *" << endl;
    cout << "********************************" << endl;
    cout << endl;
}

// Clock output function and clock time converter
void clockPrinter(int hours, int minutes, int seconds) {
    int hourConversion;
    string AmOrPm = "A.M.";

    // 24 Hours --> 12 Hours
    if (hours == 0) {
        hourConversion = 12;
    }
    else if (hours == 12) {
        hourConversion = hours;
        AmOrPm = "P.M.";
    }
    else if (hours > 12) {
        hourConversion = hours - 12;
        AmOrPm = "P.M.";
    }
    else {
        hourConversion = hours;
    }

    // 24 Hour Clock
    cout << "               ***************************" << endl;
    cout << "               *     24 Hour Clock       *" << endl;
    cout << "               *     " << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << "           *" << endl;

    // 12 hour clock
    cout << "               *     12 Hour Clock       *" << endl;
    cout << "               *     " << setw(2) << setfill('0') << hourConversion << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << " " << AmOrPm << "    *" << endl;
    cout << "               ***************************" << endl;
}

// User time getting function
void initialTime(int& setHour, int& setMin, int& setSec) {
    string userInput;
    bool logicalTime = false;
    int colonPosition;
    int colonPosition2;

    while (!logicalTime) {
        cout << "Enter time (e.g. 23:59:59): ";
        getline(cin, userInput);
        colonPosition = userInput.find(':');
        colonPosition2 = userInput.find(':', colonPosition + 1);

        // Initial conversion attempt
        try {
            setHour = stoi(userInput.substr(0, colonPosition));
            setMin = stoi(userInput.substr(colonPosition + 1, colonPosition2 - colonPosition - 1));
            setSec = stoi(userInput.substr(colonPosition2 + 1));
        }
        catch (const std::exception&) {
            setHour = setMin = setSec = -1; // Invalid input
        }

        if (userInput.size() != 8 || setHour < 0 || setHour > 23 || setMin < 0 || setMin > 59 || setSec < 0 || setSec > 59) {
            cout << "Invalid Time Entry" << endl;
            logicalTime = false;
        }
        else {
            logicalTime = true;
        }
    }
}

void userInputCheck(int& UserInput, int& setHour, int& setMin, int& setSec) {
    cout << "Select an option (e.g 1-4): ";
    if (!(cin >> UserInput)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        UserInput = 0;
    }

    // Function for Users input
    switch (UserInput) {
    case 1:
        cout << "1 hour added" << endl;
        if (setHour < 23) {
            ++setHour;
        }
        else {
            setHour = 0;
        }
        break;
    case 2:
        cout << "1 minute added" << endl;
        if (setMin < 59) {
            ++setMin;
        }
        else {
            setMin = 0;
            if (setHour < 23) {
                ++setHour;
            }
            else {
                setHour = 0;
            }
        }
        break;
    case 3:
        cout << "1 second added" << endl;
        if (setSec < 59) {
            ++setSec;
        }
        else {
            setSec = 0;
            if (setMin < 59) {
                ++setMin;
            }
            else {
                setMin = 0;
                if (setHour < 23) {
                    ++setHour;
                }
                else {
                    setHour = 0;
                }
            }
        }
        break;
    case 4:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid entry. Enter a number 1-4" << endl;
        cin.clear();
        break;
    }
}

int main() {
    int UserInput = 0;
    int setHour = 0;
    int setMin = 0;
    int setSec = 0;

    initialTime(setHour, setMin, setSec);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer after initial time input

    while (UserInput != 4) {
        clockBorderPrinter();
        clockPrinter(setHour, setMin, setSec);
        clockBorderPrinter();
        mainMenu();
        userInputCheck(UserInput, setHour, setMin, setSec);
    }
    return 0;
}