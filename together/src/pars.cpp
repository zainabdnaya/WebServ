/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:03:57 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/25 10:09:29 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pars.hpp"

Server_element::Server_element()
{
    this->port = 0;
}

Parsing::Parsing(char *av, int nbr_server, int nbr_location)
{
    int z = 0;

    int res = 0;
    std::map<int, std::string> map_s;
    std::string result;
    std::string file = av;
    char line[1024];
    int fd = open(file.c_str(), O_RDONLY);
    if (fd < 0)
        error_msg("Error file not found");
    while ((res = read(fd, line, 1024)) > 0)
    {
        if (std::strcmp(line, "\n") != 0)
            result = result + line;
        int i = 0;
        while (i < 1024)
            line[i++] = 0;
    }
    int len = nbr_lines(result);
    int i = 0;
    char **ptr = new char *[len + 1];
    int l = 0;
    int d = 0;
    while (i < len)
    {
        while (std::strcmp(Those_lines(result, i, len).c_str(), "") == 0)
            i++;
        if (std::strcmp(Those_lines(result, i, len).c_str(), "server") == 0)
        {
            i++;
            while (std::strcmp(Those_lines(result, i, len).c_str(), "{") == 0 || std::strcmp(Those_lines(result, i, len).c_str(), "}") == 0)
                i++;
            while (Those_lines(result, i, len) != "server" && Those_lines(result, i, len).find("location") == std::string::npos && i < len)
            {
                if (Those_lines(result, i, len) != "")
                {
                    char **ptr = ft_charSplit(Those_lines(result, i, len).c_str(), (char *)" \t");
                    std::string str;
                    std::string key = ptr[0];
                    int k = 1;
                    while (ptr[k])
                    {
                        if (k == 1)
                            str = ptr[k];
                        else
                            str = str + " " + ptr[k];
                        k++;
                    }
                    this->server_map.insert(std::pair<std::string, std::string>(key, str));
                }
                i++;
            }
            if(Those_lines(result, i, len).find("location") != std::string::npos)
            {
                // std::cout << Those_lines(result, i,len) << std::endl; 
                    char **ptr = ft_charSplit(Those_lines(result, i, len).c_str(), (char *)" \t");
                    std::string str;
                    std::string key = ptr[0];
                    int k = 1;
                    while (ptr[k])
                    {
                        if (k == 1)
                            str = ptr[k];
                        else
                            str = str + " " + ptr[k];
                        k++;
                    }
                    std::cout << key << " " << str << std::endl; 
                    i++;
                    // this->server_map.insert(std::pair<std::string, std::string>(key, str));
            }
            std::multimap<std::string, std::string> tmp;
            tmp = this->server_map;
            this->_server_map[z++] = tmp;
            this->server_map.clear();
            // i--;
        }
        if (Those_lines(result, i, len).find("location") != std::string::npos)
        {
            while (Those_lines(result, i, len).find("}") == std::string::npos)
            {
                if (Those_lines(result, i, len) != "" && Those_lines(result, i, len) != "}" && Those_lines(result, i, len) != "{")
                {
                    char **ptr = ft_charSplit(Those_lines(result, i, len).c_str(), (char *)" \t");
                    std::string str;
                    std::string key = ptr[0];
                    int k = 1;
                    while (ptr[k])
                    {
                        if (k == 1)
                            str = ptr[k];
                        else
                            str = str + " " + ptr[k];
                        k++;
                    }
                    // std::cout << Those_lines(result, i, len) << std::endl;
                    this->loc_map.insert(std::pair<std::string, std::string>(key, str));
                }
                i++;
            }
            std::multimap<std::string, std::string> tmp;
            tmp = this->loc_map;
            this->_loc_map[d++] = tmp;
            this->loc_map.clear();
            // std::cout << "this server number : " << z << " and location is : " << d << std::endl;
        }
        // this->all.insert(std::pair<std::map<int, std::multimap<std::string, std::string> >, std::map<int, std::multimap<std::string, std::string> > >(this->_server_map,this->_loc_map));
        if (i < len)
            i++;
    }

    // std::multimap<std::map<int, std::multimap<std::string, std::string> >, std::map<int, std::multimap<std::string, std::string> > >::iterator it;
    // for (it = this->all.begin(); it != this->all.end(); ++it)
    // {
    //     std::map<int, std::multimap<std::string, std::string> >::iterator it1 = it->first;
    //     std::cout << "-----------------------------------------------------";
    //     for (it1 = it->first.begin(); it1 != it->first.end(); ++it1)
    //     {
    //         // std::cout << it1->first << std::endl;
    //     }
    //     std::cout << "-----------------------------------------------------";
    // }

    // std::map<int, std::multimap<std::string, std::string>>::iterator it0;

    // std::multimap<std::string, std::string>::iterator it;
    // for (it0 = _server_map.begin(); it0 != _server_map.end(); ++it0)
    // {
    //     std::cout << "----------------------------------\n";
    //     std::cout << "for server " << it0->first << std::endl;
    //     for (it = it0->second.begin(); it != it0->second.end(); ++it)
    //     {
    //         std::cout << it->first << " ==> " << it->second << std::endl;
    //     }
    // }
    // std::map<int, std::multimap<std::string, std::string>>::iterator it2;

    // std::multimap<std::string, std::string>::iterator it1;
    // for (it2 = _loc_map.begin(); it2 != _loc_map.end(); ++it2)
    // {
    //     std::cout << "----------------------------------\n";
    //     std::cout << "for location " << it2->first << std::endl;
    //     for (it1 = it2->second.begin(); it1 != it2->second.end(); ++it1)
    //     {
    //         std::cout << " [" << it1->first << "]  ==> " << it1->second << std::endl;
    //     }
    //     std::cout << "----------------------------------\n";
    // }
}

Parsing::~Parsing()
{
}
