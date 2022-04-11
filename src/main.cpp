#include "../include/student.h"
#include "../include/professor.h"
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;

int main(){

    address a = address();
    person p = person("Jane","Smith","09/07/2020","fakeEmail@email.com","01793434757", a);

    student s = student(934563u, 1u, 2016u, p);
    professor prof = professor(01u, 001u, "TA", "businesEmail@email.com", p);
    
    a.update("SA2OPJ","16", "Dryden", "Swansea", "Absinths");

    return 0;
}