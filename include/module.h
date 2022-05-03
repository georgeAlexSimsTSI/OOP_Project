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
    string getModuleCode() const;
    string getDesc() const;
    void setModuleCode(const string &code);
    void setDesc(const string & desc);
};

#endif