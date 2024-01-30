#include "date.h"
#include "validation.h"
#include "prompts.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

Date::Date(){
    SetProperties();
}

void Date::SetProperties(){
    setYear();
    setMonth();
    setDay();
    createString();
}

void Date::setYear(){
    std::string prompt = "Enter the Year of the event: "; 
    year = ValidateIntTryYear(prompt);
}

void Date::setMonth(){
    std::string prompt = "Enter the correleting number of the Month of the event: "; 
    month = ValidateIntTryMonth(prompt);
}

void Date::setDay(){
    std::string prompt = "Enter the Calendar Day of the event: "; 
    day = ValidateIntTryDay(prompt, month, year);
}

void Date::createString() {
    std::string monthName = getMonth(month);
    std::ostringstream oss;
    oss << monthName << " " << day << ", " << year;
    dateString = oss.str();
}

std::string Date::getDateString() const {
    return dateString;
}
