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

string Module::getModuleCode()
{
    return this->moduleCode;
}

string Module::getDesc()
{
    return this->description;
}

void Module::setModuleCode(string code)
{
    this->moduleCode = code;
}

void Module::setDesc(string desc)
{
    this->description = desc;
}