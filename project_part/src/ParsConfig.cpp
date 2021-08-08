/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsConfig.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:33:38 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/08 12:58:13 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ParsConfig.hpp"

ParsConfig::ParsConfig(char *file)
{
    this->nbr_server = 0;
    this->nbr_location = 0;
    this->server = 0;
    this->location = 0;
    this->file = file;
    std::map<int, std::string> tst = get_map(file);
    check_error(tst);
    // std::map<int, std::string>::iterator it = tst.begin();
    // for (it = tst.begin(); it != tst.end(); ++it)
    // {
    //     std::cout << "key is " << it->first;
    //     std::cout << "  the value: \t\t\t";
    //     std::cout << it->second << std::endl;
    // }
}
/****************  Those lines **********************************************/
std::string Those_lines(std::string txt, int nbr_line, int txt_lines)
{
    int i = 0;
    int j = 0;
    int w = 0;
    if (nbr_line >= txt_lines)
        return (std::string(NULL));
    while (i < nbr_line)
    {
        if (txt[j] == '\n')
            i++;
        j++;
    }
    while (txt[j] != '\n' && std::isspace(txt[j])) // for the space befor  txt start from where the txt begins
        j++;
    w = 0;
    while (txt[w + j] && txt[w + j] != '\n') // when the line ends until \n
        ++w;
    while (w > 0 && std::isspace(txt[w + j - 1])) // escape space after the txt o the line
        --w;
    return (std::string(txt, j, w));
}
/****************************************************************************/

/************* Map *********************************************************/
std::map<int, std::string> get_map(char *av)
{
    int res = 0;
    std::map<int, std::string> map_s;
    std::string result;
    std::string file = av;
    char line[1024];
    int fd = open(file.c_str(), O_RDONLY);
    while ((res = read(fd, line, 1024)) > 0)
    {
        if (std::strcmp(line, "\n") != 0)
            result = result + line;
        int i = 0;
        while (i < 1024)
            line[i++] = 0;
    }
    int i = 0;
    while (i < nbr_lines(result))
    {
        map_s[i + 1] = Those_lines(result, i, nbr_lines(result));
        i++;
    }
    return (map_s);
}
/**************************************************************************/
/******************** Error *******************************************/

void check_error(std::map<int, std::string> error_mp)
{
    std::map<int, std::string>::iterator it;

    for (it = error_mp.begin(); it != error_mp.end(); ++it)
    {
        while (it->second == "\n")
            error_mp.erase(it->first);
        if (it->first == 1 && it->second != "server")
            error_msg("Error : file should start eith server");
    }
    for (it = error_mp.begin(); it != error_mp.end(); ++it)
    {
        std::cout << "key is " << it->first;
        std::cout << "  the value: \t\t\t";
        std::cout << it->second << std::endl;
    }
}

/******************************************************************************/
ParsConfig::~ParsConfig()
{
}
// void check_error(char *file)
// {
//     std::string line = "";
//     std::ifstream my_file;
//     unsigned int w = 0;
//     unsigned int h = 0;
//     unsigned int k = 0;
//     int nb_line = 0;
//     my_file.open(file);
//     if (!my_file.is_open())
//         error_msg("Error: File not opned or not found");
//     while (std::getline(my_file, line, '\n'))
//     {
//         nb_line++;
//         if (nb_line == 1 && line.find("server") == std::string::npos)
//             error_msg("Error: sould start with server ");
//         if (line.find("#") != std::string::npos)
//         {
//             std::cout << " ERROR : line = " << nb_line + 1 << " ==> " << std::endl
//                       << line << std::endl;
//             exit(EXIT_FAILURE);
//         }
//         if (line.find("{") != std::string::npos)
//         {
//             k++;
//         }
//         if (line.find("}") != std::string::npos)
//         {
//             k--;
//         }
//     }
//     if (k != 0)
//         error_msg("Error: wrong number of brackets");
// }