# DateDock
DateDock v1.05
Author: Bruce Nebergall
Last Updated: 1/29/2024

Purpose:
The DateDock program is designed to collect, store, and display dates. It allows users to input properties of a date (year, month, day) and manage a list of these dates through a simple console interface.

Features:
- Input and edit the properties of an active date (year, month, day).
- Save the active date to a 'dock', a collection of dates.
- Display all dates saved in the dock.
- Data validation for year, month, and day inputs with user-friendly error messages.

Files in the Program:
- DateDock.cpp: The main program file containing the application's entry point and user interface logic.
- date.cpp: Defines the Date class, responsible for date property management and string representation.
- validation.cpp: Contains functions for input validation, including year, month, and day validations.
- Prompts.cpp: Stores string constants used for user prompts and messages throughout the application.

Ensure you have a C++ compiler installed (e.g., g++, clang, MSVC). Compile the program with all provided .cpp files.

DateDock DateDock.cpp date.cpp validation.cpp Prompts.cpp
Then Run DateDock.exe

Usage Instructions:
1. Start the program to be greeted with an initial prompt.
2. Follow on-screen instructions to navigate through the menu options:
   - Edit Active Date: Enter a new date by providing year, month, and day.
   - Save to Date Dock: Save the currently active date to the dock.
   - Display Dock: View all dates saved in the dock.
   - Quit Program: Exit the application.
3. Input validation is in place to guide correct inputs for dates.
