#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int NUMGRADES = 5;

struct StudentInfo
{
  string id;
  int grades[NUMGRADES];
  double avGrade;
};

int ReadStudents(istream &input, StudentInfo Info[]);
void HighestAverage(StudentInfo Info[], int numStudents, string &id, double &maxAv);
