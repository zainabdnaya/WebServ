/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:23:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/18 13:43:09 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>     //it have all data sockaddr ....
#include <netdb.h> // definitions for network database operations
#include <sys/socket.h> // have data of socket ... lenght 32bits
#include <sys/types.h>
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <sstream>
#include "ParsConfig.hpp"
class Server 
{
    private:
        int socket_fd;
        int new_socket;
        struct sockaddr_in add;
        int sizeof_add;
    public:
        Server();
        ~Server();
        int creatSocket_fd(void);
        void set_strructAddr(struct sockaddr_in add);
        int get_sizeofAdd(void);
        void bind_socket(struct sockaddr_in add);
        void listen_socket(int socket_fd);
        void accept_socket(int socket_fd,struct sockaddr_in add);
};

#endif