#include "menu.h"
#include "student.h"
#include "utils.h"
#include <iostream>

void displayMenu() {
  std::cout << "==========STUDENT MANAGEMENT SYSTEM==========\n";
  std::cout << "[1] Add Student\n";
  std::cout << "[2] Edit Student\n";
  std::cout << "[3] Delete Student\n";
  std::cout << "[4] View Student Records\n";
  std::cout << "[5] Exit Program\n";
}

void validationLooper(Student students[], int studentCount, int index) {
  bool IDIsUnique = false;
  while (!IDIsUnique) {
    IDIsUnique = validateStudentID(students, studentCount, index);
  }
}

bool studentDataIsDeleted(Student students[], int studentCount, int index) {
  char option;
  std::cout << "Delete? [Y/N]: ";
  std::cin >> option;

  if (tolower(option) == 'y') {
    clearScreen();
    deleteStudent(students, studentCount, index);
    return true;
  }
  return false;
}

void viewStudentRecords(Student students[], int studentCount) {
  if (studentCount < 1) {
    std::cout << "No student records found.\n";
    return;
  }
  char option;
  std::cout << "[1] Alphabetically\n";
  std::cout << "[2] By GPA\n";
  std::cout << "Select view option: ";
  std::cin >> option;

  while (option != '1' && option != '2') {
    std::cout << "Invalid input. Enter another option: ";
    std::cin >> option;
  }

  clearScreen();

  if (option == '1') {
    sortAlphabetically(students, studentCount);
  }
  if (option == '2') {
    sortByGPA(students, studentCount);
  }

  displayAllStudentData(students, studentCount);
}