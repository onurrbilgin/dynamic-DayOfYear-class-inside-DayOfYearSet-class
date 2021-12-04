// Author: Onur Bilgin

//This is the header file dayofyearset.h.
//This is the interface for the class DayOfYearSet.

#ifndef DAY_OF_YEAR_H
#define DAY_OF_YEAR_H

#include <iostream>
#include <fstream>
#include <cstdlib>  // Just used for exit() function
#include <string>
#include <vector>


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
                    explicit DayOfYear(int);
                    DayOfYear(int, int);

                    // Getters
                    const int getDay() const;
                    const int getMonth() const;

                    // Other public member functions
                    void output() const;
                
                private:
                    // Private data
                    int _month;
                    int _day;

            };  // End of DayOfYear class
        
            // Constructors
            DayOfYearSet();
            DayOfYearSet(int, int);
            DayOfYearSet(const std::vector <DayOfYear>&);
            DayOfYearSet(const DayOfYear);
            DayOfYearSet(const DayOfYearSet&);  // Copy constructor

            // Getters
            const DayOfYear getDayOfYear(int, int) const;

            // Other member functions
            void add(const std::vector <DayOfYear>&);
            void add(const DayOfYear);
            void add(int, int);
            void remove(const std::vector <DayOfYear>&);
            void remove(const DayOfYear);
            void remove(int, int);
            const int size() const;
            bool checkDuplicate(const DayOfYear) const;
            void writeText() const;
            DayOfYear* getArray() const;

            // Static functions
            static int allDayOfYear();

            // Friend global operator overloads
            friend std::ostream& operator<<(std::ostream&, const DayOfYearSet&);
            friend const DayOfYearSet operator!(const DayOfYearSet&);

            // Member operator overloads
            bool operator==(const DayOfYearSet&) const;
            bool operator!=(const DayOfYearSet&) const;
            const DayOfYearSet operator+(const DayOfYearSet&) const;
            const DayOfYearSet operator-(const DayOfYearSet&) const;
            const DayOfYearSet operator^(const DayOfYearSet&) const;
            const DayOfYear operator[](int) const;

            // Assignment operator overload and destructor
            DayOfYearSet& operator =(const DayOfYearSet&);
            ~DayOfYearSet();
        
        private:
            // Private data
            DayOfYear* _sets;
            int _size;
            static int _allDayOfYear;
            static int _fileCounter;

    };  // End of DayOfYearSet class

}   // End of namespace DayOfYearSetBilgin

#endif  // DAY_OF_YEAR.H
