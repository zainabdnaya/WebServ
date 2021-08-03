/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/02 18:22:31 by zainabdnaya      ###   ########.fr       */
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
        std::cerr << "wronf file \n"
    return (0);
}