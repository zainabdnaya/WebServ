
#include "student.h"
#include <utility>
int main()
{
    Student S("zainab",38393);
    Student S1("abc",9300);
    Student S2("amine",9340);
    Student S3("samir",902);     
  
    std::map <int, Student> m;

    m[-5]= S; 
    m[200]= S2;
    m[7]= S3;

    // std::cout << "hello "  << S.get_name() << " with code "  << S.get_cne() << std::endl;
    // m.insert()
    // for (int i = 0; i < 4 ;i++)
    // {
        std::pair <int , Student>  p(56,S);
        m.insert(p);
        // std::cout << "for " << it->first << std::endl;
        // std::cout << "hello "  << it->second.get_name() << " with code "  << it->second.get_cne() << std::endl;
    // }
    for (std::map <int, Student>::iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << "for " << it->first << std::endl;
        std::cout << "hello "  << it->second.get_name() << " with code "  << it->second.get_cne() << std::endl;
    }
    return(0);
}