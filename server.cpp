/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/27 13:21:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"
#include <cstring>

int main(int ac, char **av)
{
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw client & server
  int valread; // communication part
  struct sockaddr_in add;
  struct sockaddr_in client;
  socklen_t size_client = sizeof(client); // socklen_t size of adress
  char buffer[1024] = {0};


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

  memset(add.sin_zero, '\0', sizeof add.sin_zero); // why help to pad from sockaddr_in to sockaddr

  // Forcefully attaching socket to the PORT 
  if (bind(server_fd, (struct sockaddr *)&add, sizeof(add)) < 0)
  {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // wait for an incoming connection
  if (listen(server_fd, SOMAXCONN)) // SOMAXCONN is the maximum number of pending connections that can be queued up before connections are refused.
      {
        std::cerr << "Listening failed" << std::endl;
        exit(EXIT_FAILURE);
      }
      // The accept system call grabs the first connection request
      if ((new_socket = accept(server_fd, (struct sockaddr *)&client,
                               &size_client)) < 0)
      {
        std::cerr << "acceptance failed" << std::endl;
        exit(EXIT_FAILURE);
      }

      else {
        std::cout << "Server Connected from " <<  inet_ntoa(client.sin_addr) << " port  "  <<  ntohs(client.sin_port) << std::endl;
      }

      // since we have a valid socket , we gonna print some information
      // send and receive msg , now we use rcv and  a buffer size
      // const void *msg = "hello from server\n";
      // send(new_socket, msg, 20, 0);
      // comunication part
      valread = read(new_socket, buffer, 500);
      if (valread < 0) {
        std::cerr << ("ERROR reading from socket") << std::endl;
      }
     std::cout << "Here is the message: " << buffer << std::endl;
     close(new_socket);
     close(server_fd);

    return 0;
      
}