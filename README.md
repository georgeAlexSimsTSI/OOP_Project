
Switched to iterative development to make finding bugs a bit easier
11/04/2022 
+ Did a lot of work towards keeping objects as reference's but it caused a lot of issues with inheritance, will revisit with time and do it with pointers
+ just learnt about circular dependency and how its been causing certain issues so I need to keep that in mind for future 

12/04/2022
+ tested and fixed student module instance and module
+ finished up and tested year
+ tested and fixed system, had issue with modifying passed values
+ start planning out app
+ display methods
+ add person, student, professor, assignment

13/04/2022
+ working on add module function
+ started work on selecting methods 
+ found out that I misunderstood the throw() statement in method decelerations, it is different to java
+ finished add methods
+ started work on select students and select professors
+ changed system to store everything in maps instead of vectors. This is to make checking for duplicate keys faster

** practice copy constructors as my attempt seems to break code **

**to do**
* modify methods
*   update person
*       update address
*   update student, professor
*   update year
*       add student, professor to year
*       add module instance
*       update module instance
*           update assignment
*           give student grade
* run method


look into C++ iomanip