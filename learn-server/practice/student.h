

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <map>

class Student
{
    private:
        std::string name;
        unsigned int _cne;
    public:
        Student();
        ~Student();
        Student(std::string name,unsigned int _cne);
        std::string get_name(void);
        unsigned int get_cne(void);
};


#endif