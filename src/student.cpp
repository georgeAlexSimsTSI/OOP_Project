#include "../include/Student.h"

Student::Student() : Person()
{
    this->StudentNumber = 0u;
    this->YearOfStudy = 0u;
    this->enrollmentYear = 0u;
}

Student::Student(unsigned int StudentNumber, unsigned int YearOfStudy, unsigned int enrollmentYear, Person &person) : Person(person)
{
    this->StudentNumber = StudentNumber;
    this->YearOfStudy = YearOfStudy;
    this->enrollmentYear = enrollmentYear;
}

// Student::Student(Student & s) : Person(s.firstName,s.lastName,s.dob,s.email,s.contactNumber,s.address){
//     this->StudentNumber = s.StudentNumber;
//     this->YearOfStudy = s.YearOfStudy;
//     this->enrollmentYear = s.enrollmentYear;
// }

unsigned int Student::getStudentNumber()
{
    return this->StudentNumber;
}

unsigned int Student::getYearOfStudy()
{
    return this->YearOfStudy;
}

unsigned int Student::getenrollmentYear()
{
    return this->enrollmentYear;
}

bool Student::passYear(unsigned int Year)
{
    // create a list of modules with this Year, and then get the students grade average
    vector<ModuleInstance> mods = getModules(Year);
    float passPoint = 40.0, gpa = 0.0;
    // iterate through and check students average grade for module
    for (auto it : mods)
    {
        gpa = it.getStudentAverage(this->StudentNumber);
        if (gpa < passPoint) // need to pass every module
            return false;
    }
    return true;
}

vector<ModuleInstance> Student::getModules()
{
    vector<ModuleInstance> mods;
    for (auto &it : this->modules)
    {
        mods.push_back(*it.second);
    }
    return mods;
}

vector<ModuleInstance> Student::getModules(unsigned int Year)
{
    vector<ModuleInstance> mods;
    for (auto &it : this->modules)
    {
        if (it.second->getYear() == Year)
        {
            mods.push_back(*it.second);
        }
    }
    return mods;
}

void Student::addModule(ModuleInstance *ModuleInstance_)
{
    string code = ModuleInstance_->getModule().getModuleCode() + std::to_string(ModuleInstance_->getYear());
    this->modules[code] = ModuleInstance_;
}

void Student::removeModule(ModuleInstance *ModuleInstance_)
{
    string code = ModuleInstance_->getModule().getModuleCode() + std::to_string(ModuleInstance_->getYear());
    this->modules.erase(code); // should be fine if the module isn't even in the map, erase indicates how many values have been removed
}

float Student::getGPA()
{
    float gpa = 0;
    int count = 0;
    if (modules.size() == 0)
        return 0;
    for (auto i : modules)
    {
        gpa += i.second->getStudentAverage(this->StudentNumber);
        ++count;
    }
    return (gpa / count);
}

void Student::setYearOfStudy(unsigned int i)
{
    this->YearOfStudy = i;
}

void Student::setEnrollmentYear(unsigned int i)
{
    this->enrollmentYear = i;
}
