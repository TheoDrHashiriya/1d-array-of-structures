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

void displayMenu() {
  std::cout << "=====STUDENT MANAGEMENT SYSTEM=====\n";
  std::cout << "[1] Add Student\n";
  std::cout << "[2] Edit Student\n";
  std::cout << "[3] Delete Student\n";
  std::cout << "[4] View Student Records\n";
  std::cout << "[5] Exit Program\n";
}

void displayStudentData(const Student students[], int index) {
  std::cout << "==================================================\n";
  std::cout << "Student ID: " << students[index].studentId << "\n";
  std::cout << "Name: " << students[index].lastName << ", "
            << students[index].firstName << "\n";
  std::cout << "Course: " << students[index].course << "\n";
  std::cout << "GPA: " << students[index].GPA << "\n";
  std::cout << "==================================================\n";
  return;
}

void displayAllStudentData(const Student students[], int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    displayStudentData(students, i);
  }
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

std::string enterSearchID(std::string searchID) {
  std::cout << "Search for student ID: ";
  std::cin >> searchID;

  return searchID;
}

bool searchStudentData(Student students[], int studentCount) {
  if (studentCount < 1) {
    std::cout << "No student records found.\n";
    return false;
  }
  std::string searchID;
  searchID = enterSearchID(searchID);

  for (int i = 0; i < studentCount; i++) {
    if (searchID == students[i].studentId) {
      std::cout << "Student ID found.\n";
      displayStudentData(students, i);
      return true;
    }
  }
  std::cout << "Student ID not found.\n";
  return false;
}

bool validateStudentID(Student students[], int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    if (students[studentCount].studentId == students[i].studentId) {
      std::cout << "Student ID duplicate found. Please re-enter ID: ";
      std::cin >> students[studentCount].studentId;
      return false;
    }
  }
  std::cout << "Student info successfully registered!\n";
  return true;
}

void validationLooper(Student students[], int studentCount, bool IDIsUnique) {
  while (!IDIsUnique) {
    IDIsUnique = validateStudentID(students, studentCount);
  }
}

void addStudentData(Student students[], int studentCount) {
  std::cout << "Enter Student ID: ";
  std::cin >> students[studentCount].studentId;
  std::cout << "Enter first name: ";
  std::cin >> students[studentCount].firstName;
  std::cout << "Enter last name: ";
  std::cin >> students[studentCount].lastName;
  std::cout << "Enter course: ";
  std::cin >> students[studentCount].course;
  std::cout << "Enter GPA: ";
  std::cin >> students[studentCount].GPA;
}

void editStudentData(Student students[], int studentCount) {
  std::cout << "Enter new student data.\n";
  addStudentData(students, studentCount);
}

void deleteStudentData(Student students[], int studentCount) {
  students[studentCount].studentId = " ";
  students[studentCount].firstName = " ";
  students[studentCount].lastName = " ";
  students[studentCount].course = " ";
  students[studentCount].GPA = 0;
  std::cout << "Student data deleted successfully!\n";
}

bool searchAndDelete(Student students[], int studentCount) {
  if (studentCount < 1) {
    std::cout << "No student records found.\n";
    return false;
  }
  std::string searchID;
  searchID = enterSearchID(searchID);

  for (int i = 0; i < studentCount; i++) {
    if (searchID == students[i].studentId) {
      std::cout << "Student ID found.\n";
      displayStudentData(students, i);

      char option;
      std::cout << "Delete? [Y/N]: ";
      std::cin >> option;

      if (tolower(option) == 'y') {
        deleteStudentData(students, i);
        return true;
      }
      return false;
    }
  }
  std::cout << "Student ID not found.\n";
  return false;
}

void sortAlphabetically(Student students[], int studentCount) {
  for (int i = 0; i < studentCount; i++) {
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
  for (int i = 0; i < studentCount; i++) {
    for (int j = 0; j < studentCount - i - 1; j++) {
      if (students[j].GPA > students[j + 1].GPA) {
        Student temp = students[i];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
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

  if (option == '1') {
    sortAlphabetically(students, studentCount);
  }
  if (option == '2') {
    sortByGPA(students, studentCount);
  }

  displayAllStudentData(students, studentCount);
}