#include "menu.h"
#include "student.h"
#include <iostream>
#include <limits>

void clearScreen() {
#ifdef _WIN32
  std::cout.flush();
  system("cls");
#else
  std::cout.flush();
  system("clear");
#endif
}

// this method of pausing the screen should be more universal...
void pauseScreen() {
  std::cout << "Press enter to go back to main menu: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

char enterOption(char option) {
  std::cout << "Enter option: ";
  std::cin >> option;

  while (option != '1' && option != '2' && option != '3' && option != '4' &&
         option != '5') {
    std::cout << "Invalid input. Enter another option: ";
    std::cin >> option;
  }

  return option;
}

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