#ifndef MODULE_H
#define MODULE_H

#include <string>
using std::string;

class Module
{
private:
    string moduleCode;
    string description;

public:
    Module();
    Module(string moduleCode, string desc);
    string getModuleCode();
    string getDesc();
    void setModuleCode(string code);
    void setDesc(string desc);
};

#endif