#include "../include/module.h"

module_::module_()
{
    this->moduleCode = "UI001";
    this->description = "Default module: Uni Induction 01";
}

module_::module_(string moduleCode, string desc)
{
    this->moduleCode = moduleCode;
    this->description = desc;
}

string module_::getModuleCode()
{
    return this->moduleCode;
}

string module_::getDesc()
{
    return this->description;
}

void module_::setModuleCode(string code)
{
    this->moduleCode = code;
}

void module_::setDesc(string desc)
{
    this->description = desc;
}