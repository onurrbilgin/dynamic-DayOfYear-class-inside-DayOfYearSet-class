//This is the driver code main.cpp. It tests all the functions
//and everything in dayofyear.h and its source file.

#include <iostream>
#include "dayofyearset.h"
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

using namespace DayOfYearSetBilgin;

void test1();   // Declaration of test1() function


int main(){     // Driver

    test1();    // Call test function
    return 0;   // End of program
}


void test1(){ // Function for testing dayofyear.h
    
    DayOfYearSet::DayOfYear obj1(3, 3);         // Create an instance of DayOfYear with (int, int) constructor
    vector <DayOfYearSet::DayOfYear> elements;  // Vector will be used for parameter
    for(auto i = 0; i < 5; ++i){                // Fill the vector with some DayOfYear objects
        
        DayOfYearSet::DayOfYear obj(i + 1, (i + 1)*2);
        elements.push_back(obj);
    }

    // Test for DayOfYear::output()
    cout << "Output function for the class DayOfYear:" << endl << endl;
    obj1.output();

    // Test for DayOfYearSet::DayOfYear(vector) constructor
    DayOfYearSet set1(elements);
    cout << endl << endl << "Set1:" << endl << endl << set1 << endl;

    // Test for DayOfYearSet::add() function
    set1.add(obj1);
    cout << endl <<"obj1 Added Set1:" << endl << endl << set1 << endl;
    cout << "Trying to Add obj1 again to Set1:" << endl;
    set1.add(obj1);

    // Test for DayOfYearSet::remove() functions
    set1.remove(obj1);
    cout << endl << "obj1 Removed Set:" << endl << endl << set1 << endl;
    cout << "Trying to Remove obj1 again from Set1:" << endl;
    set1.remove(obj1);

    // Overload of remove with vector
    set1.remove(elements);
    cout << endl << "First 5 elements Removed from Set1:" << endl << set1 << endl;
    cout << "trying to remove first 5 elements again from Set1:" << endl << endl;
    set1.remove(elements);
    cout << endl;

    // Test for DayOfYear::DayOfYear constructors
    DayOfYearSet::DayOfYear NOPCobj, OPCobj(5);
    set1.add(NOPCobj);
    set1.add(OPCobj);
    cout << "Added 2 new objects to the Set1:" << endl << endl;
    cout << set1 << endl;

    // Test for DayOfYearSet::size() function
    cout << endl << "Size of the Set1:" << endl << endl;
    cout << set1.size() << endl << endl;

    DayOfYearSet set2(elements);
    cout << "Created new Set2 with first 5 elements" << endl << endl;
    cout << set2 << endl << endl;

    // Test for DayOfYear::allDayOfYear() static function
    cout << "All DayOfYear objects living in DayOfYearSets:" << endl << endl;
    cout << DayOfYearSet::allDayOfYear() << endl << endl;

    set1.add(2, 4);
    cout << "Added February 4th to the Set1:" << endl << endl;
    cout << "Set1:" << endl << endl;
    cout << set1 << endl;

    // Test for DayOfYearSet::operator-() overload
    cout << "(Set1 - Set2):" << endl << endl;
    cout << set1 - set2 << endl;
    cout << "(Set2 - Set1):" << endl << endl;
    cout << set2 - set1 << endl;

    // Test for DayOfYearSet::operator+() overload
    cout << "(Set1 + Set2)" << endl << endl;
    cout << set1 + set2 << endl;

    // Test for DayOfYearSet::operator^() overload
    cout << "Intersection of Set1 and Set2:" << endl << endl;
    cout << (set1^set2) << endl;
    
    // Test for DayOfYearSet::operator==() overload
    if(set1 == set2)
        cout << "operator==: Set1 is equal to Set2" << endl << endl;
    else
        cout << "operator==: Set1 is not equal to Set2" << endl << endl;

    // Test for DayOfYearSet::operator=() overload
    set1 = set2;
    cout << "Made set1 = set2 with assignment operator=" << endl << endl;

    // Test for DayOfYearSet::operator!=() overload
    if(set1 != set2)
        cout << "operator!=: Set1 is not equal to Set2" << endl << endl;
    else
        cout << "operator!=: Set1 is equal to Set2" << endl << endl;

    // Test for DayOfYearSet::operator[]() overload
    cout << "Using overloaded index operator[]:" << endl << endl << "set1[0]: " << set1[0] << endl;

    // Test for DayOfYearSet::operator!() overload
    cout << "Set1:" << endl << endl;
    cout << set1 << endl;
    cout << "Complement of Set1:" << endl << endl;
    cout << !set1 << endl;

    // Test for DayOfYear::writeText() function
    cout << "Writing Set1, Set2 and complement of Set1 (!set1) to text files:" << endl << endl;
    set1.writeText();
    // Modify set2 a little bit
    set2.add(1, 1);
    set2.add(9, 9);
    set2.add(4, 12);
    set2.writeText();
    (!set1).writeText();
}

