/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:29:18 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/05 15:20:55 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void check_error(char *file)
{
    Error check;
    std::string line = "";
    std::ifstream my_file;
    unsigned int w = 0;
    unsigned int h = 0;
    unsigned int k = 0;
    int nb_line = 0;
    my_file.open(file);
    if (!my_file.is_open())
        error_msg("Error: File not opned or not found");
    while (std::getline(my_file, line, '\n'))
    {
        nb_line++;
        if(nb_line == 1 && line.find("server") == std::string::npos)
            error_msg("Error: sould start with server ");
        if(line.find("#") != std::string::npos)
        {
            std::cout << " ERROR : line = " << nb_line + 1 << " ==> " << std::endl  << line << std::endl;
            exit(EXIT_FAILURE);
        }
        if (line.find("{") != std::string::npos)
        {
            k++;
        }
        if(line.find("}") != std::string::npos)
        {
            k--;
        }
        if(line.find("server") != std::string::npos)
        {
            check.set_one(w++);   
        }
        if(line.find("location") != std::string::npos)
        {
            check.set_two(h++);   
        }
    }
    if (k!= 0)
        error_msg("Error: wrong number of brackets");
}