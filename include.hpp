/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:20:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/27 11:54:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <arpa/inet.h>     //it have all data sockaddr ....
#include <netdb.h> // definitions for network database operations
#include <sys/socket.h> // have data of socket ... lenght 32bits
#include <sys/types.h>
#include <unistd.h>
#define PORT 8080


/*
-------------- Socket addres stucture ------------
    struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
===============================>>>why sin_zero :
    As struct sockaddr_in needs to be cast to struct sockaddr it has to be kept
the same size, sin_zero is an unused member whose sole purpose is to pad the
structure out to 16 bytes (which is the size of sock_addr).
This padding size may vary depending on the address family.
<===============================================================================>
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};
*/

#endif