// #include "../include/year.h"

// year::year()
// {
//     this->year_ = 0u;
//     this->modules = vector<module_>();
//     this->students = vector<student>();
//     this->professors = vector<professor>();
//     this->activeModules = vector<moduleInstance>();
// }

// year::year(unsigned int year_, vector<module_> modules, vector<student> students, vector<professor> professors, vector<moduleInstance> activeModules)
// {
//     this->year_ = year_;
//     this->modules = modules;
//     this->students = students;
//     this->professors = professors;
//     this->activeModules = activeModules;
// }

// year::year(year &year_) : year(year_.year_, year_.modules, year_.students, year_.professors, year_.activeModules)
// {
// }

// vector<student> &year::getStudents()
// {
//     return this->students;
// }

// void year::setStudents(vector<student> students)
// {
//     this->students = students;
// }

// void year::addStudent(student student_)
// {
//     this->students.push_back(student_);
// }

// vector<module_> &year::getModule()
// {
//     return this->modules;
// }

// void year::setModules(vector<module_> modules)
// {
//     this->modules = modules;
// }

// void year::addModule(module_ module__)
// {
//     this->modules.push_back(module__);
// }

// vector<professor> &year::getProfessors()
// {
//     return this->professors;
// }

// void year::setProfessors(vector<professor> professors)
// {
//     this->professors = professors;
// }

// void year::addProfessor(professor professor_)
// {
//     this->professors.push_back(professor_);
// }

// vector<moduleInstance> &year::getActiveModules()
// {
//     return this->activeModules;
// }

// void year::setActiveModules(vector<moduleInstance> activeModules_)
// {
//     this->activeModules = activeModules_;
// }

// void year::addActiveModule(moduleInstance activeModule)
// {
//     this->activeModules.push_back(activeModule);
// }

// moduleInstance &year::getActiveModule(string moduleCode) throw()
// {
//     for (auto &i : this->activeModules)
//     {
//         if (i.getModule().getModuleCode() == moduleCode)
//         {
//             return i;
//         }
//     }
//     throw std::domain_error("No active module with that code");
// }

// unsigned int year::getYear(){
//     return this->year_;
// }

// void year::setYear(unsigned int year_){
//     this->year_ = year_;
// }