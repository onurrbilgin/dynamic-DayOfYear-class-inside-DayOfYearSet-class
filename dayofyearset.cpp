//This is the implementation file dayofyearset.cpp of the class DayOfYearSet.
//The interface for the class DayOfYearSet is in the header file dayofyearset.h.

#include "dayofyearset.h"
using std::ostream;
using std::ofstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


namespace // Unnamed namespace
{
    bool checkDate(int month, int day){ // Function for checking if the given date and month are correct

        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if((month <= 12) && (month > 0) && (day > 0)){

            if((day <= months[month - 1]))
                return true;
        }
        
        cout << "Error! Not a valid date.." << endl;
        return false;
    }

    void printMonth(const int month){   // Function for printing month names to the output

        char months[12][10] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"},
                                {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

        cout << months[month - 1];
    }

    void writeMonth(const int month, ostream &fileOut){ // Function for writing month names to the file

        char months[12][10] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"},
                                {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

        fileOut << months[month - 1];
    }

    void printSuffix(const int day){   // Function for printing necessary suffix to day numbers

        if((day == 1) || (day == 21) || (day == 31))
            cout << "st" << endl;
        else if((day == 2) || (day == 22))
            cout << "nd" << endl;
        else if((day == 3)  || (day == 23))
            cout << "rd" << endl;
        else if(((day <= 20) && (day >= 4)) || (day <= 30) && (day >= 24))
            cout << "th" << endl;
    }

    void writeSuffix(const int day, ostream &fileOut){  // Function for writing necessary suffix to day numbers

        if((day == 1) || (day == 21) || (day == 31))
            fileOut << "st" << endl;
        else if((day == 2) || (day == 22))
            fileOut << "nd" << endl;
        else if((day == 3)  || (day == 23))
            fileOut << "rd" << endl;
        else if(((day <= 20) && (day >= 4)) || (day <= 30) && (day >= 24))
            fileOut << "th" << endl;
    }
}   // End of unnamed namespace

namespace DayOfYearSetBilgin
{
    int DayOfYearSet::_allDayOfYear = 0; // Keeping all DayOfYear objects that are inside DayOfYearSet instances
    int DayOfYearSet::_fileCounter = 0; // Keeping number of files for if we need to output multiple files at one run

    // IMPLEMENTATION OF "DayOfYear" CLASS

    DayOfYearSet::DayOfYear::DayOfYear():_day(1), _month(1){ // No parameter DayOfYear constructor that create January 1st
        /* Body Intentionally Empty */
    }

    DayOfYearSet::DayOfYear::DayOfYear(int month):_day(1), _month(month){ // DayOfYear constructor with just month value that creates 1st day of that month

        if((month < 0) || (month > 12)){

            cout << "Error! Not a valid month value for the constructor.. (1 <= month <= 12)" << endl;
            exit(1);
        }
            
    }
    
    DayOfYearSet::DayOfYear::DayOfYear(int month, int day):_day(day), _month(month){ // DayOfYear constructor that creates the object with month and day values
                                                                                     // if they are valid
        if(!checkDate(month, day)){
            
            cout << "Error! Not a valid month and day value for the constructor.." << endl;
            exit(1);
        }
    }
    
    const int DayOfYearSet::DayOfYear::getDay() const{ // DayOfYear getter to get day
        return _day;
    }

    const int DayOfYearSet::DayOfYear::getMonth() const{ // DayOfYear getter to get month
        return _month;
    }

    void DayOfYearSet::DayOfYear::output() const{ // DayOfYear output function to output object info
        
        printMonth(getMonth());
        cout << " " << getDay();
        printSuffix(getDay());    
    }
    
    // END OF IMPLEMENTATION FOR "DayOfYear" CLASS


    // IMPLEMENTATION OF "DayOfYearSet" CLASS

    DayOfYearSet::DayOfYearSet():_sets(nullptr), _size(0){ // No parameter DayOfYearSet constructor
        /* Body Intentionally Empty */
    }

    DayOfYearSet::DayOfYearSet(int month, int day):_sets(nullptr), _size(0){ // DayOfYearSet constructor that initiliazes with one DayOfYear object
        add(DayOfYear(month, day));
    }

    DayOfYearSet::DayOfYearSet(const DayOfYear day):_sets(nullptr), _size(0){ // DayOfYearSet constructor that initiliazes with one DayOfYear object
        add(day);
    }

    DayOfYearSet::DayOfYearSet(const vector <DayOfYear> &objs):_sets(nullptr), _size(0){ // DayOfYearSet constructor that initiliazes with a vector
                                                                                         // that has DayOfYear objects inside
        for(auto i = 0; i < objs.size(); ++i)
            add(objs.at(i));
    }

    const DayOfYearSet::DayOfYear DayOfYearSet::getDayOfYear(int month, int day) const{ // DayOfYearSet function to get a given DayOfYear if it lives
                                                                                        // inside of the set
        for(auto i = 0; i < size(); ++i){
            if((day == getArray()[i].getDay()) && (month == getArray()[i].getMonth())){
                return getArray()[i];
                break;
            }
        }

        cout << "Error! No object with the given day and month.." << endl;
        exit(1);
    }

    // The big three start
    DayOfYearSet& DayOfYearSet::operator =(const DayOfYearSet &rtSide){ // Assignment operator overload

        if(this == &rtSide) // Check if object on the left and right side of the operator= are equal
            return *this;
        else{   // If not, create new dynamic elements and transfer the data

            _size = rtSide.size();          // Same size
            delete [] _sets;                // Delete old array
            _sets = new DayOfYear[_size];   // Initialize new array same size as the right object
            
            for(auto i = 0; i < _size; ++i) // Copy elements
                _sets[i] = rtSide._sets[i];

            _allDayOfYear -= size();
            _allDayOfYear += rtSide.size();

            return *this;
        }
    }

    DayOfYearSet::DayOfYearSet(const DayOfYearSet &doysObj):_sets(nullptr), _size(doysObj.size()){ // Copy constructor

        _sets = new DayOfYear[_size];   // Same size
        
        for(auto i = 0; i < _size; ++i) // Copy elements
            _sets[i] = doysObj._sets[i];
    }

    DayOfYearSet::~DayOfYearSet(){ // Destructor
        if(_sets != nullptr) // Check where the pointer is pointing at
            delete [] _sets; // to not to call delete on a pointer that is pointing at nullptr
        _sets = nullptr;
        _allDayOfYear -= size();
    }
    // End of the big three implementations

    const int DayOfYearSet::size() const{   // Function that returns the size of array
        return _size;
    }

    bool DayOfYearSet::checkDuplicate(const DayOfYear obj) const{ // Function for checking the dynamic array with the given DayOfYear object
                                                                  // to not have duplicate objects in the array
        for(auto i = 0; i < size(); ++i)
            if((obj.getDay() == getArray()[i].getDay()) && (obj.getMonth() == getArray()[i].getMonth()))
                return false;
        return true;
    }

    void DayOfYearSet::add(const DayOfYear day){ // Function for adding elements to the array
        
        if(checkDuplicate(day)){  // Check if it already exists in array
            
            if(size() == 0){ // If its the first object do not call delete
                
                _sets = new DayOfYear[++_size];
                _sets[0] = day;

                _allDayOfYear++;

            }else{  // If its not the first object
                
                DayOfYear *temp;                    // Create an temp pointer
                temp = new DayOfYear[++_size];      // Make its size +1 bigger
            
                for(auto i = 0; i < _size - 1; i++) // Copy elements
                    temp[i] = _sets[i];
                temp[_size - 1] = day;              // Add new element at the end
                delete [] _sets;                    // Delete old array
                _sets = temp;                       // Point to new array with the added element

                _allDayOfYear++;
            }
        }else
            cout << "Error! Object already exists.." << endl;
    }

    void DayOfYearSet::add(int month, int day){ // Overload for add function to be able to add elements
        add(DayOfYear(month, day));             // without creating an instance of DayOfYear
    }

    void DayOfYearSet::add(const vector <DayOfYear> &objs){ // Overload for add function to be able to add elements
                                                            // using vector of DayOfYear objects
        for(auto i = 0; i < objs.size(); i++)
            add(objs.at(i));
    }

    void DayOfYearSet::remove(const DayOfYear day){ // Function for removing elements anywhere on the array

        int location = -1;
        for(decltype (location) i = 0; i < size(); ++i){ // Find the given object in the array

            if((day.getDay() == getArray()[i].getDay()) && (day.getMonth() == getArray()[i].getMonth())){
                location = i;
                break;
            }
        }

        if(location == -1){

            cout << "Error! Object doesn't exist in the array.." << endl; // It may not exist in array
            return;
        }else{ // If it exists

            if(size() == 1){      // If its just 1 element
                
                delete [] _sets;  // Delete it
                _sets = nullptr;  // Avoid dangling pointer
                _size = 0;
            }else{ // If its not just 1 element

                DayOfYear *temp;                // Create an temp pointer
                temp = new DayOfYear[--_size];  // Make its size -1 smaller

                for(decltype (location) i = 0; i < location; ++i)               // Copy elements until the element that will be removed
                        temp[i] = _sets[i];
                for(decltype (location) i = location + 1; i < _size + 1; ++i)   // Copy elements after the element that will be removed
                        temp[i - 1] = _sets[i];

                delete [] _sets;  // Delete old array
                _sets = temp;     // Point the new array with the removed element
            }

            _allDayOfYear--;
        }
    }

    void DayOfYearSet::remove(int month, int day){ // Overload for remove function to be able to remove elements
        remove(DayOfYear(month, day));             // without creating an instance of DayOfYear
    }

    void DayOfYearSet::remove(const vector <DayOfYear> &objs){ // Overload for remove function to be able to remove elements
                                                               // using vector of DayOfYear objects
        for(auto i = 0; i < objs.size(); ++i)
            remove(objs.at(i));
    }

    int DayOfYearSet::allDayOfYear(){ // Static function to return all the DayOfYear objects
        return _allDayOfYear;         // living in DayOfYearSets
    }

    DayOfYearSet::DayOfYear* DayOfYearSet::getArray() const{ // Function that returns head pointer of the array
        return _sets;
    }

    ostream& operator<<(ostream& out, const DayOfYearSet &obj){ // Stream extraction overload

        for(auto i = 0; i < obj.size(); ++i){           // Print all objects
            printMonth(obj.getArray()[i].getMonth());   // Month
            out << " " << obj.getArray()[i].getDay();   // Day
            printSuffix(obj.getArray()[i].getDay());    // Day suffix
        }

        return out;
    }

    const DayOfYearSet::DayOfYear DayOfYearSet::operator[](int index) const{ // Index operator overload

        if(index < 0){              // Check for valid index
            
            cout << "Error! Index cannot be negative.." << endl;
            exit(1);
        }

        if(index >= size()){        // Check for valid index

            cout << "Error! Index overflows the array size.." << endl;
            exit(1);
        }

        return getArray()[index];   // Return the element
    }

    const DayOfYearSet DayOfYearSet::operator+(const DayOfYearSet &other) const{ // Union operator overload

        vector <DayOfYear> temp;

        if(other.size() >= size()){
        
            for(auto i = 0; i < other.size(); ++i)          // Push the elements of second set to the vector
                temp.push_back(other[i]);

            for(auto i = 0; i < size(); ++i)                // Check each element with nested loop
                for(auto j = 0; j < other.size(); ++j){
                    if((getArray()[i].getDay() == other[j].getDay()) && (getArray()[i].getMonth() == other[j].getMonth()))  // If same element exists, break loop
                        break;
                    if(j == other.size() - 1)               // If its the last element of other object and loop didn't break
                        temp.push_back(getArray()[i]);      // push the element to the vector
                }
        }else{

            for(auto i = 0; i < size(); ++i)                // Push the elements of first set to the vector
                temp.push_back(getArray()[i]);

            for(auto i = 0; i < other.size(); ++i)          // Check each element with nested loop
                for(auto j = 0; j < size(); ++j){
                    if((getArray()[j].getDay() == other[i].getDay()) && (getArray()[j].getMonth() == other[i].getMonth()))            // If same element exists, break loop
                        break;
                    if(j == other.size() - 1)               // If its the last element of actual object and loop didn't break
                        temp.push_back(other[i]);           // push the element to the vector
                }
        }

        return DayOfYearSet(temp); // Return the new set with vector constructor
    }

    const DayOfYearSet DayOfYearSet::operator-(const DayOfYearSet &other) const{ // Difference operator overload

        vector <DayOfYear> temp;
        for(auto i = 0; i < size(); ++i)                    // Push the elements of first set to the vector
            temp.push_back(getArray()[i]);

        for(auto i = 0; i < size(); ++i)                    // Check each element with nested loop
            for(auto j = 0; j < other.size(); ++j)
                if((getArray()[i].getDay() == other[j].getDay()) && (getArray()[i].getMonth() == other[j].getMonth()))      // If same element exists, break loop
                    temp.erase(temp.begin() + i);           // Remove that element from vector

        return DayOfYearSet(temp); // Return the new set with vector constructor
    }

    const DayOfYearSet DayOfYearSet::operator^(const DayOfYearSet &other) const{ // Intersection operator overload

        vector <DayOfYear> temp;
        for(auto i = 0; i < size(); ++i)
            for(auto j = 0; j < other.size(); ++j)
                if((getArray()[i].getDay() == other[j].getDay()) && (getArray()[i].getMonth() == other[j].getMonth()))      // Compare each element in both sets
                    temp.push_back(getArray()[i]);          // If same element exists on both sets, add it to the vector

        return DayOfYearSet(temp); // Return the new set with vector constructor
    }


    const DayOfYearSet operator!(const DayOfYearSet &obj){ // Complement operator overload

        vector <DayOfYearSet::DayOfYear> temp;
        for(auto i = 0; i < 12; ++i){ // 12 Months in a year

            if((i == 0) || (i == 2) || (i == 4) || (i == 6) || (i == 7) || (i == 9) || (i == 11)){ // Months with 31 days

                for(auto j = 0; j < 31; ++j){ // Add all days of that month

                    DayOfYearSet::DayOfYear tempObj(i + 1, j + 1);
                    if(obj.checkDuplicate(tempObj)) // Do not add the elements in the set
                        temp.push_back(tempObj);
                }

            }else if((i == 3) || (i == 5) || (i == 8) || (i == 10)){ // Months with 30 days

                for(auto j = 0; j < 30; ++j){ // Add all days of that month

                    DayOfYearSet::DayOfYear tempObj(i + 1, j + 1);
                    if(obj.checkDuplicate(tempObj)) // Do not add the elements in the set
                        temp.push_back(tempObj);
                }

            }else{  // February with 28 days

                for(auto j = 0; j < 28; ++j){ // Add all days of that month

                    DayOfYearSet::DayOfYear tempObj(i + 1, j + 1);
                    if(obj.checkDuplicate(tempObj)) // Do not add the elements in the set
                        temp.push_back(tempObj);
                }
            }
        }

        return DayOfYearSet(temp); // Return the new set with vector constructor
    }

    bool DayOfYearSet::operator==(const DayOfYearSet &other) const{ // Equality operator overload

        auto counter = 0;
        if(size() != other.size()) // If sets have different sizes
            return false;          // they are not equal
        else{

            for(auto i = 0; i < size(); ++i)
                for(auto j = 0; j < other.size(); ++j)
                    if((getArray()[i].getDay() == other[j].getDay()) && (getArray()[i].getMonth() == other[j].getMonth()))      // Compare each element in both sets
                        counter++; // Count how many elements are same
        }

        if(counter == size())      // If they are same as their sizes
            return true;           // They are equal
        else                       // If not
            return false;          // They are not equal
    }

    bool DayOfYearSet::operator!=(const DayOfYearSet &other) const{ // Inequality operator overload
        return !(*this == other);  // Return not of the value returned by equality operator
    }

    void DayOfYearSet::writeText() const{ // Function for writing sets to files

        _fileCounter++;
        string fileName = "Set " + std::to_string(_fileCounter) + ".txt"; // For creating multiple files with different numbers at a run
        ofstream fileOut(fileName);

        for(auto i = 0; i < size(); ++i){                   // Write all objects
            writeMonth(getArray()[i].getMonth(), fileOut);  // Month
            fileOut << " " << getArray()[i].getDay();       // Day
            writeSuffix(getArray()[i].getDay(), fileOut);   // Day suffix
        }

        cout << "Wrote " << fileName << " to the directory." << endl;
        fileOut.close(); // Close the file
    }

    // END OF IMPLEMENTATION FOR "DayOfYearSet" CLASS

}  // End of namespace DayOfYearSetBilgin