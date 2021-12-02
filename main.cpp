#include <iostream>
#include "dayofyearset.h"
using std::vector;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;

using namespace DayOfYearSetBilgin;

int main(){

    DayOfYearSet::DayOfYear doy1(3, 5);
    DayOfYearSet doys1(doy1);

    cout << doys1;


    return 0;
}