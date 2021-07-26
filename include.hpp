/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:20:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/25 20:48:31 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-------------- Socket addres stucture ------------
    struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};
*/
#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sys/socket.h> // have data of socket ... lenght 32bits
#include <netinet/in.h>  //it have all data sockaddr ....
#define PORT 8080


#endif