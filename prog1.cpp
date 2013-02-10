#include "prog1.h"

int ReadStudents(istream &input, StudentInfo Info[])
{
  int numStudents=0;
  string theId;
  while(input >> theId)
    {
      int i = 0;
      int sum = 0;
      int average = 0;
      StudentInfo student;

      student.id = theId;
      for(i=0; i<NUMGRADES; i++)
	{
	  input >> student.grades[i];
	  //cout << "Grade " << i << ": " << student.grades[i] << endl;
	  sum += student.grades[i];
	  //cout << "Sum " << i << ": " << sum << endl;  
	}
      student.avGrade = sum / NUMGRADES;
      sum = 0;
      //cout << "Student " << numStudents+1 << " average is " << student.avGrade << endl; 
      Info[numStudents] = student;
      numStudents++;
    }
  return numStudents;
}

void HighestAverage(StudentInfo Info[], int numStudents, string &id, double &maxAv)
{
  //set max to first student
  id = Info[0].id;
  maxAv = Info[0].avGrade;

  //loop through array to find student with highest average
  for(int i = 1; i<numStudents; i++)
    {
      if(Info[i].avGrade > maxAv)
	{
	  maxAv = Info[i].avGrade;
	  id = Info[i].id;
	}
    }
}
