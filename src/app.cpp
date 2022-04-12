#include "../include/app.h"

inline bool areTheseDetailsCorrect()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string userInput;
    cout << "Are these details correct (yes/y or no/n)" << endl;
    getline(cin, userInput);

    return (userInput == "yes" || userInput == "y" || userInput == "YES" || userInput == "Y"); // later change input to lowercase
}

app::app()
{
    sys = uniSystem();
}

app::app(uniSystem &sys)
{
    this->sys = sys;
}

void app::displayStudents()
{
    vector<student> students = sys.getStudent();
    for (student i : students)
    {
        // student num firstName lastName gpa
        cout << "Student num: " + std::to_string(i.getStudentNumber()) + " " + i.getFullName() + " GPA: " + std::to_string(i.getGPA()) << endl;
    }
}

void app::displayStudent(unsigned int studentNum) // student num firstName lastName gpa
{
    try
    {
        student i = sys.getStudent(studentNum); // throws an error if student isn't found
        cout << "Student num: " + std::to_string(i.getStudentNumber()) + " " + i.getFullName() + " GPA: " + std::to_string(i.getGPA()) << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No student with that ID was found" << endl;
    }
}

void app::displayProfessors()
{
    vector<professor> professors = sys.getProfessor();
    for (professor i : professors)
    {
        // staff num firstName lastName position email
        cout << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
}

void app::displayProfessor(unsigned int staffNum) // staff num firstName lastName position
{
    try
    {
        professor i = sys.getProfessor(staffNum); // throws an error if student isn't found
        cout << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No professor with that ID was found" << endl;
    }
}

void app::displayYears() // year numberOfStudents numberOfActiveModules
{
    vector<year> years = sys.getYear();
    for (year i : years)
    {
        cout << i.getYear() << " Students:" << i.getStudents().size() << " Professors: " << i.getProfessors().size() << " Active Modules" << i.getActiveModules().size() << endl;
    }
}

void app::displayYear(unsigned int yearVal) // year numberOfStudents numberOfActiveModules
{
    try
    {
        year i = sys.getYear(yearVal); // throws an error if student isn't found
        cout << i.getYear() << " Students:" << i.getStudents().size() << " Professors: " << i.getProfessors().size() << " Active Modules: " << i.getActiveModules().size() << endl;
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
    system("cls");
    // year(unsigned int year_, vector<module_> modules, vector<student*> students, vector<professor*> professors, vector<moduleInstance> activeModules);
    unsigned int year_;
}

person app::addPerson()
{
    // string firstName, string lastName, string dob, string email, string contactNum;
    // address -> string postCode, string houseNumber, string roadName, string town, string county
    system("cls");
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
    system("cls");
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
    system("cls");
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

void app::addModule()
{
}

void app::addAssignment()
{
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

        assignment a = assignment(code, desc);

        cout << "The details you have entered are: " << endl;
        cout << "Assignment Code: " << a.getCode() << endl;
        cout << "Assignment Description: " << a.getDesc() << endl;
        accepted = areTheseDetailsCorrect();
    } while (!accepted);
}