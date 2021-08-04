/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_err.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:33:17 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/04 10:49:49 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

Error::Error()
{
    nbr_server = 0;
    nbr_location = 0;
}

unsigned int Error::get_server()
{
    return (this->nbr_server);
}

unsigned int Error::get_location()
{
    return (this->nbr_location);
}

unsigned int Error::get_brakets()
{
    return (this->nbr_brakets);
}


void Error::set_server(unsigned int ser)
{
    this->nbr_server = ser;
}

void Error::set_location(unsigned int nbr_loc)
{
    this->nbr_location = nbr_loc;
}

void Error::set_brakets(unsigned int nbr_brak)
{
    this->nbr_brakets = nbr_brak;
}

Error::~Error()
{
}