/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/25 20:49:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int main(int ac, char **av)
{
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw client & server
  int valread;
  struct sockaddr_in s_add;

    // ** CREATE SOCKET**/
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE);
  }

}