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
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

int nbr_lines(std::string source)
{
    int i;
    int lines;

    i = 0;
    lines = 1;
    while (source[i])
    {
        if (source[i] == '\n')
            lines++;
        i++;
    }
    return (lines);
}

std::string Those_lines(std::string txt, int nbr_line, int txt_lines)
{
    int i = 0;
    int j = 0;
    int w = 0;
    if (nbr_line >= txt_lines)
        return (std::string(NULL));
    while (i < nbr_line)
    {
        if (txt[j] == '\n')
            i++;
        j++;
    }
    while (txt[j] != '\n' && std::isspace(txt[j])) // for the space befor  txt start from where the txt begins
        j++;
    w = 0;
    while (txt[w + j] && txt[w + j] != '\n') // when the line ends until \n
        ++w;
    while (w > 0 && std::isspace(txt[w + j - 1])) // escape space after the txt o the line
        --w;
    return (std::string(txt, j, w));
}

int main()
{
    std::ifstream my_file;
    char line[2024];
    int nbr_line = 0;
    my_file.open("tst.txt");
    if (!my_file.is_open())
        std::cerr << "Error: File not opned or not found\n";
    else
    {
        int res = 0;
        std::string result;
        std::string file = "tst.txt";
        int fd = open(file.c_str(), O_RDONLY);
        while ((res = read(fd, line, 1024)) > 0)
        {
            if (std::strcmp(line, "\n") != 0)
                result = result + line;
            int i = 0;
            while (i < 1024)
                line[i++] = 0;
        }
        // std::cout << nbr_lines(result) << std::endl;
        std::cout << Those_lines(result, 10, nbr_lines(result)) << std::endl;
    }
}