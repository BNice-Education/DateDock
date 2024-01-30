#include <string>
#include "Prompts.h"

//ProgramPrompts
const std::string Prompts::InitialPrompt =  "Welcome to the Date Dock\nFollow the onscreen prompts to enter the Year, Month, and Date of Your Event Respectively\n\n";
const std::string Prompts::EndPrompt = "\nDate Dock Deleted, and shutting down...\nProgram Complete.";

//User Confirmation Prompt (Honestly it was more work to code this than it will be to use it)
const std::string Prompts::EnterToContinue = "\nPress 'Enter' to continue...";

//Error Text
const std::string Prompts::InvalidInEmpty = "Invalid input. Please enter a non-empty string.\n";

//Main Menu Text
const std::string Prompts::MainMenuPrompt = 
    "\nMain Menu"
    "\n1 - Edit Active Date"
    "\n2 - Save to Date Dock"
    "\n3 - Display Dock"
    "\n4 - Quit Program"
    "\nSelect a menu option: ";


    