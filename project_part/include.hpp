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
    unsigned int server;
    unsigned int location;

public:
    Error();
    ~Error();
    unsigned int get_server();
    unsigned int get_location();
    unsigned int get_one();
    unsigned int get_two();
    void set_server(unsigned int nbr_ser);
    void set_location(unsigned int nbr_loc);
    void set_one(unsigned int ser);
    void set_two(unsigned int loc);
};

class Parse_server
{
protected:
    int listen;
    std::string host;
    std::string server_name;
    std::string clinet_max_bosy_size;
    std::string *error_pages;
    std::string root;

public:
    Parse_server();
    ~Parse_server();
    std::map<std::string, std::string> map_element(std::ifstream my_file, unsigned int nbr_serv);
};

class Parse_location
{
protected:
    std::string root;
    std::string autoindex;
    std::string index;
    std::string allow_methods;
    std::string redirection; // return _code _url [like:return(300)]
    std::string CGI;
    std::string upload_store_directory;

public:
    Parse_location();
    ~Parse_location();
    std::map<std::string, std::string> map_element(std::ifstream my_file, unsigned int nbr_loc);
};

bool compare_end(std::string const &s1, std::string const &s2);
void check_error(char *file);
void error_msg(std::string const msg);
bool line_equal(std::string const &line, std::string const &str);
int check_details(std::string line, Error check);
#endif