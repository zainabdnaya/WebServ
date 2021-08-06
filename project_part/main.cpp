/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/06 15:27:07 by zainabdnaya      ###   ########.fr       */
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
        if (!my_file.is_open())
            error_msg("Error opening the file");
        Parsing pars;
        std::map<std::string, std::string> map_pr;
        if (check.get_one() == 1 && check.get_two() <= 1)
           pars.map_simpl(my_file);
        std::map<std::string, std::string>::iterator it;
        for (it = pars.get_map().begin(); it != pars.get_map().end(); ++it)
        {
            std::cout << "key is " << it->first;
            std::cout << "  the value: \t\t\t";
            std::cout << it->second << std::endl;
        }
    }
    else
        std::cerr << "wrong file \n";
    return (0);
}
// std::string line = "    dkdkdlkdk";
// if(line.find("}") != std::string::npos)
//     std::cout << "true" << std::endl;
// else
//     std::cout << "false" << std::endl;