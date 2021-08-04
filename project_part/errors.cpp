/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:29:18 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/04 19:01:37 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void check_error(char *file)
{
    Error check;
    std::string line;
    std::ifstream my_file;

    my_file.open(file);
    if (!my_file.is_open())
        error_msg("Error: File not opned or not found");
    unsigned int k = 0;
    int j = 0;
    int w = 0;
    while (std::getline(my_file, line, '\n'))
    {
        int i = 0;
        if (line.find("server"))
            check.set_server(k++);
        else if (line.find("{") > 0)
        {
            check.set_brakets((unsigned int)w++);
            std::cout << line << std::endl;
        }
        else if (line.find("}") > 0)
            check.set_brakets((unsigned int)w--);
        else if (line.find("#") > 0)
            error_msg("Error: 0. No comment allowed");
        else if (line.find("location") && check.get_brakets() >= 1)
            {
                std::cout << " •••• I m here •••• " << std::endl;
                check.set_location((unsigned int)j++);
            }
        else if (line.find("location") && check.get_brakets() == 0)
            error_msg("Error: add braket after server");
        //now location thing ....
    }
    std::cout << "==>brakets :  " << check.get_brakets() << std::endl;
    if (check.get_brakets() != 0)
        error_msg("Error: wrong number of brackets");
}
// void check_details(Error check, std::string line)
// {
//     int i = 0;
//     unsigned int j = check.get_brakets();
//     unsigned int w = check.get_location();

//     while (line[i])
//     {
//         std::cout << "line: " << line << std::endl;
//         if (check.get_server() == 0 && line[i] != '{' && line[i] != '\f' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ')
//             error_msg("Error: add bracket after server");
//         if (line[i] == '#' || line.find("#") != ULLONG_MAX)
//             error_msg("Error: 1 . No comment allowed");
//         if (line[i] == '{')
//         {
//             check.set_brakets((unsigned int)j++);
//             j++;
//         }
//         if (check.get_location() == 0 && line.find("}"))
//             check.set_brakets((unsigned int)j--);
//         //now location thing ....
//         if (line.find("location") != ULLONG_MAX)
//             check.set_location((unsigned int)w++);
//         if (line.find("{") != ULLONG_MAX)
//             check.set_brakets((unsigned int)j++);
//         if (line.find("server") != ULLONG_MAX)
//             check.set_server((check.get_server()) + 1);
//         if (line.find("}") != ULLONG_MAX)
//             check.set_brakets((unsigned int)j--);
//         i++;
//     }
// }
