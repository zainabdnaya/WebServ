/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:31:17 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/25 10:05:31 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_HPP
#define PARS_HPP
#include <iostream>
#include <map>
#include "ErrorHandling.hpp"

class LocationManage
{
private:
public:
};

class Server_element
{
private:
    int nb_port;
    int *port;

public:
    Server_element();
// <<<<<<< HEAD
        Server_element(int index, std::map<int, std::multimap<std::string, std::string> > _server_map,std::map<int, std::multimap<std::string, std::string> > _loc_map);
    void setPorts(int *ports);
// =====
// >>>>>>> 6f33c780ad777b28b0a6a7ca69cc1a39e4b16af2
    void GetPorts();
    void add_ports(int *port, int nb_port);
};

class Parsing
{
private:
    Server_element *server;
    std::map<int, Server_element> parsing;
    std::multimap<std::string, std::string> server_map;
    std::multimap<std::string, std::string> loc_map;
    std::map<int, std::multimap<std::string, std::string> > _server_map;
    std::map<int, std::multimap<std::string, std::string> > _loc_map;
// <<<<<<< HEAD
// =======
    std::multimap<std::map<int, std::multimap<std::string, std::string> >, std::map<int, std::multimap<std::string, std::string> > > all;
// >>>>>>> 6f33c780ad777b28b0a6a7ca69cc1a39e4b16af2

public:
    Parsing(char *, int nbr_server, int nbr_location);
    ~Parsing();
};
#endif