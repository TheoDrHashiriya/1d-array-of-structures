#pragma once
#include <string>

struct Student {
  std::string studentID = " ";
  std::string firstName = " ";
  std::string lastName = " ";
  std::string course = " ";
  double GPA = 0;
};

void displayStudentData(const Student students[], int index);
void displayAllStudentData(const Student students[], int studentCount);
int searchStudentData(Student students[], int studentCount);
bool validateStudentID(Student students[], int studentCount, int index);
void addStudentData(Student students[], int studentCount, int index);
void editStudentData(Student students[], int studentCount, int index);
void deleteStudent(Student students[], int &studentCount, int index);