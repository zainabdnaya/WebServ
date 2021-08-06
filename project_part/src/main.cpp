/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/06 22:20:10 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ParsConfig.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Add conf file\n";
        exit(0);
    }
    if (compare_end(av[1], ".conf") == true)
    {
    //     check_error(av[1]);
    //     std:: cout << check.get_two();
        // std::ifstream my_file;
        // my_file.open(av[1]);
        // if (!my_file.is_open())
        //     error_msg("Error opening the file");
        // Parsing pars;
        // std::map<std::string, std::string>::iterator it;
        // if (check.get_one() >= 2 && check.get_two() <= 1)
        // {
        //     std::cout << "";
        //     for (it = pars.map_simpl(my_file).begin(); it != pars.map_simpl(my_file).end(); ++it)
        //     {
        //         std::cout << "key is " << it->first;
        //         std::cout << "  the value: \t\t\t";
        //         std::cout << it->second << std::endl;
        //     }
        // }
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