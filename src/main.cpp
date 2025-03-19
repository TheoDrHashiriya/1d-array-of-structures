#include "menu.h"
#include "student.h"
#include <iostream>

int main() {
  Student students[1000]; // SORRY NOT BEST PRACTICES!
  // "Use "std::array" or "std::vector" instead of a C-style array."
  // sonarqube(cpp:S5945)
  int studentCount = 0;
  bool IDIsUnique = false;
  bool IDIsFound = false;
  bool dataIsDeleted = false;
  char opt = ' ';

  while (opt != '5') {
    displayMenu();
    opt = enterOption(opt);
    clearScreen();

    switch (opt) {
    default: // no longer needed since enterOption() handles invalid inputs
    case '1':
      if (studentCount >= 1000) {
        std::cout << "Student count exceeded! Enroll somewhere else!\n";
        break;
      }
      addStudentData(students, studentCount);
      validationLooper(students, studentCount, IDIsUnique);
      studentCount++;
      break;

    case '2':
      IDIsFound = searchStudentData(students, studentCount);
      if (!IDIsFound) {
        break;
      }
      editStudentData(students, studentCount);
      validationLooper(students, studentCount, IDIsUnique);
      break;

    case '3':
      dataIsDeleted = searchAndDelete(students, studentCount);
      if (dataIsDeleted) {
        studentCount--;
      }
      break;

    case '4':
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
