/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:51:29 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/08 00:23:34 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <unistd.h>


bool compare_end(std::string const &s1, std::string const &s2);
bool line_equal(std::string const &line, std::string const &str);
int check_details(std::string line);
int nbr_lines(std::string source);



#endif