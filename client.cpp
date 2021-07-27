/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:25 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/27 16:56:23 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
    exit(1);
    }
    
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw client & server
  int valread; // communication part
  struct sockaddr_in add;
  char buffer[1024] = {0};

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    std::cerr << "Socket failed" << std::endl;
    exit(EXIT_FAILURE);
  }
  memset(&add, '0', sizeof(add));
  add.sin_family = AF_INET;
  add.sin_port = htons(std::stoi(av[1]));
  add.sin_addr.s_addr = INADDR_ANY;

  if (inet_addr("127.0.0.1") ==  ( in_addr_t)(-1))
  {
    std::cerr << "Invalid IP" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (connect(server_fd, (struct sockaddr *)&add, sizeof(add)) < 0)
    {
      std::cerr << "Failed to connect " << std::endl;
        exit(EXIT_FAILURE);
  }
  
  send(server_fd, "hello from client", strlen("hello from client"), 0);
  std::cerr << "hello from client";
  valread = recv(new_socket, buffer, 1024, 0);
  std::cerr << buffer << std::endl;
       close(server_fd);

  return 0;
}
