#ifndef MODULE_H
#define MODULE_H

#include <string>
using std::string;

class module_
{
private:
    string moduleCode;
    string description;

public:
    module_();
    module_(string moduleCode, string desc);
    string getModuleCode();
    string getDesc();
    void setModuleCode(string code);
    void setDesc(string desc);
};

#endif