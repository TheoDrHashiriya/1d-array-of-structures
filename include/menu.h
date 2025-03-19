#pragma once
#include "student.h"

void clearScreen();
void pauseScreen();
void displayMenu();
void displayStudentData(const Student students[], int index);
void displayAllStudentData(const Student students[], int studentCount);
char enterOption(char option);
std::string enterSearchID(std::string searchID);
bool searchStudentData(Student students[], int studentCount);
bool validateStudentID(Student students[], int studentCount);
void validationLooper(Student students[], int studentCount, bool IDIsUnique);
void addStudentData(Student students[], int studentCount);
void editStudentData(Student students[], int studentCount);
void deleteStudentData(Student students[], int studentCount);
bool searchAndDelete(Student students[], int studentCount);
void sortAlphabetically(Student students[], int studentCount);
void sortByGPA(Student students[], int studentCount);
void viewStudentRecords(Student students[], int studentCount);