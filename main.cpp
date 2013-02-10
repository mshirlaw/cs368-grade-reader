/*
  Author: mshirlaw
  A solution to the first assignment for CS368
  "Learning a New Programming Language: C++ for Java Programmers"
*/

#include "prog1.h"
#include <fstream>
#include <stdlib.h>


void openDataSource(ifstream &inFile, char *name)
{
  //open the file 
  inFile.open(name);
  
  //make sure it worked
  if (inFile.fail())
    {
      cerr << "Unable to open " << name << endl;
      exit(1);
    }
}

int main(int argc, char *argv[])
{
  string id;
  double maxAv;
  ifstream inFile;
  int numStudents = 0;

  //make sure the file name was given as a command line arg
  if(argc < 2)
    {
      cerr << "Usage: " << argv[0] << " <file name>" << endl;
      exit(1);
    }

  openDataSource(inFile, argv[1]);

  //count number of students
  while(inFile.good())
    {
      string line;
      getline(inFile, line);
      ++numStudents;
    }

  inFile.close();
  openDataSource(inFile, argv[1]);

  //cout << numStudents << endl;
  
  StudentInfo Info[numStudents];
  numStudents = ReadStudents(inFile,Info);
  HighestAverage(Info, numStudents, id, maxAv);
  
  cout << "Student " << id << " has the highest average: " << maxAv << endl;

  return 0;
}
