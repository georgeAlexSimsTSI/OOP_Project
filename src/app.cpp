#include "../include/app.h"

inline bool areTheseDetailsCorrect() // Done this to prevent repeated code, easier to change one place than many
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string userInput;
    cout << "Are these details correct (yes/y or no/n)" << endl;
    getline(cin, userInput);

    return (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y"); // later change input to lowercase
}

app::app() // blank system
{
    sys = uniSystem();
}

app::app(uniSystem &sys)
{
    this->sys = sys;
}

void app::displayStudents()
{
    auto students = sys.getStudent();
    for (auto i : students)
    {
        cout << "Student num: " + std::to_string(i.second.getStudentNumber()) + " " + i.second.getFullName() + " GPA: " + std::to_string(i.second.getGPA()) << endl;
    }
}

void app::displayStudent(unsigned int studentNum) // student num firstName lastName gpa
{
    try
    {
        student i = sys.getStudent(studentNum); // throws an error if student isn't found
        cout << "Student: " + std::to_string(i.getStudentNumber()) + " " + i.getFullName() + " GPA: " + std::to_string(i.getGPA()) << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No student with that ID was found" << endl;
    }
}

void app::displayProfessors()
{
    auto professors = sys.getProfessor();
    for (auto j : professors)
    {
        auto i = j.second;
        cout << "Professor: " << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
}

void app::displayProfessor(unsigned int staffNum) // staff num firstName lastName position
{
    try
    {
        professor i = sys.getProfessor(staffNum); // throws an error if student isn't found
        cout << "Professor: " << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No professor with that ID was found" << endl;
    }
}

void app::displayYears() // year numberOfStudents numberOfActiveModules
{
    auto years = sys.getYear();
    for (auto i : years)
    {
        cout << i.second.getYear() << " Students:" << i.second.getStudents().size() << " Professors: " << i.second.getProfessors().size() << " Active Modules: " << i.second.getActiveModules().size() << endl;
    }
}

void app::displayYear(unsigned int yearVal) // year numberOfStudents numberOfActiveModules
{
    try
    {
        year i = sys.getYear(yearVal); // throws an error if student isn't found
        cout << i.getYear() << " Students: " << i.getStudents().size() << " Professors: " << i.getProfessors().size() << " Active Modules: " << i.getActiveModules().size() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Year found" << endl;
    }
}

void app::displayModuleInstances() // {code = year+modulecode}year moduleCode display assignment
{
    // displays instances from the currently selected year
    vector<moduleInstance> moduleInstances = currentYear->getActiveModules();
    for (auto i : moduleInstances)
    { // year moduleCode display assignment
        cout << i.getYear() << " " << i.getModule().getModuleCode() << " Assignments: " << i.getAssignments().size() << endl;
    }
}

void app::displayModuleInstance(string code)
{
    try
    {
        moduleInstance i = currentYear->getActiveModule(code);
        cout << i.getYear() << " " << i.getModule().getModuleCode() << " Assignments: " << i.getAssignments().size() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Year found" << endl;
    }
}

void app::displayAssignments() // code + desc
{
    vector<assignment> assignments = this->currentModuleInstance->getAssignments();
    for (auto i : assignments)
    {
        cout << "Code: " << i.getCode() << " description: " << i.getDesc() << endl;
    }
}

void app::addYear()
{
    // system("cls");
    // year(unsigned int year_, vector<student*> students, vector<professor*> professors, vector<moduleInstance> activeModules);

    // want an option to either add all students or pick ones to be added
    // option to add all professors or to pick ones to be added
    year yearIns;
    unsigned int year_;
    vector<student *> students;
    vector<professor *> professors;
    bool accepted = false;
    string userInput;
    do
    {

        year_ = userInput::validateInput(year_, "Enter the year: ");
        try
        {
            this->currentYear = &this->sys.getYear(year_);
            cout << "This year already exists, please enter another year" << endl;
            continue;
        }
        catch (...)
        {
            // catch and release, we want the exception to be thrown as it means it doesn't exist
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Do you wish to add all of the professors or add them individually? " << endl
             << "yes to add them all" << endl;
        getline(cin, userInput);

        if (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y")
        {
            professors = addAllProfessors();
        }
        else
        {
            professors = selectProfessors();
        }

        cout << "Do you wish to add all of the students or add them individually? " << endl
             << "yes to add them all" << endl;
        getline(cin, userInput);

        if (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y")
        {
            students = addAllStudents();
        }
        else
        {
            students = selectStudents();
        }

        yearIns = year(year_, students, professors, {});

        cout << "The details you have entered are: " << endl;
        cout << "Year: " << yearIns.getYear() << endl;
        cout << "Number of Students: " << yearIns.getStudents().size() << endl;
        cout << "Number of Professors: " << yearIns.getProfessors().size() << endl;

        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    sys.addYear(yearIns);
}

person app::addPerson()
{
    // string firstName, string lastName, string dob, string email, string contactNum;
    // address -> string postCode, string houseNumber, string roadName, string town, string county
    // system("cls");
    string firstName, lastName, dob, email, contactNum, postCode, houseNumber, roadName, town, county;
    address address_;
    person p;
    bool accepted = false;
    do
    {
        cout << "Enter the first Name: ";
        getline(cin, firstName);

        cout << "Enter the last Name: ";
        getline(cin, lastName);

        cout << "Enter the date of birth e.g. dd/mm/yyyy: ";
        getline(cin, dob);

        cout << "Enter the email address: ";
        getline(cin, email);

        cout << "Enter the preferred contact number: ";
        getline(cin, contactNum);

        cout << "Enter the post code e.g. SA2 0PJ: ";
        getline(cin, postCode);

        cout << "Enter the house number: ";
        getline(cin, houseNumber);

        cout << "Enter the road name: ";
        getline(cin, roadName);

        cout << "Enter the town: ";
        getline(cin, town);

        cout << "Enter the county: ";
        getline(cin, county);

        address_ = address(postCode, houseNumber, roadName, town, county);
        p = person(firstName, lastName, dob, email, contactNum, address_);

        cout << "The details you have entered are: " << endl;
        cout << "Full Name: " << p.getFullName() << endl;
        cout << "Date of birth: " << p.getDateOfBirth() << endl;
        cout << "Email Address: " << p.getEmail() << endl;
        cout << "Preferred Contact Number: " << p.getContactNum() << endl;
        cout << "Address:" << endl;
        cout << "Post code: " << p.getAddress().getPostCode() << endl;
        cout << "House Number: " << p.getAddress().getHouseNumber() << endl;
        cout << "Road Name: " << p.getAddress().getRoadName() << endl;
        cout << "Town/City: " << p.getAddress().getTown() << endl;
        cout << "County: " << p.getAddress().getCounty() << endl;

        accepted = areTheseDetailsCorrect();

    } while (!accepted);
    return p;
}

void app::addStudent()
{
    // system("cls");
    person p = addPerson();
    student s;
    // unsigned int studentNumber unsigned int yearOfStudy unsigned int enrollmentYear
    unsigned int studentNumber, yearOfStudy, enrollmentYear;
    bool accepted = false;
    do
    {
        studentNumber = userInput::validateInput(studentNumber, "Enter the student number: ");
        yearOfStudy = userInput::validateInput(yearOfStudy, "Enter the current year of study: ");
        enrollmentYear = userInput::validateInput(enrollmentYear, "Enter the year of enrollment: ");
        s = student(studentNumber, yearOfStudy, enrollmentYear, p);

        cout << "The details you have entered are: " << endl;
        cout << "Student Number: " << s.getStudentNumber() << endl;
        cout << "Year of study: " << s.getYearOfStudy() << endl;
        cout << "Enrolment year: " << s.getenrollmentYear() << endl;

        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    sys.addStudent(s);
}

void app::addProfessor()
{
    // system("cls");
    person p = addPerson();
    professor prof;
    unsigned int staffNumber, officeNumber;
    string position, staffEmail;
    bool accepted = false;
    do
    {
        staffNumber = userInput::validateInput(staffNumber, "Enter the staff number: ");
        officeNumber = userInput::validateInput(officeNumber, "Enter the office number: ");

        cout << "Enter the position e.g. Teaching assistant: ";
        getline(cin, position);
        cout << endl;

        cout << "Enter the staff email address: ";
        getline(cin, staffEmail);
        cout << endl;

        prof = professor(staffNumber, officeNumber, position, staffEmail, p);

        cout << "The details you have entered are: " << endl;
        cout << "Staff number: " << prof.getStaffNumber() << endl;
        cout << "Office number: " << prof.getOfficeNumber() << endl;
        cout << "Position: " << prof.getPosition() << endl;
        cout << "Email: " << prof.getStaffEmail() << endl;

        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    sys.addProfessor(prof);
}

// should only be accessible after going through modify year
void app::addModuleInstance()
{
    // professor &professor_, vector<assignment> assignments, unsigned int year, module_ module__

    // professor will be gotten from a function to select one from the current year, if there are no professors
    //  professor *prof; // will use member variable currentProfessor
    vector<assignment> assignments = vector<assignment>();
    unsigned int year = currentYear->getYear(); // take this from the current year
    module_ mod;
    moduleInstance ins;
    bool accepted = false;
    do
    {
        mod = addModule();
        selectProfessor(); // list current professors take input, if none available prompt user to create one
        cout << "The details you have entered are: " << endl;
        // list module details

        ins = moduleInstance(*currentProfessor, {}, year, mod);
        cout << "Module Code: " << mod.getModuleCode() << endl;
        cout << "Module Description: " << mod.getDesc() << endl;
        // list professor details

        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    this->currentYear->addActiveModule(ins);
}

module_ app::addModule()
{
    module_ mod;
    string moduleCode, description;
    bool accepted = false;
    do
    {
        cout << "Enter the Module Code: ";
        getline(cin, moduleCode);

        cout << "Enter the Module description: ";
        getline(cin, description);

        cout << "The details you have entered are:" << endl;
        mod = module_(moduleCode, description);
        cout << "Module Code: " << mod.getModuleCode() << endl;
        cout << "Module Description: " << mod.getDesc() << endl;

        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    return mod;
}

// should only be accessible after going through modify moduleInstance
void app::addAssignment()
{
    assignment a;
    string code, desc;
    bool accepted = false;
    do
    {
        cout << "Enter the assignment code: ";
        getline(cin, code);
        cout << endl;

        cout << "Enter a description of the assignment: ";
        getline(cin, desc);
        cout << endl;

        a = assignment(code, desc);

        cout << "The details you have entered are: " << endl;
        cout << "Assignment Code: " << a.getCode() << endl;
        cout << "Assignment Description: " << a.getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    this->currentModuleInstance->addAssignment(a);
}

// methods to select objects from the the system, should list options then take user input
void app::selectYear()
{
    if (sys.getYear().size() == 0)
    {
        cout << "There are currently no years, please add one" << endl;
        addYear();
    }

    unsigned int selectedYear;
    bool accepted, error;
    // this->currentYear = &this->sys.getYear(2022u);
    do
    {
        error = false;
        displayYears(); // list all options
        selectedYear = userInput::validateInput(selectedYear, "Enter the year to select: ");

        try
        {
            this->currentYear = &this->sys.getYear(selectedYear);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid year, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT YEAR" << endl;
            error = true;
        }

        if (error)
            continue;

        cout << "You have selected Year: " << selectedYear << endl;
        this->displayYear(selectedYear);

        accepted = areTheseDetailsCorrect();

    } while (!accepted);
}

void app::selectStudent()
{

    if (sys.getStudent().size() == 0)
    {
        cout << "There are currently no students, please add one" << endl;
        addStudent();
    }

    // display all students then ask for student number, going to be similar to select year
    unsigned int selectedStudentNumber;
    bool accepted, error;
    // this->currentYear = &this->sys.getYear(2022u);
    do
    {
        error = false;
        displayStudents(); // list all options
        selectedStudentNumber = userInput::validateInput(selectedStudentNumber, "Enter the student number to select: ");

        try
        {
            this->currentStudent = &this->sys.getStudent(selectedStudentNumber);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid student id, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT STUDENT" << endl;
            error = true;
        }

        if (error)
            continue;

        cout << "You have selected student: " << selectedStudentNumber << endl;
        this->displayStudent(selectedStudentNumber);

        accepted = areTheseDetailsCorrect();

    } while (!accepted);
}

void app::selectProfessor()
{

    if (sys.getProfessor().size() == 0)
    {
        cout << "There are currently no professors, please add one: " << endl;
        addProfessor();
    }

    unsigned int selectedStaffNumber;
    bool accepted, error;
    do
    {
        error = false;
        displayProfessors(); // list all options
        selectedStaffNumber = userInput::validateInput(selectedStaffNumber, "Enter the staff number to select: ");

        try
        {
            this->currentProfessor = &this->sys.getProfessor(selectedStaffNumber);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid staff id, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT PROFESSOR" << endl;
            error = true;
        }

        if (error)
            continue;

        cout << "You have selected Professor: " << selectedStaffNumber << endl;
        this->displayProfessor(selectedStaffNumber);

        accepted = areTheseDetailsCorrect();

    } while (!accepted);
}

void app::selectModuleInstance() // This should always run after select year
{
    // display available module instances from current year
    if (currentYear->getActiveModules().size() == 0)
    {
        cout << "There are no module instances, please create one: " << endl;
        addModuleInstance();
    }

    string code;
    bool accepted = false, error;

    do
    {
        error = false;
        displayModuleInstances();

        cout << "Enter the module code: ";
        getline(cin, code);
        cout << endl;

        try
        {
            this->currentModuleInstance = &this->currentYear->getActiveModule(code);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid staff id, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT MODULE INSTANCE" << endl;
            error = true;
        }

        cout << "You have selected module:" << endl;
        displayModuleInstance(currentModuleInstance->getModule().getModuleCode());
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}

void app::selectAssignment() // should run after select moduleInstance
{
    if (currentModuleInstance->getAssignments().size() == 0)
    {
        cout << "There are no assignments, please add one " << endl;
        addAssignment();
    }

    string code;
    bool accepted = false, error;
    do
    {
        error = false;
        displayAssignments();

        cout << "Enter the assignment code: ";
        getline(cin, code);
        cout << endl;

        try
        {
            this->currentAssignment = &this->currentModuleInstance->getAssignment(code);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid assignment code, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT ASSIGNMENT" << endl;
            error = true;
        }

        cout << "You have selected module:" << endl;
        displayModuleInstance(currentModuleInstance->getModule().getModuleCode());
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}

vector<professor *> app::addAllProfessors()
{
    vector<professor *> professors;
    for (auto &i : sys.getProfessor())
    {
        professors.push_back(&i.second);
    }
    return professors;
}

// to do
vector<professor *> app::selectProfessors()
{
    vector<professor *> professors;
    return professors;
}

vector<student *> app::addAllStudents()
{
    vector<student *> students;
    for (auto &i : sys.getStudent())
    {
        students.push_back(&i.second);
    }
    return students;
}

// to do
vector<student *> app::selectStudents()
{
    vector<student *> students;
    return students;
}

void app::updateYear() // add student, professor from wider system, add module instance, update module instance
{
    /**
     * 1. display current year
     * 2. display students
     * 3. display professors
     * 4. display modules
     * 5. add student
     * 6. add professor
     * 7. add module instance
     * 8. update module instance
     * 9. exit
     */

    selectYear();

    bool validChoice;
    int userChoice;
    vector<student *> currentStudents, availableStudents;
    vector<professor *> currentProfessors, availableProfessors;
    map<unsigned int, student> allStudents;
    map<unsigned int, professor> allProfessors;
    do
    {
        validChoice = false;
        cout << "Update Year Menu" << endl
             << "1. display current year" << endl
             << "2. display students" << endl
             << "3. display professors" << endl
             << "4. display modules" << endl
             << "5. add student" << endl
             << "6. add professor" << endl
             << "7. add module instance" << endl
             << "8. update module instance" << endl
             << "9. exit" << endl
             << endl;
        userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 9)
        {
            cout << "Out of valid input range, please try again" << endl;
            continue;
        }

        switch (userChoice)
        {
        case (1):
            displayYear(this->currentYear->getYear());
            break;
        case (2):
            for (auto &i : this->currentYear->getStudents())
                displayStudent(i->getStudentNumber());
            break;
        case (3):
            for (auto &i : this->currentYear->getProfessors())
                displayProfessor(i->getStaffNumber());
            break;
        case (4):
            for (auto &i : this->currentYear->getActiveModules())
                displayModuleInstance(i.getModule().getModuleCode());
            break;
        case (5):
            // create a list of students not currently in this year
            // pick a student id
            // add student to this year
            currentStudents = currentYear->getStudents();
            allStudents = sys.getStudent();
            availableStudents = vector<student *>();
            for (auto &i : allStudents)
            {
            }

            break;
        case (6):
            // create a list of professors not currently in this year
            // pick a staff id
            // add professor to this year
            break;
        case (7):
            addModuleInstance();
            break;
        case (8):
            updateModuleInstance();
            break;
        default:
            break;
        }

    } while (userChoice != 9);
}

void app::updatePerson() // update personal details and address
{
}

void app::updateAddress() // update address details
{
}

void app::updateStudent() // update person then student details
{
}

void app::updateProfessor() // update person then professor details
{
}

void app::updateModuleInstance() // update module, update assignment or change professor
{
    selectModuleInstance();
}

void app::updateModule() // update module description, not allowing change to module code
{
}

void app::updateAssignment() // update description or give grade
{
}
