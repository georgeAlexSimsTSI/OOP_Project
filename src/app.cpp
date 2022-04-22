#include "../include/app.h"

inline bool areTheseDetailsCorrect() // Done this to prevent repeated code, easier to change one place than many
{
    string userInput;
    cout << endl
         << "Are these details correct (yes/y or no/n)" << endl;
    getline(cin, userInput);

    return (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y"); // later change input to lowercase
}

App::App() // blank system
{
    sys = UniSystem();
}

App::App(UniSystem &sys)
{
    this->sys = sys;
}

void App::displayStudent()
{
    auto students = sys.getStudent();
    for (auto i : students)
    {
        cout << "Student: " << std::setw(7) << std::to_string(i.second.getStudentNumber()) << " " << std::setw(25) << i.second.getFullName() + " GPA: ";
        std::printf("%5.2f", i.second.getGPA());
        cout << "%" << endl;
    }
}

void App::displayStudent(unsigned int StudentNum) // Student num firstName lastName gpa
{
    try
    {
        Student i = sys.getStudent(StudentNum); // throws an error if Student isn't found
        cout << "Student: " << std::setw(7) << std::to_string(i.getStudentNumber()) << " " << std::setw(25) << i.getFullName() + " GPA: ";
        std::printf("%.2f", i.getGPA());
        cout << "%" << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Student with that ID was found" << endl;
    }
}

void App::displayProfessor()
{
    auto professors = sys.getProfessor();
    for (auto j : professors)
    {
        auto i = j.second;
        cout << "Professor: " << std::setw(7) << i.getStaffNumber() << " " << std::setw(15) << i.getFullName() << " " << std::setw(15) << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
}

void App::displayProfessor(unsigned int staffNum) // staff num firstName lastName position
{
    try
    {
        Professor i = sys.getProfessor(staffNum); // throws an error if Student isn't found
        cout << "Professor: " << std::setw(7) << i.getStaffNumber() << " " << std::setw(15) << i.getFullName() << " " << std::setw(15) << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Professor with that ID was found" << endl;
    }
}

void App::displayYear() // Year numberOfStudents numberOfActiveModules
{
    auto years = sys.getYear();
    for (auto i : years)
    {
        cout << i.second.getYear() << " students:" << std::setw(3) << i.second.getstudents().size() << " professors: " << std::setw(3) << i.second.getprofessors().size() << " Active Modules: " << std::setw(3) << i.second.getActiveModules().size() << endl;
    }
}

void App::displayYear(unsigned int YearVal) // Year numberOfStudents numberOfActiveModules
{
    try
    {
        Year i = sys.getYear(YearVal); // throws an error if Student isn't found
        cout << i.getYear() << " students:" << std::setw(3) << i.getstudents().size() << " professors: " << std::setw(3) << i.getprofessors().size() << " Active Modules: " << std::setw(3) << i.getActiveModules().size() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Year found" << endl;
    }
}

void App::displayModuleInstance() // {code = Year+modulecode}Year moduleCode display Assignment
{
    // displays instances from the currently selected Year
    vector<ModuleInstance> ModuleInstances = currentYear->getActiveModules();
    for (auto i : ModuleInstances)
    { // Year moduleCode display Assignment
        cout << std::setw(3) << i.getYear() << " " << std::setw(7) << i.getModule().getModuleCode() << " assignments: " << std::setw(3) << i.getassignments().size() << "  Professor: " << i.getProfessor()->getStaffNumber() << endl;
    }
}

void App::displayModuleInstance(string code)
{
    try
    {
        ModuleInstance i = currentYear->getActiveModule(code);
        cout << std::setw(3) << i.getYear() << " " << std::setw(7) << i.getModule().getModuleCode() << " assignments: " << std::setw(3) << i.getassignments().size() << "  Professor: " << i.getProfessor()->getStaffNumber() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Module Instance found" << endl;
    }
}

void App::displayAssignment() // code + desc
{
    vector<Assignment> assignments = this->currentModuleInstance->getassignments();
    for (auto i : assignments)
    {
        cout << "Code: " << std::setw(10) << i.getCode() << " description: " << i.getDesc() << endl;
    }
}

void App::displayAssignment(string code)
{
    try
    {
        Assignment i = currentModuleInstance->getAssignment(code);
        cout << "Code: " << i.getCode() << " description: " << i.getDesc() << endl
             << "Grades: " << endl;
        for (auto j : i.getGrade())
        {
            cout << "Student: " << std::setw(10) << j.first << " Grade: " << std::setw(5) << j.second << "%" << endl;
        }
    }
    catch (std::domain_error e)
    {
        cout << "No Assignment found" << endl;
    }
}

void App::addYear()
{
    // want an option to either add all students or pick ones to be added
    // option to add all professors or to pick ones to be added
    Year YearIns;
    unsigned int year;
    vector<Student *> students;
    vector<Professor *> professors;
    bool accepted = false;
    string userInput;
    do
    {
        cout << endl;
        year = userInput::validateInput(year, "Enter the Year: ");
        try
        {
            this->currentYear = &this->sys.getYear(year);
            cout << "This Year already exists, please enter another Year" << endl;
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
            professors = addAllprofessors();
        }
        else
        {
            professors = selectprofessors();
        }
        cout << "Do you wish to add all of the students or add them individually? " << endl
             << "yes to add them all" << endl;
        getline(cin, userInput);
        if (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y")
        {
            students = addAllstudents();
        }
        else
        {
            students = selectstudents();
        }
        YearIns = Year(year, students, professors, {});
        cout << "The details you have entered are: " << endl;
        cout << "Year: " << YearIns.getYear() << endl;
        cout << "Number of students: " << YearIns.getstudents().size() << endl;
        cout << "Number of professors: " << YearIns.getprofessors().size() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    sys.addYear(YearIns);
}

Person App::addPerson()
{
    string firstName, lastName, dob, email, contactNum, postCode, houseNumber, roadName, town, county;
    Address address;
    Person p;
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
        cout << "Enter the email Address: ";
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
        address = Address(postCode, houseNumber, roadName, town, county);
        p = Person(firstName, lastName, dob, email, contactNum, address);
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

void App::addStudent()
{
    Person p = addPerson();
    Student s;
    unsigned int StudentNumber, YearOfStudy, enrollmentYear;
    bool accepted = false;
    do
    {
        cout << endl;
        StudentNumber = userInput::validateInput(StudentNumber, "Enter the Student number: ");
        try
        {
            sys.getStudent(StudentNumber);
            cout << "That Id is already in use. Please try again" << endl;
            continue;
        }
        catch (...)
        {
            // We want it to throw an error
        }
        YearOfStudy = userInput::validateInput(YearOfStudy, "Enter the current Year of study: ");
        enrollmentYear = userInput::validateInput(enrollmentYear, "Enter the Year of enrollment: ");
        s = Student(StudentNumber, YearOfStudy, enrollmentYear, p);
        cout << endl;
        cout << "The details you have entered are: " << endl;
        cout << "Student Number: " << s.getStudentNumber() << endl;
        cout << "Year of study: " << s.getYearOfStudy() << endl;
        cout << "Enrolment Year: " << s.getenrollmentYear() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    sys.addStudent(s);
}

void App::addProfessor()
{
    // system("cls");
    Person p = addPerson();
    Professor prof;
    unsigned int staffNumber, officeNumber;
    string position, staffEmail;
    bool accepted = false;
    do
    {
        cout << endl;
        staffNumber = userInput::validateInput(staffNumber, "Enter the staff number: ");
        try
        {
            sys.getProfessor(staffNumber);
            cout << "That Id is already in use. Please try again" << endl;
            continue;
        }
        catch (...)
        {
            // We want it to throw an error
        }
        officeNumber = userInput::validateInput(officeNumber, "Enter the office number: ");
        cout << "Enter the position e.g. Teaching assistant: ";
        getline(cin, position);
        cout << "Enter the staff email Address: ";
        getline(cin, staffEmail);
        cout << endl;
        prof = Professor(staffNumber, officeNumber, position, staffEmail, p);
        cout << "The details you have entered are: " << endl;
        cout << "Staff number: " << prof.getStaffNumber() << endl;
        cout << "Office number: " << prof.getOfficeNumber() << endl;
        cout << "Position: " << prof.getPosition() << endl;
        cout << "Email: " << prof.getStaffEmail() << endl;
        accepted = areTheseDetailsCorrect();
        cout << endl;
    } while (!accepted);
    sys.addProfessor(prof);
}

// should only be accessible after going through modify Year
void App::addModuleInstance()
{
    // Professor &professor, vector<Assignment> assignments, unsigned int Year, Module module_
    // Professor will be gotten from a function to select one from the current Year, if there are no professors
    // Professor *prof; // will use member variable currentProfessor
    vector<Assignment> assignments = vector<Assignment>();
    unsigned int Year = currentYear->getYear(); // take this from the current Year
    Module mod;
    ModuleInstance ins;
    bool accepted = false;
    do
    {
        cout << endl;
        mod = addModule();
        try
        {
            sys.getYear(Year).getActiveModule(mod.getModuleCode());
            cout << "That Module code is already in use. Please try again " << endl;
            continue;
        }
        catch (...)
        {
            // We want it to throw an error
        }
        selectProfessor(); // list current professors take input, if none available prompt user to create one
        cout << endl;
        cout << "The details you have entered are: " << endl; // list module details
        cout << endl;
        ins = ModuleInstance(*currentProfessor, {}, Year, mod);
        cout << "Module Code: " << mod.getModuleCode() << endl;
        cout << "Module Description: " << mod.getDesc() << endl; // list Professor details
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    this->currentYear->addActiveModule(ins);
}

Module App::addModule()
{
    Module mod;
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
        mod = Module(moduleCode, description);
        cout << "Module Code: " << mod.getModuleCode() << endl;
        cout << "Module Description: " << mod.getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    return mod;
}

// should only be accessible after going through modify ModuleInstance
void App::addAssignment()
{
    Assignment a;
    string code, desc;
    bool accepted = false;
    do
    {
        cout << endl;
        cout << "Enter the Assignment code: ";
        getline(cin, code);
        try
        {
            currentModuleInstance->getAssignment(code);
            cout << "That code is already in use. Please try again" << endl;
            continue;
        }
        catch (...)
        {
            // We want it to throw an error
        }
        cout << "Enter a description of the Assignment: ";
        getline(cin, desc);
        a = Assignment(code, desc);
        cout << endl;
        cout << "The details you have entered are: " << endl;
        cout << "Assignment Code: " << a.getCode() << endl;
        cout << "Assignment Description: " << a.getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
    this->currentModuleInstance->addAssignment(a);
}

// methods to select objects from the the system, should list options then take user input
void App::selectYear()
{
    if (sys.getYear().size() == 0)
    {
        cout << "There are currently no years, please add one" << endl;
        cout << endl;
        addYear();
    }
    unsigned int selectedYear;
    bool accepted, error;
    do
    {
        error = false;
        cout << endl;
        displayYear(); // list all options
        cout << endl;
        selectedYear = userInput::validateInput(selectedYear, "Enter the Year to select: ");
        try
        {
            this->currentYear = &this->sys.getYear(selectedYear);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid Year, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT Year" << endl;
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

void App::selectStudent()
{
    if (sys.getStudent().size() == 0)
    {
        cout << "There are currently no students, please add one" << endl;
        cout << endl;
        addStudent();
    }
    // display all students then ask for Student number, going to be similar to select Year
    unsigned int selectedStudentNumber;
    bool accepted, error;
    do
    {
        error = false;
        cout << endl;
        displayStudent(); // list all options
        selectedStudentNumber = userInput::validateInput(selectedStudentNumber, "Enter the Student number to select: ");
        cout << endl;
        try
        {
            this->currentStudent = &this->sys.getStudent(selectedStudentNumber);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid Student id, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT Student" << endl;
            error = true;
        }
        if (error)
            continue;
        cout << endl;
        cout << "You have selected Student: " << selectedStudentNumber << endl;
        this->displayStudent(selectedStudentNumber);
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}

void App::selectProfessor()
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
        displayProfessor(); // list all options
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
            cout << "UNEXPECTED ERROR IN SELECT Professor" << endl;
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

void App::selectModuleInstance() // This should always run after select Year
{
    // display available module instances from current Year
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
        displayModuleInstance();
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

void App::selectAssignment() // should run after select ModuleInstance
{
    if (currentModuleInstance->getassignments().size() == 0)
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
        displayAssignment();
        cout << endl;
        cout << "Enter the Assignment code: ";
        getline(cin, code);
        try
        {
            this->currentAssignment = &this->currentModuleInstance->getAssignment(code);
        }
        catch (std::domain_error e)
        {
            cout << "Invalid Assignment code, please try again" << endl;
            error = true;
        }
        catch (...)
        {
            cout << "UNEXPECTED ERROR IN SELECT Assignment" << endl;
            error = true;
        }
        if (error)
            continue;
        cout << endl;
        cout << "You have selected Assignment: " << endl;
        cout << endl;
        displayAssignment(currentAssignment->getCode());
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}

vector<Professor *> App::addAllprofessors()
{
    vector<Professor *> professors;
    for (auto &i : sys.getProfessor())
    {
        professors.push_back(&i.second);
    }
    return professors;
}

vector<Professor *> App::selectprofessors()
{
    unsigned int userInput;
    vector<Professor *> professors;
    map<int, Professor> availableprofessors; // local copy
    availableprofessors.insert(sys.getProfessor().begin(), sys.getProfessor().end());
    bool done = false;
    while (!done && availableprofessors.size() > 0)
    {
        cout << endl;
        cout << "The available professors are: " << endl;
        for (auto i : availableprofessors)
        {
            displayProfessor(i.second.getStaffNumber());
        }
        cout << endl;
        userInput = userInput::validateInput(userInput, "Enter the staff number: ");
        try
        {
            professors.push_back(&sys.getProfessor(userInput));
            cout << "Professor: " << userInput << " has been added to the list" << endl;
            availableprofessors.erase(userInput);
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

vector<Student *> App::addAllstudents()
{
    vector<Student *> students;
    for (auto &i : sys.getStudent())
    {
        students.push_back(&i.second);
    }
    return students;
}

vector<Student *> App::selectstudents()
{
    unsigned int userInput;
    vector<Student *> students;
    map<int, Student> availablestudents; // local copy
    availablestudents.insert(sys.getStudent().begin(), sys.getStudent().end());
    bool done = false;
    while (!done && availablestudents.size() > 0)
    {
        cout << endl;
        cout << "The available students are: " << endl;
        for (auto i : availablestudents)
        {
            displayStudent(i.second.getStudentNumber());
        }
        cout << endl;
        userInput = userInput::validateInput(userInput, "Enter the Student number: ");
        try
        {
            students.push_back(&sys.getStudent(userInput));
            cout << "Student: " << userInput << " has been added to the list" << endl;
            availablestudents.erase(userInput);
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

void App::updateYear() // add Student, Professor from wider system, add module instance, update module instance
{
    /**
     * 1. display current Year
     * 2. display students
     * 3. display professors
     * 4. display modules
     * 5. add Student
     * 6. add Professor
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
    vector<Student *> currentstudents;
    vector<Professor *> currentprofessors;
    map<unsigned int, Student> availablestudents;
    map<unsigned int, Professor> availableprofessors;
    do
    {
        cout << endl;
        validChoice = false;
        cout << "Update Year Menu" << endl
             << "1. display current Year" << endl
             << "2. display students" << endl
             << "3. display professors" << endl
             << "4. display modules" << endl
             << "5. add Student" << endl
             << "6. add Professor" << endl
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
            for (auto &i : this->currentYear->getstudents())
                displayStudent(i->getStudentNumber());
            break;
        case (3):
            for (auto &i : this->currentYear->getprofessors())
                displayProfessor(i->getStaffNumber());
            break;
        case (4):
            for (auto &i : this->currentYear->getActiveModules())
                displayModuleInstance(i.getModule().getModuleCode());
            break;
        case (5):
            // create a list of students not currently in this Year
            // pick a Student id
            // add Student to this Year
            currentstudents = currentYear->getstudents();
            availablestudents.insert(sys.getStudent().begin(), sys.getStudent().end()); // local copy of the map
            for (auto &i : currentstudents)
                availablestudents.erase(i->getStudentNumber());
            while (!validChoice && availablestudents.size() > 0)
            {
                cout << "Available students: " << endl;
                for (auto &i : availablestudents)
                    displayStudent(i.second.getStudentNumber());
                userInput::validateInput(identificationNumber, "Enter the Student number: ");
                try
                {
                    currentYear->addStudent(&sys.getStudent(identificationNumber));
                    cout << "Student " << identificationNumber << " has been added to the Year" << endl;
                    validChoice = true;
                }
                catch (...)
                {
                    cout << "Invalid Student number, try again" << endl;
                }
            }
            break;
        case (6):
            // create a list of professors not currently in this Year
            // pick a staff id
            // add Professor to this Year
            currentprofessors = currentYear->getprofessors();
            availableprofessors.insert(sys.getProfessor().begin(), sys.getProfessor().end()); // local copy of the map
            for (auto &i : availableprofessors)
                availableprofessors.erase(i.second.getStaffNumber());
            while (!validChoice && availableprofessors.size() > 1)
            {
                cout << "Available professors: " << endl;
                for (auto &i : availableprofessors)
                    displayProfessor(i.second.getStaffNumber());
                userInput::validateInput(identificationNumber, "Enter the staff number: ");
                try
                {
                    currentYear->addProfessor(&sys.getProfessor(identificationNumber));
                    cout << "Professor " << identificationNumber << " has been added to the Year" << endl;
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

void App::updatePerson(Person *p) // update Personal details and Address
{
    /**
     * firstName
     * lastName
     * dob
     * email
     * contactNum
     * Address
     */
    bool finished = false;
    int choice;
    string userInput;
    Address a;
    while (!finished)
    {
        cout << endl;
        cout << "1. First Name: " << p->getFirstName() << endl
             << "2. Last Name: " << p->getLastName() << endl
             << "3. Date Of Birth: " << p->getDateOfBirth() << endl
             << "4. Personal Email: " << p->getEmail() << endl
             << "5. Contact Num: " << p->getContactNum() << endl
             << "6. Edit Address" << endl
             << "7. Exit" << endl;
        cout << endl;
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
            a = setAddress(p->getAddress());
            p->setAddress(a);
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
            cout << "The new Personal email is: " << userInput << endl;
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

Address App::setAddress(Address a) // update Address details
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
        cout << "The current Address details are: " << endl
             << "1. Post Code: " << a.getPostCode() << endl
             << "2. House Number: " << a.getHouseNumber() << endl
             << "3. Road Name: " << a.getRoadName() << endl
             << "4. Town/City: " << a.getTown() << endl
             << "5. County: " << a.getCounty() << endl
             << "6. Exit: " << endl;
        userChoice = userInput::validateInput(userChoice, "If you wish to abort enter 6: ");
        cout << endl;
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
        cout << "The new Address details are: " << endl
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

void App::updateStudent() // update Person then Student details
{
    /**
     * Personal details
     * YearOfStudy
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
        cout << "The Student: " << currentStudent->getStudentNumber() << endl
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

void App::updateProfessor() // update Person then Professor details
{
    /**
     * Personal details
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

void App::updateModuleInstance() // update module, update Assignment or change Professor
{
    selectModuleInstance();
    /**
     *  add Assignment
     *  modify module details
     *  modify Assignment
     */
    bool accepted = false;
    int userChoice;
    while (!accepted)
    {
        cout << endl;
        displayModuleInstance(this->currentModuleInstance->getModule().getModuleCode());
        displayAssignment();
        cout << endl;
        cout << "1. Modify Module details: " << endl
             << "2. Modify Assignment (give grade): " << endl
             << "3. Add Assignment: " << endl
             << "4. Replace Professor" << endl
             << "5. exit" << endl;
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        cout << endl;
        if (userChoice < 1 || userChoice > 5)
        {
            cout << "Invalid input " << endl;
            continue;
        }
        if (userChoice == 5)
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
        case 4:
            selectProfessor(); // not taking any measures to prevent you from replacing a Professor with them selves
            currentModuleInstance->setProfessor(currentProfessor);
        }
    }
}

void App::updateModule() // update module description, not allowing change to module code
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
        this->currentModuleInstance->getModule().setDesc(newDesc);
        cout << "New Module Description: " << this->currentModuleInstance->getModule().getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    }
}

void App::updateAssignment() // update description or give grade
{
    /**
     * Assignment description
     * Assignment code if there aren't any grades
     * add grade
     */
    // when adding a grade need to select a Student from the ones in the Year.
    // after giving the Student a grade check that the Student is enrolled in the module
    cout << endl;
    selectAssignment();
    bool done = false, validStudent;
    int choice, StudentNum;
    float grade;
    string userInputString;
    while (!done)
    {
        cout << endl;
        cout << "Assignment Code: " << currentAssignment->getCode() << endl
             << "Description: " << currentAssignment->getDesc() << endl
             << "Has " << currentAssignment->getGrade().size() << " Grades stored" << endl;
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
            if (currentAssignment->getGrade().size() == 0)
            {
                cout << "Enter the new Assignment Code: ";
                getline(cin, userInputString);
                currentAssignment->setCode(userInputString);
            }
            else
            {
                cout << "The Assignment already has submissions so you cant change the code. " << endl;
            }
            break;
        case 2: // desc
            cout << "Enter the new Assignment Description: ";
            getline(cin, userInputString);
            currentAssignment->setDesc(userInputString);
            break;
        case 3: // give grade
            // select Student from available in Year
            validStudent = false;
            while (!validStudent)
            {
                cout << "Available students are: " << endl;
                for (auto &i : currentYear->getstudents())
                {
                    displayStudent(i->getStudentNumber());
                }
                StudentNum = userInput::validateInput(StudentNum, "Enter the Student number: ");
                try
                {
                    currentStudent = &sys.getStudent(StudentNum);
                }
                catch (...)
                {
                    cout << "No Student with that number was found " << endl;
                    continue;
                }
                grade = userInput::validateInput(grade, "Enter the grade%: ");
                if (grade < 0.0)
                {
                    cout << "Invalid grade %, must be positive" << endl;
                    continue;
                }
                cout << "You have decided to give Student: " << StudentNum << " A grade of: " << grade << endl;
                validStudent = areTheseDetailsCorrect();
                if (!validStudent)
                    continue;
                currentAssignment->giveGrade(StudentNum, grade);
                currentStudent->addModule(currentModuleInstance);
            }
            break;
        }
    }
}

// Will condense later, just want a working version before my brain stops working for the day
inline void introduction()
{
    cout << endl
         << "Welcome to the fake university system";
}

inline void MainMenu()
{
    cout << endl
         << "1. Display" << endl
         << "2. Add" << endl
         << "3. Update" << endl
         << "4. Delete" << endl
         << "5. EXIT" << endl
         << endl;
}

inline void displayMenu()
{
    cout << endl
         << "1. Display students" << endl
         << "2. Display professors" << endl
         << "3. Display years" << endl
         << "4. Display Modules" << endl
         << "5. Display assignments" << endl
         << "6. EXIT" << endl
         << endl;
}

inline void getMenu() // specific display
{
    cout << endl
         << "1. Get Student" << endl
         << "2. Get Professor" << endl
         << "3. Get Year" << endl
         << "4. Get Module" << endl
         << "5. Get Assignment" << endl
         << "6. EXIT" << endl
         << endl;
}

inline void addMenu()
{
    cout << endl
         << "1. Add Student" << endl
         << "2. Add Professor" << endl
         << "3. Add Year" << endl
         << "4. EXIT" << endl
         << endl;
}

inline void updateMenu()
{
    cout << endl
         << "1. Update Student" << endl
         << "2. Update Professor" << endl
         << "3. Update Year" << endl
         << "4. EXIT" << endl
         << endl;
}

inline void deleteMenu()
{
    cout << endl
         << "1. Delete Student" << endl
         << "2. Delete Professor" << endl
         << "3. Delete Year" << endl
         << "4. Delete Module" << endl
         << "5. Delete Assignment" << endl
         << "6. EXIT" << endl
         << endl;
}

void App::displayObjectProcess()
{
    int userChoice = 1;
    system("cls");
    while (userChoice != 6)
    {
        cout << endl;
        displayMenu();
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 6)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 6)
            continue;
        switch (userChoice)
        {
        case 1: // students
            displayStudent();
            break;
        case 2: // professors
            displayProfessor();
            break;
        case 3: // years
            displayYear();
            break;
        case 4: // Modules
            cout << "First Select a Year to display modules from: " << endl;
            selectYear();
            displayModuleInstance();
            break;
        case 5: // Assignment
            cout << "First need to select the Year: " << endl;
            selectYear();
            cout << "Now need to select the Module: " << endl;
            selectModuleInstance();
            selectAssignment();
            displayAssignment(currentAssignment->getCode());
            break;
        }
    }
}

void App::addObjectProcess()
{
    int userChoice = 1;
    system("cls");
    while (userChoice != 4)
    {
        cout << endl;
        addMenu();
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 4)
            continue;
        switch (userChoice)
        {
        case 1: // students
            addStudent();
            break;
        case 2: // professors
            addProfessor();
            break;
        case 3: // years
            addYear();
            break;
        case 4: // Modules
            cout << "First Select a Year to select a module from: " << endl;
            selectYear();
            addModuleInstance();
            break;
        }
    }
}

void App::updateObjectProcess()
{
    int userChoice = 1;
    system("cls");
    while (userChoice != 4)
    {
        cout << endl;
        updateMenu();
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 4)
            continue;
        switch (userChoice)
        {
        case 1: // students
            updateStudent();
            break;
        case 2: // professors
            updateProfessor();
            break;
        case 3: // years
            updateYear();
            break;
        case 4: // Modules
            cout << "First Select a Year to select a module from: " << endl;
            selectYear();
            addModuleInstance();
            break;
        }
    }
}

void App::deleteObjectProcess()
{
    Professor *p;
    int userChoice = 1;
    system("cls");
    while (userChoice != 6)
    {
        cout << endl;
        deleteMenu();
        userChoice = userInput::validateInput(userChoice, "Enter your choice: ");
        if (userChoice < 1 || userChoice > 6)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 6)
            continue;
        switch (userChoice)
        {
        case 1: // students
            selectStudent();
            sys.removeStudent(currentStudent->getStudentNumber());
            break;
        case 2: // professors
            selectProfessor();
            p = currentProfessor;
            cout << "Please Select the replacement Professor for any teaching modules: " << endl;
            selectProfessor();
            sys.removeProfessor(p->getStaffNumber(), currentProfessor->getStaffNumber());
            break;
        case 3: // years
            selectYear();
            sys.removeYear(currentYear->getYear());
            break;
        case 4: // Modules
            cout << "First Select a Year to select a module from: " << endl;
            selectYear();
            selectModuleInstance();
            sys.removeModuleInstance(currentYear->getYear(), currentModuleInstance->getModule().getModuleCode());
            break;
        case 5:
            cout << "First Select a Year to select a module from: " << endl;
            selectYear();
            cout << "Now please select a module to remove the Assignment from: " << endl;
            selectModuleInstance();
            cout << "Now please select the Assignment: " << endl;
            selectAssignment();
            sys.removeAssignment(currentYear->getYear(), currentModuleInstance->getModule().getModuleCode(), currentAssignment->getCode());
        }
    }
}

void App::run()
{
    // system("cls");
    introduction();
    int userChoice = 1;
    while (userChoice != 5)
    {
        cout << endl;
        MainMenu();
        userChoice = userInput::validateInput(userChoice, "Pick an option: ");
        if (userChoice < 1 || userChoice > 5)
        {
            cout << "Invalid Input" << endl;
            continue;
        }
        if (userChoice == 5)
            continue;
        switch (userChoice)
        {
        case 1: // display
            displayObjectProcess();
            break;
        case 2: // add
            addObjectProcess();
            break;
        case 3: // update
            updateObjectProcess();
            break;
        case 4: // delete
            deleteObjectProcess();
            break;
        }
    }
    cout << "Good bye" << endl;
}