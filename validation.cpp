#include "validation.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <vector>


// Function for clearing input stream/errors
void QuickClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// Function for User Menu loop
int UserMenuSelection(const std::string& menuText, int minOption, int maxOption) {
    int selection;
    do {
        std::cout << menuText;
        std::cin >> selection;
        if (std::cin.fail() || selection < minOption || selection > maxOption) {
            std::cout << "Invalid Selection. Choose a valid option with an integer between " << minOption << " and " << maxOption << ".\n";
            QuickClear();
        } else {
            QuickClear(); 
            return selection;  // Valid input
        }
    } while (true);
}

// Require User to Press Enter to continue
void UserConfirm() {
    std::cout << Prompts::EnterToContinue;
    std::string confirm; std::getline(std::cin, confirm);
}


bool isLeapYear(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

// Function to get the maximum days in a month
int getMaxDaysInMonth(int month, int year) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; // February has 29 days in a leap year
    }
    return daysInMonth[month - 1];
}

std::string getMonth(int monthNumber) {
    // Array (or vector) of month names
    const std::vector<std::string> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Subtract 1 from monthNumber because the array index is 0-based
    return monthNames[monthNumber - 1];
}

int ValidateIntTryDay(const std::string& prompt, int month, int year) {
    int maxOption = getMaxDaysInMonth(month, year);
    int minOption = 1; // The minimum day is always 1
    while (true) {
        int value;
        std::cout << prompt;
        std::cin >> value;
        try {
            if (std::cin.fail()) {
                throw std::invalid_argument("Input was not an integer.");
            }
            if (value < minOption || value > maxOption) {
                std::ostringstream errMsg;
                errMsg << "There are only " << maxOption << " days in the month of ";
                errMsg << getMonth(month) << ". You entered " << value << ".";
                throw std::out_of_range(errMsg.str());
            }
            return value; // If input is valid, return it
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. " << e.what() << std::endl;
            QuickClear(); // Clear the error state
        } catch (const std::out_of_range& e) {
            std::cerr << "Invalid value. " << e.what() << std::endl;
            QuickClear(); // Clear the error state
        }
    }
}


int ValidateIntTryMonth(const std::string& prompt) {
    int minOption = 1; // The minimum month (January)
    int maxOption = 12; // The maximum month (December)
    while (true) {
        int value;
        std::cout << prompt;
        std::cin >> value;
        try {
            if (std::cin.fail()) {
                throw std::invalid_argument("Please enter an integer between 1 and 12 for month");
            }
            if (value < minOption) {
                throw std::out_of_range("Please enter a number between 1 and 12 for the month.");
            }
            if (value > maxOption) {
                throw std::out_of_range("Invalid month. There are only 12 months");
            }
            return value; // If input is valid, return it
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. " << e.what() << std::endl;
            QuickClear(); 
        } catch (const std::out_of_range& e) {
            std::cerr << "Invalid month. " << e.what() << std::endl;
            QuickClear(); 
        }
    }
}

int ValidateIntTryYear(const std::string& prompt) {
    int minOption = 1900; // minimum year
    int maxOption = 2020; // maximum year
    while (true) { // Keep asking for input until a valid year is entered
        int value;
        std::cout << prompt;
        std::cin >> value;

        try {
            if (std::cin.fail()) {
                throw std::invalid_argument("Input was not an integer.");
            }
            if (value < minOption) {
                std::ostringstream errMsg;
                errMsg << "Please enter a year after " << minOption - 1 << ".";
                throw std::out_of_range(errMsg.str());
            }
            if (value > maxOption) {
                std::ostringstream errMsg;
                errMsg << "Please enter a year before " << maxOption + 1 << ".";
                throw std::out_of_range(errMsg.str());
            }
            return value; // If input is valid, return it
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input for Year. " << e.what() << std::endl;
            QuickClear(); 
        } catch (const std::out_of_range& e) {
            std::cerr << "Invalid value for Year. " << e.what() << std::endl;
            QuickClear(); 
        }
    }
    
}
