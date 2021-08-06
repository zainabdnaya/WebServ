/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_parrs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:44:15 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/06 15:12:05 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

Parsing::Parsing()
{
    this->map_s[""] = "";//<std::string,str::string>;
}

std::map<std::string, std::string> Parsing::map_simpl(std::ifstream my_file)
{
    std::string key;
    std::string str1;
    std::string str;
    while (my_file >> str)
    {
        while ((str == "{" || str == "server"))
            my_file >> str;
        if (str == "}" && my_file.eof())
            my_file >> str;
        else if (str == "}" && !my_file.eof())
            break;
        else if (str == "http_methods")
        {
            key = str;
            my_file >> str;
            str1 = "";
            while (str == "GET" || str == "HEAD" || str == "POST" || str == "PUT" || str == "OPTIONS" || str == "DELETE")
            {
                str1 += str + " ";
                my_file >> str;
            }
            map_s[key] = str1;
            if (str == "error_page")
            {
                key = str;
                my_file >> str;
                str1 = str;
                my_file >> str;
                map_s[key] = str1 + " " + str;
            }
            else
            {
                key = str;
                my_file >> str;
                map_s[key] = str;
            }
        }
        else if (str == "error_page")
        {
            key = str;
            my_file >> str;
            str1 = str;
            my_file >> str;
            map_s[key] = str1 + " " + str;
        }
        else
        {
            key = str;
            my_file >> str;
            map_s[key] = str;
        }
    }
    return(map_s);
}

std::map<std::string, std::string> Parsing::get_map()
{
    return(std::map<std::string, std::string>(this->map_s));
}

Parsing::~Parsing()
{
}
