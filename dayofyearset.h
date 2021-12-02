//This is the header file dayofyearset.h. This is the interface for the class
//DayOfYearSet. ...

#ifndef DAY_OF_YEAR.H
#define DAY_OF_YEAR.H

#include <iostream>
#include <cstdlib>
#include <vector>

//  TODO: Add big three: destructor, copy constructor and assignment overload. ALSO write overloads for both classes.

namespace DayOfYearSetBilgin
{
    class DayOfYearSet
    {
        public:
            class DayOfYear
            {
                public:
                    // Constructors
                    DayOfYear();
                    DayOfYear(int month);  // explicit keyword is unnecessary here imho because truncation of a double or a float is kinda useful
                    DayOfYear(int month, int day);
                    // Getters
                    const int getDay() const;
                    const int getMonth() const;
                    // Setters
                    void setDay(int day);
                    void setMonth(int month);
                    // Other public member functions
                    void input();
                    void output() const;
                private:
                    int _month;
                    int _day;
            };  // End of DayOfYear class
        
            // Constructors
            DayOfYearSet();
            //DayOfYearSet(const vector <DayOfYear> &sets);
            DayOfYearSet(const DayOfYear day);
            DayOfYearSet(const DayOfYearSet &doysObj);  // Copy constructor
            // Getters
            const DayOfYear getDay(int month, int day) const;
            // Setters
            //
            // Other public member functions
            void add(const DayOfYear day);
            void remove(const DayOfYear day);
            bool checkDuplicate(const DayOfYear obj) const;
            const int size() const;
            DayOfYear* getArray() const;
            static int allDayOfYear();
            // Maybe, add input()

            friend ostream& operator<<(ostream& out, const DayOfYearSet &obj);

            DayOfYearSet& operator =(const DayOfYearSet &rtSide);   // Assignment operator overload
            ~DayOfYearSet(); // Destructor
        private:
            //  vector <DayOfYear> _tempSets;
            DayOfYear* _sets;
            int _size;
            static int _allDayOfYear;



    };  // End of DayOfYearSet class

}   // End of namespace DayOfYearSetBilgin

//  ...

#endif  // DAY_OF_YEAR.H
