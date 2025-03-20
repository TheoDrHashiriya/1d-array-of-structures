#pragma once
#include "student.h"

void displayMenu();
void validationLooper(Student students[], int studentCount, int index);
bool studentDataIsDeleted(Student students[], int studentCount, int index);
void viewStudentRecords(Student students[], int studentCount);
