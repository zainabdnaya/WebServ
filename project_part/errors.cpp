/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:29:18 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/03 14:00:52 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void    check_error(char *file)
{
    std::string line;
    std::ifstream my_file;
    my_file.open(file);
    
    if(!my_file.is_open())
     error_msg("Error: File not opned or not found");
    while(!my_file.eof())
    { 
        std::getline(my_file, line);
        if(line != "\n")
        {
            
        }
    }
}