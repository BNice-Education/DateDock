#ifndef VALIDATION_H
#define VALIDATION_H

#include "prompts.h"
#include <string>

void QuickClear();
int ValidateIntTryMonth(const std::string& prompt);
int ValidateIntTryYear(const std::string& prompt);
int ValidateIntTryDay(const std::string& prompt, int month, int year);
int UserMenuSelection(const std::string& menuText, int minOption, int maxOption);
void UserConfirm();
std::string getMonth(int month);

#endif // VALIDATION_H
