#include "../include/module.h"

Module::Module()
{
    this->moduleCode = "UI001";
    this->description = "Default module: Uni Induction 01";
}

Module::Module(string moduleCode, string desc)
{
    this->moduleCode = moduleCode;
    this->description = desc;
}

string Module::getModuleCode() const
{
    return this->moduleCode;
}

string Module::getDesc() const
{
    return this->description;
}

void Module::setModuleCode(const string &code)
{
    this->moduleCode = code;
}

void Module::setDesc(const string &desc)
{
    this->description = desc;
}