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
std::map<std::string, std::string> tst;
public:
    ParsConfig(char *file);
    ~ParsConfig();

    void set_map(std::map<int, std::string> map_s);
    std::map<int, std::string> get_cmap(void);
};

std::map<int, std::string> get_map(char *av);
std::map<int, std::string> clean_map(std::map<int, std::string> error_mp);
void error_msg(std::string const msg);
std::string Those_lines(std::string txt, int nbr_line, int txt_lines);

#endif