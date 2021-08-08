#ifndef PARSCONFIG_HPP
#define PARSCONFIG_HPP

#include "tools.hpp"

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <utility>
#include <iomanip>
#include <unistd.h>
#include <fcntl.h>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

class ParsConfig
{
private:
    unsigned int nbr_server;
    unsigned int nbr_location;
    unsigned int server;
    unsigned int location;
    std::map<int, std::string> map_s;
    char *file;

public:
    ParsConfig(char *file);
    ~ParsConfig();
    unsigned int get_server();
    unsigned int get_location();
    unsigned int get_one();
    unsigned int get_two();
    void set_server(unsigned int nbr_ser);
    void set_location(unsigned int nbr_loc);
    void set_one(unsigned int ser);
    void set_two(unsigned int loc);
    std::map<std::string, std::string> map_simpl(std::ifstream &my_file);
};

std::map<int, std::string> get_map(char *av);
void check_error(std::map<int, std::string> error_mp);
void error_msg(std::string const msg);
std::string Those_lines(std::string txt, int nbr_line, int txt_lines);

#endif