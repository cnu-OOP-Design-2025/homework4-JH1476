#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
    : midterm(midterm), final(final)
{}

float StudentRecord::getTotal() const {
    float sum = midterm + final;
    return sum;

    return 0.0f;
}

void StudentRecord::updateScores(float midterm, float final) {
   this->midterm = midterm;
   this->final = final;
}


/* Student */

Student::Student()
    : name(""), id(0), record(0.0f, 0.0f)
{ }

Student::Student(const char *name, int id, float midterm, float final)
    : name(name), id(id), record(midterm, final)
{  }

void Student::updateRecord(const char *name, float midterm, float final) {
    this->name = name;
    record.updateScores(midterm,final);
}

