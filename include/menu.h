#pragma once
#include "student.h"

void clearScreen();
void pauseScreen();
char enterOption(char option);
void displayMenu();
void validationLooper(Student students[], int studentCount, int index);
bool studentDataIsDeleted(Student students[], int studentCount, int index);
void viewStudentRecords(Student students[], int studentCount);
