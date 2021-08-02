
#include "student.h"

int main()
{
    Student S("zainab",1685);
    
    // std::map <int, Student>;
    
    std::cout << "hello "  << S.get_name() << " with code "  << S.get_cne() << std::endl;
    return(0);
}