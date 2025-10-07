#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    int idx = findStudentByID(id);

    for(int i = idx; i < num_of_students-1; i++) {
        students[i] = students[i+1];
    }
    num_of_students--;
}

void StudentManager::modifyStudent(const Student& student) {
    int id = student.getID();
    int idx = findStudentByID(id);
    students[idx] = student;
}

int StudentManager::findStudentByID(int id) const {
    for (int i = 0; i < num_of_students; i++) {
        if(students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    if (num_of_students > 0) {
    float max = 0.0f;
    int best_idx = 0;
    for (int i = 0; i < num_of_students; i++) {
        if(students[i].getRecord().getMidterm() > max) {
            max = students[i].getRecord().getMidterm();
            best_idx = i;
            }
        }
        return best_idx;
    }
    return -1;
}

int StudentManager::findBestStudentInFinal() const {
    if (num_of_students > 0) {
    float max = 0.0f;
    int best_idx = 0;
    for (int i = 0; i < num_of_students; i++) {
        if(students[i].getRecord().getFinal() > max) {
            max = students[i].getRecord().getFinal();
            best_idx = i;
            }
        }
        return best_idx;
    }
    return -1;
}

int StudentManager::findBestStudent() const {
    if (num_of_students > 0) {
    float max = 0.0f;
    int best_id = 0;
    for (int i = 0; i < num_of_students; i++) {
        if(students[i].getRecord().getMidterm() + students[i].getRecord().getFinal() > max) {
            max = students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
            best_id = students[i].getID();
            }
        }
        return best_id;
    }
    return -1;
}

float StudentManager::getMidtermAverage() const {
    if(num_of_students > 0) {
        float sum = 0.0f;
        for(int i = 0; i < num_of_students; i++) {
            sum += students[i].getRecord().getMidterm();
        }
        return sum/(float)num_of_students;
    }
    return 0.0f;
}

float StudentManager::getFinalAverage() const {
    if(num_of_students > 0) {
        float sum = 0.0f;
        for(int i = 0; i < num_of_students; i++) {
            sum += students[i].getRecord().getFinal();
        }
        return sum/(float)num_of_students;
    }
    return 0.0f;
}

float StudentManager::getTotalAverage() const {
    if(num_of_students > 0) {
        float sum = 0.0f;
        for(int i = 0; i < num_of_students; i++) {
            sum += (students[i].getRecord().getMidterm() + students[i].getRecord().getFinal());
        }
        return sum/(float)num_of_students;
    }
    return 0.0f;
}

