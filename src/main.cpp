#include "menu.h"
#include "student.h"
#include "utils.h"
#include <iostream>

int main() {
  Student students[1000]; // SORRY NOT BEST PRACTICES!
  // "Use "std::array" or "std::vector" instead of a C-style array."
  // sonarqube(cpp:S5945)
  int studentCount = 0;
  int searchIndex = 0;
  bool dataIsDeleted = false;
  char opt = ' ';

  while (opt != '5') {
    displayMenu();
    opt = enterOption(opt);
    clearScreen();

    switch (opt) {
    default: // no longer needed since enterOption() handles invalid inputs
    case '1':
      std::cout << "==========ADD A STUDENT==========\n";
      addStudentData(students, studentCount, studentCount);
      studentCount++;
      break;

    case '2':
      std::cout << "==========EDIT STUDENT DATA==========\n";
      searchIndex = searchStudentData(students, studentCount);
      if (searchIndex == -1) {
        break;
      }
      editStudentData(students, studentCount, searchIndex);
      break;

    case '3':
      std::cout << "==========DELETE STUDENT DATA==========\n";
      searchIndex = searchStudentData(students, studentCount);
      if (searchIndex == -1) {
        break;
      }
      dataIsDeleted = studentDataIsDeleted(students, studentCount, searchIndex);
      if (dataIsDeleted) {
        studentCount--;
      }
      break;

    case '4':
      std::cout << "==========STUDENT RECORDS==========\n";
      viewStudentRecords(students, studentCount);
      break;

    case '5':
      std::cout << "Exiting program... Goodbye!";
      return 0;
    }

    pauseScreen();
    clearScreen();
  }
}
