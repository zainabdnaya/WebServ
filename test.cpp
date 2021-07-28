/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:07:42 by zdnaya            #+#    #+#             */
/*   Updated: 2021/07/28 16:00:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main () {

  std::ifstream is ("index.html", std::ifstream::binary);
  if (is) {
    // get length of file:
    // is.seekg (15, is.end);
    int length = is.tellg();
    is.seekg (15, is.beg);

    char * buffer = new char [length];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    if (is)
      std::cout << "all characters read successfully." << std::endl;
    else
      std::cout << "error: only " << is.gcount() << " could be read";
    std::cout << buffer;
    is.close();
    // ...buffer contains the entire file...

    delete[] buffer;
  }
  return 0;
}