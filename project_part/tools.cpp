/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:24:36 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/02 17:35:46 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

bool compare_end(std::string const &s1, std::string const &s2)
{
    int i;
    int j;

    i = s1.size() - 1;
    j = s2.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s1[i] != s2[j])
            return false;
        i--;
        j--;
    }
    return true;
}


void    error_msg(std::string const msg)
{
    std::cout << msg << std::endl;
    exit(EXIT_FAILURE);    
}