#include "../include/app.h"

inline bool areTheseDetailsCorrect() // Done this to prevent repeated code, easier to change one place than many
{
    string userInput;
    cout << endl << "Are these details correct (yes/y or no/n)" << endl;
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
        cout << endl;
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
        cout << endl;
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
        cout << endl;
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
        cout << endl;
        studentNumber = userInput::validateInput(studentNumber, "Enter the student number: ");
        yearOfStudy = userInput::validateInput(yearOfStudy, "Enter the current year of study: ");
        enrollmentYear = userInput::validateInput(enrollmentYear, "Enter the year of enrollment: ");
        s = student(studentNumber, yearOfStudy, enrollmentYear, p);
        cout << endl;
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
        cout << endl;
        staffNumber = userInput::validateInput(staffNumber, "Enter the staff number: ");
        officeNumber = userInput::validateInput(officeNumber, "Enter the office number: ");
        cout << "Enter the position e.g. Teaching assistant: ";
        getline(cin, position);
        cout << endl;
        cout << "Enter the staff email address: ";
        getline(cin, staffEmail);
        cout << endl;
        prof = professor(staffNumber, officeNumber, position, staffEmail, p);
        cout << endl;
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
        cout << endl;
        mod = addModule();
        selectProfessor(); // list current professors take input, if none available prompt user to create one
        cout << endl;
        cout << "The details you have entered are: " << endl;
        // list module details
        cout << endl;
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
        cout << endl;
        cout << "Enter the Module Code: ";
        getline(cin, moduleCode);
        cout << "Enter the Module description: ";
        getline(cin, description);
        cout << endl;
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
        cout << endl;
        cout << "Enter the assignment code: ";
        getline(cin, code);
        cout << endl;
        cout << "Enter a description of the assignment: ";
        getline(cin, desc);
        cout << endl;
        a = assignment(code, desc);
        cout << endl;
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
        cout << endl;
        addYear();
    }

    unsigned int selectedYear;
    bool accepted, error;
    // this->currentYear = &this->sys.getYear(2022u);
    do
    {
        error = false;
        cout << endl;
        displayYears(); // list all options
        cout << endl;
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
        cout << endl;
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
        cout << endl;
        addStudent();
    }

    // display all students then ask for student number, going to be similar to select year
    unsigned int selectedStudentNumber;
    bool accepted, error;
    // this->currentYear = &this->sys.getYear(2022u);
    do
    {
        error = false;
        cout << endl;
        displayStudents(); // list all options
        selectedStudentNumber = userInput::validateInput(selectedStudentNumber, "Enter the student number to select: ");
        cout << endl;
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
        cout << endl;
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
        cout << endl;
        addProfessor();
        cout << endl;
    }

    unsigned int selectedStaffNumber;
    bool accepted, error;
    do
    {
        error = false;
        cout << endl;
        displayProfessors(); // list all options
        cout << endl;
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
        cout << endl;
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
        cout << endl;
        addModuleInstance();
    }
    string code;
    bool accepted = false, error;
    do
    {
        error = false;
        cout << endl;
        displayModuleInstances();
        cout << endl;
        cout << "Enter the module code: ";
        getline(cin, code);
        cout << endl;
        try
        {
            this->currentModuleInstance = &this->currentYear->getActiveModule(code);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid Module id, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT MODULE INSTANCE" << endl;
            error = true;
        }
        if (error)
            continue;
        cout << endl;
        cout << "You have selected module:" << endl;
        cout << endl;
        displayModuleInstance(currentModuleInstance->getModule().getModuleCode());
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}

void app::selectAssignment() // should run after select moduleInstance
{
    if (currentModuleInstance->getAssignments().size() == 0)
    {
        cout << "There are no assignments, please add one " << endl;
        cout << endl;
        addAssignment();
    }

    string code;
    bool accepted = false, error;
    do
    {
        error = false;
        cout << endl;
        displayAssignments();
        cout << endl;
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
        if (error)
            continue;
        cout << endl;
        cout << "You have selected module:" << endl;
        cout << endl;
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
    unsigned int userInput;
    vector<professor *> professors;
    map<int, professor> availableProfessors; // local copy
    availableProfessors.insert(sys.getProfessor().begin(), sys.getProfessor().end());
    bool done = false;
    while (!done && availableProfessors.size() > 0)
    {
        cout << endl;
        cout << "The available professors are: " << endl;
        for (auto i : availableProfessors)
        {
            displayProfessor(i.second.getStaffNumber());
        }
        cout << endl;
        userInput = userInput::validateInput(userInput, "Enter the staff number: ");
        try
        {
            professors.push_back(&sys.getProfessor(userInput));
            cout << "Professor: " << userInput << " has been added to the list" << endl;
            availableProfessors.erase(userInput);
        }
        catch (...)
        {
            cout << "Invalid Staff number, please try again" << endl;
            continue;
        }
        cout << endl;
        cout << "If you wish to stop enter 0: " << endl;
        cout << endl;
        userInput = userInput::validateInput(userInput, "0 to stop 1 to continue: ");
        if (userInput == 0)
            done = true;
    }
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
    unsigned int userInput;
    vector<student *> students;
    map<int, student> availableStudents; // local copy
    availableStudents.insert(sys.getStudent().begin(), sys.getStudent().end());
    bool done = false;
    while (!done && availableStudents.size() > 0)
    {
        cout << endl;
        cout << "The available Students are: " << endl;
        for (auto i : availableStudents)
        {
            displayStudent(i.second.getStudentNumber());
        }
        cout << endl;
        userInput = userInput::validateInput(userInput, "Enter the Student number: ");
        try
        {
            students.push_back(&sys.getStudent(userInput));
            cout << "Student: " << userInput << " has been added to the list" << endl;
            availableStudents.erase(userInput);
        }
        catch (...)
        {
            cout << "Invalid Student number, please try again" << endl;
            continue;
        }
        cout << endl;
        cout << "If you wish to stop enter 0: " << endl;
        userInput = userInput::validateInput(userInput, "0 to stop 1 to continue: ");
        if (userInput == 0)
            done = true;
    }
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
    cout << endl;
    selectYear();
    cout << endl;
    bool validChoice;
    int userChoice;
    unsigned int identificationNumber;
    vector<student *> currentStudents;
    vector<professor *> currentProfessors;
    map<unsigned int, student> availableStudents;
    map<unsigned int, professor> availableProfessors;
    do
    {
        cout << endl;
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
        cout << endl;
        userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 9)
        {
            cout << "Out of valid input range, please try again" << endl;
            continue;
        }
        cout << endl;
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
            availableStudents.insert(sys.getStudent().begin(), sys.getStudent().end()); // local copy of the map
            for (auto &i : currentStudents)
                availableStudents.erase(i->getStudentNumber());

            while (!validChoice && availableStudents.size() > 0)
            {
                cout << "Available Students: " << endl;
                for (auto &i : availableStudents)
                    displayStudent(i.second.getStudentNumber());

                userInput::validateInput(identificationNumber, "Enter the student number: ");

                try
                {
                    currentYear->addStudent(&sys.getStudent(identificationNumber));
                    cout << "Student " << identificationNumber << " has been added to the year" << endl;
                    validChoice = true;
                }
                catch (...)
                {
                    cout << "Invalid student number, try again" << endl;
                }
            }
            break;
        case (6):
            // create a list of professors not currently in this year
            // pick a staff id
            // add professor to this year
            currentProfessors = currentYear->getProfessors();
            availableProfessors.insert(sys.getProfessor().begin(), sys.getProfessor().end()); // local copy of the map
            for (auto &i : availableProfessors)
                availableProfessors.erase(i.second.getStaffNumber());

            while (!validChoice && availableProfessors.size() > 1)
            {
                cout << "Available Professors: " << endl;
                for (auto &i : availableProfessors)
                    displayProfessor(i.second.getStaffNumber());
                userInput::validateInput(identificationNumber, "Enter the staff number: ");
                try
                {
                    currentYear->addProfessor(&sys.getProfessor(identificationNumber));
                    cout << "Professor " << identificationNumber << " has been added to the year" << endl;
                    validChoice = true;
                }
                catch (...)
                {
                    cout << "Invalid staff number, try again" << endl;
                }
            }
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
        cout << endl;
    } while (userChoice != 9);
}

void app::updatePerson(person *p) // update personal details and address
{
    /**
     * firstName
     * lastName
     * dob
     * email
     * contactNum
     * address
     */
    bool finished = false;
    int choice;
    string userInput;
    address a;
    while (!finished)
    {
        cout << endl;
        cout << "1. First Name: " << p->getFirstName() << endl
             << "2. Last Name: " << p->getLastName() << endl
             << "3. Date Of Birth: " << p->getDateOfBirth() << endl
             << "4. Personal Email: " << p->getEmail() << endl
             << "5. Contact Num: " << p->getContactNum() << endl
             << "6. Edit address" << endl
             << "7. Exit" << endl;
        userInput::validateInput(choice, "Enter your choice: ");
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid input" << endl;
            continue;
        }
        if (choice == 7)
        {
            finished = true;
            continue;
        }
        if (choice == 6)
        {
            a = updateAddress(p->getAddress());
            p->updateAddress(a);
            continue;
        }
        cout << "Enter the new value: ";
        getline(cin, userInput);
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "The new First Name is: " << userInput << endl;
            p->setFirstName(userInput);
            break;
        case 2:
            cout << "The new Last Name is: " << userInput << endl;
            p->setLastName(userInput);
            break;
        case 3:
            cout << "The new Date Of Birth is: " << userInput << endl;
            p->setDateOfBirth(userInput);
            break;
        case 4:
            cout << "The new personal email is: " << userInput << endl;
            p->setEmail(userInput);
            break;
        case 5:
            cout << "The new preferred contact number is: " << userInput << endl;
            p->setContactNum(userInput);
            break;
        default:
            break;
        }
    }
}

address app::updateAddress(address a) // update address details
{
    /**
     * postCode
     * houseNumber
     * roadName
     * town
     * county
     */
    bool done = false;
    string postCode, houseNumber, roadName, town, county;
    int userChoice;
    while (!done)
    {
        cout << endl;
        cout << "The current address details are: " << endl
             << "1. Post Code: " << a.getPostCode() << endl
             << "2. House Number: " << a.getHouseNumber() << endl
             << "3. Road Name: " << a.getRoadName() << endl
             << "4. Town/City: " << a.getTown() << endl
             << "5. County: " << a.getCounty() << endl
             << "6. Exit: " << endl;
        userChoice = userInput::validateInput(userChoice, "If you wish to abort enter 6: ");
        if (userChoice < 1 || userChoice > 6)
        {
            cout << "Invalid Input, try again" << endl;
            continue;
        }
        if (userChoice == 6)
        {
            done = true;
            continue;
        }
        cout << endl;
        postCode, houseNumber, roadName, town, county;
        cout << "Enter the new Post Code: ";
        getline(cin, postCode);
        cout << "Enter the new House Number: ";
        getline(cin, houseNumber);
        cout << "Enter the new Road Name: ";
        getline(cin, roadName);
        cout << "Enter the new Town/City: ";
        getline(cin, town);
        cout << "Enter the new county: ";
        getline(cin, county);
        cout << endl;
        a.update(postCode, houseNumber, roadName, town, county);
        cout << endl;
        cout << "The new address details are: " << endl
             << "1. Post Code: " << a.getPostCode() << endl
             << "2. House Number: " << a.getHouseNumber() << endl
             << "3. Road Name: " << a.getRoadName() << endl
             << "4. Town/City: " << a.getTown() << endl
             << "5. County: " << a.getCounty() << endl
             << "6. Exit: " << endl;
        done = areTheseDetailsCorrect();
    }
    return a;
}

void app::updateStudent() // update person then student details
{
    /**
     * personal details
     * yearOfStudy
     * enrollmentYear
     */
    cout << endl;
    selectStudent();
    bool accepted = false;
    int userChoice, userInput;
    while (!accepted)
    {
        cout << endl;
        cout << endl;
        cout << "The student: " << currentStudent->getStudentNumber() << endl
             << "1. Personal details: " << endl
             << "2. Current Year of Study: " << currentStudent->getYearOfStudy() << endl
             << "3. Enrollment Year: " << currentStudent->getenrollmentYear() << endl
             << "4. EXIT" << endl;
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        cout << endl;
        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 4)
        {
            accepted = true;
            continue;
        }
        switch (userChoice)
        {
        case 1:
            updatePerson(this->currentStudent);
            break;
        case 2:
            userInput = userInput::validateInput(userInput, "Enter The new Year of study: ");
            this->currentStudent->setYearOfStudy((unsigned)userInput);
            break;
        case 3:
            userInput = userInput::validateInput(userInput, "Enter The new Year of enrollment: ");
            this->currentStudent->setEnrollmentYear((unsigned)userInput);
            break;
        }
    }
}

void app::updateProfessor() // update person then professor details
{
    /**
     * personal details
     * officeNumber
     * position
     * staffEmail
     */
    cout << endl;
    selectProfessor();
    bool accepted = false;
    int userChoice, userInput;
    string userStrInput;
    while (!accepted)
    {
        cout << endl;
        cout << "The Professor: " << currentProfessor->getStaffNumber() << endl
             << "1. Personal details: " << endl
             << "2. Office Number : " << currentProfessor->getOfficeNumber() << endl
             << "3. Position: " << currentProfessor->getPosition() << endl
             << "4. Staff Email: " << currentProfessor->getEmail() << endl
             << "5. EXIT" << endl;
        if (userChoice < 1 || userChoice > 5)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 5)
        {
            accepted = true;
            continue;
        }
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        cout << endl;
        switch (userChoice)
        {
        case 1:
            updatePerson(this->currentProfessor);
            break;
        case 2:
            userInput = userInput::validateInput(userInput, "Enter The new office number: ");
            this->currentProfessor->setOfficeNumber((unsigned)userInput);
            break;
        case 3:
            cout << "Enter the new position: ";
            getline(cin, userStrInput);
            cout << endl;
            this->currentProfessor->setPosition(userStrInput);
            break;
        case 4:
            cout << "Enter the new Staff Email: ";
            getline(cin, userStrInput);
            cout << endl;
            this->currentProfessor->setStaffEmail(userStrInput);
            break;
        }
    }
}

void app::updateModuleInstance() // update module, update assignment or change professor
{
    cout << endl;
    selectModuleInstance();
    /**
     *  add assignment
     *  modify module details
     *  modify assignment
     */
    bool accepted = false;
    int userChoice;
    while (!accepted)
    {
        cout << endl;
        displayModuleInstance(this->currentModuleInstance->getModule().getModuleCode());
        displayAssignments();
        cout << endl;
        cout << "1. Modify Module details: " << endl
             << "2. Modify Assignment (give grade): " << endl
             << "3. Add assignment: " << endl
             << "4. exit" << endl;
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        cout << endl;
        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid input " << endl;
            continue;
        }
        if (userChoice == 4)
        {
            accepted = true;
            continue;
        }
        switch (userChoice)
        {
        case 1:
            updateModule();
            break;
        case 2:
            updateAssignment();
            break;
        case 3:
            addAssignment();
            break;
        }
    }
}

void app::updateModule() // update module description, not allowing change to module code
{
    /**
     * module description
     */
    bool accepted = false;
    int choice;
    string newDesc;
    while (!accepted)
    {
        cout << endl;
        cout << "The current Module Details are: " << endl
             << "1. Module Code: " << this->currentModuleInstance->getModule().getModuleCode() << endl
             << "2. Module Description: " << this->currentModuleInstance->getModule().getDesc() << endl
             << "3. Exit: " << endl;

        userInput::validateInput(choice, "You can only modify the Description. So enter 2 to modify the description or 3 to cancel: ");
        if (choice < 2 || choice > 3)
        {
            cout << "Invalid choice" << endl;
            continue;
        }
        if (choice == 3)
        {
            accepted = true;
            continue;
        }
        cout << "Enter the new Description: ";
        getline(cin, newDesc);
        cout << endl;
        cout << endl;
        this->currentModuleInstance->getModule().setDesc(newDesc);
        cout << "New Module Description: " << this->currentModuleInstance->getModule().getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    }
}

void app::updateAssignment() // update description or give grade
{
    /**
     * assignment description
     * assignment code if there aren't any grades
     * add grade
     */

    // when adding a grade need to select a student from the ones in the year.
    // after giving the student a grade check that the student is enrolled in the module
    cout << endl;
    selectAssignment();
    bool done = false, validStudent;
    int choice, studentNum;
    float grade;
    string userInputString;
    while (!done)
    {
        cout << endl;
        cout << "Assignment Code: " << currentAssignment->getCode() << endl
             << "Description: " << currentAssignment->getDesc() << endl
             << "Has " << currentAssignment->getGrades().size() << " Grades stored" << endl;
        cout << endl;
        cout << "1. If there are no stored grades then Assignment Code " << endl
             << "2. Description " << endl
             << "3. Give Student a grade" << endl
             << "4. exit " << endl;
        choice = userInput::validateInput(choice, "Enter your choice: ");
        if (choice < 1 || choice > 4)
        {
            cout << "Invalid input" << endl;
            continue;
        }
        if (choice == 4)
        {
            done = true;
            continue;
        }
        cout << endl;
        switch (choice)
        {
        case 1: // code
            if (currentAssignment->getGrades().size() == 0)
            {
                cout << "Enter the new Assignment Code: ";
                getline(cin, userInputString);
                currentAssignment->setCode(userInputString);
            }
            else
            {
                cout << "The assignment already has submissions so you cant change the code. " << endl;
            }
            break;
        case 2: // desc
            cout << "Enter the new Assignment Description: ";
            getline(cin, userInputString);
            currentAssignment->setDesc(userInputString);
            break;
        case 3: // give grade
            // select student from available in year
            validStudent = false;
            while (!validStudent)
            {
                cout << "Available students are: " << endl;
                for (auto &i : currentYear->getStudents())
                {
                    displayStudent(i->getStudentNumber());
                }
                studentNum = userInput::validateInput(studentNum, "Enter the student number: ");
                try
                {
                    currentStudent = &sys.getStudent(studentNum);
                }
                catch (...)
                {
                    cout << "No student with that number was found " << endl;
                    continue;
                }
                grade = userInput::validateInput(grade, "Enter the grade%: ");
                if (grade < 0.0)
                {
                    cout << "Invalid grade %, must be positive" << endl;
                    continue;
                }
                cout << "You have decided to give Student: " << studentNum << " A grade of: " << grade << endl;
                validStudent = areTheseDetailsCorrect();
                if (!validStudent)
                    continue;
                currentAssignment->giveGrade(studentNum, grade);
                currentStudent->addModule(currentModuleInstance);
            }
            break;
        }
    }
}
