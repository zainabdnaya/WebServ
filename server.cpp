/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/27 18:45:22 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"
#include <cstring>

int main(int ac, char **av)
{
  if (ac != 2) {
    exit(1);
  }
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw client & server
  int valrecv; // communication part
  struct sockaddr_in add;
  struct sockaddr_in client;
  socklen_t size_client = sizeof(client); // socklen_t size of adress

  // ** CREATE SOCKET**/
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0)
  {
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // bind an IP add and a port to a  socket
  add.sin_port = htons(std::stoi(av[1]));
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

      // since we have a valid socket , we gonna print some information
      // send and receive msg , now we use rcv and  a buffer size
     //read from new_socket
      while (1) {
        std::cout << "\t\t\t Waiting for new connection\n";
      if ((new_socket = accept(server_fd, (struct sockaddr *)&client,
                               &size_client)) < 0)
      {
        std::cerr << "acceptance failed" << std::endl;
        exit(EXIT_FAILURE);
      }
        std::cout << "Server Connected from " <<  inet_ntoa(client.sin_addr) << " port  "  <<  ntohs(client.sin_port) << std::endl;
      char buffer[1024] = {0};
      valrecv = recv(new_socket, buffer, 1024, 0);
      std::cout << buffer << std::endl;
      write(new_socket , "\thello from server", strlen("\thello from server"));
      std::cout << "------------------------------------------------------" << std::endl;
      close(new_socket);
      }
    return 0;
}