#pragma once
#include "student.h"

void clearScreen();
void pauseScreen();
char enterOption(char option);
std::string enterSearchID();
void sortAlphabetically(Student students[], int studentCount);
void sortByGPA(Student students[], int studentCount);