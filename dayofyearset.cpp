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
using std::endl;


namespace
{

}   // UNNAMED NAMESPACE: Later will be used for local compilation unit functions etc.

namespace DayOfYearSetBilgin
{
    int DayOfYearSet::_allDayOfYear = 0;

    // IMPLEMENTATION OF "DayOfYear" CLASS

    DayOfYearSet::DayOfYear::DayOfYear():_day(0), _month(0){
        _allDayOfYear++;
    }
    DayOfYearSet::DayOfYear::DayOfYear(int month):_day(0), _month(month){

        if((month > 12) || (month < 0)) // Check if given month is valid
            _month = 0;

        _allDayOfYear++;
    }
    DayOfYearSet::DayOfYear::DayOfYear(int month, int day):_day(day), _month(month){    // I will accept all months as 30 days
        
        if((month > 12) || (month < 0)) // Check if given month is valid
            _month = 0;
        if((day > 30) || (day < 0)) // Check if given day is valid
            _day = 0;
        
        _allDayOfYear++;
    }
    
    const int DayOfYearSet::DayOfYear::getDay() const{
        return _day;
    }

    const int DayOfYearSet::DayOfYear::getMonth() const{
        return _month;
    }

    void DayOfYearSet::DayOfYear::setDay(int day){
        
        if((day > 30) || (day < 0)){

            cout << "Invalid number for a day! (0 <= day <= 30)" << endl;
            return;
        }
            
        _day = day;
    }

    void DayOfYearSet::DayOfYear::setMonth(int month){
        
        if((month > 12) || (month < 0)){

            cout << "Invalid number for a month! (0 <= month <= 12)" << endl;
            return;
        }
        
        _month = month;
    }

    void DayOfYearSet::DayOfYear::input(){
        // To be implemented..
    }

    void DayOfYearSet::DayOfYear::output() const{
        // To be implemented..
    }
    
    // END OF IMPLEMENTATION FOR "DayOfYear" CLASS


    // IMPLEMENTATION OF "DayOfYearSet" CLASS

    DayOfYearSet::DayOfYearSet(){
        _sets = nullptr;
        _size = 0;
    }

    /*DayOfYearSet::DayOfYearSet(const vector <DayOfYear> &sets){
        // To be implemented..
        // This constructor has to transfer the argument vector to private data vector then
        // create or stretch the dynamic array while ignoring replica elements
        // lastly has to clear the private data vector
    }*/

    DayOfYearSet::DayOfYearSet(const DayOfYear day){
        // To be implemented..
        // This constructor has to create or stretch the dynamic array
        // if the dereferenced object is not a replice in the array
    }

    const DayOfYearSet::DayOfYear DayOfYearSet::getDay(int month, int day) const{

        for(auto i = 0; i < _size; ++i){

            if((day == _sets[i].getDay()) && (month == _sets[i].getMonth())){
                return _sets[i];
                break;
            }
        }

        cout << "Error! No object with the given day and month.." << endl;  // Im not sure about this type of return, if it assigns it to an object and there is no object
        return;                                                             // that can cause some problems: come back to this later.
    }

    // The big three start
    DayOfYearSet& DayOfYearSet::operator =(const DayOfYearSet &rtSide){ // Assignment operator overload

        if(this == &rtSide) // Check if object on the left and right side of the operator= are equal
            return *this;
        else{   // If not, create new dynamic elements and transfer the data

            _size = rtSide.size();
            delete [] _sets;
            _sets = new DayOfYear[_size];
            
            for(auto i = 0; i < _size; ++i)
                _sets[i] = rtSide._sets[i];

            return *this;
        }
    }

    DayOfYearSet::DayOfYearSet(const DayOfYearSet &doysObj):_size(doysObj.size()){    // Copy constructor

        _sets = new DayOfYear[_size];
        
        for(auto i = 0; i < _size; ++i)
            _sets[i] = doysObj._sets[i];
    }

    DayOfYearSet::~DayOfYearSet(){  // Destructor
        delete [] _sets;
    }
    // End of the big three implementations

    const int DayOfYearSet::size() const{   // Function that returns the size of array
        return _size;
    }

    bool DayOfYearSet::checkDuplicate(const DayOfYear obj) const{

        for(auto i = 0; i < _size; ++i){

            if((obj.getDay() == _sets[i].getDay()) && (obj.getMonth() == _sets[i].getMonth())){

                cout << "Error! Object already exists.." << endl;
                return false;
            }
        }

        return true;
    }

    void DayOfYearSet::add(const DayOfYear day){

        if(DayOfYearSet::checkDuplicate(day)){

            if(_size == 0){

                _sets = new DayOfYear[++_size];
                _sets[0] = day;

            }else{

                DayOfYear *temp;
                temp = new DayOfYear[++_size];
            
                for(auto i = 0; i < _size - 1; i++)
                    temp[i] = _sets[i];
                temp[_size - 1] = day;
                delete [] _sets;
                _sets = temp;
            }
        }
    }

    void DayOfYearSet::remove(const DayOfYear day){

        int location = -1;
        for(decltype (location) i = 0; i < _size; ++i){

            if((day.getDay() == _sets[i].getDay()) && (day.getMonth() == _sets[i].getMonth())){
                location = i;
                break;
            }
        }

        if(location == -1){

            cout << "Error! Object doesn't exist in the array.." << endl;
            return;
        }else{

            DayOfYear *temp;
            temp = new DayOfYear[--_size];

            for(decltype (location) i = 0; i < _size + 1; ++i){

                if(i != location)
                    temp[i] = _sets[i];
            }

            delete [] _sets;
            _sets = temp;
        }
    }

    int DayOfYearSet::allDayOfYear(){
        return _allDayOfYear;
    }

    DayOfYearSet::DayOfYear* DayOfYearSet::getArray() const{
        return _sets;
    }

    ostream& operator<<(ostream& out, const DayOfYearSet &obj){

        for(auto i = 0; i < obj.size(); ++i)
            out << "Day: " << obj.getArray()[i].getDay() << " , Month:" << obj.getArray()[i].getMonth() << endl;

        return out;
    }



}   // End of namespace DayOfYearSetBilgin