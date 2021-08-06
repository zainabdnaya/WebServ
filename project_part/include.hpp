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

class Parsing
{
protected:
    // int listen;
    // std::string host;
    // std::string server_name;
    // std::string clinet_max_bosy_size;
    // std::string *error_pages;
    // std::string root;
    std::map<std::string, std::string> map_s;

public:
    Parsing();
    ~Parsing();
    std::map<std::string, std::string> map_simpl(std::ifstream my_file);
    std::map<std::string, std::string> get_map();
};

bool compare_end(std::string const &s1, std::string const &s2);
void check_error(char *file);
void error_msg(std::string const msg);
bool line_equal(std::string const &line, std::string const &str);
int check_details(std::string line, Error check);
#endif