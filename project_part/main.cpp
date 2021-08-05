/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/05 16:40:09 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Add conf file\n";
        exit(0);
    }
    if (compare_end(av[1], ".conf") == true)
    {
        Error check;
        check_error(av[1]);
        std::ifstream my_file;
        my_file.open(av[1]);
        Parse_server pars;
        pars.map_element(my_file, check.get_one());
        if (check.get_two() != 0)
        {
            Parse_location pars1;
            pars1.map_element(my_file, check.get_two());
        }
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