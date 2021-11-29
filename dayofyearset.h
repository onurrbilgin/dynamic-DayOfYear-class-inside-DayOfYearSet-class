//This is the header file dayofyearset.h. This is the interface for the class
//DayOfYearSet. ...

#ifndef DAY_OF_YEAR.H
#define DAY_OF_YEAR.H

#include <iostream>
#include <cstdlib>
#include <vector>
using std::istream;
using std::ostream;
using std::string;


namespace DayOfYearBilgin
{
    class DayOfYearSet
    {
        public:
            class DayOfYear
            {
                public:
                    // Constructors
                    DayOfYear();
                    DayOfYear(int month);  // explicit keyword is unnecessary here imho because truncation of a double or a float is useful
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
            };
        
            // Constructors
            DayOfYearSet();
            DayOfYearSet(const vector <DayOfYear> &sets);
            DayOfYearSet(const DayOfYear* day);
            // Getters
            const DayOfYear* getADay(int month, int day) const; // not sure about this const at the beginning
            // Setters
            //
            // Other public member functions
            bool add(const DayOfYear day);
            bool remove(const DayOfYear day);
            const int size() const;
            static int allDayOfYear();
        
        private:
            vector <DayOfYear> _tempSets;
            DayOfYear* _sets;
            static int _allDayOfYear;



    };

}

//  ...

#endif  // DAY_OF_YEAR.H
