#include "student.h"
#include "menu.h"
#include <iostream>

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

void displayStudentData(const Student students[], int index) {
  std::cout << "=========================\n";
  std::cout << students[index].lastName << ", ";
  std::cout << students[index].firstName << "\n";
  std::cout << "ID number: " << students[index].studentID << "\n";
  std::cout << "Course: " << students[index].course << ", ";
  std::cout << "GPA: " << students[index].GPA << "\n";
  std::cout << "=========================\n";
}

void displayAllStudentData(const Student students[], int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    displayStudentData(students, i);
  }
}

int searchStudentData(Student students[], int studentCount) {
  if (studentCount < 1) {
    std::cout << "No student records found.\n";
    return -1;
  }
  std::string targetID = enterSearchID();

  for (int i = 0; i < studentCount; i++) {
    if (targetID == students[i].studentID) {
      std::cout << "Student ID found.\n";
      displayStudentData(students, i);
      return i;
    }
  }
  std::cout << "Student ID not found.\n";
  return -1;
}

bool validateStudentID(Student students[], int studentCount, int index) {
  for (int i = 0; i < studentCount; i++) {
    if (i != index && students[index].studentID == students[i].studentID) {
      std::cout << "Student ID duplicate found. Please re-enter ID: ";
      std::cin >> students[index].studentID;
      return false;
    }
  }
  std::cout << "Student info successfully registered!\n";
  return true;
}

void addStudentData(Student students[], int studentCount, int index) {
  if (studentCount >= 1000) {
    std::cout << "Student count exceeded! Enroll somewhere else!\n";
    return;
  }
  std::cout << "Enter Student ID: ";
  std::cin >> students[index].studentID;
  std::cout << "Enter first name: ";
  std::cin >> students[index].firstName;
  std::cout << "Enter last name: ";
  std::cin >> students[index].lastName;
  std::cout << "Enter course: ";
  std::cin >> students[index].course;
  std::cout << "Enter GPA: ";
  std::cin >> students[index].GPA;
  std::cout << "\n";

  validationLooper(students, studentCount, index);
}

void editStudentData(Student students[], int studentCount, int index) {
  std::cout << "Enter new student data.\n";
  addStudentData(students, studentCount, index);
}

void deleteStudent(Student students[], int &studentCount, int index) {
  for (int i = index; i < studentCount - 1; i++) {
    students[i] = students[i + 1];
  }

  students[studentCount - 1].studentID = " ";
  students[studentCount - 1].firstName = " ";
  students[studentCount - 1].lastName = " ";
  students[studentCount - 1].course = " ";
  students[studentCount - 1].GPA = 0;

  studentCount--;
  std::cout << "Student data deleted successfully!\n";
}