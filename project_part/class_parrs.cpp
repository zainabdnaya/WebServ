/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_parrs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:44:15 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/05 17:33:54 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

Parse_server::Parse_server()
{
    listen = 80;
    host = "";
    server_name = "";
    clinet_max_bosy_size = "";
    error_pages = NULL;
    root = "";
}

Parse_location::Parse_location()
{
    root = "";
    index = "";
    allow_methods = "";
    redirection = ""; 
    CGI = "";
    upload_store_directory = "";
}

std::map<std::string, std::string>  Parse_server::map_element(std::ifstream my_file, unsigned int nbr_serv)
{
    // while(std)
}



 std::map<std::string, std::string>  Parse_location::map_element(std::ifstream my_file, unsigned int nbr_loc)
{   
}


Parse_server::~Parse_server()
{
    
}
Parse_location::~Parse_location()
{
    
}