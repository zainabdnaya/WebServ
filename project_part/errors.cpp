/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:29:18 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/04 12:34:11 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void check_error(char *file)
{
    Error check;
    std::string line;
    std::ifstream my_file;
    unsigned int k = 0;
    int w = 0;

    my_file.open(file);

    if (!my_file.is_open())
        error_msg("Error: File not opned or not found");
    while (!my_file.eof())
    {
        while (std::getline(my_file, line, '\n'))
        {
            int i = 0;
            if (check.get_server() == 0)
            {
                if (line_equal(line, "server"))
                    check.set_server(k++);
                else if (line_equal(line, "server {") || line_equal(line, "server{") || line_equal(line, "server   {"))
                {
                    check.set_server(k++);
                    check.set_brakets((unsigned int)w++);
                }
                if (line_equal(line, "{"))
                    check.set_brakets(k++);
                if (line_equal(line, "}"))
                    check.set_brakets(k--);
                if(line.find("#") != ULLONG_MAX || line_equal(line, "#"))
                    error_msg("Error: 0. No comment allowed");
                else
                {
                    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\v')
                        i++;
                    if (line[i] == '#' )
                        error_msg("Error: 0. No comment allowed");
                    if (line.find("server") == 0)
                    {
                        int j = line.find("server") + 6;
                        check.set_server(k++);
                        while (line[j])
                        {
                            if (line[j] == '{')
                                check.set_brakets((unsigned int)w++);
                            if (line[j] != ' ' && line[j] != '\t' && line[j] != '\n' && line[j] != '\v')
                                error_msg("Error");
                            if (line[j] == '}')
                                check.set_brakets((unsigned int)w--);

                            j++;
                        }
                    }
                    else
                        error_msg("Error:Config file should start with server { or server or server{");
                }
            }
            else
                check_details(check, line);
        }
    }
    if (check.get_brakets() != 0)
        error_msg("Error: wrong number of brackets");
}
void check_details(Error check, std::string line)
{
    int i = 0;
    unsigned int j = check.get_brakets();
    unsigned int w = check.get_location();

    while (line[i])
    {
        if (check.get_server() == 0 && line[i] != '{' && line[i] != '\f' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ')
            error_msg("Error: add bracket after server");
        if (line[i] == '#' || line.find("#") != ULLONG_MAX)
            error_msg("Error: 1 . No comment allowed");
        if (line[i] == '{')
        {
            check.set_brakets((unsigned int)j++);
            j++;
        }
        if (check.get_location() == 0 && line.find("}"))
            check.set_brakets((unsigned int)j--);
        //now location thing ....
        if (line.find("location"))
            check.set_location((unsigned int)w++);
        if (line.find("{"))
            check.set_brakets((unsigned int)j++);
        if(line.find("server"))
            check.set_server((check.get_server())+ 1);
        if (line.find("}"))
            check.set_brakets((unsigned int)j--);
        i++;
    }
}
