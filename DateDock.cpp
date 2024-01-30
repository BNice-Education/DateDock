// # Program name: DateDock.cpp v1.05
// # Author: Bruce Nebergall
// # Date last updated: 1/29/2024
// # Purpose: To collect properties of a Date, and allow the user to store and display a list of dates.

#include "date.h"
#include "validation.h"
#include "prompts.h"

#include <iostream>
#include <string>
#include <vector>

// Function prototypes
void saveDate(std::vector<std::string>& dateDock, Date& activeDate);
void displayDates(const std::vector<std::string>& dateDock);

int main() {
    std::cout << Prompts::InitialPrompt;
    Date activeDate; // Constructor Class prompts users for date
    std::vector<std::string> dateDock; // Using vector to store dates

    while (true) {
        std::cout << "\nThe active Date is:  " << activeDate.getDateString() << "\n"; // Active Date Properties are Displayed at the beginning of each iteration of the main loop
        int menuOption = UserMenuSelection(Prompts::MainMenuPrompt, 1, 4);
        switch (menuOption) { // Switch Case on User Input at Main Menu
            case 1:
                activeDate.SetProperties();
                break;
            case 2: // Save Date to 'Dock'
                saveDate(dateDock, activeDate);
                break;
            case 3: // Display Full Dock
                displayDates(dateDock);
                break;
            case 4: // End Program
                std::cout << Prompts::EndPrompt;
                UserConfirm();
                return 0;
            default:
                break;
        }
    }
    return 1;
}

// Function to save a date to the dock
void saveDate(std::vector<std::string>& dateDock, Date& activeDate) {
    dateDock.push_back(activeDate.getDateString());
}

// Function to display all saved dates
void displayDates(const std::vector<std::string>& dateDock) {
    for (size_t i = 0; i < dateDock.size(); ++i) {
        std::cout << i + 1 << " - " << dateDock[i] << std::endl;
    }
}
