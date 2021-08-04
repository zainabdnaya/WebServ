/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/04 17:19:41 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cerr << "Add conf file\n";
        exit(0);
    }    
    if (compare_end(av[1], ".conf") == true)
    {
            check_error(av[1]);
    }
    else
        std::cerr << "wrong file \n";
    // std::string line = "    dkdkdlkdk";
    // if(line.find("}") != std::string::npos)
    //     std::cout << "true" << std::endl;
    // else
    //     std::cout << "false" << std::endl;
    return (0);
}