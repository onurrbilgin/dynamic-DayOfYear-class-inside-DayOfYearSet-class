// Author: Onur Bilgin 

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

    // Create 4 more different pairs below
    cout << "Create 8 more different sets" << endl << endl;
    elements.clear();
    for(auto i = 0; i < 12; ++i){

        DayOfYearSet::DayOfYear obj(i + 1, (i + 1)*2);
        elements.push_back(obj);
    }
    
    DayOfYearSet set3(elements);
    DayOfYearSet set4(!set3);
    DayOfYearSet set5(11, 30);
    
    elements.clear();
    for(auto i = 0; i < 7; ++i){

        DayOfYearSet::DayOfYear obj(2, i + 10);
        elements.push_back(obj);
    }
    
    DayOfYearSet set6(elements);
    
    for(auto i = 0; i < 21; ++i){

        DayOfYearSet::DayOfYear obj(5, i + 3);
        elements.push_back(obj);
    }
    
    DayOfYearSet set7(elements);

    elements.clear();
    for(auto i = 0; i < 31; ++i){

        DayOfYearSet::DayOfYear obj(10, i + 1);
        elements.push_back(obj);
    }
    
    DayOfYearSet set8(elements);

    DayOfYearSet set9;
    set9.add(1, 1);
    set9.add(2, 1);
    set9.add(3, 1);
    
    elements.clear();
    for(auto i = 5; i < 15; ++i){

        DayOfYearSet::DayOfYear obj(i - 3, i*2);
        elements.push_back(obj);
    }
    
    DayOfYearSet set10(elements);
    // Now, we have 5 set pairs in total

    // Test for De Morgan rule !(s1 + s2) == !s1 ^ !s2
    cout << "Test for De Morgan rule  !(s1 + s2) == !s1 ^ !s2 :" << endl << endl;
    if((!(set1 + set2) == (!set1 ^ !set2)) && (!(set3 + set4) == (!set3 ^ !set4)) && (!(set5 + set6) == (!set5 ^ !set6))
         && (!(set7 + set8) == (!set7 ^ !set8)) && (!(set9 + set10) == (!set9 ^ !set10)))
        cout << "De Morgan rule  !(s1 + s2) == !s1 ^ !s2  satisfed" << endl << endl;
    else
        cout << "De Morgan rule  !(s1 + s2) == !s1 ^ !s2  not satisfied" << endl << endl;

    // Test for DayOfYear::writeText() function
    cout << "Writing Set2, Set3, Set4, Set5 and complement of Set6 (!set6) to text files:" << endl << "(Text file names will start from Set 1.txt, Set 2.txt..)" << endl << endl;
    set2.writeText();
    set3.writeText();
    set4.writeText();
    set5.writeText();
    (!set6).writeText();
    cout << endl;

    // End of test1() function
}

