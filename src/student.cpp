#include "../include/student.h"

student::student() : person(){
    this->studentNumber = 0u;
    this->yearOfStudy = 0u;
    this->enrollmentYear = 0u;
}

student::student(unsigned int studentNumber, unsigned int yearOfStudy, unsigned int enrollmentYear, person &person_) : person(person_)
{
    this->studentNumber = studentNumber;
    this->yearOfStudy = yearOfStudy;
    this->enrollmentYear = enrollmentYear;
}

// student::student(student & s) : person(s.firstName,s.lastName,s.dob,s.email,s.contactNumber,s.address_){
//     this->studentNumber = s.studentNumber;
//     this->yearOfStudy = s.yearOfStudy;
//     this->enrollmentYear = s.enrollmentYear;
// }

unsigned int student::getStudentNumber()
{
    return this->studentNumber;
}

unsigned int student::getYearOfStudy()
{
    return this->yearOfStudy;
}

unsigned int student::getenrollmentYear()
{
    return this->enrollmentYear;
}

// bool student::passYear(unsigned int year)
// {
//     // create a list of modules with this year, and then get the students grade average
//     vector<moduleInstance> mods = getModules(year);

//     float passPoint = 40.0, gpa = 0.0;
//     // iterate through and check students average grade for module
//     for (auto it : mods)
//     {
//         gpa = it.getStudentAverage(this->studentNumber);
//         if (gpa < passPoint) // need to pass every module
//             return false;
//     }

//     return true;
// }

// vector<moduleInstance> &student::getModules()
// {
//     return this->modules;
// }

// vector<moduleInstance> &student::getModules(unsigned int year)
// {
//     vector<moduleInstance> mods;
//     for (auto &it : this->modules)
//     {
//         if (it.getYear() == year)
//             mods.push_back(it);
//     }
//     return mods;
// }

// void student::addModule(moduleInstance &moduleInstance_)
// {
//     this->modules.push_back(moduleInstance_);
// }

// void student::removeModule(moduleInstance &moduleInstance_)
// {

//     // remove student from the modules active students list
//     vector<student> moduleStudents = moduleInstance_.getStudents();
//     for (int i = 0; i < moduleStudents.size(); ++i)
//         if (moduleStudents[i].studentNumber == this->studentNumber)
//             moduleStudents.erase(moduleStudents.begin() + i);

//     for (int i = 0; i < this->modules.size(); ++i)
//         if (modules[i].getModule().getModuleCode() == moduleInstance_.getModule().getModuleCode())
//             modules.erase(modules.begin() + i);
// }
