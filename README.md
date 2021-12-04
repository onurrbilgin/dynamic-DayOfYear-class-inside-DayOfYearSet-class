## Dynamic DayOfYearSet class with nested DayOfYear class

This program creates DayOfYearSet class instances and
holds dynamically allocated DayOfYear class objects.

Includes operator overloads such as ==, !=, =, +, -,
!, [], ^, << which does set operations and satisfies
basic De Morgan rule which is:
        
            !(s1 + s2) == !s1 ^ !s2