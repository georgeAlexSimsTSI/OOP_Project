#include "../include/student.h"
#include "../include/professor.h"
#include "../include/assignment.h"
#include "../include/module.h"
#include "../include/moduleInstance.h"
#include "../include/year.h"
#include "../include/system.h"
#include "../include/app.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;

int main()
{

    address a = address();
    a.update("SA2OPJ", "16", "Dryden", "Swansea", "Absinths");
    vector<person> people{
        person("Robert", "Smith", "24/07/1998", "RobertHenderson@gmail.com", "66014072705", a), // 0
        person("George", "Gonzalez", "05/11/1998", "GeorgeGonzalez@gmail.com", "18780002657", a),
        person("Joshua", "Marsh", "01/11/1996", "Joshua Marsh@gmail.com", "16420037531", a),
        person("Joe", "Davis", "24/12/1999", "JoeDavus@gmail.com", "42213821893", a),
        person("Matilda", "Moore", "24/11/1994", "MatildaMoore@gmail.com", "69414402257", a),
        person("Maya", "Gray", "29/04/1985", "MayaGray@gmail.com", "54489390372", a),
        person("Abby", "Tomlinson", "21/01/1993", "AbbyTomlinson@gmail.com", "57490966824", a),
        person("Riley", "Connors", "05/12/1999", "RileyO'Connor@gmail.com", "66777640162", a),
        person("Lucas", "Daniels", "25/05/2000", "LucaDaniels@gmail.com", "26772032653", a),
        person("Elise", "Phillips", "15/08/1991", "ElisePhillips@gmail.com", "21362649305", a),
        person("Alexander", "Bolton", "14/06/1993", "AlexanderBolton@gmail.com", "6444138776", a),
        person("Anna", "Douglas", "10/12/1986", "AnnaDouglas@gmail.com", "57239521427", a),
        person("Danielle", "Hancock", "20/04/1991", "DanielleHancock@gmail.com", "57391582885", a),
        person("Lucy", "Campbell", "05/09/1980", "LucyCampbell@gmail.com", "97133355633", a),
        person("Amelia", "Howards", "24/07/1973", "AmelieHowards@gmail.com", "19827493186", a),
        person("Kai", "Lynch", "30/09/1988", "KaiLynch@gmail.com", "75740356721", a),
        person("Charlie", "Hanson", "24/10/1994", "Charlie Hanson@gmail.com", "74592187916", a) // 16
    };

    map<unsigned int, student> students{
        {63006u, student(63006, 1u, 20021, people[0])},
        {14494u, student(14494, 2u, 2020u, people[1])},
        {64189u, student(64189, 4u, 2018u, people[2])},
        {33096u, student(33096, 3u, 2019u, people[3])},
        {17280u, student(17280, 2u, 2020u, people[4])},
        {93326u, student(93326, 4u, 2018u, people[5])},
        {37544u, student(37544, 4u, 2018u, people[6])},
        {30745u, student(30745, 3u, 2019u, people[7])},
        {22398u, student(22398, 1u, 2021u, people[8])},
        {77148u, student(77148, 1u, 2021u, people[9])},
        {72791u, student(72791, 1u, 2021u, people[10])},
        {64274u, student(64274, 1u, 2021u, people[11])},
        {49024u, student(49024, 4u, 2018u, people[12])},
        {45235u, student(45235, 2u, 2020u, people[13])},
    };

    map<unsigned int, professor> professors{
        {48804u, professor(48804, 1, "Teaching Professor", "AmelieHowards@fakeuni.eu@email.com", people[14])},
        {48413u, professor(48413, 3, "Research Professor", "KaiLynch@fakeuni.eu", people[15])},
        {35849u, professor(35849, 8, "Teaching assistant", "Charlie Hanson@fakeuni.eu", people[16])},
    };

    map<unsigned int, year> years{
        {2018u, year(2018u, {&students[64189u], &students[93326u], &students[37544u], &students[49024u]}, {&professors[48804u], &professors[48413u], &professors[35849u]}, {})},
        {2019u, year(2019u, {&students[64189u], &students[93326u], &students[37544u], &students[49024u], &students[33096u], &students[30745u]}, {&professors[48804u], &professors[48413u], &professors[35849u]}, {})},
        {2020u, year(2020u, {&students[64189u], &students[93326u], &students[37544u], &students[49024u], &students[33096u], &students[30745u], &students[14494u], &students[17280], &students[45235]}, {&professors[48804u], &professors[48413u], &professors[35849u]}, {})},
        {2021u, year(2021u, {&students[64189u], &students[93326u], &students[37544u], &students[49024u], &students[33096u], &students[30745u], &students[14494u], &students[17280], &students[45235], &students[63006u], &students[22398u], &students[77148u], &students[72791u], &students[64274u]}, {&professors[48804u], &professors[48413u], &professors[35849u]}, {})},
        {2022u, year(2022u, {}, {&professors[48804u], &professors[48413u], &professors[35849u]}, {})}};

    uniSystem sys = uniSystem(students, professors, years);

    vector<module_> mod{
        module_("CS-000", "Test module 1"), // 0
        module_("CS-001", "Test module 2"),
        module_("CSC061", "Test module 3"),
        module_("CS-110", "Test module 4"),
        module_("CS-115", "Test module 5"),
        module_("CS-150", "Test module 6"),
        module_("CS-210", "Test module 7"),
        module_("CS-230", "Test module 8"),
        module_("CS-250", "Test module 9"),
        module_("CSC313", "Test module 10"),
        module_("CSC318", "Test module 11"),
        module_("CSC337", "Test module 12"), // 11
    };

    vector<moduleInstance> modules2018{
        moduleInstance(professors[48804u], {}, 2018u, mod[0]),
        moduleInstance(professors[48804u], {}, 2018u, mod[1]),
        moduleInstance(professors[48804u], {}, 2018u, mod[2])};
    {
        sys.getYear(2018).setActiveModules(modules2018);
        sys.getYear(2018).getActiveModule("CS-000").addAssignment("CS-00001", "Assignment 1");

        sys.getYear(2018).getActiveModule("CS-000").giveGrade(64189u, "CS-00001", 60.0f);
        sys.getStudent(64189u).addModule(&sys.getYear(2018).getActiveModule("CS-000"));

        sys.getYear(2018).getActiveModule("CS-000").giveGrade(93326u, "CS-00001", 43.0f);
        sys.getStudent(93326u).addModule(&sys.getYear(2018).getActiveModule("CS-000"));

        sys.getYear(2018).getActiveModule("CS-000").giveGrade(37544u, "CS-00001", 78.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2018).getActiveModule("CS-000"));

        sys.getYear(2018).getActiveModule("CS-000").giveGrade(49024u, "CS-00001", 53.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2018).getActiveModule("CS-000"));

        sys.getYear(2018).getActiveModule("CS-001").addAssignment("CS-00101", "Assignment 1");
        sys.getYear(2018).getActiveModule("CS-001").giveGrade(64189u, "CS-00101", 56.0f);
        sys.getStudent(64189u).addModule(&sys.getYear(2018).getActiveModule("CS-001"));

        sys.getYear(2018).getActiveModule("CS-001").giveGrade(93326u, "CS-00101", 75.0f);
        sys.getStudent(93326u).addModule(&sys.getYear(2018).getActiveModule("CS-001"));

        sys.getYear(2018).getActiveModule("CS-001").giveGrade(37544u, "CS-00101", 65.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2018).getActiveModule("CS-001"));

        sys.getYear(2018).getActiveModule("CS-001").giveGrade(49024u, "CS-00101", 59.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2018).getActiveModule("CS-001"));

        sys.getYear(2018).getActiveModule("CSC061").addAssignment("CSC06101", "Assignment 1");
        sys.getYear(2018).getActiveModule("CSC061").giveGrade(64189u, "CSC06101", 58.0f);
        sys.getStudent(64189u).addModule(&sys.getYear(2018).getActiveModule("CSC061"));

        sys.getYear(2018).getActiveModule("CSC061").giveGrade(93326u, "CSC06101", 67.0f);
        sys.getStudent(93326u).addModule(&sys.getYear(2018).getActiveModule("CSC061"));

        sys.getYear(2018).getActiveModule("CSC061").giveGrade(37544u, "CSC06101", 60.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2018).getActiveModule("CSC061"));

        sys.getYear(2018).getActiveModule("CSC061").giveGrade(49024u, "CSC06101", 49.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2018).getActiveModule("CSC061"));

        sys.getYear(2018).getActiveModule("CSC061").addAssignment("CSC06102", "Assignment 2");
        sys.getYear(2018).getActiveModule("CSC061").giveGrade(64189u, "CSC06102", 52.0f);
        sys.getYear(2018).getActiveModule("CSC061").giveGrade(93326u, "CSC06102", 68.0f);
        sys.getYear(2018).getActiveModule("CSC061").giveGrade(37544u, "CSC06102", 64.0f);
        sys.getYear(2018).getActiveModule("CSC061").giveGrade(49024u, "CSC06102", 67.0f);
    };

    vector<moduleInstance> modules2019{
        moduleInstance(professors[35849u], {}, 2019u, mod[0]),
        moduleInstance(professors[35849u], {}, 2019u, mod[1]),
        moduleInstance(professors[35849u], {}, 2019u, mod[2]),
        moduleInstance(professors[48804u], {}, 2019u, mod[3]),
        moduleInstance(professors[48804u], {}, 2019u, mod[4]),
        moduleInstance(professors[48804u], {}, 2019u, mod[5])};

    {
        sys.getYear(2019).setActiveModules(modules2019);

        // students[64189u], students[93326u], students[37544u], students[49024u]
        // "CS-110" "CS-115", CS-150"
        sys.getYear(2019).getActiveModule("CS-150").addAssignment("CS-15001", "Assignment 1");
        sys.getYear(2019).getActiveModule("CS-110").addAssignment("CS-11001", "Assignment 1");
        sys.getYear(2019).getActiveModule("CS-110").addAssignment("CS-11002", "Assignment 2");
        sys.getYear(2019).getActiveModule("CS-115").addAssignment("CS-11501", "Assignment 1");

        sys.getYear(2019).getActiveModule("CS-150").giveGrade(64189u, "CS-15001", 73.0f);
        sys.getStudent(64189u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));
        sys.getYear(2019).getActiveModule("CS-150").giveGrade(93326u, "CS-15001", 72.0f);
        sys.getStudent(93326u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));
        sys.getYear(2019).getActiveModule("CS-150").giveGrade(37544u, "CS-15001", 68.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));
        sys.getYear(2019).getActiveModule("CS-150").giveGrade(49024u, "CS-15001", 81.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));

        sys.getYear(2019).getActiveModule("CS-110").giveGrade(64189u, "CS-11001", 67.0f);
        sys.getStudent(64189u).addModule(&sys.getYear(2019).getActiveModule("CS-110"));
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(93326u, "CS-11001", 56.0f);
        sys.getStudent(93326u).addModule(&sys.getYear(2019).getActiveModule("CS-110"));
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(37544u, "CS-11001", 59.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2019).getActiveModule("CS-110"));
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(49024u, "CS-11001", 69.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2019).getActiveModule("CS-110"));
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(64189u, "CS-11001", 77.0f);
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(93326u, "CS-11001", 65.0f);
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(37544u, "CS-11001", 69.0f);
        sys.getYear(2019).getActiveModule("CS-110").giveGrade(49024u, "CS-11001", 79.0f);

        sys.getYear(2019).getActiveModule("CS-115").giveGrade(64189u, "CS-11501", 67.5f);
        sys.getStudent(64189u).addModule(&sys.getYear(2019).getActiveModule("CS-115"));
        sys.getYear(2019).getActiveModule("CS-115").giveGrade(93326u, "CS-11501", 53.5f);
        sys.getStudent(93326u).addModule(&sys.getYear(2019).getActiveModule("CS-115"));
        sys.getYear(2019).getActiveModule("CS-115").giveGrade(37544u, "CS-11501", 58.0f);
        sys.getStudent(37544u).addModule(&sys.getYear(2019).getActiveModule("CS-115"));
        sys.getYear(2019).getActiveModule("CS-115").giveGrade(49024u, "CS-11501", 72.0f);
        sys.getStudent(49024u).addModule(&sys.getYear(2019).getActiveModule("CS-115"));

        // students[33096u], students[30745u] // CS-000  CS-001  CSC061

        sys.getYear(2019).getActiveModule("CS-000").addAssignment("CS-00001", "Assignment 1");

        sys.getYear(2019).getActiveModule("CS-000").giveGrade(33096u, "CS-00001", 82.0f);
        sys.getStudent(33096u).addModule(&sys.getYear(2019).getActiveModule("CS-000"));

        sys.getYear(2019).getActiveModule("CS-000").giveGrade(30745u, "CS-00001", 58.0f);
        sys.getStudent(30745u).addModule(&sys.getYear(2019).getActiveModule("CS-000"));

        sys.getYear(2019).getActiveModule("CS-001").addAssignment("CS-00101", "Assignment 1");

        sys.getYear(2019).getActiveModule("CS-001").giveGrade(33096u, "CS-00101", 59.0f);
        sys.getStudent(33096u).addModule(&sys.getYear(2019).getActiveModule("CS-001"));

        sys.getYear(2019).getActiveModule("CS-001").giveGrade(30745u, "CS-00101", 65.0f);
        sys.getStudent(30745u).addModule(&sys.getYear(2019).getActiveModule("CS-001"));

        sys.getYear(2019).getActiveModule("CSC061").addAssignment("CSC06101", "Assignment 1");

        sys.getYear(2019).getActiveModule("CSC061").giveGrade(33096u, "CSC06101", 55.0f);
        sys.getStudent(33096u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));

        sys.getYear(2019).getActiveModule("CSC061").giveGrade(30745u, "CSC06101", 69.0f);
        sys.getStudent(30745u).addModule(&sys.getYear(2019).getActiveModule("CSC061"));
    };

    vector<moduleInstance> modules2020{
        moduleInstance(professors[35849u], {}, 2019u, mod[0]),
        moduleInstance(professors[35849u], {}, 2019u, mod[1]),
        moduleInstance(professors[35849u], {}, 2019u, mod[2]),
        moduleInstance(professors[48804u], {}, 2019u, mod[3]),
        moduleInstance(professors[48804u], {}, 2019u, mod[4]),
        moduleInstance(professors[48804u], {}, 2019u, mod[5]),
        moduleInstance(professors[48413u], {}, 2020u, mod[6]),
        moduleInstance(professors[48413u], {}, 2020u, mod[7]),
        moduleInstance(professors[48413u], {}, 2020u, mod[8])};

    {
        sys.getYear(2020).setActiveModules(modules2020);
        // 14494 17280 45235
        // CS-000  CS-001  CSC061
        {
            sys.getYear(2020).getActiveModule("CS-000").addAssignment("CS-00001", "Assignment 1");
            sys.getYear(2020).getActiveModule("CS-001").addAssignment("CS-00101", "Assignment 1");
            sys.getYear(2020).getActiveModule("CSC061").addAssignment("CSC06101", "Assignment 1");
            sys.getYear(2020).getActiveModule("CSC061").addAssignment("CSC06102", "Assignment 2");

            sys.getYear(2020).getActiveModule("CS-000").giveGrade(14494u, "CS-00001", 73.0f);
            sys.getStudent(14494u).addModule(&sys.getYear(2020).getActiveModule("CS-000"));
            sys.getYear(2020).getActiveModule("CS-000").giveGrade(17280u, "CS-00001", 82.0f);
            sys.getStudent(17280u).addModule(&sys.getYear(2020).getActiveModule("CS-000"));
            sys.getYear(2020).getActiveModule("CS-000").giveGrade(45235u, "CS-00001", 63.0f);
            sys.getStudent(45235u).addModule(&sys.getYear(2020).getActiveModule("CS-000"));

            sys.getYear(2020).getActiveModule("CS-001").giveGrade(14494u, "CS-00101", 54.0f);
            sys.getStudent(14494u).addModule(&sys.getYear(2020).getActiveModule("CS-001"));
            sys.getYear(2020).getActiveModule("CS-001").giveGrade(17280u, "CS-00101", 49.0f);
            sys.getStudent(17280u).addModule(&sys.getYear(2020).getActiveModule("CS-001"));
            sys.getYear(2020).getActiveModule("CS-001").giveGrade(45235u, "CS-00101", 57.0f);
            sys.getStudent(45235u).addModule(&sys.getYear(2020).getActiveModule("CS-001"));

            sys.getYear(2020).getActiveModule("CSC061").giveGrade(14494u, "CSC06101", 83.0f);
            sys.getStudent(14494u).addModule(&sys.getYear(2020).getActiveModule("CSC061"));
            sys.getYear(2020).getActiveModule("CSC061").giveGrade(17280u, "CSC06101", 62.0f);
            sys.getStudent(17280u).addModule(&sys.getYear(2020).getActiveModule("CSC061"));
            sys.getYear(2020).getActiveModule("CSC061").giveGrade(45235u, "CSC06101", 72.0f);
            sys.getStudent(45235u).addModule(&sys.getYear(2020).getActiveModule("CSC061"));

            sys.getYear(2020).getActiveModule("CSC061").giveGrade(14494u, "CSC06102", 71.0f);
            sys.getYear(2020).getActiveModule("CSC061").giveGrade(17280u, "CSC06102", 83.0f);
            sys.getYear(2020).getActiveModule("CSC061").giveGrade(45235u, "CSC06102", 77.0f);
        };

        // 33096u, 30745u
        //"CS-110" "CS-115", CS-150
        {
            sys.getYear(2020).getActiveModule("CS-150").addAssignment("CS-15001", "Assignment 1");
            sys.getYear(2020).getActiveModule("CS-110").addAssignment("CS-11001", "Assignment 1");
            sys.getYear(2020).getActiveModule("CS-110").addAssignment("CS-11002", "Assignment 2");
            sys.getYear(2020).getActiveModule("CS-115").addAssignment("CS-11501", "Assignment 1");

            sys.getYear(2020).getActiveModule("CS-150").giveGrade(33096u, "CS-00001", 73.0f);
            sys.getStudent(33096u).addModule(&sys.getYear(2020).getActiveModule("CS-150"));
            sys.getYear(2020).getActiveModule("CS-150").giveGrade(30745u, "CS-00001", 82.0f);
            sys.getStudent(30745u).addModule(&sys.getYear(2020).getActiveModule("CS-150"));

            sys.getYear(2020).getActiveModule("CS-110").giveGrade(33096u, "CS-11001", 54.5f);
            sys.getStudent(33096u).addModule(&sys.getYear(2020).getActiveModule("CS-110"));
            sys.getYear(2020).getActiveModule("CS-110").giveGrade(30745u, "CS-11001", 49.0f);
            sys.getStudent(30745u).addModule(&sys.getYear(2020).getActiveModule("CS-110"));

            sys.getYear(2020).getActiveModule("CS-110").giveGrade(33096u, "CS-11002", 71.0f);
            sys.getYear(2020).getActiveModule("CS-110").giveGrade(30745u, "CS-11002", 83.0f);

            sys.getYear(2020).getActiveModule("CS-115").giveGrade(33096u, "CS-11501", 83.5f);
            sys.getStudent(33096u).addModule(&sys.getYear(2020).getActiveModule("CSC061"));
            sys.getYear(2020).getActiveModule("CS-115").giveGrade(30745u, "CS-11501", 62.0f);
            sys.getStudent(30745u).addModule(&sys.getYear(2020).getActiveModule("CSC061"));
        };

        // 64189u, 93326u, 37544u, 49024u
        // CS-210, CS-230, CS-250
        {
            sys.getYear(2020).getActiveModule("CS-210").addAssignment("CS-21001", "Assignment 1");
            sys.getYear(2020).getActiveModule("CS-230").addAssignment("CS-23001", "Assignment 1");
            sys.getYear(2020).getActiveModule("CS-250").addAssignment("CS-25001", "Assignment 1");

            sys.getYear(2020).getActiveModule("CS-210").giveGrade(64189u, "CS-21001", 52.0f);
            sys.getStudent(64189u).addModule(&sys.getYear(2020).getActiveModule("CS-210"));
            sys.getYear(2020).getActiveModule("CS-210").giveGrade(93326u, "CS-21001", 53.0f);
            sys.getStudent(93326u).addModule(&sys.getYear(2020).getActiveModule("CS-210"));
            sys.getYear(2020).getActiveModule("CS-210").giveGrade(37544u, "CS-21001", 63.0f);
            sys.getStudent(37544u).addModule(&sys.getYear(2020).getActiveModule("CS-210"));
            sys.getYear(2020).getActiveModule("CS-210").giveGrade(49024u, "CS-21001", 47.0f);
            sys.getStudent(49024u).addModule(&sys.getYear(2020).getActiveModule("CS-210"));

            sys.getYear(2020).getActiveModule("CS-230").giveGrade(64189u, "CS-23001", 56.0f);
            sys.getStudent(64189u).addModule(&sys.getYear(2020).getActiveModule("CS-230"));
            sys.getYear(2020).getActiveModule("CS-230").giveGrade(93326u, "CS-23001", 57.0f);
            sys.getStudent(93326u).addModule(&sys.getYear(2020).getActiveModule("CS-230"));
            sys.getYear(2020).getActiveModule("CS-230").giveGrade(37544u, "CS-23001", 54.0f);
            sys.getStudent(37544u).addModule(&sys.getYear(2020).getActiveModule("CS-230"));
            sys.getYear(2020).getActiveModule("CS-230").giveGrade(49024u, "CS-23001", 55.0f);
            sys.getStudent(49024u).addModule(&sys.getYear(2020).getActiveModule("CS-230"));

            sys.getYear(2020).getActiveModule("CS-250").giveGrade(64189u, "CS-25001", 62.0f);
            sys.getStudent(64189u).addModule(&sys.getYear(2020).getActiveModule("CS-250"));
            sys.getYear(2020).getActiveModule("CS-250").giveGrade(93326u, "CS-25001", 61.0f);
            sys.getStudent(93326u).addModule(&sys.getYear(2020).getActiveModule("CS-250"));
            sys.getYear(2020).getActiveModule("CS-250").giveGrade(37544u, "CS-25001", 53.0f);
            sys.getStudent(37544u).addModule(&sys.getYear(2020).getActiveModule("CS-250"));
            sys.getYear(2020).getActiveModule("CS-250").giveGrade(49024u, "CS-25001", 65.0f);
            sys.getStudent(49024u).addModule(&sys.getYear(2020).getActiveModule("CS-250"));
        };
    }

    vector<moduleInstance> modules2021{
        moduleInstance(professors[48804], {}, 2021u, mod[9]),
        moduleInstance(professors[48804], {}, 2021u, mod[10]),
        moduleInstance(professors[48804], {}, 2021u, mod[11])};

    app application = app(sys);

    application.run();
    return 0;
}