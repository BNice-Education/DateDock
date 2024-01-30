#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
    public:
    Date();
    //Mutator Methods
    void setDay();
    void setMonth();
    void setYear();
    void createString();
    //Initial Setup within Constructor
    void SetProperties();
    //Display & Menu Functions
    void DisplayDates();
    //Accessor Methods
    std::string getDateString() const;
    private:
    std::string dateString;
    std::string dateNote;
    int month;
    int day;
    int year;
} ;

#endif