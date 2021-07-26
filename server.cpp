/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/26 14:53:37 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int main(int ac, char **av)
{
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw client & server
  int valread;
  struct sockaddr_in add;

  // ** CREATE SOCKET**/
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0)
  {
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // bind an IP add and a port to a  socket
  add.sin_port = htons(PORT);
  add.sin_family = AF_INET;
  add.sin_addr.s_addr = INADDR_ANY;
  // Forcefully attaching socket to the PORT 
  if ((bind(server_fd, (sockaddr_in *)&add, sizeof(add))) < 0)
  {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // wait for an incoming connection
  if (listen(server_fd, SOMAXCONN) // SOMAXCONN is the maximum number of pending connections that can be queued up before connections are refused. 
  {
        std::cerr << "Listening failed" << std::endl;
        exit(EXIT_FAILURE); 
  }
}