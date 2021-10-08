/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:07:42 by zdnaya            #+#    #+#             */
/*   Updated: 2021/08/02 15:04:01 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <map>

using namespace std; // namespace
int main (){
  map<char,int> first;
  
  //initializing
  first['a']=10;
  first['b']=20;
  first['c']=30;
  first['d']=40;
  
   map<char, int>::iterator it;
  //  for(it=first.begin(); it!=first.end(); ++it)
   {
     it=first.begin();
      cout << it->first << " => " << it->second << '\n';
   }
   
  return 0;
}

// int main () {

//   std::ifstream is ("index.html", std::ifstream::binary);
//   if (is) {
//     // get length of file:
//     // is.seekg (15, is.end);
//     int length = is.tellg();
//     is.seekg (15, is.beg);

//     char * buffer = new char [length];

//     std::cout << "Reading " << length << " characters... ";
//     // read data as a block:
//     is.read (buffer,length);

//     if (is)
//       std::cout << "all characters read successfully." << std::endl;
//     else
//       std::cout << "error: only " << is.gcount() << " could be read";
//     std::cout << buffer;
//     is.close();
//     // ...buffer contains the entire file...

//     delete[] buffer;
//   }
//   return 0;
// }