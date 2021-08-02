#include "student.h"

Student::Student()
{
 name = std::string("NULL");
    _cne = 0;
}
Student::Student(std::string name,unsigned int _cne)
{
    this->name = name;
    this->_cne = _cne;
}        

std::string Student::get_name(void)
    {return (this->name);}
    
unsigned int Student::get_cne(void)
{
    return(this->_cne);
}

Student::~Student()
{
    
}


