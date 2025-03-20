#include "utils.h"
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

std::string enterSearchID() {
  std::string searchID;
  std::cout << "Search for student ID: ";
  std::cin >> searchID;

  return searchID;
}

void sortAlphabetically(Student students[], int studentCount) {
  for (int i = 0; i < studentCount - 1; i++) {
    for (int j = 0; j < studentCount - i - 1; j++) {
      if (students[j].lastName > students[j + 1].lastName) {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

void sortByGPA(Student students[], int studentCount) {
  for (int i = 0; i < studentCount - 1; i++) {
    for (int j = 0; j < studentCount - i - 1; j++) {
      if (students[j].GPA > students[j + 1].GPA) {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}