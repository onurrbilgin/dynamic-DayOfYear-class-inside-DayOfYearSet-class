//This is the implementation file dayofyearset.cpp of the class DayOfYearSet.
//The interface for the class DayOfYearSet is in the header file dayofyearset.h.

// #include <iostream>
// #include <cstdlib>
// #include <vector>
#include "dayofyearset.h"
using std::istream;
using std::ostream;
using std::vector;
using std::string;
using std::cin;
using std::cout;


namespace
{

}   // UNNAMED NAMESPACE: Later will be used for local compilation unit functions etc.

namespace DayOfYearSetBilgin
{
    int DayOfYearSet::_allDayOfYear = 0;

    DayOfYearSet::DayOfYear::DayOfYear():_day(0), _month(0){
        _allDayOfYear++;
    }
    DayOfYearSet::DayOfYear::DayOfYear(int month):_day(0), _month(month){
        _allDayOfYear++;
    }
    DayOfYearSet::DayOfYear::DayOfYear(int month, int day):_day(day), _month(month){
        _allDayOfYear++;
    }
    
    const int DayOfYearSet::DayOfYear::getDay() const{
        return _day;
    }

    const int DayOfYearSet::DayOfYear::getMonth() const{
        return _month;
    }

    void DayOfYearSet::DayOfYear::setDay(int day){
        _day = day;
    }

    void DayOfYearSet::DayOfYear::setMonth(int month){
        _month = month;
    }

    void DayOfYearSet::DayOfYear::input(){
        // To be implemented..
    }

    void DayOfYearSet::DayOfYear::output() const{
        // To be implemented..
    }
    



    DayOfYearSet::DayOfYearSet(){
        _sets = nullptr;
    }

    DayOfYearSet::DayOfYearSet(const vector <DayOfYear> &sets){
        // To be implemented..
        // This constructor has to transfer the argument vector to private data vector then
        // create or stretch the dynamic array while ignoring replica elements
        // lastly has to clear the private data vector
    }

    DayOfYearSet::DayOfYearSet(const DayOfYear day){
        // To be implemented..
        // This constructor has to create or stretch the dynamic array
        // if the dereferenced object is not a replice in the array
    }

    class DayOfYear DayOfYearSet::getDay(int month, int day) const{

        // To be implemented..
    }




}   // End of namespace DayOfYearSetBilgin