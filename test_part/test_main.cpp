/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:16:26 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/09 18:00:14 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t countLines(std::string source)
{
    size_t i;
    size_t lines;

    i = 0;
    lines = 1;
    while (source[i])
    {
        if (source[i] == '\n')
            ++lines;
        ++i;
    }
    return (lines);
}

std::string in_line(std::string source, size_t n)
{
    size_t i;
    size_t j;
    size_t line_count;

    if (n >= countLines(source))
        return (std::string());
    line_count = 0;
    i = 0;
    while (line_count < n)
    {
        if (source[i++] == '\n')
            ++line_count;
    }
    while (std::isspace(source[i]) && source[i] != '\n')
    {
        ++i;
    }
    j = 0;
    while (source[i + j] && source[i + j] != '\n')
        ++j;
    while (j > 0 && std::isspace(source[i + j - 1]))
       {
        //    std::cout <<  "helo "<< source[i + j - 1] << std::endl;
           --j;
       } 
    // std::cout << source[i+j -1] << std::endl;
    return (std::string(source, i, j));
}

int main()
{
    std::map<int, std::string> tst;
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
        // std::cout << countLines(result) << std::endl;
        // std::cout << in_line(result,20) << std::endl;
        // result = "abcdefakka";
        // std::cout << std::string(result,0,10);
        // int i = 0;

        // while ( i < countLines(result))
        // {
        //     tst[i + 1] =  in_line(result,i);
        //     i++;
        // }
        // std::map<int, std::string>::iterator it = tst.begin();
        // for (it = tst.begin(); it != tst.end(); ++it)
        // {
        //     std::cout << "key is " << it->first;
        //     std::cout << "  the value: \t\t\t";
        //     std::cout << it->second << std::endl;
        // }
    }
}