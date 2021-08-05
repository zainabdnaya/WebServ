#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <utility>
#include <iomanip>
#include <fstream>


class Error
{
    private:
        unsigned int nbr_server;
        unsigned int nbr_location;
        unsigned int nbr_brakets;
    public:
    Error();
    ~Error();
    unsigned int    get_server();
    unsigned int    get_location();
    unsigned int    get_brakets();
    void            set_server(unsigned int nbr_ser);
    void            set_location(unsigned int nbr_loc);
    void            set_brakets(unsigned int nbr_brak);
    
};



bool    compare_end(std::string const &s1, std::string const &s2);
void    check_error(char    *file);
void    error_msg(std::string const msg);
bool    line_equal(std::string const &line, std::string const &str);
int	check_details(std::string line, Error check);
#endif