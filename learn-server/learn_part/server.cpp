/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:16:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/08/10 16:10:38 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"
#include <cstring>
#include <fcntl.h>
int main(int ac, char **av)
{
  if (ac != 2) {
    exit(1);
  }
  int server_fd; // socket descriptor, an integer!
  int new_socket; // conection establish btw add & server
  int valrecv; // communication part
  struct sockaddr_in add;
  // struct sockaddr_in add;
  int fd = open("index.html", O_RDWR);
    // char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

  int size_add = sizeof(add); // socklen_t size of adress

  // ** CREATE SOCKET**/
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0)
  {
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // bind an IP add and a port to a  socket
  add.sin_port = htons(80);
  add.sin_family = AF_INET;
  add.sin_addr.s_addr = INADDR_ANY;

  // memset(add.sin_zero, '\0', sizeof add.sin_zero); // why help to pad from sockaddr_in to sockaddr

  // Forcefully attaching socket to the PORT 
  if (bind(server_fd, (struct sockaddr *)&add, sizeof(add)) < 0)
  {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
  }
  // wait for an incoming connection
  if (listen(server_fd, 10)) // SOMAXCONN is the maximum number of pending connections that can be queued up before connections are refused.
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
      if ((new_socket = accept(server_fd, (struct sockaddr *)&add,
                               (socklen_t *)&size_add)) < 0)
      {
        std::cerr << "acceptance failed" << std::endl;
        exit(EXIT_FAILURE);
      }
        // std::cout << "Server Connected from " <<  inet_ntoa(add.sin_addr) << " port  "  <<  ntohs(add.sin_port) << std::endl;
      // char *buffer = new char[500000];
      char buffer[30000] = {0};
      read(fd, buffer, 30000);
      // valrecv = recv(new_socket, buffer, 1024, 0);
      // std::cout << buffer << std::endl;
      // printf("===>%s\n", buffer);
      write(new_socket, buffer, 30000);
      // write(new_socket , "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", strlen("HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!"));
      std::cout << "------------------------------------------------------" <<  std::endl;
      }
    return 0;
}

// #include "include.hpp"
// #include <cstring>
// #include <fcntl.h>

// int main(int ac, char **av)
// {
//   if (ac != 2) {
//     exit(1);
//   }
//   int server_fd; // socket descriptor, an integer!
//   int new_socket; // conection establish btw add & server
//   int valrecv; // communication part
//   struct sockaddr_in add;
//   // struct sockaddr_in add;
//   int fd = open("index.html", O_RDONLY);
//   socklen_t size_add = sizeof(add); // socklen_t size of adress
//   int len;
//   // ** CREATE SOCKET**/
//   server_fd = socket(AF_INET, SOCK_STREAM, 0);
//   if (server_fd == 0)
//   {
//         std::cerr << "socket failed" << std::endl;
//         exit(EXIT_FAILURE);
//   }
//   // bind an IP add and a port to a  socket
//   add.sin_port = htons(std::stoi(av[1]));
//   add.sin_family = AF_INET;
//   add.sin_addr.s_addr = INADDR_ANY;

//   // memset(add.sin_zero, '\0', sizeof add.sin_zero); // why help to pad from sockaddr_in to sockaddr

//   // Forcefully attaching socket to the PORT 
//   if (bind(server_fd, (struct sockaddr *)&add, sizeof(add)) < 0)
//   {
//         std::cerr << "Bind failed" << std::endl;
//         exit(EXIT_FAILURE);
//   }
//   // wait for an incoming connection
//   if (listen(server_fd, 10)) // SOMAXCONN is the maximum number of pending connections that can be queued up before connections are refused.
//       {
//         std::cerr << "Listening failed" << std::endl;
//         exit(EXIT_FAILURE);
//       }
//       // The accept system call grabs the first connection request

//       // since we have a valid socket , we gonna print some information
//       // send and receive msg , now we use rcv and  a buffer size
//       // read from new_socket
//       //read file
//       while (1)
//       {
//           std::cout << "\t\t\t Waiting for new connection\n";
//           if ((new_socket = accept(server_fd, (struct sockaddr *)&add, &size_add)) < 0)
//           {
//           std::cerr << "acceptance failed" << std::endl;
//           exit(EXIT_FAILURE);
//       }
//     /*••••••••••••••••••••••••••••••••°°°°°°°°°°°Reading file°°°°°°°°°°°°••••••••••••••••••••••••••••••••••*/
//     // std::ifstream is ("index.html", std::ifstream::binary);
//   //   if (is) {
//   //   is.seekg (0, is.end);
//   //  len = is.tellg();
//   //   is.seekg (0, is.beg);
//   //   char * buffer = new char [len];
//   //   is.read(buffer, len);
//     /*••••••••••••••••••••••••••••••••°°°°°°°°°°°Reading file°°°°°°°°°°°°••••••••••••••••••••••••••••••••••*/
//       char *buffer = new char[30000];
      
//       read(fd, buffer, 30000);
//     write(new_socket, buffer,strlen(buffer));
//     // std ::cout <<  buffer << std::endl;
//     std::cout << "------------------------------------------------------" << std::endl;
//     close(new_socket);}
//     return 0;
// }